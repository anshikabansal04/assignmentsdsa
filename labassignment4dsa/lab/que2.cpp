#include<iostream>
#include<queue>
using namespace std;
class circle{
	int size;
	int front;
	int rear;
	int *arr;
	public:
			circle(int s){
			size=s;
			arr=new int[size];
			front=-1;
			rear=-1;
		}
		bool isfull(){
			return ((front==0 && rear==size-1)||front==rear+1);
		}
		bool isempty(){
			return front==-1;
		}
				void enqueue(int value){
			
			if(isfull()){
				cout<<"queue is full"<<endl;//overflow
			}
			if(isempty()){
				front=rear=0;
			}
			else if(rear==size-1 && front!=0){
				rear=0;
			}
			else{
	
			rear++;}
				arr[rear]=value;
			}
				void dequeue(){
			if(isempty()){
				cout<<"queue is empty"<<endl;//underflow
			}
			if(front==rear){
				front=rear=-1;
			}
		else if(front==size-1){
				front=0;
			}
			else{
				front++;
			}
		}
		void display(){
			cout<<"elements are:"<<endl;
			if(rear>=front){
				for(int i=front;i<=rear;i++){
				cout<<arr[i]<<endl;
			}
			}
			else{
					for(int i=front;i<size;i++){
				cout<<arr[i]<<endl;
			}
				for(int i=0;i<=rear;i++){
				cout<<arr[i]<<endl;
			}
		}
			
		cout<<endl;
		
		}
		void peek(){
			if(isempty()){
				cout<<"empty";
			}
			cout<<arr[front];
		}	
};
int main(){
	circle q(6);
	int choice,value;
	do{
		cout<<"\n---cicular menu---\n";
		cout<<"1.enqueue(insert)----\n";
			cout<<"2.dequeue----\n";
				cout<<"3.display()----\n";
				cout<<"4.peek()----\n";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"enter value to insert"<<endl;
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
					q.peek();
					break;			
		}
	}while(choice!=5);
	return 0;
}
