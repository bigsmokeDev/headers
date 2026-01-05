#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DS_IMPL
#include "ds.h"

ds_dynarr_prototype(int);
ds_dynarr_impl(int);

int main(int argc, char *argv[]) {
    ds_dynarr(int) arr = {0};
    for (int i = 0; i < 5; i++)
        ds_dynarr_append(int, &arr, i + 1);
    for (int i = 0; i < arr.len; i++)
        printf("%d\n", arr.data[i]);
    ds_dynarr_destroy(arr);

    return 0;
}
