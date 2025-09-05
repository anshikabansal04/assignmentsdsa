#include<iostream>
using namespace std;
class stack{
	int top;
	int size;
	int *arr;
	public:
	stack(int size){
		this->size=size;
		top=-1;
		arr=new int [size];
	}
	void  isempty(){
	if(top==-1){
		cout<<"is empty stack";
	}
	else{
		cout<<"not an empty stack"<<endl;
	}
}
	void isfull(){
		if(top==size-1){
			cout<<"stack is full"<<endl;
		}
		else {
			cout<<"not full";
		}
	}
	void display() {
    
        cout<<"Stack elements: ";
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

 void push(int element){
if(top<size-1){
    top++;
    arr[top]=element;
}
else{
    cout<<"overflow";
}
    }
 void pop(){
        if(top>=0){//means top!=-1
            top--;
        }
        else{
            cout<<"underflow"<<endl;
        }

    }
void peek(){
	if(top!=-1){
		cout<<arr[top]<<endl;
	}
	else{
		cout<<"stack empty"<<endl;
	}
}

};
int main(){
stack st(9);
st.push(9);
st.push(10);
st.push(5);
st.pop();
cout<<endl;
st.display();
cout<<endl;
st.peek();
cout<<endl;
st.isfull();
cout<<endl;
st.isempty();
return 0;
}


