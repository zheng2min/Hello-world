#include <stdio.h> 
#include <pthread.h> 
#include <assert.h>  
void* start_routine(void* param) 
{ 
    int index = *(int*)param; 
    printf("%s:%d\n", __func__, index); 
    return NULL; 
} 
#define THREADS_NR 10 
void create_test_threads() 
{ 
    int i = 0; 
    void* ret = NULL; 
    pthread_t ids[THREADS_NR] = {0}; 
    for(i = 0; i < THREADS_NR; i++) 
    { 
        printf("%s:%d\n", __func__, i); 
        pthread_create(ids + i, NULL, start_routine, &i); 
    } 
    for(i = 0; i < THREADS_NR; i++) 
    { 
        pthread_join(ids[i], &ret); 
    } 
    return ; 
} 
int main(int argc, char* argv[]) 
{ 
    create_test_threads(); 
	char *aa ="yes";
	int a='yes'; 
	printf("%d,%d,%d\n",a,*(aa),*(aa+1));
    return 0; 
} 