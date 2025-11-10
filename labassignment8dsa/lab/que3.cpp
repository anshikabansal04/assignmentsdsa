#include<iostream>
using namespace std;
class node{
public:
int data ;
node* left;
node* right;
node(int d){
    data=d;
    left=nullptr;
    right=nullptr;
}
};
node* insert(node* root,int element){
    if(root==nullptr){
    return new node(element);
    }
     else if(root->data>element){
        root->left=insert(root->left,element);
    }
    else if(element>root->data){
       root->right= insert(root->right,element);
    }
    else{
        cout<<"duplicate"<<element;
    }
return root;
}
node* findMin(node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}
node* deletenode(node* root,int key){
    if(root==nullptr){
        return root;
    }
  if(key<root->data){
    root->left=deletenode(root->left,key);
  }
  else if(key>root->data){
    root->right=deletenode(root->right,key);
  }
  else{
    if(root->left==nullptr && root->right==nullptr){
        delete root;
        return nullptr;
    }
    else if(root->left==nullptr){
node* pree=root->right;
delete root;
return pree;
    }
    else if(root->right==nullptr){
     node* pree=root->left;
delete root;
return pree; 
}
else{
  node* succ=findMin(root->right);
  root->data=succ->data;
  root->right=deletenode(root->right,succ->data);
}
}
return root;
}
int maxDepth(node* root) {
    if (root == nullptr){
	 return 0;
}
    int leftDepth=maxDepth(root->left);
    int rightDepth=maxDepth(root->right);
    return  max(leftDepth, rightDepth) + 1;
}
int minDepth(node* root) {
    if (root == nullptr){
	 return 0;
}
    if (!root->left){
	 return 1+minDepth(root->right);
}
	 
    if (!root->right) {
	       return 1+minDepth(root->left);
}
    return 1+min(minDepth(root->left), minDepth(root->right));
}
void inorder(node* root){
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main(){
	node* root=nullptr;
	int n;
	int element;
	cout<<"enter number of nodes:"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"enter an element to insert"<<endl;
		cin>>element;
		root=insert(root,element);
	}
	inorder(root);
	cout<<endl;
	int delval;
	cout<<"enter element you want to delete"<<endl;
	cin>>delval;
	root=deletenode(root,delval);
	cout<<"after deletion is"<<endl;
	inorder(root);
	cout<<endl;
	cout<<"maximum depth is "<<maxDepth(root);
	cout<<endl;
	cout<<"minimum depth is "<<minDepth(root)<<endl;
	return 0;	
}
