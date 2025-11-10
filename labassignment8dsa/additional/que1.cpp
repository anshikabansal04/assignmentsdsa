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
int findsum(node* root){
	int sum=0;
	if(root==nullptr){
		return 0;
	}
	if(root->left &&(root->left->left==nullptr && root->left->right==nullptr)){
		sum=sum+root->left->data;
	}
	sum+=findsum(root->left);
	sum+=findsum(root->right);
return sum;
}
int main(){
	node* root=create(root);
	int ans=findsum(root);
	cout<<"sum of all left leaf is  "<<ans<<endl;
	return 0;
}
