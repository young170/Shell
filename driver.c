// Creating a simple Linux shell in C
// 31/12/2022 ~ 
// Author : Seongbin Kim


#include "shell.h"


int 
main(void)
{

    while(1)
    {
        fprintf(stdout, "=> ");
        
        // Recieve input command.
        char *buf;
        int input_size = 32;
        if (getline(&buf, input_size, stdin) == -1) {
            fprintf(stderr, "*** [Error] Reading command - input\n");
            continue;
        }


        // Handle parsing and execution.
        if (interpretCmd(buf, strlen(buf)) == -1) {
            fprintf(stderr, "*** [Error] Interpreting command");
        }
    }
    

}
