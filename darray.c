#include "darray.h"

#define return_value_if_fail(param, ret) \
    if (!(param))                        \
    {                                    \
        return (ret);                    \
    }

#define return_void_if_fail(param) \
    if (!(param))                  \
    {                              \
        return;                    \
    }

#define array_len(arr) ((int)(sizeof(arr) / sizeof((arr)[0])))

typedef struct darray_t
{
    void *arr;
    int size;
    int capacity;
    char *data_type;
} darray_t;

static bool is_valid_data_type(const char *data_type)
{
    return_value_if_fail(data_type != NULL, false);

    // TODO: More data type should be supported
    const char valid_data_type[] = {
        "int",
    };

    for (int i = 0; i < array_len(valid_data_type); i++)
    {
        
    }
}

darray_t *darray_init(const char *data_type)
{
    return_value_if_fail(data_type != NULL, NULL);

    return_value_if_fail(is_valid_data_type(data_type), NULL);

    darray_t *darray = (darray_t *)malloc(sizeof(darray_t));
    return_value_if_fail(darray != NULL, NULL);

    darray->data_type = (char *)malloc(sizeof(char) * (strlen(data_type) + 1));
    return_value_if_fail(darray->data_type != NULL, NULL);

    darray->arr = NULL;
    darray->size = 0;
    darray->capacity = 0;

    return darray;
}

void darray_destroy(darray_t *darray)
{
    return_void_if_fail(darray != NULL);

    if (darray->data_type)
    {
        free(darray->data_type);
        darray->data_type = NULL;
    }

    if (darray->arr)
    {
        free(darray->arr);
        darray->arr = NULL;
    }

    free(darray);
    darray = NULL;
}

int darray_size(darray_t *darray)
{
    return_value_if_fail(darray, 0);
    return darray->size;
}