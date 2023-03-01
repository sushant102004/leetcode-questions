/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.
*/

#include<iostream>
#include <bits/stdc++.h>

using namespace std; 

bool checkString(string s, int start, int end){
    while(start <= end){
        if(s[start] != s[end]){
            return false;
        }
        start++;
        end--;
    }
    return false;
}

bool isPalidrome(string s){
    int start = 0;
    int end = s.size() - 1;

    while(start <= end){
        if(s[start] != s[end]){
            if(checkString(s, start + 1, end) || checkString(s, start, end - 1)){
                return true;
            } else return false;
        }
        start++;
        end--;
    }
    return true;
};

int main(){
    string s = "abcba";
    cout << isPalidrome(s);
    return 0;
}