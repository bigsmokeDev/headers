// TODO(smoke): put some docs up here
// TODO(smoke): add GL context creation (GLX, WGL)

#ifndef OS_H
#define OS_H

#if defined(_WIN32)
#define OS_WIN32
#elif defined(__gnu_linux__)
#define OS_XLIB
#endif

// custom malloc/free
#if !defined(OS_MALLOC) && !defined(OS_FREE)
#define OS_MALLOC(s) malloc(s)
#define OS_FREE(p) free(p)
#endif

// basic types
#if !defined(OS_NO_TYPES)
typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef double f64;
typedef int b32;
#endif

// booleans
#if !defined(OS_NO_BOOLS)
#define true 1
#define false 0
#endif

// :assertion
#if !defined(OS_ASSERT)
#define OS_ASSERT(c,msg) do {\
    if (!(c)) {\
        fprintf(stderr, (msg));\
        abort();\
    }\
} while (0);
#endif

// :types
typedef void OS_WindowHandle;
typedef enum {
    OS_WINDOW_FLAG_RESIZABLE = (1 << 1),
    OS_WINDOW_FLAG_OPENGL    = (1 << 2),
} OS_WindowFlags;

typedef void OS_DynLib;

typedef enum
{
    OS_KEY_BACKSPACE = 0x08,
    OS_KEY_ENTER = 0x0D,
    OS_KEY_TAB = 0x09,
    OS_KEY_SHIFT = 0x10,
    OS_KEY_CONTROL = 0x11,
    
    OS_KEY_PAUSE = 0x13,
    OS_KEY_CAPITAL = 0x14,
    
    OS_KEY_ESCAPE = 0x1B,
    
    OS_KEY_CONVERT = 0x1C,
    OS_KEY_NONCONVERT = 0x1D,
    OS_KEY_ACCEPT = 0x1E,
    OS_KEY_MODECHANGE = 0x1F,
    
    OS_KEY_SPACE = 0x20,
    OS_KEY_PAGE_UP = 0x21,
    OS_KEY_PAGE_DOWN = 0x22,
    OS_KEY_END = 0x23,
    OS_KEY_HOME = 0x24,
    OS_KEY_LEFT = 0x25,
    OS_KEY_UP = 0x26,
    OS_KEY_RIGHT = 0x27,
    OS_KEY_DOWN = 0x28,
    OS_KEY_SELECT = 0x29,
    OS_KEY_PRINT = 0x2A,
    OS_KEY_EXECUTE = 0x2B,
    OS_KEY_PRINT_SCREEN = 0x2C,
    OS_KEY_INSERT = 0x2D,
    OS_KEY_DELETE = 0x2E,
    OS_KEY_HELP = 0x2F,
    
    OS_KEY_0 = 0x30,
    OS_KEY_1 = 0x31,
    OS_KEY_2 = 0x32,
    OS_KEY_3 = 0x33,
    OS_KEY_4 = 0x34,
    OS_KEY_5 = 0x35,
    OS_KEY_6 = 0x36,
    OS_KEY_7 = 0x37,
    OS_KEY_8 = 0x38,
    OS_KEY_9 = 0x39,
    
    OS_KEY_A = 0x41,
    OS_KEY_B = 0x42,
    OS_KEY_C = 0x43,
    OS_KEY_D = 0x44,
    OS_KEY_E = 0x45,
    OS_KEY_F = 0x46,
    OS_KEY_G = 0x47,
    OS_KEY_H = 0x48,
    OS_KEY_I = 0x49,
    OS_KEY_J = 0x4A,
    OS_KEY_K = 0x4B,
    OS_KEY_L = 0x4C,
    OS_KEY_M = 0x4D,
    OS_KEY_N = 0x4E,
    OS_KEY_O = 0x4F,
    OS_KEY_P = 0x50,
    OS_KEY_Q = 0x51,
    OS_KEY_R = 0x52,
    OS_KEY_S = 0x53,
    OS_KEY_T = 0x54,
    OS_KEY_U = 0x55,
    OS_KEY_V = 0x56,
    OS_KEY_W = 0x57,
    OS_KEY_X = 0x58,
    OS_KEY_Y = 0x59,
    OS_KEY_Z = 0x5A,
    
    OS_KEY_LSUPER = 0x5B,
    OS_KEY_RSUPER = 0x5C,
    OS_KEY_APPS = 0x5D,
    
    OS_KEY_SLEEP = 0x5F,
    
    OS_KEY_NUMPAD0 = 0x60,
    OS_KEY_NUMPAD1 = 0x61,
    OS_KEY_NUMPAD2 = 0x62,
    OS_KEY_NUMPAD3 = 0x63,
    OS_KEY_NUMPAD4 = 0x64,
    OS_KEY_NUMPAD5 = 0x65,
    OS_KEY_NUMPAD6 = 0x66,
    OS_KEY_NUMPAD7 = 0x67,
    OS_KEY_NUMPAD8 = 0x68,
    OS_KEY_NUMPAD9 = 0x69,
    OS_KEY_MULTIPLY = 0x6A,
    OS_KEY_ADD = 0x6B,
    OS_KEY_SEPARATOR = 0x6C,
    OS_KEY_SUBTRACT = 0x6D,
    OS_KEY_DECIMAL = 0x6E,
    OS_KEY_DIVIDE = 0x6F,
    
    OS_KEY_F1 = 0x70,
    OS_KEY_F2 = 0x71,
    OS_KEY_F3 = 0x72,
    OS_KEY_F4 = 0x73,
    OS_KEY_F5 = 0x74,
    OS_KEY_F6 = 0x75,
    OS_KEY_F7 = 0x76,
    OS_KEY_F8 = 0x77,
    OS_KEY_F9 = 0x78,
    OS_KEY_F10 = 0x79,
    OS_KEY_F11 = 0x7A,
    OS_KEY_F12 = 0x7B,
    OS_KEY_F13 = 0x7C,
    OS_KEY_F14 = 0x7D,
    OS_KEY_F15 = 0x7E,
    OS_KEY_F16 = 0x7F,
    OS_KEY_F17 = 0x80,
    OS_KEY_F18 = 0x81,
    OS_KEY_F19 = 0x82,
    OS_KEY_F20 = 0x83,
    OS_KEY_F21 = 0x84,
    OS_KEY_F22 = 0x85,
    OS_KEY_F23 = 0x86,
    OS_KEY_F24 = 0x87,
    
    OS_KEY_NUMLOCK = 0x90,
    
    OS_KEY_SCROLL = 0x91,
    
    OS_KEY_NUMPAD_EQUAL = 0x92,
    
    OS_KEY_LSHIFT = 0xA0,
    OS_KEY_RSHIFT = 0xA1,
    OS_KEY_LCONTROL = 0xA2,
    OS_KEY_RCONTROL = 0xA3,
    OS_KEY_LALT = 0xA4,
    OS_KEY_RALT = 0xA5,
    
    OS_KEY_SEMICOLON = 0x3B,
    
    OS_KEY_APOSTROPHE = 0xDE,
    OS_KEY_QUOTE = OS_KEY_APOSTROPHE,
    OS_KEY_EQUAL = 0xBB,
    OS_KEY_COMMA = 0xBC,
    OS_KEY_MINUS = 0xBD,
    OS_KEY_PERIOD = 0xBE,
    OS_KEY_SLASH = 0xBF,
    
    OS_KEY_GRAVE = 0xC0,
    
    OS_KEY_LBRACKET = 0xDB,
    OS_KEY_PIPE = 0xDC,
    OS_KEY_BACKSLASH = OS_KEY_PIPE,
    OS_KEY_RBRACKET = 0xDD,
    
    OS_KEY_MAX = 0xFF,
} OS_InputKey;

