#include<iostream>
#include <bits/stdc++.h>

using namespace std; 

// Using Stack

int main(){
    string s = "hello world";
    stack<char> st;
    int i = 0;
    
    for(int i = 0; i < s.size(); i++){
        st.push(s[i]);
    }

    while(!st.empty()){
        s[i] = st.top();
        st.pop();
        i++;
    }

    cout << s << endl;

    return 0;
}