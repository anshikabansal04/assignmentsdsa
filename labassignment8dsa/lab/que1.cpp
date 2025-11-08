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
node* create(node* &root){
    int data;
    cout<<"enter data"<<endl;
    cin>>data;
    if(data==-1){
    return nullptr;
    }
 root=new node(data);
 cout<<"enter left child of data"<<data<<endl;
 root->left=create(root->left);
 cout<<"enter right child of data"<<data<<endl;
 root->right=create(root->right); 
 return root; 
}

void inorder(node* root){
if(root==nullptr){
    return ;
}
inorder(root->left);
cout<<root->data;
inorder(root->right);
}
void preorder(node* root){
    if(root==nullptr){
        return ;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
    if(root==nullptr){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
}
int main(){
    node* root=nullptr;
    root=create(root);
     cout << "\nInorder Traversal: ";
    inorder(root);
     cout << "\npreorder Traversal: ";
    preorder(root);
     cout << "\npostorder Traversal: ";
postorder(root);
return 0;
}