typedef enum {
    OS_MOUSE_BUTTON_LEFT,
    OS_MOUSE_BUTTON_RIGHT,
    OS_MOUSE_BUTTON_MIDDLE,
    
    OS_MOUSE_BUTTON_MAX
} OS_InputMouseButton;

typedef struct {
    b32 keys[OS_KEY_MAX], mouse_buttons[OS_MOUSE_BUTTON_MAX];
    f32 mouse_pos[2];
} OS_InputState;

// :functions
OS_WindowHandle *os_window_create(u32 w, u32 h, const char *t, OS_WindowFlags flags);
void os_window_destroy(OS_WindowHandle *handle);
b32 os_window_should_close(OS_WindowHandle *handle);
void os_window_poll_events(OS_WindowHandle *handle);
void os_window_size_get(OS_WindowHandle *handle, u32 *size);

#if defined(OS_GL_NEW) || defined(OS_GL_OLD)
void os_gl_swap_buffers(OS_WindowHandle *handle);
#endif

OS_DynLib *os_dynlib_load(const char *path);
void os_dynlib_unload(OS_DynLib *handle);
void *os_dynlib_proc_address_get(OS_DynLib *handle, const char *name);

f64 os_time_get(void);

OS_InputState *os_input_state_get(void);
void os_input_update(void); // copies input_state to last_input_state
b32 os_input_is_key_down(OS_InputKey key);
b32 os_input_is_mouse_button_down(OS_InputMouseButton mouse_button);
b32 os_input_is_key_pressed(OS_InputKey key);
b32 os_input_is_mouse_button_pressed(OS_InputMouseButton mouse_button);
void os_input_mouse_pos_get(f32 *mouse_pos);

