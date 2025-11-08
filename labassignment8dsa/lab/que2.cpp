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
bool search(node* root,int key){
    if(root==nullptr){
        return false;
    }
    if(root->data==key){
        return true;
    }
    if(key>root->data){
         return search(root->right,key);
    }
    else{
       return  search(root->left,key);
    }
}
/*
bool search(node* root,int key){
while(root!=nullptr){
if(root->data==key){
return true;}
else if(key<root->data){
root=root->left;}
else{
root=root->right;
}
}
return false;
}
*/
int  max(node* root){
    if(root==nullptr){
return -1;
    }
    while(root->right){
        root=root->right;
    }
    return root->data;
}
int  min(node* root){
    if(root==nullptr){
        return -1;
    }
    while(root->left){
        root=root->left;
    }
    return root->data;
}
node* inordersucc(node* root,int key){
    node* succ=nullptr;
    int succs;
    while(root){
    if(key<root->data){
succ=root;
root=root->left;
    }
    else{
        root=root->right;
    }
}
return succ;
    }
node* inoederped(node* root,int key){
       node* pred=nullptr;
       while(root){
        if(key>root->data){
pred=root;
root=root->right;
        }
else{
    root=root->left;
}
       }
       return pred;
        }
node* insert(node* root, int data) {
    if (root == nullptr)
        return new node(data);
    if (data<root->data)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);
    return root;
}
int main(){
    node* root=nullptr;
    int n;
    cout<<"number of nodes"<<endl;
    cin>>n;
   cout << "Enter values: ";
    for (int i=0;i<n;i++) {
        int val;
        cin>>val;
        root=insert(root, val);
    }
    int key;
    cout<<"enter key to sech"<<endl;
    cin>>key;
   bool ans= search(root,key);
if(ans){
    cout<<"found"<<endl;
}
else{
    cout<<"not found"<<endl;
}
cout<<"min value"<<min(root);
cout<<"max value"<<max(root);
node* succ=inordersucc(root,5);
node* pred=inoederped(root,8);
if(succ){
    cout<<succ->data;
}
else{
    cout<<"no succ"<<endl;
}
if(pred){
    cout<<pred->data;
}
else{
    cout<<"no pred"<<endl;
}
return 0;

}
