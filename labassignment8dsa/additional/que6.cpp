#include<iostream>
#include<vector>
#include<queue>
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
int findposition(int in[],int element,int n){
    for(int i=0;i<n;i++){
if(in[i]==element){
    return i;
}
    } return -1;
}
node* solve(int in[],int post[],int &index,int inorderstart,int inorderend,int n){//n is number of nodes 
    if(index<0||inorderstart>inorderend){
    return nullptr;
    }
int element=post[index--];
node* temp=new node(element);
int position=findposition(in,element,n);
temp->right=solve(in,post,index,position+1,inorderend,n);
temp->left=solve(in,post,index,inorderstart,position-1,n);
return temp;
}
node* bulitree(int in[],int post[],int n){
    int postorderindex=n-1;
    node* ans=solve(in,post,postorderindex,0,n-1,n);
return ans;
}
void inorder(node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main(){
    int in[50]={4, 2, 5, 1, 6, 3, 7};
    int post[50]={4, 5, 2, 6, 7, 3, 1};
    int n=7;
    node* root=bulitree(in,post,7);
    inorder(root);
}
