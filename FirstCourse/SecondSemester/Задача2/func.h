#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>

typedef struct
{
    int **arr;
    int *idx;
    int strok;
    int stolb;
    int idxsize;
} Array;

/* Прототипы функций */
int createmassive(Array *mass, FILE *inp);
int find_columns_to_process(Array *mass, int M);
int process_columns(Array *mass, int N);
int free_massive(Array *mass);
int print_matrix(Array *mass, FILE *out);

/* Прототипы функций для автотестов */
int Autotest(void);
int Autotest1(void);
int Autotest2(void);
int Autotest3(void);

#endif
