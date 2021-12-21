/*
Problem Statement:Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.

I/P: Array: 1 3 -1 -3 5 3 6 7
     k = 3
O/P: 3 3 5 6 7

Approach:
The idea is very basic run a nested loop, the outer loop which will mark the starting point of the subarray of length k, the inner loop will run from the starting index to index+k, k elements from starting index and print the maximum element among these k elements. 
Here, Time Complexity: O(N * K). 
      The outer loop runs n-k+1 times and the inner loop runs k times for every iteration of outer loop. So time complexity is O((n-k+1)*k) which can also be written as O(N * K).
      Space Complexity: O(1). 

An Efficient Solution is to use sliding window concept using priority_queue.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> maximumSumSubarray(int k, int *arr , int n){
    vector<int>ans;
    int i = 0, j = 0;
    priority_queue<pair<int,int>>pq;
    while(j<n){
        pq.push({arr[j],j});
        if(j-i+1<k)
        j++;
        else{
            ans.push_back(pq.top().first);
            i++;
            j++;
            while (!pq.empty()&&pq.top().second<i){
                pq.pop();
            } 
        }
    }
    return ans;
}

int main(){

    int arr[] = { 2, 3, -1, -3, 9, 3, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    vector<int>res = maximumSumSubarray(k, arr, n);
    for(int i = 0; i<res.size(); i++)
    cout<<res[i]<<" ";

    return 0;
}