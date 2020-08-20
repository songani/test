#include<iostream>
#include<functional>
using namespace std;
//negate 一元仿函数 取反仿函数
void test01(){
    negate<int> n;
    cout<<n(20)<<endl;
}
//plus 二元仿函数 加法仿函数
void test02(){
    plus<int> p;
    cout<<p(10,20)<<endl;
}
int main(){
    test01();
    test02();
    return 0;
}