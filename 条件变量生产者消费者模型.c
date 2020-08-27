#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
//单生产者多消费者
int beginnum=1000;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

typedef struct _ProdInfo{
    int num;
    struct _ProdInfo *next;
}ProdInfo;

ProdInfo *head=NULL; 

void *thr_producter(void *arg){
    while(1){
        //负责在链表添加数据
        ProdInfo *prod=malloc(sizeof(ProdInfo));
        prod->num=beginnum;
        beginnum++;
        //加到链表上
        pthread_mutex_lock(&mutex);
        prod->next=head;
        head=prod;
        printf("------%s------self=%lu------%d\n",__FUNCTION__,pthread_self(),prod->num);
        pthread_mutex_unlock(&mutex);
        //发起通知
        pthread_cond_signal(&cond);
        sleep(rand()%2);
    }
    return NULL;
}
void *thr_consumer(void *arg){
    ProdInfo *prod=NULL; 
    while(1){
        //取链表的数据
        pthread_mutex_lock(&mutex);
        //if(head==NULL){
        while(head==NULL){
            pthread_cond_wait(&cond,&mutex);
        }
        prod=head;
        head=head->next;
        printf("------%s------self=%lu------%d\n",__FUNCTION__,pthread_self(),prod->num);
        pthread_mutex_unlock(&mutex);
        free(prod);
        sleep(rand()%4);
    }
    return NULL;
}
int main(){
    pthread_t tid[3];
    pthread_create(&tid[0],NULL,thr_producter,NULL);
    pthread_create(&tid[1],NULL,thr_consumer,NULL);
    pthread_create(&tid[2],NULL,thr_consumer,NULL);
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    pthread_join(tid[2],NULL);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}