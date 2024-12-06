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
#include "../include/task.h"

int display_pid(void)
{
    DIR *directory = opendir("/proc");
    struct dirent *entry;
    int line = 4;

    if (directory == NULL) {
        return 84;
    }
    for (entry = readdir(directory); entry != NULL;
        entry = readdir(directory)) {
        if (my_str_isnum(entry->d_name))
            mvprintw(line++, 0, "%s", entry->d_name);
    }
    closedir(directory);
    return 0;
}

static void update_count(const char *state, task_t *counter)
{
    switch (state[0]) {
        case 'R':
            counter->running++;
            break;
        case 'S':
        case 'I':
            counter->sleeping++;
            break;
        case 'Z':
            counter->zombie++;
            break;
        case 'T':
            counter->stopped++;
            break;
        default:
            break;
    }
}

int count_state(const char *pid, task_t *counter)
{
    char path[100];
    char line[100];
    FILE *file;
    char *state;

    snprintf(path, sizeof(path), "/proc/%s/status", pid);
    file = fopen(path, "r");
    if (file == NULL)
        return 84;
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "State:", 6) == 0) {
            state = line + 7;
            state[strcspn(state, "\n")] = 0;
            update_count(state, counter);
            break;
        }
    }
    fclose(file);
    return 0;
}

int display_task(void)
{
    DIR *directory = opendir("/proc");
    struct dirent *entry;
    task_t c = {0, 0, 0, 0};
    int total = 0;

    if (directory == NULL)
        return 84;
    entry = readdir(directory);
    while (entry != NULL) {
        if (my_str_isnum(entry->d_name))
            count_state(entry->d_name, &c);
        entry = readdir(directory);
    }
    closedir(directory);
    total = c.running + c.sleeping + c.zombie + c.stopped;
    mvprintw(1, 0, "Tasks: %d total, %d running, %d sleeping, %d stopped,\
    %d zombie",
            total, c.running, c.sleeping, c.stopped, c.zombie);
    return 0;
}
