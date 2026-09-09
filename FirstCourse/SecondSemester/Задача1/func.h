typedef struct
{
    int **arr;
    int *idx; // для хранения индексов удаляемых столбцов
    int strok, stolb, idxsize;
} Array;

int createmassive(Array *mass, FILE *inp);
int find_columns_to_delete(Array *mass);
int delete_columns(Array *mass);
int free_massive(Array *mass);
int print_matrix(Array *mass, FILE *out);

int Autotest(void);
int Autotest1(void);
int Autotest2(void);
int Autotest3(void);
