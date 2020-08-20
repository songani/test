#include <iostream>
using namespace std;

int Partition(int data[],int length,int start,int end){
    if(length<=0||start<0||end>=lendth||data==NULL)
        throw new exception("Invalid ParaMeters");
    int temp=data[start];
    while(start!=end){
        while(data[end]>temp&&end>start){
            end--;
        }
        data[start]=data[end];
        while(data[start]<temp&&end>start){
            start++;
        }
        data[end]=data[start];
    }
    date[start]=temp;
    return start;

}

int QuickSort(int data[],int length,int start,int end){
    if(start==end)
        return 0;
    int index=Partition();
    if(index>start)
        QuickSort(data,length,start,index-1);
    if(index<end)
        QuickSort(data,length,index+1,end);
}

int main(){
    return 0;
}