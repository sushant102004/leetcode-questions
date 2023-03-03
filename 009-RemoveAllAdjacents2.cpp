/*
You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"

*/


#include<iostream>
#include <bits/stdc++.h>

using namespace std;

class Pair {
    public:
        char item;
        int count;
    
    Pair(char item, int count){
        this->item = item;
        this->count = count;
    }
};

string solution(string s, int k){
    stack<Pair>st;
    string ans = "";
    
    for(int i = 0; i < s.size(); i++){
        if(!st.empty() && s[i] == st.top().item){
            st.top().count++;
            if(st.top().count == k) {
                st.pop();
            }
        } else {
            Pair pair = Pair(s[i], 1);
            st.push(pair);
        }
    }

    while(!st.empty()){
        int count = st.top().count;
        for(int i = 0; i < count; i++){
            ans.push_back(st.top().item);
        }
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string s = "deeedbbcccbdaa";
    cout << solution(s, 3);
    return 0;
}