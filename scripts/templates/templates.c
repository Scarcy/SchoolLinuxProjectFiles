#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <termios.h>
#include <unistd.h>

void list_files(const char* path, char files[][256], int* count){
  struct dirent *entry;
  DIR *dir = opendir(path);
  
  if(dir == NULL){
    printf("Kunne ikke åpne mappen");
    exit(1);
  }

  while((entry = readdir(dir)) != NULL) {
    if(entry->d_type == DT_REG) {
      strcpy(files[*count], entry->d_name);
      (*count)++;
          
    }
  }
  closedir(dir);
}
void display_menu(char files[][256], int count, int selected) {
    printf("\033[u");
    for (int i = 0; i < count; ++i) {
        printf("\r\033[K");  // Move to the beginning of the line and clear it
        if (i == selected) {
            printf("> ");
        } else {
            printf("  ");
        }
        printf("%s\n", files[i]);

    }
}
int main(){
  char *homefolder = getenv("HOME");
  char *path = "/templates";
  if(homefolder == NULL){
    printf("Noe galt med HOME env variabelen\n");
    return 1;
  }
  

  int path_length = strlen(homefolder) + strlen(path) + 1;
  char folder[path_length];
  
  strcpy(folder, homefolder);
  strcat(folder, path);

  printf("Folder: %s\n", folder);
  char files[100][256];
  int count = 0;
  int selected = 0;
  char name[256];
  char cmd[512];

  list_files(folder, files, &count);
  if(count == 0){
    printf("Fant ingen filer i template mappen\n");
    printf("Mappen: %s", folder);
    return 1;
  }

      // Set terminal to raw mode
    struct termios orig_termios, raw;
    tcgetattr(STDIN_FILENO, &orig_termios);
    raw = orig_termios;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

    // Lagrer mus posisjon
    printf("\033[s");
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

    printf("Navnet til den nye filen: ");
    scanf("%s", name);
    snprintf(cmd, sizeof(cmd), "cp %s/%s %s%s", folder, files[selected], "./", name);
    system(cmd);

    printf("Malen er kopiert");
    printf("\033[u");  // Restore saved cursor position
    printf("\033[%dB", count + 3);  // Move cursor down by 'count' lines

    return 0;
}
