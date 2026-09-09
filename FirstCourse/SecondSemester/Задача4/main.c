#include <stdio.h>
#include <stdlib.h>
#include "func.h" 

int main(void)
{
    Array matr;
    FILE *inp, *out;

    inp = fopen("data.dat", "r");
    out = fopen("data.res", "w");

    if (inp == NULL || out == NULL)
    {
        printf("Error opening files\n");
        return 1;
    }

    if (fscanf(inp, "%d", &matr.strok) != 1)
    {
        printf("Error reading number of rows\n");
        fclose(inp);
        fclose(out);
        return 1;
    }

    fgetc(inp);

    if (createmassive(&matr, inp) != 0)
    {
        printf("Error creating matrix\n");
        fclose(inp);
        fclose(out);
        return 1;
    }

    fclose(inp);

    find_and_remove_column(&matr);
    print_matrix(&matr, out);

    free_massive(&matr);
    fclose(out);

    Autotest();
    return 0;
}
