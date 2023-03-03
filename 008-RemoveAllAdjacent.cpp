/*
    Input: - abbcarr
    Output: - aca
*/

#include<iostream>
#include <bits/stdc++.h>

using namespace std; 

// Stack Approach
string stackApproach(string s){
    stack<char> st;
    string answer = "";

    for(int i = 0; i < s.size(); i++){
        if(!st.empty() && s[i] == st.top()){
            st.pop();
        } else {
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        answer.push_back(st.top());
        st.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

// Without using extra space
string optimizedApproach(string s){
    int stkPtr = -1;
    string answer = "";

    for(int i = 0; i < s.size(); i++){
        if(stkPtr != -1 && s[i] == s[stkPtr]){
            stkPtr--; 
        } else {
            stkPtr++;
            s[stkPtr] = s[i];
        }
    }
    
    for(int i = 0; i <= stkPtr; i++){
        answer.push_back(s[i]);
    }
    return answer;
}


int main(){
    string s = "abbaca";
    // string ans = stackApproach(s);
    string ans = optimizedApproach(s);
    cout << ans << endl;
    return 0;
}