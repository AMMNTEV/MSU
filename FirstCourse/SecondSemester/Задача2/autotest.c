#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int Autotest(void)
{
    if (Autotest1() != 0)
    {
        printf("Autotest 1 FAILED\n");
        return 1;
    }
    else
        printf("Autotest 1 PASSED\n");

    if (Autotest2() != 0)
    {
        printf("Autotest 2 FAILED\n");
        return 1;
    }
    else
        printf("Autotest 2 PASSED\n");

    if (Autotest3() != 0)
    {
        printf("Autotest 3 FAILED\n");
        return 1;
    }
    else
        printf("Autotest 3 PASSED\n");

    return 0;
}

int Autotest1(void)
{
    Array amatr;
    int i, j;
    int isxodn[3][4] = {
        {6, 2, 4, 12},
        {6, 3, 3, 12},
        {6, 1, 5, 12}};
    int M = 2, N = 2;
    int result[3][3] = {
        {2, 2, 4},
        {2, 3, 3},
        {2, 1, 5}};

    amatr.strok = 3;
    amatr.stolb = 4;
    amatr.arr = NULL;
    amatr.idx = NULL;

    amatr.arr = (int **)malloc(amatr.strok * sizeof(int *));
    if (amatr.arr == NULL)
        return 1;

    for (i = 0; i < amatr.strok; i++)
    {
        amatr.arr[i] = (int *)malloc(amatr.stolb * sizeof(int));
        if (amatr.arr[i] == NULL)
        {
            for (j = 0; j < i; j++)
                free(amatr.arr[j]);
            free(amatr.arr);
            return 1;
        }
    }

    for (i = 0; i < amatr.strok; i++)
        for (j = 0; j < amatr.stolb; j++)
            amatr.arr[i][j] = isxodn[i][j];

    if (find_columns_to_process(&amatr, M) != 0)
        goto error;
    if (process_columns(&amatr, N) != 0)
        goto error;

    for (i = 0; i < amatr.strok; i++)
        for (j = 0; j < amatr.stolb; j++)
            if (amatr.arr[i][j] != result[i][j])
                goto error;

    for (i = 0; i < amatr.strok; i++)
        free(amatr.arr[i]);
    free(amatr.arr);
    if (amatr.idx)
        free(amatr.idx);
    return 0;

error:
    for (i = 0; i < amatr.strok; i++)
        free(amatr.arr[i]);
    free(amatr.arr);
    if (amatr.idx)
        free(amatr.idx);
    return 1;
}

int Autotest2(void)
{
    Array amatr;
    int i, j;
    int isxodn[3][5] = {
        {2, 5, 4, 8, 10},
        {4, 5, 6, 12, 14},
        {6, 5, 8, 16, 18}};
    int M = 2, N = 3;
    int result[3][3] = {
        {4, 5, 2},
        {6, 5, 6},
        {6, 5, 2}};

    amatr.strok = 3;
    amatr.stolb = 5;
    amatr.arr = NULL;
    amatr.idx = NULL;

    amatr.arr = (int **)malloc(amatr.strok * sizeof(int *));
    if (amatr.arr == NULL)
        return 1;

    for (i = 0; i < amatr.strok; i++)
    {
        amatr.arr[i] = (int *)malloc(amatr.stolb * sizeof(int));
        if (amatr.arr[i] == NULL)
        {
            for (j = 0; j < i; j++)
                free(amatr.arr[j]);
            free(amatr.arr);
            return 1;
        }
    }

    for (i = 0; i < amatr.strok; i++)
        for (j = 0; j < amatr.stolb; j++)
            amatr.arr[i][j] = isxodn[i][j];

    if (find_columns_to_process(&amatr, M) != 0)
        goto error;
    if (process_columns(&amatr, N) != 0)
        goto error;

    for (i = 0; i < amatr.strok; i++)
        for (j = 0; j < amatr.stolb; j++)
            if (amatr.arr[i][j] != result[i][j])
                goto error;

    for (i = 0; i < amatr.strok; i++)
        free(amatr.arr[i]);
    free(amatr.arr);
    if (amatr.idx)
        free(amatr.idx);
    return 0;

error:
    for (i = 0; i < amatr.strok; i++)
        free(amatr.arr[i]);
    free(amatr.arr);
    if (amatr.idx)
        free(amatr.idx);
    return 1;
}

int Autotest3(void)
{
    Array amatr;
    int i, j;
    int isxodn[3][3] = {
        {1, 2, 3333},
        {4, 5, 666},
        {7, 8, 99}};
    int M = 3, N = 4;
    int result[3][3] = {
        {1, 2, 3333},
        {4, 5, 666},
        {7, 8, 99}};

    amatr.strok = 3;
    amatr.stolb = 3;
    amatr.arr = NULL;
    amatr.idx = NULL;

    amatr.arr = (int **)malloc(amatr.strok * sizeof(int *));
    if (amatr.arr == NULL)
        return 1;

    for (i = 0; i < amatr.strok; i++)
    {
        amatr.arr[i] = (int *)malloc(amatr.stolb * sizeof(int));
        if (amatr.arr[i] == NULL)
        {
            for (j = 0; j < i; j++)
                free(amatr.arr[j]);
            free(amatr.arr);
            return 1;
        }
    }

    for (i = 0; i < amatr.strok; i++)
        for (j = 0; j < amatr.stolb; j++)
            amatr.arr[i][j] = isxodn[i][j];

    if (find_columns_to_process(&amatr, M) != 0)
        goto error;
    if (process_columns(&amatr, N) != 0)
        goto error;

    for (i = 0; i < amatr.strok; i++)
        for (j = 0; j < amatr.stolb; j++)
            if (amatr.arr[i][j] != result[i][j])
                goto error;

    for (i = 0; i < amatr.strok; i++)
        free(amatr.arr[i]);
    free(amatr.arr);
    if (amatr.idx)
        free(amatr.idx);
    return 0;

error:
    for (i = 0; i < amatr.strok; i++)
        free(amatr.arr[i]);
    free(amatr.arr);
    if (amatr.idx)
        free(amatr.idx);
    return 1;
}
