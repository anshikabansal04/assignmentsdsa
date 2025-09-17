#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        this->data=d;
        this->next=nullptr;
    }
};
 void display(node* head) {
 node* temp = head;
 while (temp != nullptr) {
        cout<<temp->data;
        if(temp->next)
         cout<<"->";
        temp = temp->next;
    }
    cout << endl;
}
int countanddel(node* head,int key){
    int count=0;
    while(head!=nullptr && head->data==key){
        node* temp=head;
        head=head->next;
        delete temp;
        count++;
    }
    node* current=head;
    while(current!=nullptr && current->next!=nullptr){
        if (current->next->data == key) {
            node* nodeToDelete = current->next;
            current->next = current->next->next;
            delete nodeToDelete;
            count++;
        } else {
            current = current->next;
        }
    }
    return count;
    }
void insertionbeg(node* &head,int d){
node* temp=new node(d);
temp->next=head;
head=temp;
    }
int main(){
    node* n1=new node(9);
    node* head=n1;
int key=1;
insertionbeg(head,1);
insertionbeg(head,2);
insertionbeg(head,1);
insertionbeg(head,2);
insertionbeg(head,1);
insertionbeg(head,3);
insertionbeg(head,1);
display(head);
int count=countanddel(head,1);
cout<<count;
display(head);
return 0;
}
