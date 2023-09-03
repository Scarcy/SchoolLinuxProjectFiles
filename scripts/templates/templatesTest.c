#include <stdio.h>
#include <termios.h>
#include <unistd.h>

void display_menu(char files[][256], int count, int selected) {
    printf("\033[2J\033[H");  // Clear screen and move cursor to top-left
    for (int i = 0; i < count; ++i) {
        if (i == selected) {
            printf("> ");
        } else {
            printf("  ");
        }
        printf("%s\n", files[i]);
    }
}

int main() {
    char files[][256] = {"file1", "file2", "file3"};  // Replace with your file list
    int count = 3;  // Replace with your file count
    int selected = 0;

    // Set terminal to raw mode
    struct termios orig_termios, raw;
    tcgetattr(STDIN_FILENO, &orig_termios);
    raw = orig_termios;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

    // Initial display
    display_menu(files, count, selected);

    // Main loop
    char c;
    while (read(STDIN_FILENO, &c, 1) == 1) {
        if (c == '\033') {
            read(STDIN_FILENO, &c, 1);
            read(STDIN_FILENO, &c, 1);
            if (c == 'A') {
                if (selected > 0) {
                    selected--;
                }
            } else if (c == 'B') {
                if (selected < count - 1) {
                    selected++;
                }
            }
        } else if (c == '\n') {
            break;
        }

        // Update display
        display_menu(files, count, selected);
    }

    // Reset terminal settings
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);

    printf("You selected: %s\n", files[selected]);

    return 0;
}

