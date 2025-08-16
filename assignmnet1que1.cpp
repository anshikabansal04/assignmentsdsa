#include<iostream>
using namespace std;
int arr[90];
int size;
void create(){

	cout<<"enter size";
	cin>>size;
		for(int i=0;i<size;i++){
			cout<<"enter elements";
			cin>>arr[i];
		}
		cout<<"array created";
}
void display(){
cout<<"array elements are:";
for(int i=0;i<size;i++){
            cout<<arr[i]<<endl;
        }
}
void insertion()
{
//	create(arr,size);
	int value,posd;
	cout<<"enter val";
	cin>>value;
	cout<<"enter posd";
	cin>>posd;
		for(int j=size-1;j>=posd;j--){
			arr[j+1]=arr[j];		
		}
		arr[posd]=value;
		size++;
	cout<<"emente inseted";
}
void deleted(){

	int pos;
	cout<<"enter pos";
	cin>>pos;
			 for (int i = pos; i < size-1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout<<"elemnt deleted";
}
void linear(){

	int k;
	cout<<"enter key";
	cin>>k;
		for(int i=0;i<size;i++){
			if (arr[i]==k){
				cout<<"key found at"<<i;;
				break;
			}
		}
	
}
void exit(){
	cout<<"exits program";
}
int main(){
	int choice;
	 do{
    cout << "MENU\n";
    cout << "1. CREATE\n";
    cout << "2. DISPLAY\n";
    cout << "3. INSERT\n";
    cout << "4. DELETE\n";
    cout << "5. LINEAR SEARCH\n";
    cout << "6. EXIT\n";
    cout<<"Enter choice:"<<endl;
    cin>>choice;
    
	switch(choice){
		case 1:create();
		break;
		case 2:display();
		break;
		case 3:insertion();
		break;
		case 4:deleted();
		break;
		case 5:linear();
		break;
		case 6:exit();
		break;
		default:
        cout<<"Invalid choice"<<endl;
	}
}while(choice!=6);

	return 0;
}
