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
int count;
for(it=freq.begin();it!=freq.end();it++){
  int key=it->first;
  count=it->second;
  int max=INT_MIN;
  if(count>max){
   count=max;
  }
}
cout<<"count is"<<count<<endl;
return 0;
}
