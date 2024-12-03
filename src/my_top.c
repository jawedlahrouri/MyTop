/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** reproduce top command
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include "../include/my.h"

int display_time(void)
{
    char buffer[80];
    time_t current_time;
    struct tm *local;

    initscr();
    while (1) {
        current_time = time(NULL);
        local = localtime(&current_time);
        strftime(buffer, sizeof(buffer), "%H:%M:%S", local);
        mvprintw(0, 0, "Heure : %s", buffer);
        refresh();
        napms(1000);
    }
    endwin();
    return 0;
}

int main(void)
{
    display_time();
    return 0;
}
