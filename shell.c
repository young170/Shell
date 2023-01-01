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
        "\nCopyright @ Suprotik Dey"
        "\n-Use the shell at your own risk..."
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
interpertCmd(char** buf, size_t len)
{
    if(parseCmd == -1)
    {
        return -1;
    }

    if(exCmd == -1)
    {
        return -1;
    }
}