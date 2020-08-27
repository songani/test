#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

#define _SEM_CNT_ 5
sem_t blank,xfull;
int queue[_SEM_CNT_];//模拟盛放容器
int beginnum=100;

void *thr_producter(void *arg){
    int i=0;
    while(1){
        sem_wait(&blank);//申请资源,blank--
        printf("------%s------self=%lu------num=%d\n",__FUNCTION__,pthread_self(),beginnum);
        queue[(i++)%_SEM_CNT_]=beginnum++;
        sem_post(&xfull);//xfull++
        sleep(rand()%3); 
    }
    return NULL;
}
void *thr_consumer(void *arg){
    int i=0;
     while(1){
        sem_wait(&xfull);
        printf("------%s------self=%lu------num=%d\n",__FUNCTION__,pthread_self(),queue[(i++)%_SEM_CNT_]);
        sem_post(&blank);
        sleep(rand()%3); 
    }
    return NULL;
}

int main(){
    sem_init(&blank,0,_SEM_CNT_);
    sem_init(&xfull,0,0);//消费者一开始默认没有产品
    pthread_t tid[2];
    pthread_create(&tid[0],NULL,thr_producter,NULL);
    pthread_create(&tid[1],NULL,thr_consumer,NULL);
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    sem_destroy(&blank);
    sem_destroy(&xfull);
    return 0;
}