// ==== OS_IMPL ==== //
#if defined(OS_IMPL)

// :xlib
#if defined(OS_XLIB)

#include <dlfcn.h>
#include <time.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#if defined(OS_GL_NEW) || defined(OS_GL_OLD)
#include <GL/glx.h>
#endif

// globals
static Display *dpy;
static f64 clk_freq = 0.000000001;
static struct timespec start_time;

#if defined(OS_GL_NEW)
typedef GLXContext(*glXCreateContextAttribsARBProc)(Display*, GLXFBConfig, GLXContext, Bool, const int*);
static glXCreateContextAttribsARBProc glXCreateContextAttribsARB = 0;
//typedef void (*glXSwapIntervalEXTProc) (Display *dpy, GLXDrawable drawable, int interval);
//glXSwapIntervalEXTProc glXSwapIntervalEXT = 0;
#endif

#if defined(OS_GL_NEW) || defined(OS_GL_OLD)
static GLXFBConfig best_fb_config;
#endif

// types
typedef struct {
    Window win;
    Atom wm_delete_win;
#if defined(OS_GL_OLD) || defined(OS_GL_NEW)
    GLXContext gl_ctx;
#endif

    u32 w, h;
    b32 should_close;
} OS_XlibWindow;

// functions
static XVisualInfo *glx_visual_info_get(void);
static void glx_init(OS_XlibWindow *win, XVisualInfo *vis);

