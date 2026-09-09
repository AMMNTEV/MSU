#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(void)
{
    Array matr;
    FILE *inp = fopen("data.dat", "r");
    FILE *out = fopen("data.res", "w");
    
    matr.arr = NULL;
    matr.idx = NULL;

   

    if (!inp)
    {
        printf("Error inp\n");
        return 1;
    }

    if (!out)
    {
        printf("Error out\n");
        return 1;
    }

    // Читаем размеры матрицы
    if (fscanf(inp, "%d %d", &matr.strok, &matr.stolb) != 2)
    {
        printf("Error format\n");
        fclose(inp);
        fclose(out);
        return 1;
    }

    // Создаем матрицу
    if (createmassive(&matr, inp) != 0)
    {
        printf("Error creating matrix\n");
        fclose(inp);
        fclose(out);
        return 1;
    }

    if(find_columns_to_delete(&matr) != 0){
        printf("error1\n");
        return 1;
    }
    if(delete_columns(&matr) != 0){
        printf("error2\n");
        return 1;
    }
    fclose(inp);
    
    if(print_matrix(&matr, out) != 0){
        printf("error3\n");
        return 1;
    }
    if(free_massive(&matr) != 0){
        printf("error4\n");
        return 1;
    }

    
    fclose(out);
    
    printf("success\n");

    Autotest();

    return 0;
}
