#include <iostream>
using namespace std;
struct BiTree{
    int value;
    BiTree* left;
    BiTree* right;
};
BiTree* Construct(int* pre,int* in,int length){
    if(length<=0||pre==NULL||length==NULL){
        return NULL;
    }
    BiTree* root=new BiTree();
    root->value=pre[0];
    int flag=-1;
    for(int i=0;i<length;i++){
        if(pre[i]==in[i]){
            flag=i;
            break;
        }
    }
    if(flag==-1)
        exit(0);
    root->left=Construct(pre+1,in,flag);
    root->right=Construct(pre+flag+1,in+flag+1,length-flag-1); 
    return root;
}

