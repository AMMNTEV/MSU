#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int m;
    int n;
    int size, size_idx;
    int* arr;
    int* idx;
    double sred_ar;

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
    sm.sred_ar = 0;

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

        sm.sred_ar += (double)sm.arr[i]/sm.size;
    }

    fclose(f);

    sm.idx = (int*)malloc((size_t)sm.size * sizeof(int));

    tmp = 0;
    for (int i = 0; i < sm.size; i++){
        if (((double)sm.arr[i]-sm.sred_ar <= (double)sm.m/sm.n) && ((double)sm.arr[i]-sm.sred_ar >= (-1) * (double)sm.m/sm.n)){
            sm.idx[tmp++] = i;
        }
        sm.size_idx = tmp;
    }

    for (int i = sm.size_idx - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (sm.arr[sm.idx[j]] > sm.arr[sm.idx[j + 1]]){
                tmp = sm.arr[sm.idx[j]];
                sm.arr[sm.idx[j]] = sm.arr[sm.idx[j + 1]];
                sm.arr[sm.idx[j + 1]] = tmp;
            }
        }
    }

    for (int  i = 0; i < sm.size; i++){
        fprintf(out, "%d ", sm.arr[i]);
    }

    fclose(out);

    return 0;
}


