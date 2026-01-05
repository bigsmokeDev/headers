#ifndef DS_H
#define DS_H

// custom malloc/free
#if !defined(DS_MALLOC) && !defined(DS_FREE) && !defined(DS_REALLOC)
#define DS_MALLOC(s) malloc(s)
#define DS_FREE(p) free(p)
#define DS_REALLOC(p, s) realloc(p, s)
#endif

// basic types
#if !defined(DS_NO_TYPES)
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef double f64;
typedef int b32;
#endif

// booleans
#if !defined(DS_NO_BOOLS)
#define true 1
#define false 0
#endif

// :assertion
#if !defined(DS_ASSERT)
#define DS_ASSERT(c,...)\
    do {\
        if (!(c)) {\
            fprintf(stderr, "assertion failure at %s:%d: ", __FILE__, __LINE__);\
            fprintf(stderr, ##__VA_ARGS__);\
            abort();\
        }\
    } while (0)
#endif

// :types
typedef struct {
    u8 *data;
    u32 offset, cap;
} DS_Arena;

// :functions
DS_Arena ds_arena_create(u32 size);
void ds_arena_destroy(DS_Arena *arena);
void *ds_arena_alloc(DS_Arena *arena, u32 size);
void ds_arena_reset(DS_Arena *arena);

#define ds_dynarr_destroy(dynarr)\
    dynarr.cap = 0;\
    dynarr.len = 0;\
    DS_FREE(dynarr.data);
#define DS_DYNARR_DEFAULT_CAP 16
#define ds_dynarr(type) type##_dynarr
#define ds_dynarr_resize(type, dynarr, len) type##_dynarr_resize(dynarr, len)
#define ds_dynarr_reserve(type, dynarr, len) type##_dynarr_reserve(dynarr, len)
#define ds_dynarr_append(type, dynarr, value) type##_dynarr_append(dynarr, value)
#define ds_dynarr_remove(type, dynarr, index) type##_dynarr_remove(dynarr, index)
#define ds_dynarr_unordered_remove(type, dynarr, index) type##_dynarr_unordered_remove(dynarr, index)

#define ds_dynarr_prototype(type)\
    typedef struct {\
        type *data;\
        u32 len, cap;\
    } type##_dynarr;\
    void type##_dynarr_destroy(type##_dynarr *dynarr);\
    void type##_dynarr_resize(type##_dynarr *dynarr, u32 len);\
    void type##_dynarr_reserve(type##_dynarr *dynarr, u32 len);\
    void type##_dynarr_append(type##_dynarr *dynarr, type value);\
    void type##_dynarr_remove(type##_dynarr *dynarr, u32 index);\
    void type##_dynarr_unordered_remove(type##_dynarr *dynarr, u32 index);

#define ds_dynarr_impl(type)\
    void type##_dynarr_resize(type##_dynarr *dynarr, u32 len) {\
        dynarr->data = DS_REALLOC(dynarr->data, sizeof(type) * len);\
        DS_ASSERT(dynarr->data, "failed to reserve %lu byte for dynamic array\n", sizeof(type) * len);\
        dynarr->cap = len;\
    }\
    void type##_dynarr_reserve(type##_dynarr *dynarr, u32 len) {\
        dynarr->data = DS_REALLOC(dynarr->data, sizeof(type) * len);\
        DS_ASSERT(dynarr->data, "failed to reserve %lu byte for dynamic array\n", sizeof(type) * len);\
        dynarr->cap += len;\
    }\
    void type##_dynarr_append(type##_dynarr *dynarr, type value) {\
        if (dynarr->len + 1 > dynarr->cap) {\
            if (dynarr->cap == 0)\
                dynarr->cap = DS_DYNARR_DEFAULT_CAP;\
            else\
                dynarr->cap *= 2;\
            dynarr->data = DS_REALLOC(dynarr->data, sizeof(type) * dynarr->cap);\
            DS_ASSERT(dynarr->data, "failed to reserve %lu bytes for dynamic array\n", sizeof(type) * dynarr->cap);\
        }\
        dynarr->data[dynarr->len++] = value;\
    }\
    void type##_dynarr_remove(type##_dynarr *dynarr, u32 index) {\
        DS_ASSERT(index <= dynarr->len, "indexing out of bounds in dynamic array");\
        for (int i = index; i < dynarr->len; i++)\
            dynarr->data[i] = dynarr->data[i + 1];\
        dynarr->len--;\
    }\
    void type##_dynarr_unordered_remove(type##_dynarr *dynarr, u32 index) {\
        DS_ASSERT(index <= dynarr->len, "indexing out of bounds in dynamic array");\
        memmove(&dynarr->data[index], &dynarr->data[dynarr->len - 1], sizeof(type));\
        dynarr->len--;\
    }

// ==== DS_IMPL ====
#if defined(DS_IMPL)

// :arena
DS_Arena ds_arena_create(u32 size) {
    DS_Arena arena = {0};

    arena.data = DS_MALLOC(size);
    DS_ASSERT(arena.data, "failed to alloc %d bytes for arena\n", size);
    memset(arena.data, 0, size);
    arena.cap = size;

    return arena;
}

void ds_arena_destroy(DS_Arena *arena) {
    DS_FREE(arena->data);
}

void *ds_arena_alloc(DS_Arena *arena, u32 size) {
    DS_ASSERT(size + arena->offset <= arena->cap, "no more space left on arena\n");

    u8 *ptr = arena->data + arena->offset;
    arena->offset += size;

    return (void*)ptr;
}

void ds_arena_reset(DS_Arena *arena) {
    memset(arena->data, 0, arena->cap);
}

#endif // DS_IMPL

#endif // DS_H
