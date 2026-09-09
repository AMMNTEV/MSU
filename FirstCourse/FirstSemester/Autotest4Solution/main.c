#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int m;
    int size;
    int* arr;

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

    if(sm.size < 2){
        return -1;
    }

    rewind(f);

    sm.size = sm.size - 2;

    fscanf(f,"%d", &sm.m);
    if (sm.m < 0 || sm.m > 30){
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

    for (int i = 0; i < sm.size; i++){
        if(((sm.arr[i]>>sm.m)&1) == ((sm.arr[i]>>(sm.m+1))&1)){
            tmp = 0;

            for (int j = 0; j < 32; j++){
                tmp += (sm.arr[i]>>j)&1;
            }

            sm.arr[i] = tmp;
        }
    }

    for (int  i = 0; i < sm.size; i++){
        fprintf(out, "%d\n", sm.arr[i]);
    }

    fclose(out);

    return 0;
}