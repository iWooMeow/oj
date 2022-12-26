//
// Created by Ryan Dylan on 12/23/22.
//

//test1.c
#include<stdio.h>
#include<pthread.h>
#define NUM_THREADS 5

void *PrintTh(void *th){
    int i = *((int*)th);
    printf("Hello, I'm thread %d\n", i);
    return 0;
}

int main(){
    int i,ret;
    pthread_t p;
    for(i=0; i<NUM_THREADS; i++){
        printf("create th %d\n",i);
        ret = pthread_create(&p,NULL, PrintTh, (void*)&i);
        if(ret != 0)
            printf("th %d error, code = \n",i);
    }
    pthread_exit(NULL);
    return 0;
}
