/*
Problem Statement: Given a string S, find the length of the longest substring without repeating characters.
I/P: S= abdefgabef
O/P: 6
Longest substring are "abdefg" , "bdefga" and "defgab".

Approach:
A simple approach is we can consider all substrings one by one and check for each substring whether it contains all unique characters or not. There will be n*(n+1)/2 substrings. Whether a substring contains all unique characters or not can be checked in linear time by scanning it from left to right and keeping a map of visited characters. Time complexity of this solution would be O(n^3).

The problem can be solved in O(n^2). The idea is to use window sliding. Whenever we see repetition, we remove the previous occurrence and slide the window.
*/

#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubstring(string S)
{
    int i = 0, j = 0;
    vector<int> m(26, 0);
    int mx = INT_MIN;
    int ln;
    while (j < S.length()){
        m[S[j] - 'a']++;
        if (m[S[j] - 'a'] == 1){
            mx = max(j - i + 1, mx);
            j++;
        }
        else{
            while (m[S[j] - 'a'] == 2){
                m[S[i++] - 'a']--;
            }
            j++;
        }
    }
    return mx;
}

int main()
{
    string s;
    cout << "s: ";
    cin >> s;

    cout << longestUniqueSubstring(s) << endl;

    return 0;
}
