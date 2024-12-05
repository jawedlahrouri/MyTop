/*
** EPITECH PROJECT, 2024
** .h
** File description:
** task
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct task {
    int running;
    int sleeping;
    int zombie;
    int stopped;
} task_t;
#endif
