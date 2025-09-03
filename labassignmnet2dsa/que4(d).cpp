#include <iostream>
#include <string>
#include <vector>
using namespace std;
void alphabetical(vector<string>&arr, int n) {
    for (int i = 0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if (arr[i]>arr[j]) {
                string temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout <<"Strings in alphabetical order:\n";
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<endl;
    }
}

int main() {
    int n;
    cout<<"Enter number of strings: ";
    cin>>n;

    cin.ignore();

    vector<string> arr(n);
    for (int i=0; i<n;i++) {
        cout<<"Enter string"<<i+1<< ": ";
        getline(cin,arr[i]);
    }
    alphabetical(arr,n);
   return 0;
}


