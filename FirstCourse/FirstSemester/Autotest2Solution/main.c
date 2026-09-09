#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int m;
    int n;
    int size;
    int* arr;

}SmartArray;


int main(void){
    SmartArray sm;
    int tmp = 0;
    FILE * f = fopen("input.txt", "r");
    FILE * out = fopen("output.txt", "w");
    int sum = 0;
    
    if (!f){
        return -1;
    }
    if (!out){
        return -1;
    }

    sm.size = 0;

    while(fscanf(f, "%d", &tmp) == 1){
        sm.size++;
    }

    if(sm.size < 3){
        return -1;
    }

    rewind(f);

    sm.size = sm.size - 3;

    fscanf(f,"%d", &sm.m);

    fscanf(f,"%d", &sm.n);
    if (sm.n == 0){
        return -1;
    }

    fscanf(f,"%d", &tmp);
    if (tmp > sm.size){
        return -1;
    }

    sm.arr = (int*)malloc((size_t)sm.size * sizeof(int));

    for (int i = 0; i < sm.size; i++){
        fscanf(f,"%d", &sm.arr[i]);

        sum += sm.arr[i];
    }

    fclose(f);

    for (int i = 1; i < sm.size-1; i++){
        if (sm.size * sm.arr[i] * sm.n == sum * sm.m);
            sm.arr[i] = (sm.arr[i-1] + sm.arr[i-1]) / 2;
        }
    }

    for (int  i = 0; i < sm.size; i++){
        fprintf(out, "%d ", sm.arr[i]);
    }

    fclose(out);

    return 0;
}


