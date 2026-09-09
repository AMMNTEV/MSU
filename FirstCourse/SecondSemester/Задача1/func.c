#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int createmassive(Array *mass, FILE *inp)
{
    mass->arr = (int **)malloc(mass->strok * sizeof(int *));
    mass->idx = NULL; // пока не выделяем память для idx
    if (mass->arr == NULL)
    {
        printf("Memory Error\n");
        return 1;
    }

    for (int i = 0; i < mass->strok; i++)
    {
        mass->arr[i] = (int *)malloc(mass->stolb * sizeof(int));
        if (mass->arr[i] == NULL)
        {
            printf("Memory Error\n");
            for (int j = 0; j < i; j++)
            {
                free(mass->arr[j]);
            }
            free(mass->arr);
            return 1;
        }
    }

    for (int i = 0; i < mass->strok; i++)
    {
        for (int j = 0; j < mass->stolb; j++)
        {
            if (fscanf(inp, "%d", &mass->arr[i][j]) != 1)
            {
                printf("Error reading data\n");
                for (int k = 0; k < mass->strok; k++)
                {
                    free(mass->arr[k]);
                }
                free(mass->arr);
                return 1;
            }
        }
    }
    return 0;
}

int find_columns_to_delete(Array *mass)
{
    long long row_sum;
    int column_valid;
    int idx_pos;
    
    int *delete_flags = (int *)malloc(mass->stolb * sizeof(int));
    if (delete_flags == NULL)
    {
        printf("Memory Error\n");
        return 1;
    }

    // Для каждого столбца проверяем условие
    for (int j = 0; j < mass->stolb; j++)
    {
        column_valid = 1; // предполагаем, что столбец подходит
        
        // Проверяем каждый элемент в столбце
        for (int i = 0; i < mass->strok; i++)
        {
            // Вычисляем сумму всех элементов в строке
            row_sum = 0;
            for (int k = 0; k < mass->stolb; k++)
            {
                row_sum += mass->arr[i][k];
            }

            // Проверяем, равен ли текущий элемент среднему арифметическому
            if ((mass->arr[i][j] * (mass->stolb - 1)) != (row_sum - mass->arr[i][j]))
            {
                column_valid = 0;
            }
        }

        if (column_valid)
        {
            delete_flags[j] = 1;
        }
        else{
            delete_flags[j] = 0;
        }
    }

    // Формируем массив индексов для удаления
    mass->idxsize = 0;
    for (int j = 0; j < mass->stolb; j++)
    {
        if (delete_flags[j])
        {
            mass->idxsize++;
        }
    }

    if (mass->idxsize > 0)
    {
        mass->idx = (int *)malloc(mass->idxsize * sizeof(int));
        if (mass->idx == NULL)
        {
            free(delete_flags);
            printf("Memory Error\n");
            return 1;
        }

        idx_pos = 0;
        for (int j = 0; j < mass->stolb; j++)
        {
            if (delete_flags[j])
            {
                mass->idx[idx_pos++] = j;
            }
        }
    }

    free(delete_flags);
    
    return 0;
}

int delete_columns(Array *mass)
{
    int new_stolb;
    int *delete_map;
    int new_j;
    int *new_row;
    
    if (mass->idxsize == 0)
    {
        return 0;
    }

    new_stolb = mass->stolb - mass->idxsize;
    delete_map = (int *)malloc(mass->stolb * sizeof(int));
    for (int i = 0; i < mass->stolb; i++)
    {
        delete_map[i] = 0;
    }

    // Отмечаем столбцы для удаления
    for (int i = 0; i < mass->idxsize; i++)
    {
        delete_map[mass->idx[i]] = 1;
    }
    
    /*
    for (int i = 0; i < mass->strok; i++)
    {
        for (int j = 0; j < mass->stolb; j++)
        {
            printf("%d ", mass->arr[i][j]);
        }
    }*/
    
    // Создаем новую матрицу без удаленных столбцов
    for (int i = 0; i < mass->strok; i++)
    {
        new_row = (int *)malloc(new_stolb * sizeof(int));
        if (new_row == NULL)
        {
            printf("Memory Error\n");
            return 1;
        }

        new_j = 0;
        for (int j = 0; j < mass->stolb; j++)
        {
            if (!delete_map[j])
            {
                new_row[new_j++] = mass->arr[i][j];
            }
        }
        

        free(mass->arr[i]);
        mass->arr[i] = new_row;
    }

    mass->stolb = new_stolb;
    free(delete_map);
    
 
    return 0;
}

int free_massive(Array *mass)
{
    if (mass->arr != NULL)
    {
        for (int i = 0; i < mass->strok; i++)
        {
            free(mass->arr[i]);
        }
        free(mass->arr);
    }

    if (mass->idx != NULL)
    {
        free(mass->idx);
    }
    return 0;
}

int print_matrix(Array *mass, FILE *out)
{
    for (int i = 0; i < mass->strok; i++)
    {
        for (int j = 0; j < mass->stolb; j++)
        {
            fprintf(out, "%d ", mass->arr[i][j]);
        }
        fprintf(out, "\n");
    }
    return 0;
}
