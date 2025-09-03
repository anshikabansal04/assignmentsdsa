#include <iostream>
#include <string>
using namespace std;
string convert(string str, int n) {
    for (int i = 0; i < n; i++) { 
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a'; 
        }
    }
    return str; 
}
int main() {
    string str, str2;
    cout << "enter string: ";
    getline(cin, str);
    int n = str.length();
    str2 = convert(str, n);
    cout << "Converted string: " << str2 << endl;
    return 0;
}

