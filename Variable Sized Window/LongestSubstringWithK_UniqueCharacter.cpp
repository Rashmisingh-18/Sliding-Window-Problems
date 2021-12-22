/*
Problem Statement:Given a string you need to print longest possible substring that has exactly k unique characters. If there are more than one substring of longest possible length, then print any one of them.
I/P: String: aabacbebebe
     k = 3
O/P: aabac
"cbebebe" is the longest substring with K distinct characters.

Approach:
If the length of string is n, then there can be n*(n+1)/2 possible substrings. A simple way is to generate all the substring and check each one whether it has exactly k unique characters or not. If we apply this brute force, it would take O(n2) to generate all substrings and O(n) to do a check on each one. Thus overall it would go O(n3).

The problem can be solved in O(n). Idea is to maintain a window and add elements to the window till it contains less or equal k, update our result if required while doing so. If unique elements exceeds than required in window, start removing the elements from left side. 
*/

#include <bits/stdc++.h>
using namespace std;

int KUniqueCharacters(string s, int k){
    unordered_map<char,int>mp;
    int j=0, i=0, mx=-1;
    while(j<s.size()){
        mp[s[j]]++;
        if(mp.size()<k)
        j++;
        else if(mp.size()==k){
            mx=max(mx,j-i+1);
            j++;
        }
        else if(mp.size()>k){
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return mx;
}

int main(){
    string s;
    cout<<"s: ";
    cin>>s;
    int k;
    cout<<"k: ";
    cin>>k;
    cout<<KUniqueCharacters(s,k)<<endl;
    
    return 0;
}