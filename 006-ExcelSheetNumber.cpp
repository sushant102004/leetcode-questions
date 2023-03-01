/*
Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3

Z -> 26
AA -> 27
AB -> 28 
*/

#include<iostream>
#include <bits/stdc++.h>

using namespace std; 

int excelSheetNumber(string s){
    int ans = 0;
    long long power = 1;
    int size = s.size();

    for(int i = size - 1; i >= 0; i--){
        ans = ans + (s[i] - 64) * power;
        power = power * 26;
    }

    return ans;
}

int main(){
    string s = "AAA";
    cout << excelSheetNumber(s) << endl;
    return 0;
}