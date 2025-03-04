/*
 * (C) Copyright 2005- ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 *
 * In applying this licence, ECMWF does not waive the privileges and immunities granted to it by
 * virtue of its status as an intergovernmental organisation nor does it submit to any jurisdiction.
 */

/**************************************
 *  Enrico Fucile
 **************************************/


#include "grib_scaling.h"
#include "grib_api_internal.h"
/*
   This is used by make_class.pl

   START_CLASS_DEF
   CLASS      = accessor
   SUPER      = grib_accessor_class_double
   IMPLEMENTS = unpack_double
   IMPLEMENTS = init
   MEMBERS=const char*    binaryScaleFactor
   MEMBERS=const char*    bitsPerValue
   MEMBERS=const char*    decimalScaleFactor
   MEMBERS=const char*    referenceValue
   MEMBERS=const char*    floatType
   END_CLASS_DEF

 */

/* START_CLASS_IMP */

/*

Don't edit anything between START_CLASS_IMP and END_CLASS_IMP
Instead edit values between START_CLASS_DEF and END_CLASS_DEF
or edit "accessor.class" and rerun ./make_class.pl

*/

static int unpack_double(grib_accessor*, double* val, size_t* len);
static void init(grib_accessor*, const long, grib_arguments*);

typedef struct grib_accessor_simple_packing_error
{
    grib_accessor att;
    /* Members defined in gen */
    /* Members defined in double */
    /* Members defined in simple_packing_error */
    const char*    binaryScaleFactor;
    const char*    bitsPerValue;
    const char*    decimalScaleFactor;
    const char*    referenceValue;
    const char*    floatType;
} grib_accessor_simple_packing_error;

extern grib_accessor_class* grib_accessor_class_double;

static grib_accessor_class _grib_accessor_class_simple_packing_error = {
    &grib_accessor_class_double,                      /* super */
    "simple_packing_error",                      /* name */
    sizeof(grib_accessor_simple_packing_error),  /* size */
    0,                           /* inited */
    0,                           /* init_class */
    &init,                       /* init */
    0,                  /* post_init */
    0,                    /* destroy */
    0,                       /* dump */
    0,                /* next_offset */
    0,              /* get length of string */
    0,                /* get number of values */
    0,                 /* get number of bytes */
    0,                /* get offset to bytes */
    0,            /* get native type */
    0,                /* get sub_section */
    0,               /* pack_missing */
    0,                 /* is_missing */
    0,                  /* pack_long */
    0,                /* unpack_long */
    0,                /* pack_double */
    0,                 /* pack_float */
    &unpack_double,              /* unpack_double */
    0,               /* unpack_float */
    0,                /* pack_string */
    0,              /* unpack_string */
    0,          /* pack_string_array */
    0,        /* unpack_string_array */
    0,                 /* pack_bytes */
    0,               /* unpack_bytes */
    0,            /* pack_expression */
    0,              /* notify_change */
    0,                /* update_size */
    0,             /* preferred_size */
    0,                     /* resize */
    0,      /* nearest_smaller_value */
    0,                       /* next accessor */
    0,                    /* compare vs. another accessor */
    0,      /* unpack only ith value (double) */
    0,       /* unpack only ith value (float) */
    0,  /* unpack a given set of elements (double) */
    0,   /* unpack a given set of elements (float) */
    0,     /* unpack a subarray */
    0,                      /* clear */
    0,                 /* clone accessor */
};


grib_accessor_class* grib_accessor_class_simple_packing_error = &_grib_accessor_class_simple_packing_error;

/* END_CLASS_IMP */

static void init(grib_accessor* a, const long l, grib_arguments* c)
{
    grib_accessor_simple_packing_error* self = (grib_accessor_simple_packing_error*)a;
    int n                                    = 0;

    self->bitsPerValue       = grib_arguments_get_name(grib_handle_of_accessor(a), c, n++);
    self->binaryScaleFactor  = grib_arguments_get_name(grib_handle_of_accessor(a), c, n++);
    self->decimalScaleFactor = grib_arguments_get_name(grib_handle_of_accessor(a), c, n++);
    self->referenceValue     = grib_arguments_get_name(grib_handle_of_accessor(a), c, n++);
    self->floatType          = grib_arguments_get_name(grib_handle_of_accessor(a), c, n++);

    a->flags |= GRIB_ACCESSOR_FLAG_READ_ONLY;
    a->length = 0;
}

static int unpack_double(grib_accessor* a, double* val, size_t* len)
{
    grib_accessor_simple_packing_error* self = (grib_accessor_simple_packing_error*)a;
    int ret                                  = 0;
    long binaryScaleFactor                   = 0;
    long bitsPerValue                        = 0;
    long decimalScaleFactor                  = 0;
    double referenceValue                    = 0;

    if ((ret = grib_get_long_internal(grib_handle_of_accessor(a),
                                      self->binaryScaleFactor, &binaryScaleFactor)) != GRIB_SUCCESS)
        return ret;
    if ((ret = grib_get_long_internal(grib_handle_of_accessor(a),
                                      self->bitsPerValue, &bitsPerValue)) != GRIB_SUCCESS)
        return ret;

    if ((ret = grib_get_long_internal(grib_handle_of_accessor(a),
                                      self->decimalScaleFactor, &decimalScaleFactor)) != GRIB_SUCCESS)
        return ret;

    if ((ret = grib_get_double_internal(grib_handle_of_accessor(a),
                                        self->referenceValue, &referenceValue)) != GRIB_SUCCESS)
        return ret;

    if (!strcmp(self->floatType, "ibm"))
        *val = grib_ibmfloat_error(referenceValue);
    else if (!strcmp(self->floatType, "ieee"))
        *val = grib_ieeefloat_error(referenceValue);
    else
        Assert(1 == 0);

    if (bitsPerValue != 0)
        *val = (*val + codes_power<double>(binaryScaleFactor, 2)) * codes_power<double>(-decimalScaleFactor, 10) * 0.5;

    if (ret == GRIB_SUCCESS)
        *len = 1;

    return ret;
}
