#include<iostream>
#include<stdbool.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        this->data=d;
        left=nullptr;
        right=nullptr;
    }
};
#define max 100
bool hashtable[max]={false};
bool hasduplicate(node* root){
    if(root==nullptr){
        return false;
    }
    if(hashtable[root->data]){
        return true;
    }
    hashtable[root->data]=true;
    return hasduplicate(root->left) || hasduplicate(root->right);
}
int main(){
    node* root=new node(1);
   root->left = new node(2);
root->right = new node(3);
root->left->left = new node(4);
root->left->right = new node(2);
if(hasduplicate(root)){
    cout<<"yes"<<endl;
} 
else{
cout<<"no"<<endl;
}

}