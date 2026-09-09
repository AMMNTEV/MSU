#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "func.h"

int Autotest(void)
{
    if (Autotest1() != 0)
    {
        printf("Autotest 1 FAILED\n");
        return 1;
    }
    else
    {
        printf("Autotest 1 PASSED\n");
    }

    if (Autotest2() != 0)
    {
        printf("Autotest 2 FAILED\n");
        return 1;
    }
    else
    {
        printf("Autotest 2 PASSED\n");
    }

    if (Autotest3() != 0)
    {
        printf("Autotest 3 FAILED\n");
        return 1;
    }
    else
    {
        printf("Autotest 3 PASSED\n");
    }

    return 1;
}

int Autotest1(void)
{
    Array amatr;

    int isxodn[3][4] = {
        {6, 2, 4, 12},
        {6, 3, 3, 12},
        {6, 1, 5, 12}};

    int result[3][3] = {
        {2, 4, 12},
        {3, 3, 12},
        {1, 5, 12}};

    amatr.strok = 3;
    amatr.stolb = 4;
    amatr.arr = NULL;
    amatr.idx = NULL;

    amatr.arr = (int **)malloc(amatr.strok * sizeof(int *));
    if (amatr.arr == NULL)
        return 1;

    for (int i = 0; i < amatr.strok; i++)
    {
        amatr.arr[i] = (int *)malloc(amatr.stolb * sizeof(int));
        if (amatr.arr[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(amatr.arr[j]);
            free(amatr.arr);
            return 1;
        }
    }

    for (int i = 0; i < amatr.strok; i++)
    {
        for (int j = 0; j < amatr.stolb; j++)
        {
            amatr.arr[i][j] = isxodn[i][j];
        }
    }

    find_columns_to_delete(&amatr);
    delete_columns(&amatr);

    // Сравниваем результат с ожидаемым
    for (int i = 0; i < amatr.strok; i++)
    {
        for (int j = 0; j < amatr.stolb; j++)
        {
            if (amatr.arr[i][j] != result[i][j])
            {
                for (int k = 0; k < amatr.strok; k++)
                    free(amatr.arr[k]);
                free(amatr.arr);
                if (amatr.idx)
                    free(amatr.idx);
                return 1;
            }
        }
    }

    for (int i = 0; i < amatr.strok; i++)
        free(amatr.arr[i]);
    free(amatr.arr);
    if (amatr.idx)
        free(amatr.idx);

    return 0;
}

int Autotest2(void)
{
    Array amatr;

    int isxodn[3][5] = {
        {1, 5, 9, 5, 5},
        {1, 5, 9, 5, 5},
        {1, 5, 9, 5, 5}};

    int result[3][2] = {
        {1, 9},
        {1, 9},
        {1, 9}};

    amatr.strok = 3;
    amatr.stolb = 5;
    amatr.arr = NULL;
    amatr.idx = NULL;

    amatr.arr = (int **)malloc(amatr.strok * sizeof(int *));
    if (amatr.arr == NULL)
        return 1;

    for (int i = 0; i < amatr.strok; i++)
    {
        amatr.arr[i] = (int *)malloc(amatr.stolb * sizeof(int));
        if (amatr.arr[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(amatr.arr[j]);
            free(amatr.arr);
            return 1;
        }
    }

    // Заполняем массив исходными данными
    for (int i = 0; i < amatr.strok; i++)
    {
        for (int j = 0; j < amatr.stolb; j++)
        {
            amatr.arr[i][j] = isxodn[i][j];
        }
    }

    find_columns_to_delete(&amatr);
    delete_columns(&amatr);

    // Сравниваем результат с ожидаемым
    for (int i = 0; i < amatr.strok; i++)
    {
        for (int j = 0; j < amatr.stolb; j++)
        {
            if (amatr.arr[i][j] != result[i][j])
            {
                for (int k = 0; k < amatr.strok; k++)
                    free(amatr.arr[k]);
                free(amatr.arr);
                if (amatr.idx)
                    free(amatr.idx);
                return 1;
            }
        }
    }

    for (int i = 0; i < amatr.strok; i++)
        free(amatr.arr[i]);
    free(amatr.arr);
    if (amatr.idx)
        free(amatr.idx);

    return 0;
}

int Autotest3(void)
{
    Array amatr;

    int isxodn[3][3] = {
        {1, 2, 3333},
        {4, 5, 666},
        {7, 8, 99}};

    int result[3][3] = {
        {1, 2, 3333},
        {4, 5, 666},
        {7, 8, 99}};

    // Инициализация структуры
    amatr.strok = 3;
    amatr.stolb = 3;
    amatr.arr = NULL;
    amatr.idx = NULL;

    amatr.arr = (int **)malloc(amatr.strok * sizeof(int *));
    if (amatr.arr == NULL)
        return 1;

    for (int i = 0; i < amatr.strok; i++)
    {
        amatr.arr[i] = (int *)malloc(amatr.stolb * sizeof(int));
        if (amatr.arr[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(amatr.arr[j]);
            free(amatr.arr);
            return 1;
        }
    }

    // Заполняем массив исходными данными
    for (int i = 0; i < amatr.strok; i++)
    {
        for (int j = 0; j < amatr.stolb; j++)
        {
            amatr.arr[i][j] = isxodn[i][j];
        }
    }

    find_columns_to_delete(&amatr);
    delete_columns(&amatr);

    // Сравниваем результат с ожидаемым
    for (int i = 0; i < amatr.strok; i++)
    {
        for (int j = 0; j < amatr.stolb; j++)
        {
            if (amatr.arr[i][j] != result[i][j])
            {
                printf("%d %d\n", amatr.arr[i][j], result[i][j]);
                // Освобождаем память перед выходом
                for (int k = 0; k < amatr.strok; k++)
                    free(amatr.arr[k]);
                free(amatr.arr);
                if (amatr.idx)
                    free(amatr.idx);
                return 1;
            }
        }
    }

    // Освобождаем память
    for (int i = 0; i < amatr.strok; i++)
        free(amatr.arr[i]);
    free(amatr.arr);
    if (amatr.idx)
        free(amatr.idx);

    return 0;
}
