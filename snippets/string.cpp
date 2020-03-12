#include <string>
#include <iostream>

using namespace std;

int main() {
    string s1 = "hello";
    string s2 = "hello";
    // !=, <, >, <=, >=, operators is removed in c++20, only == and <=>(c++20) remain
    if (s1 == s2) cout << "two strings are the same\n";

    string s3 = s1 + " " + s2;
    cout << s3 << endl;
    cout << "the length of s3 is " << s3.size() << endl;
    cout << "the second char of s3 is " << s3[1] << endl;

    // change to c-string
    const char* str = s3.c_str();
    cout << str << endl;

    string s4 = s3.substr(6);
    cout << "the substr s4 is " << s4 << endl;
    s4 += " world!";
    cout << s4 << endl;

    cout << hash<string>{}(s4) << endl;






    return 0;
}