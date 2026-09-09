#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h" 

int createmassive(Array *mass, FILE *inp)
{
    int i, j, pos, count;
    char line[1024];
    int temp[1000];

    mass->arr = (int **)malloc(mass->strok * sizeof(int *));
    if (mass->arr == NULL)
        return 1;

    mass->row_sizes = (int *)malloc(mass->strok * sizeof(int));
    if (mass->row_sizes == NULL)
    {
        free(mass->arr);
        return 1;
    }

    for (i = 0; i < mass->strok; i++)
    {
        if (fgets(line, sizeof(line), inp) == NULL)
            return 1;

        count = 0;
        pos = 0;
        while (sscanf(line + pos, "%d", &temp[count]) == 1)
        {
            count++;
            while (line[pos] >= '0' && line[pos] <= '9')
                pos++;
            while (line[pos] == ' ')
                pos++;
        }

        mass->row_sizes[i] = count;
        mass->arr[i] = (int *)malloc(count * sizeof(int));
        if (mass->arr[i] == NULL)
            return 1;

        for (j = 0; j < count; j++)
            mass->arr[i][j] = temp[j];
    }

    return 0;
}

int find_first_matching_column(Array *mass)
{
    int i, j, sum, n;

    for (i = 0; i < mass->strok; i++)
    {
        sum = 0;
        n = mass->row_sizes[i];

        for (j = 0; j < n; j++)
            sum += mass->arr[i][j];

        for (j = 0; j < n; j++)
        {
            if (mass->arr[i][j] * n == sum)
                return j;
        }
    }

    return -1;
}

int remove_column(Array *mass, int col_index)
{
    int i, j, k;
    int **new_arr;
    int *new_row_sizes;

    if (col_index < 0)
        return 0;

    new_arr = (int **)malloc(mass->strok * sizeof(int *));
    if (new_arr == NULL)
        return 1;

    new_row_sizes = (int *)malloc(mass->strok * sizeof(int));
    if (new_row_sizes == NULL)
    {
        free(new_arr);
        return 1;
    }

    for (i = 0; i < mass->strok; i++)
    {
        if (col_index < mass->row_sizes[i])
        {
            new_row_sizes[i] = mass->row_sizes[i] - 1;
            new_arr[i] = (int *)malloc(new_row_sizes[i] * sizeof(int));
            if (new_arr[i] == NULL)
                return 1;

            k = 0;
            for (j = 0; j < mass->row_sizes[i]; j++)
            {
                if (j != col_index)
                {
                    new_arr[i][k] = mass->arr[i][j];
                    k++;
                }
            }
        }
        else
        {
            new_row_sizes[i] = mass->row_sizes[i];
            new_arr[i] = (int *)malloc(new_row_sizes[i] * sizeof(int));
            if (new_arr[i] == NULL)
                return 1;

            for (j = 0; j < mass->row_sizes[i]; j++)
                new_arr[i][j] = mass->arr[i][j];
        }
    }

    for (i = 0; i < mass->strok; i++)
        free(mass->arr[i]);
    free(mass->arr);
    free(mass->row_sizes);

    mass->arr = new_arr;
    mass->row_sizes = new_row_sizes;

    return 0;
}

int find_and_remove_column(Array *mass)
{
    int col = find_first_matching_column(mass);
    if (col != -1)
        return remove_column(mass, col);
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

    if (mass->row_sizes != NULL)
        free(mass->row_sizes);

    return 0;
}

int print_matrix(Array *mass, FILE *out)
{
    int i, j;

    for (i = 0; i < mass->strok; i++)
    {
        for (j = 0; j < mass->row_sizes[i]; j++)
            fprintf(out, "%d ", mass->arr[i][j]);
        fprintf(out, "\n");
    }

    return 0;
}
