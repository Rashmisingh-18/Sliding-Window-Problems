/*
Problem Statement: Given a text txt and a word pat. Return the count of the occurences of anagrams of the word in the text.
I/P: txt = foxrofxdox
     pat = fox
O/P: 3

Approach:
A simple approach is to traverse from start of the string considering substrings of length equal to the length of the given word and then check if this substring has all the characters of word.

An Efficient Solution is to use sliding window concept.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int search(string pat, string txt) {
	    unordered_map<char, int> m;
        for(auto it : pat) 
            m[it]++;
        int k=pat.length();
        int count=m.size();
        int i=0, j=0;
        int ans=0;
        while(j<txt.length()){
            if(m.find(txt[j])!=m.end()){
                m[txt[j]]--;
                if(m[txt[j]]==0) count--;
            }
            if((j-i+1)<k) j++;
            else if((j-i+1)==k){
                if(count==0) ans++;
                if(m.find(txt[i])!=m.end()){
                    m[txt[i]]++;
                    if(m[txt[i]]==1) count++;
                }
                i++;
                j++;
            }
        }
        return ans;
	}

int main(){
    string pat, txt;
    cout<<"Enter text (txt): ";
    cin>>txt;
    cout<<"Enter word (pat): ";
    cin>>pat;
    int ans = search(pat, txt);
    cout<<ans;

    return 0;
}