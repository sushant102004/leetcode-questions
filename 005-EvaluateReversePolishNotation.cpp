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

// Simple Method

int evalMethodTwo(vector<string> &tokens){
    stack<int> st;

    for(auto &i : tokens){
        if(i == "+" || i == "-" || i == "*" || i == "/"){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            if(i == "+") st.push(b + a);
            if(i == "-") st.push(b - a);
            if(i == "*") st.push(b * a);
            if(i == "/") st.push(b / a);
        } else st.push(stoi(i));
    }
    return st.top();
}

int main(){
    vector<string>tokens = {"4","13","5","/","+"};
    cout << evalMethodTwo(tokens);
    return 0;
}