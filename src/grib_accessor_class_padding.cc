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

#include "grib_api_internal.h"
/*
   This is used by make_class.pl

   START_CLASS_DEF
   CLASS      = accessor
   SUPER      = grib_accessor_class_bytes
   IMPLEMENTS = init;update_size;resize; value_count
   IMPLEMENTS = compare;string_length;byte_count
   END_CLASS_DEF

 */

/* START_CLASS_IMP */

/*

Don't edit anything between START_CLASS_IMP and END_CLASS_IMP
Instead edit values between START_CLASS_DEF and END_CLASS_DEF
or edit "accessor.class" and rerun ./make_class.pl

*/

static size_t string_length(grib_accessor*);
static long byte_count(grib_accessor*);
static int value_count(grib_accessor*, long*);
static void init(grib_accessor*, const long, grib_arguments*);
static void update_size(grib_accessor*, size_t);
static void resize(grib_accessor*,size_t);
static int compare(grib_accessor*, grib_accessor*);

typedef struct grib_accessor_padding
{
    grib_accessor att;
    /* Members defined in gen */
    /* Members defined in bytes */
    /* Members defined in padding */
} grib_accessor_padding;

extern grib_accessor_class* grib_accessor_class_bytes;

static grib_accessor_class _grib_accessor_class_padding = {
    &grib_accessor_class_bytes,                      /* super */
    "padding",                      /* name */
    sizeof(grib_accessor_padding),  /* size */
    0,                           /* inited */
    0,                           /* init_class */
    &init,                       /* init */
    0,                  /* post_init */
    0,                    /* destroy */
    0,                       /* dump */
    0,                /* next_offset */
    &string_length,              /* get length of string */
    &value_count,                /* get number of values */
    &byte_count,                 /* get number of bytes */
    0,                /* get offset to bytes */
    0,            /* get native type */
    0,                /* get sub_section */
    0,               /* pack_missing */
    0,                 /* is_missing */
    0,                  /* pack_long */
    0,                /* unpack_long */
    0,                /* pack_double */
    0,                 /* pack_float */
    0,              /* unpack_double */
    0,               /* unpack_float */
    0,                /* pack_string */
    0,              /* unpack_string */
    0,          /* pack_string_array */
    0,        /* unpack_string_array */
    0,                 /* pack_bytes */
    0,               /* unpack_bytes */
    0,            /* pack_expression */
    0,              /* notify_change */
    &update_size,                /* update_size */
    0,             /* preferred_size */
    &resize,                     /* resize */
    0,      /* nearest_smaller_value */
    0,                       /* next accessor */
    &compare,                    /* compare vs. another accessor */
    0,      /* unpack only ith value (double) */
    0,       /* unpack only ith value (float) */
    0,  /* unpack a given set of elements (double) */
    0,   /* unpack a given set of elements (float) */
    0,     /* unpack a subarray */
    0,                      /* clear */
    0,                 /* clone accessor */
};


grib_accessor_class* grib_accessor_class_padding = &_grib_accessor_class_padding;

/* END_CLASS_IMP */

static void init(grib_accessor* a, const long len, grib_arguments* arg)
{
    a->flags |= GRIB_ACCESSOR_FLAG_EDITION_SPECIFIC;
    a->flags |= GRIB_ACCESSOR_FLAG_READ_ONLY;
}

static int compare(grib_accessor* a, grib_accessor* b)
{
    if (a->length != b->length)
        return GRIB_COUNT_MISMATCH;
    return GRIB_SUCCESS;
}

static void update_size(grib_accessor* a, size_t new_size)
{
    /* printf("update_size: grib_accessor_class_padding.c %ld %ld %s %s\n", (long)new_size,(long)a->length,a->cclass->name,a->name); */
    a->length = new_size;
}

static void resize(grib_accessor* a, size_t new_size)
{
    void* zero = grib_context_malloc_clear(a->context, new_size);

    grib_buffer_replace(a, (const unsigned char*)zero, new_size, 1, 0);
    grib_context_free(a->context, zero);
    grib_context_log(a->context, GRIB_LOG_DEBUG, "resize: grib_accessor_class_padding.c %ld %ld %s %s\n", (long)new_size, (long)a->length, a->cclass->name, a->name);
    Assert(new_size == a->length);
}

static int value_count(grib_accessor* a, long* c)
{
    *c = a->length;
    return 0;
}
static long byte_count(grib_accessor* a)
{
    return a->length;
}
static size_t string_length(grib_accessor* a)
{
    return (size_t)a->length;
}
