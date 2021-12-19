/*
Problem Statement:Given an array and a positive long longeger k, find the first negative long longeger for each window of size k. If a window does not contain a negative long longeger, then prlong long -1 for that window.
I/P: Given Array: -2 5 -1 -8 2 9 -1
     Window Size (k): 3
O/P: -2 -1 -1 -8 -1

Approach:
1) The very basic method is: Run two loops. In the outer loop, take all subarrays(windows) of size k. In the inner loop, get the first negative long longeger of the current subarray(window). This uses two for which, so Time Complexity: O(N * K). The outer loop runs n-k+1 times and the inner loop runs k times for every iteration of outer loop. So time complexity is O((n-k+1)*k) which can also be written as O(N * K) and Space Complexity: O(1)

2) To optimize it, and to reduce time complexity; an efficient solution is using sliding window method as discussed in previous problem. Here, the Time Complexity: O(n) and Auxiliary Space: O(1)
*/
#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<long long> FirstNegativeInteger(long long int arr[], long long int n, long long int k);

int main()
{
    long long int i, n, arr[n], k;
    
    cout << "n: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "k: ";
    cin >> k;
    vector<long long> ans = FirstNegativeInteger(arr, n, k);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}

vector<long long> FirstNegativeInteger(long long int arr[], long long int n, long long int k)
{
    int i = 0, j = 0;
    list<long long> l;
    vector<long long> v;

    while (j < n)
    {
        if (arr[j] < 0)
            l.push_back(arr[j]);
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            if (l.size() == 0)
                v.push_back(0);
            else
            {
                v.push_back(l.front());
                if (arr[i] == l.front())
                    l.pop_front();
            }
            i++;
            j++;
        }
    }
    return v;
}

