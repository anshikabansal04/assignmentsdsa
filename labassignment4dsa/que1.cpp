#include <iostream>
using namespace std;
class Queue {
    int front, rear;
    int arr[5];
public:
    Queue() {
        front=-1;
        rear=-1;
    }
    bool isEmpty() {
        return (front==-1);
    }
    bool isFull() {
        return (rear==4);
    }
    void enqueue(int value) {
        if (isFull()) {
            cout <<"Queue is full. Cannot insert "<<value<<endl;
            return;
        }
        if (isEmpty()) {
            front=0;
        }
        rear++;
        arr[rear]=value;
        cout<<value<<"added to the queue."<<endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout<<"Queue is empty. Nothing to delete."<<endl;
            return;
        }
        cout<<arr[front]<<"removed from the queue."<<endl;
        if (front==rear) {
            front=rear=-1; 
        } else {
            front++;
        }
    }
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i=front;i<=rear;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main() {
    Queue q;
    int choice, value;
    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout<<"Enter value to enqueue: ";
                cin>>value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                if (q.isEmpty()) cout << "Queue is empty." << endl;
                else cout << "Queue is not empty." << endl;
                break;
            case 6:
                if (q.isFull()) cout << "Queue is full." << endl;
                else cout << "Queue is not full." << endl;
                break;
            case 0:
             cout << "Exiting program." << endl;
                break;
            default:
                cout<<"Invalid choice! Try again."<<endl;
        }
    } while (choice != 0);
    return 0;
}
