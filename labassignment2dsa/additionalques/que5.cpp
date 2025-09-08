#include <iostream>
using namespace std;
void duplicateTwos(int arr[],int n) {
    int possibleDups=0;
    int length=n-1;
    for (int i=0; i<=length -possibleDups;i++) {
        if (arr[i] ==2) {
            if (i==length-possibleDups) {
                arr[length] = 2;
                length -= 1;
                break;
            }
            possibleDups++;
        }
    }
    for (int i=length-possibleDups;i>=0; i--) {
        if (arr[i]== 2) {
            arr[i+possibleDups] = 2;
            possibleDups--;
            arr[i+possibleDups] = 2;  
        } else {
            arr[i+possibleDups] =arr[i];
        }
    }
}
int main() {
    int arr[]={1, 2, 3, 2, 4};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Original array: ";
    for (int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    duplicateTwos(arr, n);
    cout <<"Modified array: ";
    for (int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
