#include <stdio.h>

typedef struct 
{
    int **arr;
    int *row_sizes;
    int strok;
} Array;

int createmassive(Array *mass, FILE *inp);
int find_and_remove_column(Array *mass);
int free_massive(Array *mass);
int print_matrix(Array *mass, FILE *out);
int remove_column(Array *mass, int col_index);
int find_first_matching_column(Array *mass);

int Autotest(void);
int Autotest1(void);
int Autotest2(void);
int Autotest3(void);