OS_WindowHandle *os_window_create(u32 w, u32 h, const char *t, OS_WindowFlags flags) {
    if (!dpy) {
        dpy = XOpenDisplay(NULL);
        OS_ASSERT(dpy, "failed to open X11 display");
    }

    OS_XlibWindow *win = OS_MALLOC(sizeof *win);

    s32 screen = DefaultScreen(dpy);
    Window root_win = RootWindow(dpy, screen);
    XSetWindowAttributes attr = {0};
    attr.event_mask = ExposureMask | StructureNotifyMask | KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask | PointerMotionMask;

    XVisualInfo *vi;
    if (flags & OS_WINDOW_FLAG_OPENGL) {
        vi = glx_visual_info_get();
        attr.colormap = XCreateColormap(dpy, root_win, vi->visual, AllocNone);
        win->win = XCreateWindow(
                dpy, root_win,
                0, 0, w, h,
                0, vi->depth, CopyFromParent, vi->visual, 
                CWBackPixel | CWColormap | CWBorderPixel | CWEventMask, &attr);
    } else {
        win->win = XCreateWindow(
                dpy, root_win,
                0, 0, w, h,
                0, CopyFromParent, CopyFromParent, CopyFromParent, 
                CWBackPixel | CWColormap | CWBorderPixel | CWEventMask, &attr);
    }
    OS_ASSERT(win->win, "failed to create X11 window");
    XStoreName(dpy, win->win, t);

    win->wm_delete_win = XInternAtom(dpy, "WM_DELETE_WINDOW", False);
	OS_ASSERT(XSetWMProtocols(dpy, win->win, &win->wm_delete_win, 1), "failed to get WM_DELETE_WINDOW atom");

    if (flags & OS_WINDOW_FLAG_OPENGL) {
        glx_init(win, vi);
    }

    if (!(flags & OS_WINDOW_FLAG_RESIZABLE)) {
        XSizeHints *size_hints = XAllocSizeHints();
        size_hints->flags = PMinSize | PMaxSize;
        size_hints->min_width = size_hints->max_width = w;
        size_hints->min_height = size_hints->max_height = h;
        XSetWMNormalHints(dpy, win->win, size_hints);
        XFree(size_hints);
    }

    XMapWindow(dpy, win->win);
    XFlush(dpy);

    win->w = w;
    win->h = h;
    return (OS_WindowHandle*)win;
}

void os_window_destroy(OS_WindowHandle *handle) {
    OS_XlibWindow *win = (OS_XlibWindow*)handle;
#if defined(OS_GL_NEW) || defined(OS_GL_OLD)
    glXMakeCurrent(dpy, None, NULL);
    glXDestroyContext(dpy, win->gl_ctx);
#endif
    XDestroyWindow(dpy, win->win);
    OS_FREE(handle);
}

b32 os_window_should_close(OS_WindowHandle *handle) {
    OS_XlibWindow *win = (OS_XlibWindow*)handle;
    return win->should_close;
}

void os_window_size_get(OS_WindowHandle *handle, u32 *size) {
    OS_XlibWindow *win = (OS_XlibWindow*)handle;
    size[0] = win->w;
    size[1] = win->h;
}

