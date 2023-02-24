/*
    Find longest common prefix in several strings.
*/

#include<iostream>
#include <bits/stdc++.h>

using namespace std; 

string longestCommonPrefix(vector<string>s){
    string result = "";

    if(s.size() == 0){
        return "";
    }

    for(int i = 0; i < s[0].size(); i++){
        for(int j = 1; j < s.size(); j++){
            if(s[j][i] != s[0][i]){
                return result;
            }
        }
        result += s[0][i];
    }
    return result;
}

int main(){
    vector<string> s;
    s.push_back("flower");
    s.push_back("flow");

    string result = longestCommonPrefix(s);
    cout << result << endl;
    return 0;
}