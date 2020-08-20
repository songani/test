#include<iostream>
#include<functional>
#include<algorithm>
using namespace std;
//关系仿函数
//大于greater
void test01(){
    vector<int> v;
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(10);
    v.push_back(50);
    for(vector<int>::iterator it=v.begin;it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    //降序
    sort(v.begin(),v.end(),greater<int>());   
}
int main(){
    test01();
    return 0;
}