static OS_InputKey os_input_xkey_to_key(XKeyEvent *ev) {
    KeySym sym = XLookupKeysym(ev, 0);
    
    switch (sym) {
        case XK_a: case XK_A: return OS_KEY_A;
        case XK_b: case XK_B: return OS_KEY_B;
        case XK_c: case XK_C: return OS_KEY_C;
        case XK_d: case XK_D: return OS_KEY_D;
        case XK_e: case XK_E: return OS_KEY_E;
        case XK_f: case XK_F: return OS_KEY_F;
        case XK_g: case XK_G: return OS_KEY_G;
        case XK_h: case XK_H: return OS_KEY_H;
        case XK_i: case XK_I: return OS_KEY_I;
        case XK_j: case XK_J: return OS_KEY_J;
        case XK_k: case XK_K: return OS_KEY_K;
        case XK_l: case XK_L: return OS_KEY_L;
        case XK_m: case XK_M: return OS_KEY_M;
        case XK_n: case XK_N: return OS_KEY_N;
        case XK_o: case XK_O: return OS_KEY_O;
        case XK_p: case XK_P: return OS_KEY_P;
        case XK_q: case XK_Q: return OS_KEY_Q;
        case XK_r: case XK_R: return OS_KEY_R;
        case XK_s: case XK_S: return OS_KEY_S;
        case XK_t: case XK_T: return OS_KEY_T;
        case XK_u: case XK_U: return OS_KEY_U;
        case XK_v: case XK_V: return OS_KEY_V;
        case XK_w: case XK_W: return OS_KEY_W;
        case XK_x: case XK_X: return OS_KEY_X;
        case XK_y: case XK_Y: return OS_KEY_Y;
        case XK_z: case XK_Z: return OS_KEY_Z;
        
        case XK_0: return OS_KEY_0;
        case XK_1: return OS_KEY_1;
        case XK_2: return OS_KEY_2;
        case XK_3: return OS_KEY_3;
        case XK_4: return OS_KEY_4;
        case XK_5: return OS_KEY_5;
        case XK_6: return OS_KEY_6;
        case XK_7: return OS_KEY_7;
        case XK_8: return OS_KEY_8;
        case XK_9: return OS_KEY_9;
        
        case XK_F1:  return OS_KEY_F1;
        case XK_F2:  return OS_KEY_F2;
        case XK_F3:  return OS_KEY_F3;
        case XK_F4:  return OS_KEY_F4;
        case XK_F5:  return OS_KEY_F5;
        case XK_F6:  return OS_KEY_F6;
        case XK_F7:  return OS_KEY_F7;
        case XK_F8:  return OS_KEY_F8;
        case XK_F9:  return OS_KEY_F9;
        case XK_F10: return OS_KEY_F10;
        case XK_F11: return OS_KEY_F11;
        case XK_F12: return OS_KEY_F12;
        
        case XK_Left:  return OS_KEY_LEFT;
        case XK_Right: return OS_KEY_RIGHT;
        case XK_Up:    return OS_KEY_UP;
        case XK_Down:  return OS_KEY_DOWN;
        case XK_Home:  return OS_KEY_HOME;
        case XK_End:   return OS_KEY_END;
        case XK_Page_Up:   return OS_KEY_PAGE_UP;
        case XK_Page_Down: return OS_KEY_PAGE_DOWN;
        case XK_Insert: return OS_KEY_INSERT;
        case XK_Delete: return OS_KEY_DELETE;
        
        case XK_Shift_L:    return OS_KEY_LSHIFT;
        case XK_Shift_R:    return OS_KEY_RSHIFT;
        case XK_Control_L:  return OS_KEY_LCONTROL;
        case XK_Control_R:  return OS_KEY_RCONTROL;
        case XK_Alt_L:      return OS_KEY_LALT;
        case XK_Alt_R:      return OS_KEY_RALT;
        case XK_Super_L:    return OS_KEY_LSUPER;
        case XK_Super_R:    return OS_KEY_RSUPER;
        case XK_Escape:     return OS_KEY_ESCAPE;
        case XK_Tab:        return OS_KEY_TAB;
        case XK_Return:     return OS_KEY_ENTER;
        case XK_BackSpace:  return OS_KEY_BACKSPACE;
        case XK_space:      return OS_KEY_SPACE;
        
        case XK_comma:       return OS_KEY_COMMA;
        case XK_period:      return OS_KEY_PERIOD;
        case XK_minus:       return OS_KEY_MINUS;
        case XK_equal:       return OS_KEY_EQUAL;
        case XK_semicolon:   return OS_KEY_SEMICOLON;
        case XK_apostrophe:  return OS_KEY_APOSTROPHE;
        case XK_grave:       return OS_KEY_GRAVE;
        case XK_slash:       return OS_KEY_SLASH;
        case XK_backslash:   return OS_KEY_BACKSLASH;
        case XK_bracketleft: return OS_KEY_LBRACKET;
        case XK_bracketright:return OS_KEY_RBRACKET;
        
        default:
        return OS_KEY_MAX;
    }
}

