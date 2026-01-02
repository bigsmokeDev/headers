#ifndef GL_INIT_H
#define GL_INIT_H

#if defined(_WIN32)
#define GL_INIT_WGL
#elif defined(__gnu_linux__)
#define GL_INIT_GLX
#endif

// custom malloc/free
#if !defined(GL_INIT_MALLOC) && !defined(GL_INIT_FREE)
#define GL_INIT_MALLOC(s) malloc(s)
#define GL_INIT_FREE(p) free(p)
#endif

// basic types
#if !defined(GL_INIT_NO_TYPES)
typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef double f64;
typedef int b32;
#endif

// booleans
#if !defined(GL_INIT_NO_BOOLS)
#define true 1
#define false 0
#endif

// :assertion
#if !defined(GL_INIT_ASSERT)
#define GL_INIT_ASSERT(c,msg) do {\
    if (!(c)) {\
        fprintf(stderr, (msg));\
        abort();\
    }\
} while (0);
#endif

#endif // GL_INIT_H
