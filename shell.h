// Reference : 
// https://www.geeksforgeeks.org/making-linux-shell-c/ - basic template
// https://www.it-note.kr/209 - getcwd()
// https://www.studymite.com/blog/strings-in-c#read_using_getline - getline()
// https://stackoverflow.com/questions/37774983/clearing-the-screen-by-printing-a-character - clearing screen
// 


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


void init_shell();	// Prints the information at the start of boot.
void openHelp();	// Prints list of commmands.
int interpertCmd(char** buf, size_t len);	// Parses and executes command.


char pwd[1024];