void os_window_poll_events(OS_WindowHandle *handle) {
    OS_XlibWindow *win = (OS_XlibWindow*)handle;
    OS_InputState *input_state = os_input_state_get();
    XEvent ev;

    while (XPending(dpy) > 0) {
        XNextEvent(dpy, &ev);
        switch (ev.type) {

            case ClientMessage: {
                XClientMessageEvent *msg_ev = (XClientMessageEvent*)&ev;
                if ((Atom)msg_ev->data.l[0] == win->wm_delete_win)
                    win->should_close = true;
            } break;

            case ConfigureNotify: {
				XConfigureEvent *conf_ev = (XConfigureEvent*)&ev;
                win->w = conf_ev->width;
                win->h = conf_ev->height;
			} break;

			case KeyPress: {
				OS_InputKey key = os_input_xkey_to_key(&ev.xkey);
				input_state->keys[key] = true;
			} break;
			case KeyRelease: {
				OS_InputKey key = os_input_xkey_to_key(&ev.xkey);
				input_state->keys[key] = false;
			} break;

            case ButtonPress:
            case ButtonRelease: {
                b32 pressed = (ev.type == ButtonPress);
                OS_InputMouseButton mouse_button = OS_MOUSE_BUTTON_MAX;
                switch (ev.xbutton.button) {
                    case Button1: {
                        mouse_button = OS_MOUSE_BUTTON_LEFT;
                    } break;
                    case Button2: {
                        mouse_button = OS_MOUSE_BUTTON_MIDDLE;
                    } break;
                    case Button3: {
                        mouse_button = OS_MOUSE_BUTTON_RIGHT;
                    } break;
                }
				input_state->mouse_buttons[mouse_button] = pressed;
            } break;
            case MotionNotify:
                input_state->mouse_pos[0] = ev.xmotion.x;
                input_state->mouse_pos[1] = ev.xmotion.y;
                break;

            default: break;
        }
    }
}

static XVisualInfo *glx_visual_info_get(void) {
#if defined(OS_GL_NEW) || defined(OS_GL_OLD)
    const s32 attribs[] = {
        GLX_X_RENDERABLE    , True,
        GLX_DRAWABLE_TYPE   , GLX_WINDOW_BIT,
        GLX_RENDER_TYPE     , GLX_RGBA_BIT,
        GLX_X_VISUAL_TYPE   , GLX_TRUE_COLOR,
        GLX_RED_SIZE        , 8,
        GLX_GREEN_SIZE      , 8,
        GLX_BLUE_SIZE       , 8,
        GLX_ALPHA_SIZE      , 8,
        GLX_DEPTH_SIZE      , 24,
        GLX_STENCIL_SIZE    , 8,
        GLX_DOUBLEBUFFER    , True,
        None
    };
    const s32 screen = DefaultScreen(dpy);

    s32 fb_count;
    GLXFBConfig *fb_config = glXChooseFBConfig(dpy, screen, attribs, &fb_count);
    OS_ASSERT(fb_config, "glXChooseFBConfig failure");
    
    s32 best_fb_config_index = -1, worst_fb_config_index = -1, best_num_samp = -1, worst_num_samp = 999;
    for (s32 i = 0; i < fb_count; ++i)
    {
        XVisualInfo *current_visual_info = glXGetVisualFromFBConfig(dpy, fb_config[i]);
        if (current_visual_info != 0)
        {
            int samp_buf, samples;
            glXGetFBConfigAttrib(dpy, fb_config[i], GLX_SAMPLE_BUFFERS, &samp_buf);
            glXGetFBConfigAttrib(dpy, fb_config[i], GLX_SAMPLES       , &samples );
            
            if (best_fb_config_index < 0 || (samp_buf && samples > best_num_samp))
            {
                best_fb_config_index = i;
                best_num_samp = samples;
            }
            if (worst_fb_config_index < 0 || !samp_buf || samples < worst_num_samp)
                worst_fb_config_index = i;
            worst_num_samp = samples;
        }
        XFree(current_visual_info);
    }
    best_fb_config = fb_config[best_fb_config_index];
    
    XVisualInfo *visual_info = glXGetVisualFromFBConfig(dpy, best_fb_config);
    OS_ASSERT(visual_info, "glXGetVisualFromFBConfig failure");
    XFree(fb_config);

    OS_ASSERT(screen == visual_info->screen, "screen and visual info screen do not match");

    return visual_info;
#endif
    return NULL;
}

