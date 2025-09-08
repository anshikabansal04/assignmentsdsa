#include <iostream>
using namespace std;
int countPairsWithDiffK(int arr[],int n,int k) {
    int count=0;
    for (int i=0;i<n-1;i++) {
        for (int j =i+1;j<n;j++) {
            if (arr[i]-arr[j] == k||arr[j]-arr[i]==k) {
                count++;
                cout << "(" << arr[i]<< ", "<<arr[j]<< ")"<<endl;
            }
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << "Pairs with difference "<<k<<":"<< endl;
    int totalPairs=countPairsWithDiffK(arr, n, k);
    cout << "Total pairs: " << totalPairs << endl;
    return 0;
}
