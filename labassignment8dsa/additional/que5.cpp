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
node* solve(int in[],int pre[],int &index,int inorderstart,int inorderend,int n){//n is number of nodes 
    if(index>n||inorderstart>inorderend){
    return nullptr;
    }
    int element=pre[index++];
        node* temp=new node(element);
    int position=findposition(in,element,n);
    temp->left=solve(in,pre,index,inorderstart,position-1,n);
temp->right=solve(in,pre,index,position+1,inorderend,n);
return temp;
}
node* bulitree(int in[],int pre[],int n){
    int preorderindex=0;
    node* ans=solve(in,pre,preorderindex,0,n-1,n);
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
    int in[50]={4,2,5,1,6,3,7};
    int pre[50]={1,2,4,5,3,6,7};
    int n=7;
    node* root=bulitree(in,pre,7);
    inorder(root);
}
