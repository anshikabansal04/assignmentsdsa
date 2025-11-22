#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data=d;
        left=nullptr;
        right=nullptr;
    }
};
void preorder(node* root){
if(root==nullptr){
    return ;
}
cout<<root->data;
preorder(root->left);
preorder(root->right);
}
node* clone(node* root){
    if(root==nullptr){
        return nullptr;
    }
    node* newroot=new node(root->data);
    newroot->left=clone(root->left);
    newroot->right=clone(root->right);
    return newroot;
}
int generate(int start,int end,node* tree[]){
    if(start>end){
        tree[0]=nullptr;
        return 1;
    }
    int count=0;
    for(int i=start;i<=end;i++){
        node* lefttree[50];
        node* righttree[50];
        int leftcount=generate(start,i-1,lefttree);
        int rightcount=generate(i+1,end,righttree);
        for(int l=0;l<leftcount;l++){
            for(int r=0;r<rightcount;r++){
                node* root=new node(i);
                root->left=clone(lefttree[l]);
                root->right=clone(righttree[r]);
                tree[count++]=root;
            }
        }
    }
    return count;
}

int main(){
node* root=nullptr;
int n;
cout<<"enter number of nodes"<<endl;
cin>>n;
node* trre[100];
int total=generate(1,n,trre);
for(int i=0;i<total;i++){
    cout<<"tree"<<i+1<<":"<<endl;
preorder(trre[i]);
cout<<endl;
}
return 0;
}
