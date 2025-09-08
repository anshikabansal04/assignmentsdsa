#include<iostream>
#include<queue>
using namespace std;
class queues{
	int front;
	int rear;
	int *arr;
	int size;
	public:
		queues(int s){
			size=s;
			arr=new int[size];
			front=-1;
			rear=-1;
		}
			bool isfull(){
			return rear==size-1;
		}
			bool isempty(){
			return front==-1;}
				
		
		void enqueue(int value){
			
			if(isfull()){
				cout<<"queue is full"<<endl;//overflow
			}
			if(isempty()){
				front=0;
			}
			rear++;
				arr[rear]=value;
			}
		
		void dequeue(){
			if(isempty()){
				cout<<"queue is empty"<<endl;//underflow
			}
		else{
				front++;
			}
		}
		void peak(){
		if(isempty()){return ;
		}	
		cout<<"peak element is"<< arr[front]<<endl;
		}
		void display(){
			cout<<"elements are:"<<endl;
			for(int i=front;i<=rear;i++){
				cout<<arr[i]<<endl;
			}
		}
};
int main(){
	queues q(5);
	int choice,value;
do{
	cout<<"..\n..menu drive/n";
	cout<<"1.enqueue value";
	cout<<"2.dequeue ";
	cout<<" 3.display.\n";
	cout<<"4.peak.\n";
	cin>>choice;
	switch(choice){
		case 1:cout<<"enter value to insert"<<endl;
		cin>>value;
		q.enqueue(value);
		break;
		case 2:
		q.dequeue();
		break;
		case 3:
		q.display();
		break;
		case 4:
		q.peak();
		break;
	}
}while(choice!=5);

	return 0;	
}
