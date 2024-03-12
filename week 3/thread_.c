#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *print1(void *arg)
 {
    printf("Hello ");
    pthread_exit(NULL);
}

void *print2(void *arg) 
{
    printf("World\n");
    pthread_exit(NULL);
}
int main() 
{
    pthread_t thread1, thread2;
    if (pthread_create(&thread1, NULL, print1, NULL) != 0) {
        fprintf(stderr, "Error creating thread 1\n");
        return 1;
    }
    if (pthread_join(thread1, NULL) != 0) {
        fprintf(stderr, "Error joining thread 1\n");
        return 1;
    }
    if (pthread_create(&thread2, NULL, print2, NULL) != 0) {
        fprintf(stderr, "Error creating thread 2\n");
        return 1;
    }
    if (pthread_join(thread2, NULL) != 0) {
        fprintf(stderr, "Error joining thread 2\n");
        return 1;
    }

    return 0;
}
