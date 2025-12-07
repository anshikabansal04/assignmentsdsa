#include<iostream>
#include<stdbool.h>
#include<vector>
using namespace std;
#define max 100
using namespace std;
vector<int> commom(int arr[],int brr[],int n1,int n2){
    vector<int>ans;
    int hash[max]={0};
    for(int i=0;i<n1;i++){
        hash[arr[i]]=1;
    }
    for(int i=0;i<n2;i++){
        if(hash[brr[i]]==1){
ans.push_back(arr[i]);
        }
    }
    return ans;
}
int main(){
    int arr[10]={1,2,3,4};
    int brr[10]={3,4,5,6};
vector<int>ans=commom(arr,brr,4,4);
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
}
return 0;
}