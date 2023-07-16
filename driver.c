// Creating a simple Linux shell in C
// 12/31/2022 ~ 07/16/2023
// Author : Seongbin Kim
#include "shell.h"


int main(void) {
    char inputString[MAXCOM], *parsedArgs[MAXLIST];
    char* parsedArgsPiped[MAXLIST];
    int execFlag = 0;
    init_shell();
  
    while (1) {
        print_dir();

        if (FALSE_COND == get_input(inputString)) {
            continue;
        }

        // process
        execFlag = processString(inputString, parsedArgs, parsedArgsPiped);
  
        // execute
        if (execFlag == 1)
            execArgs(parsedArgs);
  
        if (execFlag == 2)
            execArgsPiped(parsedArgs, parsedArgsPiped);
    }
    return 0;
}