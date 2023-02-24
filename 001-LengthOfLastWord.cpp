/*
Find length of last word in a string.
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
*/

#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int lengthOfLastWord(string s) {
    int count = 0;
    int i = 0;
    int n = s.size();

    while(i < n){
        if(s[i] != ' '){
            count++;
            i++;
        } else {
            while(i < n && s[i] == ' ') i++;

            if(i == n){
                return count;
            } else count = 0;
        }
    }
    return count;
}

int main(){
    string s = "   fly me   to   the moon  ";
    cout << lengthOfLastWord(s) << endl;
    return 0;
}