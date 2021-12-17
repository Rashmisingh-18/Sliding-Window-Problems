/*
Problem Statement: Given an array of integers and a number k, find the maximum sum of a subarray of size k.
I/P: Given Array: 2 5 1 8 2 9 1
     Window Size: 3
O/P: 19

Approach:
1) The basic idea is a nested loop, the outer loop which will mark the starting point of the subarray of length k, the inner loop will run from the starting index to (index + k), k elements from starting index and print the maximum element among these k elements. This uses two for which, so Time Complexity: O(N * K).
The outer loop runs n-k+1 times and the inner loop runs k times for every iteration of outer loop. So time complexity is O((n-k+1)*k) which can also be written as O(N * K) and Space Complexity: O(1)

2) To optimize it, and to reduce time complexity; an efficient solution is that sum of a subarray (or window) of size k can be obtained in O(1) time using the sum of the previous subarray (or window) of size k. Except for the first subarray of size k, for other subarrays, we compute the sum by removing the first element of the last window and adding the last element of the current window. Here, the Time Complexity: O(n) and Auxiliary Space: O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

int maximumSumSubarray(int k, vector<int> &arr , int n){
       int i = 0, j = 0, sum = 0, mx = INT_MIN;
       
       while(j < n)
       {
           sum = sum + arr[j];
           
           if(j - i + 1 < k)
               j++;
               
           else if(j - i + 1 == k)
           {
               mx = max(mx, sum);
               sum = sum - arr[i];
               i++;
               j++;
           }
       }
       
       return mx;
   }

int main()
{
    int n, k;
    cout<<"n: ";
    cin>>n;
    cout<<"k: ";
    cin>>k;
    cout<<"Input values in array: ";
    vector <int> arr;
    for(int i = 0 ; i < n ; i++ ){
        int x; 
        cin>> x; 
        arr.push_back(x);
    }
    cout<<"The maximum sum of subarray of size "<< k <<" is: ";
    cout << maximumSumSubarray(k, arr , n);
    return 0;
}