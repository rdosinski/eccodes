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
   SUPER      = grib_accessor_class_gen
   IMPLEMENTS = unpack_long;pack_long; value_count
   IMPLEMENTS = unpack_string;pack_string
   IMPLEMENTS = init; get_native_type
   MEMBERS=int index
   MEMBERS=const char* the_class
   MEMBERS=const char* stream
   MEMBERS=const char* type
   MEMBERS=const char* expver
   MEMBERS=const char* typeOfProcessedData
   MEMBERS=const char* productDefinitionTemplateNumber
   MEMBERS=const char* stepType
   MEMBERS=const char* derivedForecast
   MEMBERS=const char* typeOfGeneratingProcess

   END_CLASS_DEF

 */

/* START_CLASS_IMP */

/*

Don't edit anything between START_CLASS_IMP and END_CLASS_IMP
Instead edit values between START_CLASS_DEF and END_CLASS_DEF
or edit "accessor.class" and rerun ./make_class.pl

*/

static int get_native_type(grib_accessor*);
static int pack_long(grib_accessor*, const long* val, size_t* len);
static int pack_string(grib_accessor*, const char*, size_t* len);
static int unpack_long(grib_accessor*, long* val, size_t* len);
static int unpack_string(grib_accessor*, char*, size_t* len);
static int value_count(grib_accessor*, long*);
static void init(grib_accessor*, const long, grib_arguments*);

typedef struct grib_accessor_g2_mars_labeling
{
    grib_accessor att;
    /* Members defined in gen */
    /* Members defined in g2_mars_labeling */
    int index;
    const char* the_class;
    const char* stream;
    const char* type;
    const char* expver;
    const char* typeOfProcessedData;
    const char* productDefinitionTemplateNumber;
    const char* stepType;
    const char* derivedForecast;
    const char* typeOfGeneratingProcess;
} grib_accessor_g2_mars_labeling;

extern grib_accessor_class* grib_accessor_class_gen;

