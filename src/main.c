#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DS_IMPL
#include "ds.h"

ds_dynarr_prototype(int);
ds_dynarr_impl(int);

int main(int argc, char *argv[]) {
    DS_Arena arena = ds_arena_create(1024); // NOTE: calls ds_arena_reset
    int *test = ds_arena_alloc(512);
    memset(test, 69, 512);
    ds_arena_reset(&arena); // zeroes all arena's memory
    ds_arena_destroy(&arena);

    ds_dynarr(int) arr = {0};
    for (int i = 0; i < 5; i++)
        ds_dynarr_append(int, &arr, i + 1);
    ds_dynarr_append_at(int, &arr, 69, 2);
    for (int i = 0; i < arr.len; i++)
        printf("%d\n", arr.data[i]);
    ds_dynarr_remove();
    ds_dynarr_resize(int, &arr, 2);
    ds_dynarr_reserve(int, &arr, 2); // now dynarr's capacity is 4
    ds_dynarr_destroy(arr);

    return 0;
}
