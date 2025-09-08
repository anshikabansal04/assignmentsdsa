
#include <iostream>
#include <string>
using namespace std;
bool isSubstring(const string& sub,const string& str) {
    return str.find(sub) != string::npos;
}
bool canSplitString(const string& s) {
    int n = s.size();
    for (int i=1;i<=n-2;i++) {
        for (int j=i+1; j<=n-1;j++) {
            string A=s.substr(0,i);
            string B=s.substr(i,j-i);
            string C=s.substr(j,n-j);
            if ((isSubstring(A, B) && isSubstring(A, C)) ||
                (isSubstring(B, A) && isSubstring(B, C)) ||
                (isSubstring(C, A) && isSubstring(C, B))) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    if (canSplitString(s)) {
        cout<<"Yes, it can be split"<<endl;
    } else {
        cout<<"No, it cannot be split."<<endl;
    }
  return 0;
}
