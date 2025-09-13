#include <iostream>
#include <algorithm>
using namespace std;
bool canBeSorted(int arr[],int n) {
    int sortedarr[100];     
    for (int i=0;i<n;i++) 
    sortedarr[i]=arr[i];
    sort(sortedarr,sortedarr+n);
    int s[100], top = -1; 
    int b[100], bIndex = 0;
    int j = 0;           
    for (int i =0;i<n;i++) {
        s[++top]=arr[i];
        
        while (top>=0 && s[top] == sortedarr[j]) {
            b[bIndex++]=s[top--];
            j++;
        }
    }
    if (bIndex==n) {
        cout << "yes final array is: "<<endl;
        for (int i=0;i<n;i++) 
        cout<<b[i]<<" ";
        cout<<endl;
        return true;
    } else {
        cout<<"no";
        return false;
    }
}
int main() {
    int arr[]={3, 1, 2}; 
    int n=sizeof(arr)/sizeof(arr[0]);
    canBeSorted(arr,n);
    return 0;
}
