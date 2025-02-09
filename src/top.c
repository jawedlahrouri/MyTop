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
#include <utmp.h>
#include <stdarg.h>
#include <fcntl.h>
#include "../include/my.h"


int display_time(void)
{
    char buffer[80];
    time_t current_time;
    struct tm *local;

    current_time = time(NULL);
    local = localtime(&current_time);
    strftime(buffer, sizeof(buffer), "%H:%M:%S", local);
    mvprintw(0, 0, "top - %s", buffer);
    return 0;
}

int display_white_line(void)
{
    attron(A_STANDOUT);
    mvprintw(3, 0, "PID USER  PR NI VIRT RES SHR S\
    %%CPU %%MEM TIME+ COMMAND ");
    attroff(A_STANDOUT);
}

int display_user(void)
{
    struct utmp entry;
    int user = 0;
    FILE *file = fopen("/var/run/utmp", "rb");

    if (file == NULL)   
        return 84;
    while (fread(&entry, sizeof(entry), 1, file) == 1) {
        if (entry.ut_type == USER_PROCESS)
            user++;
    }
    fclose(file);
    mvprintw(0, 28, "%d users,", user);
    return 0;
}

int display_loadavg(void)
{
    FILE *file = fopen("/proc/loadavg", "r");
    double loadavg1;
    double loadavg2;
    double loadavg3;

    if (file == NULL)
        return 84;
    if (fscanf(file, "%lf %lf %lf", &loadavg1, &loadavg2, &loadavg3) != 3) {
        fclose(file);
        return 1;
    }
    mvprintw(0, 37, "load average: %.2f,", loadavg1);
    mvprintw(0, 57, "%.2f,", loadavg2);
    mvprintw(0, 63, "%.2f", loadavg3);
    fclose(file);
    return 0;
}

int main(void)
{
    initscr();
    noecho();
    curs_set(0);
    while (1) {
        clear();
        display_time();
        display_user();
        display_white_line();
        display_task();
        display_pid();
        display_loadavg();
        refresh();
        napms(1000);
    }
    endwin();
    return (0);
}
