#include <iostream>
#include <string>
using namespace std;
int main() {
    string str, fstr;
    cout << "Enter a String that you want to print: ";
    getline(cin, str);
    int len = str.length();
    fstr.resize(len);
    for (int i=0; i<len; i++) {
        char ini = 'a';
        while (ini<=str[i]) {
            fstr[i]=ini;
            cout << fstr << endl;
            ini++;
        }
        fstr[i]=str[i];
    }
    return 0;
}