static void glx_init(OS_XlibWindow *win, XVisualInfo *vi) {
#if defined(OS_GL_NEW)
    glXCreateContextAttribsARB = (glXCreateContextAttribsARBProc)glXGetProcAddressARB((GLubyte*)"glXCreateContextAttribsARB");
    OS_ASSERT(glXCreateContextAttribsARB, "failed to find glXCreateContextAttribsARB, make sure your hardware supports modern GL");
    //glXSwapIntervalEXT = (glXSwapIntervalEXTProc)glXGetProcAddress((GLubyte*)"glXSwapIntervalEXT");
    //OS_ASSERT(glXSwapIntervalEXT, "failed to find glXSwapIntervalEXT");

    s32 context_attribs[] = {
        GLX_CONTEXT_MAJOR_VERSION_ARB, 3,
        GLX_CONTEXT_MINOR_VERSION_ARB, 3,
        GLX_CONTEXT_FLAGS_ARB, GLX_CONTEXT_CORE_PROFILE_BIT_ARB,
        None
    };

    win->gl_ctx = glXCreateContextAttribsARB(dpy, best_fb_config, NULL, True, context_attribs);
    OS_ASSERT(win->gl_ctx, "failed to create GLX context");
    glXMakeCurrent(dpy, win->win, win->gl_ctx);
#elif defined(OS_GL_OLD)
    win->gl_ctx = glXCreateContext(dpy, vi, NULL, True);
    OS_ASSERT(win->gl_ctx, "failed to create GLX context");
    glXMakeCurrent(dpy, win->win, win->gl_ctx);
#endif
}

void os_gl_swap_buffers(OS_WindowHandle *handle) {
#if defined(OS_GL_NEW) || defined(OS_GL_OLD)
    OS_XlibWindow *win = (OS_XlibWindow*)handle;
    glXSwapBuffers(dpy, win->win);
#endif
}

f64 os_time_get(void) {
    struct timespec now_time;
    clock_gettime(CLOCK_MONOTONIC, &now_time);
    return (f64)(now_time.tv_sec - start_time.tv_sec) + (now_time.tv_nsec - start_time.tv_nsec) * clk_freq;
}

OS_DynLib *os_dynlib_load(const char *path) {
    return (OS_DynLib*)dlopen(path, RTLD_LAZY);
}

void os_dynlib_unload(OS_DynLib *handle) {
    dlclose((void*)handle);
}

void *os_dynlib_proc_address_get(OS_DynLib *handle, const char *name) {
    return dlsym((void*)handle, name);
}

#endif // OS_XLIB

// :win32
#if defined(OS_WIN32)

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>

typedef struct {
    HWND win;
} OS_Win32Window;

static b32 should_close;
static u32 win_w, win_h;
static LRESULT CALLBACK win32_wnd_proc(HWND win, UINT msg, WPARAM wparam, LPARAM lparam);

static f32 clk_freq;
static LARGE_INTEGER start_time;

OS_WindowHandle *os_window_create(u32 w, u32 h, const char *t, OS_WindowFlags flags) {
    OS_Win32Window *win = OS_MALLOC(sizeof *win);

    HINSTANCE hinstance = GetModuleHandle(NULL);
    WNDCLASS wnd_class = {0};
    wnd_class.hInstance = hinstance;
    wnd_class.lpszClassName = "os_window_class";
    wnd_class.lpfnWndProc = win32_wnd_proc;

    OS_ASSERT(RegisterClass(&wnd_class), "failed to register win32 window class");

    u32 win_style = WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX;
    if (flags & OS_WINDOW_FLAG_RESIZABLE)
        win_style |= WS_THICKFRAME | WS_MAXIMIZEBOX;

    RECT border_rect = {0};
    AdjustWindowRectEx(&border_rect, win_style, 0, WS_EX_APPWINDOW);
    w += border_rect.right - border_rect.left;
    h += border_rect.bottom - border_rect.top;

    win->win = CreateWindow(
            wnd_class.lpszClassName, t, WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, w, h,
            NULL, NULL, hinstance, NULL
            );
    OS_ASSERT(win->win, "failed to create Win32 window");

    ShowWindow(win->win, SW_SHOW);

    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    clk_freq = 1.0f / (f32)freq.QuadPart;
    QueryPerformanceCounter(&start_time);

    win_w = w;
    win_h = h;

    return (OS_WindowHandle*)win;
}

void os_window_destroy(OS_WindowHandle *handle) {
    OS_Win32Window *win = (OS_WindowHandle*)handle;
    DestroyWindow(win->win);
    free(handle);
}

