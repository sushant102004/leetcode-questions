//Evaluate Postfix expression

#include<iostream>
#include <bits/stdc++.h>

using namespace std;

bool isOperand(string &token){
    return (token[0] >= '0' && token[0] <= '9');
}

int evaluate(string &oprtr, int &a, int &b){
    if(oprtr == "+") return a + b;
    else if(oprtr == "-") return a - b;
    else if(oprtr == "*") return a * b;
    return a / b;
}

int evalPostxi(vector<string> tokens){
    stack<int> st;

    for(auto &i : tokens){
        if(isOperand(i)) st.push(stoi(i));
        else {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            st.push(evaluate(i, a, b));
        }
    }
    return st.top();
}

int main(){
    vector<string>tokens = {"2","1","+","3","*"};
    cout << evalPostxi(tokens);
    return 0;
}