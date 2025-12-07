#include<iostream>
#include<stdbool.h>
using namespace std;
#define max 100
bool containsduplicate(int nums[],int n){
    int hash[max]={0};

    for(int i=0;i<n;i++){
    if(hash[nums[i]]==1){
        cout<<"duplicate present"<<endl;
        return true;
    }
    hash[nums[i]]=1;
    }
    return false;
}
int main(){
int nums[] = {1, 2, 3, 1}; 
int n=4;
bool ans=containsduplicate(nums,n);
if(ans){
    cout<<"yes"<<endl;
} 
else{
    cout<<"no"<<endl;
}
return 0;
}
