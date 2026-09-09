#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int m;
    int n;
    int size, size_idx;
    int* arr;
    int* idx;

}SmartArray;


int main(void){
    SmartArray sm;
    int tmp = 0;
    FILE * f = fopen("input.txt", "r");
    FILE * out = fopen("output.txt", "w");

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
    }

    fclose(f);

    sm.idx = (int*)malloc((size_t)sm.size * sizeof(int));

    tmp = 0;
    for (int i = 0; i < sm.size; i++){
        if (sm.arr[i] >= sm.m && sm.arr[i] <= sm.n){
            sm.idx[tmp++] = i;
        }
    }

    sm.size_idx = tmp;

    for (int i = 0; i < sm.size_idx; i++){
        tmp = 0;
        for (int j = i + 1; j < sm.size_idx; j++){
            
        if (sm.arr[sm.idx[j]] < sm.arr[sm.idx[i]] * (sm.m / sm.n))
            {
                tmp++;
            }
        }

        sm.arr[sm.idx[i]] = tmp;
    }

    for (int  i = 0; i < sm.size; i++){
        fprintf(out, "%d ", sm.arr[i]);
    }

    fclose(out);

    return 0;
}
