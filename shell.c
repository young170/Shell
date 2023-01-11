#include "shell.h"
#define clear() printf("\033[H\033[J")  // 033[H : sets the cursor to the 'home' position, 033[J : clears the entire screen


void
init_shell()
{
    clear();
    printf("\n\n\n\n******************************************");
    printf("\n\n\n\t****MY SHELL****");
    printf("\n\n\t-USE AT YOUR OWN RISK-");
    printf("\n\n\n\n******************************************");
    char* username = getenv("USER");
    printf("\n\n\nUSER is: @%s\n", username);
    sleep(1);
    clear();
}

void
openHelp()
{
    puts("\n***WELCOME TO MY SHELL HELP***"
        "\nList of Commands supported:"
        "\n>cd"
        "\n>ls"
        "\n>exit"
        "\n>all other general commands available in UNIX shell"
        "\n>pipe handling"
        "\n>improper space handling");
  
    return;
}

int
interpertCmd(char **buf, size_t len)
{
    char *first_command;
	char **parseData;

    if (parseCmd(buf, len) == -1) {
        return -1;
    }

    if (exCmd(first_command, parseData) == -1) {
        return -1;
    }
}

int
parseCmd(char **buf, size_t len)
{
    int idx_before_space = 0;
    char ***parseData;
    int idx_parseData = 0;

    // Move buf pointer to beginning of portion to copy
    // then, copy till space.
	DPRINT(cout << "[Debug] parsing data.." endl;);
    for(int i = 0; i < len - 1; i++) {
        if(buf[i] == ' ') {
            strncmp(parseData[idx_parseData], buf + idx_before_space, i - idx_before_space);
			DPRINT(cout << parseData[i] << endl;);
        }
    }

	exCmd(parseData[0], parseData);

	return -1;
}

int
exCmd(char *option, char ***parseData)
{
	char* command_list;		// list of implemented commands
    int command_count = 7;	// number of implemented comamnds
    int curr = -1;			// currently selected command

    command_list[0] = "exit";
    command_list[1] = "cd";
    command_list[2] = "ls";
    command_list[3] = "pwd";
    command_list[4] = "cp";
    command_list[5] = "mv";
    command_list[6] = "help";


	// get the current command
    for(int i = 0; i < command_count; i++) {
        if (strcmp(option, command_list[i]) == 0) {
            curr = i;
            break;
        }
    }

	// check if  command exists
    if (curr == -1) {
        fprintf(stderr, "*** [Error] Wrong command input\n");
        return -1;
    }

	// conditional branch depending on command
    switch(curr)
    {
        case 2 :	// ls
            list(parseData[1]);
            break;
			
        case 3 :	// pwd
            if(print_pwd() == -1) return -1;
			break;

		case 5 :

    }

	return 1;
}

int
print_pwd()
{
    char *pwd = getcwd(pwd, 1024);	// get current working directory

    if (pwd == NULL) {
        fprintf(stderr, "*** [Error] Obtaining current directory - pwd\n");
        return -1;
    }

    fprintf(stdout, "%s\n", pwd);
}

void
list(char *path)
{
    DIR *dirpath;
    struct dirent *dp;

    // directory path can't be found
    if ((dirpath = opendir(path)) == NULL) {
        fprintf(stderr, "*** [Error] Couldn't open path to list - ls\n");
    }

	do {
		if ((dp = readdir(dirpath)) != NULL) {		// get the data dirpath is pointing as a struct
			// if (strcmp(dp->d_name, ) != 0)	// handle case for ls + filename
			// {
			// 	continue;						// when file is not specified in command
			// }
			fprintf(stdout, "%s\t", dp->d_name);
		}
	} while(dp != NULL);

	closedir(dirpath);
	fprintf(stdout, "\n");
}



// // Function to take input
// int takeInput(char* str)
// {
//     char* buf;
  
//     buf = readline("\n>>> ");
//     if (strlen(buf) != 0) {
//         add_history(buf);
//         strcpy(str, buf);
//         return 0;
//     } else {
//         return 1;
//     }
// }
  
// // Function where the system command is executed
// void execArgs(char** parsed)
// {
//     // Forking a child
//     pid_t pid = fork(); 
  
//     if (pid == -1) {
//         printf("\nFailed forking child..");
//         return;
//     } else if (pid == 0) {
//         if (execvp(parsed[0], parsed) < 0) {
//             printf("\nCould not execute command..");
//         }
//         exit(0);
//     } else {
//         // waiting for child to terminate
//         wait(NULL); 
//         return;
//     }
// }
  
// // Function where the piped system commands is executed
// void execArgsPiped(char** parsed, char** parsedpipe)
// {
//     // 0 is read end, 1 is write end
//     int pipefd[2]; 
//     pid_t p1, p2;
  
