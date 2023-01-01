#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <ncurses.h>
#include <stdlib.h>

#define MAX_FILENAME 255


int main(int argc, char **argv) {
  initscr();

  char current_dir[MAX_FILENAME];
  getcwd(current_dir, sizeof(current_dir)); 
  printf("%s\n", current_dir);

  struct dirent *entry;
  DIR *dir = opendir(current_dir);
  while ((entry = readdir(dir)) != NULL) {
    addstr(entry->d_name);
    addstr("\n");
    //printf("%s\n", entry->d_name);
  }

  closedir(dir);
  refresh();
  getch();
  endwin();
  
  return 0;
}