b32 os_window_should_close(OS_WindowHandle *handle) {
    return should_close;
}

void os_window_poll_events(OS_WindowHandle *handle) {
    OS_Win32Window *win = (OS_WindowHandle*)handle;
    MSG msg;
    while (PeekMessageA(&msg, win->win, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
}

static LRESULT CALLBACK win32_wnd_proc(HWND win, UINT msg, WPARAM wparam, LPARAM lparam) {
    OS_InputState *input_state = os_input_state_get();

    switch (msg) {

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
            break;
        case WM_CLOSE:
            should_close = true;
            break;

        case WM_SIZE: {
            win_w = LOWORD(lparam);
            win_h = HIWORD(lparam);
        } break;

        case WM_KEYDOWN:
        case WM_SYSKEYDOWN:
            input_state->keys[wparam] = true;
            break;
        case WM_KEYUP:
        case WM_SYSKEYUP:
            input_state->keys[wparam] = false;
            break;

        case WM_LBUTTONDOWN:
            input_state->mouse_buttons[OS_MOUSE_BUTTON_LEFT] = true;
            break;
        case WM_MBUTTONDOWN:
            input_state->mouse_buttons[OS_MOUSE_BUTTON_MIDDLE] = true;
            break;
        case WM_RBUTTONDOWN:
            input_state->mouse_buttons[OS_MOUSE_BUTTON_RIGHT] = true;
            break;
        case WM_LBUTTONUP:
            input_state->mouse_buttons[OS_MOUSE_BUTTON_LEFT] = false;
            break;
        case WM_MBUTTONUP:
            input_state->mouse_buttons[OS_MOUSE_BUTTON_MIDDLE] = false;
            break;
        case WM_RBUTTONUP:
            input_state->mouse_buttons[OS_MOUSE_BUTTON_RIGHT] = false;
            break;

        case WM_MOUSEMOVE:
            input_state->mouse_pos[0] = GET_X_LPARAM(lparam);
            input_state->mouse_pos[1] = GET_Y_LPARAM(lparam);
            break;

        default: break;
    }
    return DefWindowProc(win, msg, wparam, lparam);
}

void os_window_size_get(OS_WindowHandle *handle, u32 *size) {
    OS_Win32Window *win = (OS_WindowHandle*)handle;
    size[0] = win_w;
    size[1] = win_h;
}

f64 os_time_get(void) {
    LARGE_INTEGER now_time;
    QueryPerformanceCounter(&now_time);
    return (f32)(now_time.QuadPart - start_time.QuadPart) * clk_freq;
}

OS_DynLib *os_dynlib_load(const char *path) {
    return (OS_DynLib*)LoadLibrary(path);
}

void os_dynlib_unload(OS_DynLib *handle) {
    FreeLibrary((HMODULE)handle);
}

void *os_dynlib_proc_address_get(OS_DynLib *handle, const char *name) {
    return GetProcAddress((HMODULE)handle, name);
}

#endif // OS_WIN32

// :input
static OS_InputState input_state, last_input_state;

OS_InputState *os_input_state_get(void) {
    return &input_state;
}

void os_input_update(void) {
    last_input_state = input_state;
}

b32 os_input_is_key_down(OS_InputKey key) {
    return input_state.keys[key];
}
b32 os_input_is_mouse_button_down(OS_InputMouseButton mouse_button) {
    return input_state.mouse_buttons[mouse_button];
}

b32 os_input_is_key_pressed(OS_InputKey key) {
    return !last_input_state.keys[key] && input_state.keys[key];
}
b32 os_input_is_mouse_button_pressed(OS_InputMouseButton mouse_button) {
    return !last_input_state.mouse_buttons[mouse_button] && input_state.mouse_buttons[mouse_button];
}

void os_input_mouse_pos_get(f32 *mouse_pos) {
    mouse_pos[0] = input_state.mouse_pos[0];
    mouse_pos[1] = input_state.mouse_pos[1];
}

#endif // OS_IMPL
#endif // OS_H
