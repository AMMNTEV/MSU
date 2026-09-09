#include "autotest.h"
 
int main(void)
{
    FILE *inp, *out;
    char line[257];
    char *dynamic_line;

    inp = fopen("data.dat", "r");
    out = fopen("data.res", "w");

    if (!inp || !out)
    {
        printf("Файлы не открываются\n");
        return 1;
    }

    printf("\n");
    
    while (fgets(line, sizeof(line), inp))
    {   
        line[strcspn(line, "\n")] = '\0';
        
        dynamic_line = malloc(strlen(line) + 1);
        if (!dynamic_line){
            printf("error");
            break;
        }
        strcpy(dynamic_line, line);
        dynamic_line = main_func(dynamic_line);
        fprintf(out, "%s\n", dynamic_line);
        free(dynamic_line);
    }

    if (autotest1())
    {
        printf("Автотест 1 пройден\n");
    }
    else
    {
        printf("Автотест 1 не пройден\n");
        return -1;
    }
    if (autotest2())
    {
        printf("Автотест 2 пройден\n");
    }
    else
    {
        printf("Автотест 2 не пройден\n");
        return -1;
    }
    printf("\n");

    

    fclose(inp);
    fclose(out);
    return 0;
}
