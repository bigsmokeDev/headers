#include <stdio.h>
#include <stdlib.h>

#define OS_IMPL
#include "os.h"

#define GL_INIT_IMPL
#include "gl_init.h"

int main(int argc, char *argv[]) {
    OS_WindowHandle *win = os_window_create(800, 600, "test", false);

    while (!os_window_should_close(win)) {
        os_window_poll_events(win);

        if (os_input_is_key_pressed(OS_KEY_E) || os_input_is_mouse_button_pressed(OS_MOUSE_BUTTON_LEFT)) {
            f32 mouse_pos[2];
            os_input_mouse_pos_get(mouse_pos);
            printf("%f,%f\n", mouse_pos[0], mouse_pos[1]);
        }

        if (os_input_is_key_pressed(OS_KEY_SPACE)) {
            u32 win_size[2];
            os_window_size_get(win, win_size);
            printf("%d,%d\n", win_size[0], win_size[1]);
        }

        os_input_update();
    }

    os_window_destroy(win);
    return 0;
}
