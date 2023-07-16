// Reference : 
// https://www.geeksforgeeks.org/making-linux-shell-c/ - basic template
// https://www.it-note.kr/209 - getcwd()
// https://www.studymite.com/blog/strings-in-c#read_using_getline - getline()
// https://stackoverflow.com/questions/37774983/clearing-the-screen-by-printing-a-character - clearing screen
// https://sosal.kr/114 - ls command
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>

#define MAXCOM 1000 // max number of letters to be supported
#define MAXLIST 100 // max number of commands to be supported
// Clearing the shell using escape sequences
#define clear() printf("\033[H\033[J")
#define TRUE_COND 0
#define FALSE_COND 1

void init_shell();
int get_input(char *str);
void print_dir(void);