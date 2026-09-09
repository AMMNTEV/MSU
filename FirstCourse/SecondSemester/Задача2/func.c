#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int createmassive(Array *mass, FILE *inp)
{
    int i, j;

    mass->arr = (int **)malloc(mass->strok * sizeof(int *));
    mass->idx = NULL;

    if (mass->arr == NULL)
    {
        printf("Memory Error\n");
        return 1;
    }

    for (i = 0; i < mass->strok; i++)
    {
        mass->arr[i] = (int *)malloc(mass->stolb * sizeof(int));
        if (mass->arr[i] == NULL)
        {
            printf("Memory Error\n");
            for (j = 0; j < i; j++)
                free(mass->arr[j]);
            free(mass->arr);
            return 1;
        }
    }

    for (i = 0; i < mass->strok; i++)
    {
        for (j = 0; j < mass->stolb; j++)
        {
            if (fscanf(inp, "%d", &mass->arr[i][j]) != 1)
            {
                printf("Error reading data\n");
                for (j = 0; j < mass->strok; j++)
                    free(mass->arr[j]);
                free(mass->arr);
                return 1;
            }
        }
    }

    return 0;
}

int find_columns_to_process(Array *mass, int M)
{
    int i, j;
    int all_divisible;
    int idx_pos;
    int *process_flags;

    process_flags = (int *)malloc(mass->stolb * sizeof(int));
    if (process_flags == NULL)
    {
        printf("Memory Error\n");
        return 1;
    }

    for (j = 0; j < mass->stolb; j++)
    {
        all_divisible = 1;
        for (i = 0; i < mass->strok; i++)
        {
            if (mass->arr[i][j] % M != 0)
            {
                all_divisible = 0;
                break;
            }
        }
        process_flags[j] = all_divisible;
    }

    mass->idxsize = 0;
    for (j = 0; j < mass->stolb; j++)
    {
        if (process_flags[j])
            mass->idxsize++;
    }

    if (mass->idxsize > 0)
    {
        mass->idx = (int *)malloc(mass->idxsize * sizeof(int));
        if (mass->idx == NULL)
        {
            free(process_flags);
            printf("Memory Error\n");
            return 1;
        }

        idx_pos = 0;
        for (j = 0; j < mass->stolb; j++)
        {
            if (process_flags[j])
                mass->idx[idx_pos++] = j;
        }
    }

    free(process_flags);
    return 0;
}

int process_columns(Array *mass, int N)
{
    int i, j, p;
    int new_stolb;
    int **new_arr;
    int *temp_col;
    int waiting;
    int pair_pos;
    int new_j;

    if (mass->idxsize == 0)
        return 0;

    new_stolb = mass->stolb - (mass->idxsize / 2);
    new_arr = (int **)malloc(mass->strok * sizeof(int *));
    if (new_arr == NULL)
        return 1;

    for (i = 0; i < mass->strok; i++)
    {
        new_arr[i] = (int *)malloc(new_stolb * sizeof(int));
        if (new_arr[i] == NULL)
        {
            for (j = 0; j < i; j++)
                free(new_arr[j]);
            free(new_arr);
            return 1;
        }
    }

    temp_col = (int *)malloc(mass->strok * sizeof(int));
    if (temp_col == NULL)
    {
        for (i = 0; i < mass->strok; i++)
            free(new_arr[i]);
        free(new_arr);
        return 1;
    }

    p = 0;
    j = 0;
    new_j = 0;

    while (j < mass->stolb)
    {
        if (p < mass->idxsize && j == mass->idx[p])
        {
            /* это столбец из подмножества */
            if (p % 2 == 0)
            {
                /* первый в паре */
                if (p + 1 < mass->idxsize)
                {
                    /* есть пара – резервируем место */
                    pair_pos = new_j;
                    for (i = 0; i < mass->strok; i++)
                        temp_col[i] = mass->arr[i][j];

                    new_j++;
                }
                else
                {
                    /* последний нечётный – просто копируем */
                    for (i = 0; i < mass->strok; i++)
                        new_arr[i][new_j] = mass->arr[i][j];
                    new_j++;
                }
                p++;
                j++;
            }
            else
            {
                /* второй в паре */

                for (i = 0; i < mass->strok; i++)
                {
                    int a = temp_col[i] & ((1 << N) - 1);
                    int b = mass->arr[i][j] & ((1 << N) - 1);
                    new_arr[i][pair_pos] = (a > b) ? a : b;
                }

                p++;
                j++;
            }
        }
        else
        {
            /* обычный столбец – просто копируем */
            for (i = 0; i < mass->strok; i++)
                new_arr[i][new_j] = mass->arr[i][j];
            new_j++;
            j++;
        }
    }

    free(temp_col);

    /* освобождаем старую матрицу */
    for (i = 0; i < mass->strok; i++)
        free(mass->arr[i]);
    free(mass->arr);

    mass->arr = new_arr;
    mass->stolb = new_stolb;

    return 0;
}

int free_massive(Array *mass)
{
    int i;

    if (mass->arr != NULL)
    {
        for (i = 0; i < mass->strok; i++)
            free(mass->arr[i]);
        free(mass->arr);
    }

    if (mass->idx != NULL)
        free(mass->idx);

    return 0;
}

int print_matrix(Array *mass, FILE *out)
{
    int i, j;

    for (i = 0; i < mass->strok; i++)
    {
        for (j = 0; j < mass->stolb; j++)
            fprintf(out, "%d ", mass->arr[i][j]);
        fprintf(out, "\n");
    }

    return 0;
}
