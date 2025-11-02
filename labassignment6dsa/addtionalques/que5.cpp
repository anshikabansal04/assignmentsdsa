#include <iostream>
using namespace std;
class node {
    public:
    int data;
    node* prev;
    node* next;
    node* up;
    node* down;
    node(int val) {
        data = val;
        prev=nullptr;
        next=nullptr;
        up=nullptr;
        down=nullptr;
    }
};
node* conversion(int arr[][90],node* &head,int n1,int n2){
    node* nodes[90][90];
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
nodes[i][j]=new node(arr[i][j]);
        }
    }
      for (int i=0;i<n1;i++) {
        for (int j=0;j<n2;j++) {
            if (j>0)nodes[i][j]->prev=nodes[i][j-1];     
            if (j<n2-1) nodes[i][j]->next=nodes[i][j+1]; 
            if(i>0) nodes[i][j]->up=nodes[i-1][j];       
            if(i<n1-1)nodes[i][j]->down=nodes[i + 1][j]; 
        }
    }

    return nodes[0][0];
}
void print(node* &head,int n1,int n2){
node* row=head;
while(row){
    node* col=row;
    while(col){
        cout<<col->data<<" ";
        col=col->next;
        }
        cout<<endl;
        row=row->down;
}
}
    int main(){
    int arr[90][90];
    int n1;
    cout<<"enter rows"<<endl;
    cin>>n1;
    int n2;
    cout<<"enter coloums "<<endl;
    cin>>n2;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            cout<<"enter element"<<endl;
            cin>>arr[i][j];
        }
    }
    node* head=conversion(arr,head,n1,n2);
    print(head,n1,n2);
}
