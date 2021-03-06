/*
Problem Statement: Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window.
I/P: s = "timetopractice"
     t = "toct"
O/P: topract

I/P: s = "a"
     t = "a"
O/P: a
*/

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {

    string result;

    if(s.empty() || t.empty()){
        return result;
    }

    unordered_map<char, int> map;
    unordered_map<char, int> window;

    for(int i = 0; i < t.length(); i++){
        map[t[i]]++;
    }
    int minLength = INT_MAX;
    int letterCounter = 0;
    
    for(int slow = 0, fast = 0; fast < s.length(); fast++){
        char c = s[fast];
        if(map.find(c) != map.end()){
            window[c]++;
            if(window[c] <= map[c]){
                letterCounter++;
            }
        }
      if(letterCounter >= t.length()){
            while (map.find(s[slow]) == map.end() || window[s[slow]] > map[s[slow]])
            {
                window[s[slow]]--;
                slow++;
            }
            if(fast-slow + 1 < minLength){
                minLength = fast - slow + 1;
                result = s.substr(slow, minLength);
            }
        }
    }
    return result;
}

int main(){
    string s;
    cout<<"s: ";
    cin>>s;
    string t;
    cout<<"t: ";
    cin>>t;
    cout<<minWindow(s,t)<<endl;
    
    return 0;
}