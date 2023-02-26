#include<iostream>
#include <bits/stdc++.h>

using namespace std; 

int main(){
    string s = "sushant";
    
    string *str = new string;
    *str = "Hello World";

    str -> append(" Sushant");

    // str->assign("John");

    char alpha = str -> at(2);

    cout << *str << endl;
    cout << alpha << endl;

    cout << str -> back() << endl;

    cout << str -> capacity() << endl;

    cout << *str -> cbegin() << endl;

    sort(s.begin(), s.end());

    cout << s << endl;


    // Taking Input
    string newStr;
    getline(cin, newStr);
    cout << newStr << endl;

    return 0;
}