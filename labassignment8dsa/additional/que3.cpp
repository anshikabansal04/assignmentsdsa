#include<iostream>
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
node* builttree(int n,int arr[]){
 if(n==0 ||arr[0]==-1){
 return nullptr;
}
node*  root=new node(arr[0]);
queue<node*>q;
q.push(root);
int i=1;
while(!q.empty() && i<n){
 node* current=q.front();
 q.pop();
 //creting left child
 if(i<n &&arr[i]!=-1){
current->left=new node(arr[i]);
q.push(current->left);
}
 i++;
if(i<n && arr[i]!=-1){
//creating right child
current->right=new node(arr[i]);
q.push(current->right);
}
 i++;
}
return root;
}
int maxdepth(node* root){
if(root==nullptr){
  return 0;
 }
int leftdepth=maxdepth(root->left);
int rightdepth=maxdepth(root->right);
return 1+max(leftdepth,rightdepth);
}
int main(){
    int n;
    int arr[90];
    cout<<"enter number of test cases:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"enter val"<<endl;
        cin>>arr[i];
    }
    node* root=builttree(n,arr);
    cout<<maxdepth(root);
    return 0;
}
