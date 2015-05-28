#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define NUM_COMMANDS 3


void new_cmd();
void close_cmd();
void open_cmd();


struct {
    char *name;
    void (*cmd_pointer) ();
} file_cmd[NUM_COMMANDS] = {
    {"new", new_cmd},
    {"open", open_cmd},
    {"close", close_cmd},
};


void new_cmd()
{
    puts("new");
}


void close_cmd()
{
    puts("close");
}


void open_cmd()
{
    puts("open");
}


void exec_func(char *func_name)
{
    for(int i = 0; i < NUM_COMMANDS; i++) {
        if(!strcmp(func_name, file_cmd[i].name)) {
            file_cmd[i].cmd_pointer();
            return;
        }
    }
    printf("function %s not found!\n", func_name);
}


int main()
{
    exec_func("new");
    exec_func("open");
    exec_func("close");
    exec_func("shit");

    exit(EXIT_SUCCESS);
}
