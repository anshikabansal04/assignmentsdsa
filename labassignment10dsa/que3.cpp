#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
unordered_map<int,int>freq;
int arr[] = {1, 2, 3, 1, 2, 1};
int n = 6;
for(int i=0;i<n;i++){
    freq[arr[i]]=freq[arr[i]]+1;
}
unordered_map<int,int>::iterator it;
for(it=freq.begin();it!=freq.end();it++){
  int key=it->first;
  int count=it->second;
  cout<<key<<"occurrs"<<count<<"times"<<endl;
}
return 0;
}
