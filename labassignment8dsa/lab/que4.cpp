#include<iostream>
#include<limits>
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
bool isvalidbst(node* root,int min,int max) {
    if (root==nullptr)
        return true;

    if (root->data<=min||root->data>=max)  
        return false;
    return isvalidbst(root->left,min,root->data) &&
           isvalidbst(root->right,root->data,max);
}
int main(){
	node* root=nullptr;
		root=create(root);
	bool ans=isvalidbst(root,INT_MIN,INT_MAX);
	if(ans){
		cout<<"yes it is bst"<<endl;
	}
	else{
		cout<<"its is not a bst"<<endl;
	}
	return 0;
}