static grib_accessor_class _grib_accessor_class_g2_mars_labeling = {
    &grib_accessor_class_gen,                      /* super */
    "g2_mars_labeling",                      /* name */
    sizeof(grib_accessor_g2_mars_labeling),  /* size */
    0,                           /* inited */
    0,                           /* init_class */
    &init,                       /* init */
    0,                  /* post_init */
    0,                    /* destroy */
    0,                       /* dump */
    0,                /* next_offset */
    0,              /* get length of string */
    &value_count,                /* get number of values */
    0,                 /* get number of bytes */
    0,                /* get offset to bytes */
    &get_native_type,            /* get native type */
    0,                /* get sub_section */
    0,               /* pack_missing */
    0,                 /* is_missing */
    &pack_long,                  /* pack_long */
    &unpack_long,                /* unpack_long */
    0,                /* pack_double */
    0,                 /* pack_float */
    0,              /* unpack_double */
    0,               /* unpack_float */
    &pack_string,                /* pack_string */
    &unpack_string,              /* unpack_string */
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


grib_accessor_class* grib_accessor_class_g2_mars_labeling = &_grib_accessor_class_g2_mars_labeling;

/* END_CLASS_IMP */

static void init(grib_accessor* a, const long l, grib_arguments* c)
{
    grib_accessor_g2_mars_labeling* self = (grib_accessor_g2_mars_labeling*)a;
    int n                                = 0;
    grib_handle* hand                    = grib_handle_of_accessor(a);

    self->index                           = grib_arguments_get_long(hand, c, n++);
    self->the_class                       = grib_arguments_get_name(hand, c, n++);
    self->type                            = grib_arguments_get_name(hand, c, n++);
    self->stream                          = grib_arguments_get_name(hand, c, n++);
    self->expver                          = grib_arguments_get_name(hand, c, n++);
    self->typeOfProcessedData             = grib_arguments_get_name(hand, c, n++);
    self->productDefinitionTemplateNumber = grib_arguments_get_name(hand, c, n++);
    self->stepType                        = grib_arguments_get_name(hand, c, n++);
    self->derivedForecast                 = grib_arguments_get_name(hand, c, n++);
    self->typeOfGeneratingProcess         = grib_arguments_get_name(hand, c, n++);
}

static int unpack_long(grib_accessor* a, long* val, size_t* len)
{
    grib_accessor_g2_mars_labeling* self = (grib_accessor_g2_mars_labeling*)a;
    char* key                            = NULL;

    switch (self->index) {
        case 0:
            key = (char*)self->the_class;
            break;
        case 1:
            key = (char*)self->type;
            break;
        case 2:
            key = (char*)self->stream;
            break;
        default:
            grib_context_log(a->context, GRIB_LOG_ERROR,
                             "invalid first argument of g2_mars_labeling in %s", a->name);
            return GRIB_INTERNAL_ERROR;
            break;
    }

    return grib_get_long(grib_handle_of_accessor(a), key, val);
}

static int unpack_string(grib_accessor* a, char* val, size_t* len)
{
    grib_accessor_g2_mars_labeling* self = (grib_accessor_g2_mars_labeling*)a;
    char* key                            = NULL;

    switch (self->index) {
        case 0:
            key = (char*)self->the_class;
            break;
        case 1:
            key = (char*)self->type;
            break;
        case 2:
            key = (char*)self->stream;
            break;
        default:
            grib_context_log(a->context, GRIB_LOG_ERROR,
                             "invalid first argument of g2_mars_labeling in %s", a->name);
            return GRIB_INTERNAL_ERROR;
            break;
    }

    return grib_get_string(grib_handle_of_accessor(a), key, val, len);
}

static int extra_set(grib_accessor* a, long val)
{
    int ret                              = 0;
    grib_accessor_g2_mars_labeling* self = (grib_accessor_g2_mars_labeling*)a;
    grib_handle* hand                    = grib_handle_of_accessor(a);
    char stepType[30]                    = {0,};
    size_t stepTypelen                      = 30;
    long derivedForecast                    = -1;
    long productDefinitionTemplateNumberNew = -1;
    long productDefinitionTemplateNumber;
    long typeOfProcessedData     = -1;
    long typeOfGeneratingProcess = -1;
    int is_eps                   = -1;
    int is_instant               = -1;
    long is_chemical             = 0;
    long is_chemical_distfn      = 0;
    long is_chemical_srcsink     = 0;
    long is_aerosol              = 0;
    long is_aerosol_optical      = 0;

    grib_get_long(hand, "is_chemical", &is_chemical);
    grib_get_long(hand, "is_chemical_srcsink", &is_chemical_srcsink);
    grib_get_long(hand, "is_chemical_distfn", &is_chemical_distfn);
    grib_get_long(hand, "is_aerosol", &is_aerosol);
    grib_get_long(hand, "is_aerosol_optical", &is_aerosol_optical);

    switch (self->index) {
        case 0:
            /* class */
            return ret;
            break;
        case 1:
            /* type */
            switch (val) {
                case 0: /* Unknown       (0) */
                    typeOfProcessedData     = 255;
                    typeOfGeneratingProcess = 255;
                    break;
                case 1: /* First guess          (fg) */
                case 3: /* Initialised analysis (ia) */
                    typeOfProcessedData     = 0;
                    typeOfGeneratingProcess = 1;
                    break;
                case 2:  /* Analysis                    (an) */
                case 4:  /* Oi analysis                 (oi) */
                case 5:  /* 3d variational analysis     (3v) */
                case 6:  /* 4d variational analysis     (4v) */
                case 7:  /* 3d variational gradients    (3g) */
                case 8:  /* 4d variational gradients    (4g) */
                case 90: /* Gridded analysis input     (gai) */
                    typeOfProcessedData     = 0;
                    typeOfGeneratingProcess = 0;
                    break;
                case 9: /* Forecast  (fc) */
                    typeOfProcessedData     = 1;
                    typeOfGeneratingProcess = 2;
                    break;
                case 10: /* Control forecast  (cf) */
                    typeOfProcessedData     = 3;
                    typeOfGeneratingProcess = 4;
                    break;
                case 11: /* Perturbed forecast    (pf) */
                    typeOfProcessedData     = 4;
                    typeOfGeneratingProcess = 4;
                    break;
                case 12: /* Errors in first guess  (ef) */
                case 13: /* Errors in analysis     (ea) */
                    typeOfProcessedData     = 255;
                    typeOfGeneratingProcess = 7;
                    break;
                case 14: /* Cluster means              (cm) */
                case 15: /* Cluster std deviations     (cs) */
                    typeOfProcessedData     = 255;
                    typeOfGeneratingProcess = 4;
                    break;
                case 16: /* Forecast probability  (fp) */
                    typeOfProcessedData     = 8;
                    typeOfGeneratingProcess = 5;
                    break;
                case 17: /* Ensemble mean  (em) */
                    derivedForecast = 0;
                    grib_get_string(hand, self->stepType, stepType, &stepTypelen);
                    if (!strcmp(stepType, "instant")) {
                        productDefinitionTemplateNumberNew = 2;
                    }
                    else {
                        productDefinitionTemplateNumberNew = 12;
                    }
                    typeOfProcessedData     = 255;
                    typeOfGeneratingProcess = 4;
                    break;
                case 18: /* Ensemble standard deviation     (es) */
                    derivedForecast = 4;
                    grib_get_string(hand, self->stepType, stepType, &stepTypelen);
                    if (!strcmp(stepType, "instant")) {
                        productDefinitionTemplateNumberNew = 2;
                    }
                    else {
                        productDefinitionTemplateNumberNew = 12;
                    }
                    typeOfProcessedData     = 255;
                    typeOfGeneratingProcess = 4;
                    break;
                case 19: /* Forecast accumulation           (fa)  */
                case 20: /* Climatology                     (cl)  */
                case 21: /* Climate simulation              (si)  */
                case 22: /* Climate 30 days simulation      (s3)  */
                case 23: /* Empirical distribution          (ed)  */
                case 24: /* Tubes                           (tu)  */
                case 25: /* Flux forcing realtime           (ff)  */
                case 26: /* Ocean forward                   (of)  */
                case 27: /* Extreme forecast index          (efi) */
                case 28: /* Extreme forecast index control  (efic)*/
                case 29: /* Probability boundaries          (pb)  */
                    typeOfProcessedData     = 255;
                    typeOfGeneratingProcess = 255;
                    break;
                case 30: /* Event probability      (ep) */
                    typeOfProcessedData     = 8;
                    typeOfGeneratingProcess = 5;
                    break;
                case 31: /* Bias-corrected forecast      (bf) */
                    typeOfProcessedData     = 1;
                    typeOfGeneratingProcess = 3;
                    break;
                case 32: /* Climate distribution      (cd)  */
                case 33: /* 4D analysis increments    (4i)  */
                case 34: /* Gridded observations      (go)  */
                case 35: /* Model errors              (me)  */
                case 36: /* Probability distribution  (pd)  */
                case 37: /* Cluster information       (ci)  */
                case 38: /* Shift of Tail             (sot) */
                case 39: /* Ensemble data assimilation model errors */
                case 40: /* Images                    (im)  */
                case 42: /* Simulated images          (sim) */
                    typeOfProcessedData     = 255;
                    typeOfGeneratingProcess = 255;
                    break;
                case 43: /* Weighted ensemble mean                   (wem)  */
                case 44: /* Weighted ensemble standard deviation     (wes)  */
                case 45: /* Cluster representative                   (cr)   */
                case 46: /* Scaled ensemble standard deviation       (ses)  */
                case 47: /* Time average ensemble mean               (taem) */
                case 48: /* Time average ensemble standard deviation (taes) */
                    typeOfProcessedData     = 255;
                    typeOfGeneratingProcess = 4;
                    break;
                case 50: /* Sensitivity gradient            (sg)   */
                case 52: /* Sensitivity forecast            (sf)   */
                case 60: /* Perturbed analysis              (pa)   */
                case 61: /* Initial condition perturbation  (icp)  */
                case 62: /* Singular vector                 (sv)   */
                case 63: /* Adjoint singular vector         (as)   */
                case 64: /* Signal variance                 (svar) */
                    typeOfProcessedData     = 255;
                    typeOfGeneratingProcess = 255;
                    break;
                case 65: /* Calibration/Validation forecast  (cv) */
                    typeOfProcessedData     = 5;
                    typeOfGeneratingProcess = 4;
                    break;
                case 70: /* Ocean reanalysis     (or) */
                case 71: /* Flux forcing         (fx) */
                case 72: /* Fill-up              (fu) */
                case 73: /* Simulation forced with observations (sfo) */
                case 80: /* Forecast mean        (fcmean) */
                case 81: /* Forecast maximum     (fcmax) */
                case 82: /* Forecast minimum     (fcmin) */
                case 83: /* Forecast standard deviation  (fcstdev) */
                case 86: /* Hindcast climate mean (hcmean) */
                case 87: /* Simulated satellite data */
                case 88: /* Gridded satellite data */
                case 89: /* GFAS analysis */
                    typeOfProcessedData     = 255;
                    typeOfGeneratingProcess = 255;
                    break;
                default:
                    grib_context_log(a->context, GRIB_LOG_WARNING, "g2_mars_labeling: unknown mars.type %d", (int)val);
                    /*return GRIB_ENCODING_ERROR;*/
            }
            break;
        case 2:
            /* stream */
            switch (val) {
                case 1030:      /* enda */
                case 1249:      /* elda */
                case 1250:      /* ewla */
                    is_eps = 1; /* These streams are all for ensembles */
                    grib_get_string(hand, self->stepType, stepType, &stepTypelen);
                    is_instant                         = (strcmp(stepType, "instant") == 0);
                    productDefinitionTemplateNumberNew = grib2_select_PDTN(
                        is_eps, is_instant,
                        is_chemical,
                        is_chemical_srcsink,
                        is_chemical_distfn,
                        is_aerosol,
                        is_aerosol_optical);
                    break;
            }
            break;
        default:
            grib_context_log(a->context, GRIB_LOG_ERROR,
                             "invalid first argument of g2_mars_labeling in %s", a->name);
            return GRIB_INTERNAL_ERROR;
            break;
    }

    if (productDefinitionTemplateNumberNew >= 0) {
        grib_get_long(hand, self->productDefinitionTemplateNumber, &productDefinitionTemplateNumber);
        if (productDefinitionTemplateNumber != productDefinitionTemplateNumberNew)
            grib_set_long(hand, self->productDefinitionTemplateNumber, productDefinitionTemplateNumberNew);
    }

    if (derivedForecast >= 0) {
        grib_set_long(hand, self->derivedForecast, derivedForecast);
    }

    if (typeOfProcessedData > 0)
        grib_set_long(hand, self->typeOfProcessedData, typeOfProcessedData);
    if (typeOfGeneratingProcess > 0)
        grib_set_long(hand, self->typeOfGeneratingProcess, typeOfGeneratingProcess);

    return ret;
}

static int pack_string(grib_accessor* a, const char* val, size_t* len)
{
    grib_accessor_g2_mars_labeling* self = (grib_accessor_g2_mars_labeling*)a;
    char* key                            = NULL;
    int ret                              = 0;
    long lval                            = 0;

    switch (self->index) {
        case 0:
            key = (char*)self->the_class;
            break;
        case 1:
            key = (char*)self->type;
            break;
        case 2:
            key = (char*)self->stream;
            break;
        default:
            grib_context_log(a->context, GRIB_LOG_ERROR,
                             "invalid first argument of g2_mars_labeling in %s", a->name);
            return GRIB_INTERNAL_ERROR;
            break;
    }

    ret = grib_set_string(grib_handle_of_accessor(a), key, val, len);
    if (ret)
        return ret; /* failed */

    ret = grib_get_long(grib_handle_of_accessor(a), key, &lval);
    if (ret)
        return ret; /* failed */

    return extra_set(a, lval);
}

static int pack_long(grib_accessor* a, const long* val, size_t* len)
{
    grib_accessor_g2_mars_labeling* self = (grib_accessor_g2_mars_labeling*)a;
    char* key                            = NULL;
    int ret                              = 0;

    switch (self->index) {
        case 0:
            key = (char*)self->the_class;
            break;
        case 1:
            key = (char*)self->type;
            break;
        case 2:
            key = (char*)self->stream;
            break;
        default:
            grib_context_log(a->context, GRIB_LOG_ERROR,
                             "invalid first argument of g2_mars_labeling in %s", a->name);
            return GRIB_INTERNAL_ERROR;
            break;
    }

    ret = grib_set_long(grib_handle_of_accessor(a), key, *val);
    if (ret)
        return ret; /* failed */

    return extra_set(a, *val);
}

static int value_count(grib_accessor* a, long* count)
{
    *count = 1;
    return 0;
}

static int get_native_type(grib_accessor* a)
{
    grib_accessor_g2_mars_labeling* self = (grib_accessor_g2_mars_labeling*)a;
    char* key                            = NULL;
    int ret                              = 0;
    int type                             = 0;

    switch (self->index) {
        case 0:
            key = (char*)self->the_class;
            break;
        case 1:
            key = (char*)self->type;
            break;
        case 2:
            key = (char*)self->stream;
            break;
        default:
            grib_context_log(a->context, GRIB_LOG_ERROR,
                             "invalid first argument of g2_mars_labeling in %s", a->name);
            return GRIB_INTERNAL_ERROR;
            break;
    }

    ret = grib_get_native_type(grib_handle_of_accessor(a), key, &type);
    if (ret)
        grib_context_log(a->context, GRIB_LOG_ERROR,
                         "unable to get native type for %s", key);
    return type;
}
