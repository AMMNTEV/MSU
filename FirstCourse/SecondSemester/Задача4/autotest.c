#include <stdio.h>
#include <stdlib.h>
#include "func.h"
 
int Autotest1(void)
{
    Array matr;
    int i;

    matr.strok = 3;
    matr.row_sizes = (int *)malloc(3 * sizeof(int));
    matr.arr = (int **)malloc(3 * sizeof(int *));

    matr.row_sizes[0] = 4;
    matr.row_sizes[1] = 4;
    matr.row_sizes[2] = 4;

    for (i = 0; i < 3; i++)
        matr.arr[i] = (int *)malloc(4 * sizeof(int));

    matr.arr[0][0] = 6;
    matr.arr[0][1] = 2;
    matr.arr[0][2] = 4;
    matr.arr[0][3] = 12;
    matr.arr[1][0] = 6;
    matr.arr[1][1] = 3;
    matr.arr[1][2] = 3;
    matr.arr[1][3] = 12;
    matr.arr[2][0] = 6;
    matr.arr[2][1] = 1;
    matr.arr[2][2] = 5;
    matr.arr[2][3] = 12;

    find_and_remove_column(&matr);

    if (matr.row_sizes[0] != 3)
        return 1;
    if (matr.arr[0][0] != 2 || matr.arr[0][1] != 4 || matr.arr[0][2] != 12)
        return 1;
    if (matr.arr[1][0] != 3 || matr.arr[1][1] != 3 || matr.arr[1][2] != 12)
        return 1;
    if (matr.arr[2][0] != 1 || matr.arr[2][1] != 5 || matr.arr[2][2] != 12)
        return 1;

    free_massive(&matr);
    return 0;
}

int Autotest2(void)
{
    Array matr;
    int i;

    matr.strok = 3;
    matr.row_sizes = (int *)malloc(3 * sizeof(int));
    matr.arr = (int **)malloc(3 * sizeof(int *));

    matr.row_sizes[0] = 3;
    matr.row_sizes[1] = 3;
    matr.row_sizes[2] = 3;

    for (i = 0; i < 3; i++)
        matr.arr[i] = (int *)malloc(3 * sizeof(int));

    matr.arr[0][0] = 1;
    matr.arr[0][1] = 2;
    matr.arr[0][2] = 3333;
    matr.arr[1][0] = 4;
    matr.arr[1][1] = 5;
    matr.arr[1][2] = 666;
    matr.arr[2][0] = 7;
    matr.arr[2][1] = 8;
    matr.arr[2][2] = 99;

    find_and_remove_column(&matr);

    if (matr.row_sizes[0] != 3)
        return 1;
    if (matr.arr[0][0] != 1 || matr.arr[0][1] != 2 || matr.arr[0][2] != 3333)
        return 1;
    if (matr.arr[1][0] != 4 || matr.arr[1][1] != 5 || matr.arr[1][2] != 666)
        return 1;
    if (matr.arr[2][0] != 7 || matr.arr[2][1] != 8 || matr.arr[2][2] != 99)
        return 1;

    free_massive(&matr);
    return 0;
}

int Autotest3(void)
{
    Array matr;

    matr.strok = 2;
    matr.row_sizes = (int *)malloc(2 * sizeof(int));
    matr.arr = (int **)malloc(2 * sizeof(int *));

    matr.row_sizes[0] = 4;
    matr.arr[0] = (int *)malloc(4 * sizeof(int));
    matr.arr[0][0] = 2;
    matr.arr[0][1] = 4;
    matr.arr[0][2] = 6;
    matr.arr[0][3] = 8;

    matr.row_sizes[1] = 3;
    matr.arr[1] = (int *)malloc(3 * sizeof(int));
    matr.arr[1][0] = 3;
    matr.arr[1][1] = 3;
    matr.arr[1][2] = 3;

    find_and_remove_column(&matr);

    if (matr.row_sizes[0] != 3)
        return 1;
    if (matr.row_sizes[1] != 2)
        return 1;
    if (matr.arr[1][0] != 3 || matr.arr[1][1] != 3)
        return 1;

    free_massive(&matr);
    return 0;
}

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
