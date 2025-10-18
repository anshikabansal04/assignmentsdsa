#include<iostream>
using namespace std;
class node{
    public:
    int power;
    int coff;
    node* next;
    node(int p,int c){
        power=p;
        coff=c;
        next=nullptr;
    }
};
void insert(node* &head,int c,int p){
    node* newnode=new node(p,c);
    if(head==nullptr){
      head=newnode;
    }
    else{
        node* temp=head;
        while(temp->next!=nullptr)
                temp=temp->next;
        temp->next=newnode;
    }
}
void display(node* &head){
    node* temp=head;
    while(temp!=nullptr){
        cout<<temp->coff<<"x^"<<temp->power;
        if(temp->next!=nullptr)
            cout<<"+";
            temp=temp->next;        
    }
    cout<<endl;
}
node* addpolynomials(node* p1,node* p2){
    node* result=nullptr;
    while(p1!=nullptr && p2!=nullptr){
    if(p1->power==p2->power){
        insert(result,p1->coff+p2->coff,p1->power);
        p1=p1->next;
        p2=p2->next;
    }
    else if(p1->power>p2->power){
insert(result,p1->coff,p1->power);
p1=p1->next;
    }
    else{
        insert(result,p2->coff,p2->power);
p2=p2->next;
    }
}
while(p1!=nullptr){
insert(result,p1->coff,p1->power);
p1=p1->next;
}
while(p2!=nullptr){
    insert(result,p2->coff,p2->power);
p2=p2->next;
}
return result;
}
int main(){
    node* poly1=nullptr;
    node* poly2=nullptr;
    node* sum=nullptr;
    insert(poly1,5,3);
    insert(poly1,4,2);
    insert(poly1,2,0);
    insert(poly2,5,1);
    insert(poly2,5,0);
    cout<<"Polynomial1: ";
    display(poly1);
    cout<<"Polynomial2: ";
    display(poly2);
    sum=addpolynomials(poly1,poly2);
    cout<<"Sum of Polynomials: ";
    display(sum);
    return 0;
}
