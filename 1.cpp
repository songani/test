#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//二元谓词
class MyCompare
{
public:
    bool operator()(int val1,int val2){
        return val1>val2;
    }//二元谓词
};
void test01(){
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    sort(v.begin(),v.end());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    //使用函数对象（仿函数），改变算法规则，变为排序规则为从大到小
    sort(v.begin(),v.end(),MyCompare())
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main(){
    test01();
    return 0;
}