//     if (pipe(pipefd) < 0) {
//         printf("\nPipe could not be initialized");
//         return;
//     }
//     p1 = fork();
//     if (p1 < 0) {
//         printf("\nCould not fork");
//         return;
//     }
  
//     if (p1 == 0) {
//         // Child 1 executing..
//         // It only needs to write at the write end
//         close(pipefd[0]);
//         dup2(pipefd[1], STDOUT_FILENO);
//         close(pipefd[1]);
  
//         if (execvp(parsed[0], parsed) < 0) {
//             printf("\nCould not execute command 1..");
//             exit(0);
//         }
//     } else {
//         // Parent executing
//         p2 = fork();
  
//         if (p2 < 0) {
//             printf("\nCould not fork");
//             return;
//         }
  
//         // Child 2 executing..
//         // It only needs to read at the read end
//         if (p2 == 0) {
//             close(pipefd[1]);
//             dup2(pipefd[0], STDIN_FILENO);
//             close(pipefd[0]);
//             if (execvp(parsedpipe[0], parsedpipe) < 0) {
//                 printf("\nCould not execute command 2..");
//                 exit(0);
//             }
//         } else {
//             // parent executing, waiting for two children
//             wait(NULL);
//             wait(NULL);
//         }
//     }
// }
  
// // Function to execute builtin commands
// int ownCmdHandler(char** parsed)
// {
//     int NoOfOwnCmds = 4, i, switchOwnArg = 0;
//     char* ListOfOwnCmds[NoOfOwnCmds];
//     char* username;
  
//     ListOfOwnCmds[0] = "exit";
//     ListOfOwnCmds[1] = "cd";
//     ListOfOwnCmds[2] = "help";
//     ListOfOwnCmds[3] = "hello";
  
//     for (i = 0; i < NoOfOwnCmds; i++) {
//         if (strcmp(parsed[0], ListOfOwnCmds[i]) == 0) {
//             switchOwnArg = i + 1;
//             break;
//         }
//     }
  
//     switch (switchOwnArg) {
//     case 1:
//         printf("\nGoodbye\n");
//         exit(0);
//     case 2:
//         chdir(parsed[1]);
//         return 1;
//     case 3:
//         openHelp();
//         return 1;
//     case 4:
//         username = getenv("USER");
//         printf("\nHello %s.\nMind that this is "
//             "not a place to play around."
//             "\nUse help to know more..\n",
//             username);
//         return 1;
//     default:
//         break;
//     }
  
//     return 0;
// }
  
// // function for finding pipe
// int parsePipe(char* str, char** strpiped)
// {
//     int i;
//     for (i = 0; i < 2; i++) {
//         strpiped[i] = strsep(&str, "|");
//         if (strpiped[i] == NULL)
//             break;
//     }
  
//     if (strpiped[1] == NULL)
//         return 0; // returns zero if no pipe is found.
//     else {
//         return 1;
//     }
// }
  
// // function for parsing command words
// void parseSpace(char* str, char** parsed)
// {
//     int i;
  
//     for (i = 0; i < MAXLIST; i++) {
//         parsed[i] = strsep(&str, " ");
  
//         if (parsed[i] == NULL)
//             break;
//         if (strlen(parsed[i]) == 0)
//             i--;
//     }
// }
  
// int processString(char* str, char** parsed, char** parsedpipe)
// {
  
//     char* strpiped[2];
//     int piped = 0;
  
//     piped = parsePipe(str, strpiped);
  
//     if (piped) {
//         parseSpace(strpiped[0], parsed);
//         parseSpace(strpiped[1], parsedpipe);
  
//     } else {
  
//         parseSpace(str, parsed);
//     }
  
//     if (ownCmdHandler(parsed))
//         return 0;
//     else
//         return 1 + piped;
// }
  
// int main()
// {
//     char inputString[MAXCOM], *parsedArgs[MAXLIST];
//     char* parsedArgsPiped[MAXLIST];
//     int execFlag = 0;
//     init_shell();
  
//     while (1) {
//         // print shell line
//         printDir();
//         // take input
//         if (takeInput(inputString))
//             continue;
//         // process
//         execFlag = processString(inputString,
//         parsedArgs, parsedArgsPiped);
//         // execflag returns zero if there is no command
//         // or it is a builtin command,
//         // 1 if it is a simple command
//         // 2 if it is including a pipe.
  
//         // execute
//         if (execFlag == 1)
//             execArgs(parsedArgs);
  
//         if (execFlag == 2)
//             execArgsPiped(parsedArgs, parsedArgsPiped);
//     }
//     return 0;
// }