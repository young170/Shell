// Reference : 
// https://www.geeksforgeeks.org/making-linux-shell-c/ - basic template
// https://www.it-note.kr/209 - getcwd()
// https://www.studymite.com/blog/strings-in-c#read_using_getline - getline()
// https://stackoverflow.com/questions/37774983/clearing-the-screen-by-printing-a-character - clearing screen
// https://sosal.kr/114 - ls command


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>


#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif


void init_shell();	// Prints the information at the start of boot.
void openHelp();	// Prints list of commmands.
int interpretCmd(char **buf, size_t len);	// Parses and executes command.
int parseCmd(char **buf, size_t len);
int exCmd(char *option, char ***parseData);
void list(char *path);


char pwd[1024];