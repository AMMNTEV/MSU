#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(void)
{
    Array matr;
    FILE *inp;
    FILE *out;
    int M, N;

    matr.arr = NULL;
    matr.idx = NULL;

    inp = fopen("data.dat", "r");
    out = fopen("data.res", "w");

    if (!inp)
    {
        printf("Error opening input file\n");
        return 1;
    }

    if (!out)
    {
        printf("Error opening output file\n");
        fclose(inp);
        return 1;
    }

    if (fscanf(inp, "%d %d", &matr.strok, &matr.stolb) != 2)
    {
        printf("Error reading matrix dimensions\n");
        fclose(inp);
        fclose(out);
        return 1;
    }

    if (fscanf(inp, "%d %d", &M, &N) != 2)
    {
        printf("Error reading M and N parameters\n");
        fclose(inp);
        fclose(out);
        return 1;
    }

    if (createmassive(&matr, inp) != 0)
    {
        printf("Error creating matrix\n");
        fclose(inp);
        fclose(out);
        return 1;
    }

    fclose(inp);

    if (find_columns_to_process(&matr, M) != 0)
    {
        printf("Error finding columns to process\n");
        free_massive(&matr);
        fclose(out);
        return 1;
    }

    if (process_columns(&matr, N) != 0)
    {
        printf("Error processing columns\n");
        free_massive(&matr);
        fclose(out);
        return 1;
    }

    if (print_matrix(&matr, out) != 0)
    {
        printf("Error printing matrix\n");
        free_massive(&matr);
        fclose(out);
        return 1;
    }

    free_massive(&matr);
    fclose(out);

    printf("Program completed successfully\n");
    Autotest();

    return 0;
}
