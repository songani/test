#include <iostream>
using namespace std;
//length为字符串的总容量
int ReplaceBlank(char string[],int length){
    if(string==NULL||length<=0)
        return -1;
    int olength=0;
    int blank=0;
    int i=0;
    int j=0;
    while(string[i]!='\0'){
        olength++;
        if(string[i]==' '){
            blank++;
        }
        i++;
    }
    cout<<olength<<endl;
    cout<<blank<<endl;
    for(i=(olength+blank*2),j=olength;i>=0;i--,j--){
        if(string[j]==' '){
            string[i]='0';
            i--;
            string[i]='2';
            i--;
            string[i]='%';
        }
        else
        	string[i]=string[j];
    }
    return 0;
}
int main(){
    char string[20]="We are happy";
    ReplaceBlank(string,20);
    int i;
    while(string[i]!='\0'){
        cout<<string[i];
        i++;
    }
    cout<<endl;
    return 0;
}