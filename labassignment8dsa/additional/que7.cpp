#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node* prev;
    node* next;
    node(int d){
        data=d;
        left=nullptr;
        right=nullptr;
        prev=nullptr;
        next=nullptr;
    }
};
void inorder(node* root,vector<int>&arr){
if (root==nullptr){
    return ;
}
inorder(root->left,arr);
arr.push_back(root->data);
inorder(root->right,arr);

}
vector<int> merge(vector<int>&a,vector<int>&b){
   vector<int>result;
   int i=0;
   int j=0;
   while(i<a.size() && j<b.size()){
    if(a[i]<b[j]){
        result.push_back(a[i]);
        i++;
    }
    else{
        result.push_back(b[j]);
        j++;
    }
   }
   while(i<a.size()){
    result.push_back(a[i++]);
   }
   while(j<a.size()){
    result.push_back(a[j++]);
   }
return result;
}
node* createdll(vector<int>&arr){
    if(arr.size()==0){
        return nullptr;
    }
    node* head=new node(arr[0]);
    node* current=head;
    for(int i=1;i<arr.size();i++){
        node* temp=new node(arr[i]);
        current->next=temp;
        temp->prev=current;
        current=temp;
    }
    return head;
}
void printDLL(node* head) {
    cout <<"Doubly Linked List: ";
    node* curr=head;
    while(curr!=nullptr) {
        cout<<curr->data << " ";
        curr=curr->next;
    }
    cout<<endl;
}

node* insertBST(node* root,int val) {
    if(root==nullptr) 
    {
        return new node(val);
    }
    if(val < root->data){
        root->left=insertBST(root->left, val);
    }
    else{
        root->right=insertBST(root->right, val);
    }
    return root;
}
int main(){
    node* root1=nullptr;
    node* root2=nullptr;
    root1=insertBST(root1,5);
    root1=insertBST(root1,3);
     root1=insertBST(root1,7);

     root2=insertBST(root2,4);
      root2=insertBST(root2,2);
       root2=insertBST(root2,8);
       vector<int>inorder1,inorder2;
       inorder(root1,inorder1);
       inorder(root2,inorder2);
       vector<int>merged=merge(inorder1,inorder2);
       node* heads=createdll(merged);
       printDLL(heads);
       return 0;
}
