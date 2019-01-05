#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
#include<unistd.h>  
#include<pthread.h>  
  
#define SIZE 1024

void* calc(void*);  
void start();

int p1,p2;  
int m;
int id = 10715053;
int main(){
    FILE *str;
    int pfd[2];
    int nread;
    int pid;
    char buf[SIZE];
    if (pipe(pfd) == -1){
        perror("pipe failed");
        exit(1);
    }
    if ((pid = fork()) < 0){
        perror("fork failed");
        exit(2);
    }
    if (pid == 0){
        /* child */
        close(pfd[1]);
        str = fopen("./10715053.txt", "r+");
        while ((nread = read(pfd[0], buf, SIZE)) != 0)
            fprintf(str, buf);
        fclose(str);
        close(pfd[0]);
    }
    else {
        /* parent */
        close(pfd[0]);
        start();
        char str_m[10]={0};
        char temp[10];
        int count = -1;
        while(m != 0){
            count++;
            temp[count] = m % 10 + '0';
            m /= 10;
        }
        int teco = 0;
        while(count >= 0){
            str_m[teco] = temp[count];
            count--;
            teco++;
        }
        strcpy(buf, str_m);
        /* include null terminator in write */
        write(pfd[1], buf,
        strlen(buf)+1);
        close(pfd[1]);
    }
    
    return 0;  
}

void start(){
    pthread_t pid2;
    pthread_attr_t attr;
    void *p;
    int ret=0;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);  
    pthread_create(&pid2, &attr, calc, NULL);
    ret=pthread_join(pid2, &p);
    
}

void* calc(void *arg2){  
    int i=0;  
    m = 0;
    while(id != 0){
        m+=id%10;
        id/=10;
    }
    pthread_exit((void *)2);  
}