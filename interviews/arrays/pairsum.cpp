#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// o(n^2) + o(n) 
vector<int> pairSumNaive(vector<int> &arr, int sum) {
    vector<int> result;
    // Naive
    
    int n = arr.size();
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] + arr[j] == sum)
            {
                result = {arr[i], arr[j]};
                break;
            }
        }
    }
    
    return result;
}


// o(nlogn) + o(n)
vector<int> pairSumBetterApproach1(vector<int> &arr, int sum) {
    // Better Approach 1
    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<n-1; i++)
    {
        int left = i + 1, right = n - 1;
        while(left <= right)
        {
            int middle = left + (right - left) / 2;
            int search = sum - arr[i];
            if(arr[middle] == search) {
                return {arr[i], arr[middle]};
            } else if (arr[middle] < search) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
    }
    
    return {};
}

// o(nlogn) + o(n)
vector<int> pairSumBetterApproach2(vector<int> &arr, int sum) {
    // Better Approach 2
    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    int left = 0, right = n - 1;
    while(left < right) 
    {
        if(arr[left] + arr[right] == sum) {
            return {arr[left] , arr[right]};
        } else if(arr[left] + arr[right] < sum) {
            left = left + 1;
        } else {
            right = right - 1;
        }
    }
    
    return {};
}

// o(n) + o(n)
vector<int> pairSumBest(vector<int> &arr, int sum) {
    // Better Approach 2
    int n = arr.size();
    unordered_map<int, bool> mp; // unit time insert, find and access
    
    for(int i=0; i<n; i++)
    {
        if(mp[sum - arr[i]])
            return {arr[i], sum - arr[i]};
        mp[arr[i]] = true;
    }
    
    return {};
}

int main()
{
    vector<int> input = {0, -1, 2, -3, 1};
    int sum = -2;
    // vector<int> pairSum = pairSumNaive(input, sum);
    // vector<int> pairSum = pairSumBetterApproach1(input, sum);
    // vector<int> pairSum = pairSumBetterApproach2(input, sum);
    // vector<int> pairSum = pairSumBest(input, sum);
    
    if(pairSum.empty())
    {
        cout << "No pairs found" << "\n";
    } else {
        cout << " Pair Sum = " << pairSum[0] << " + " <<  pairSum[1] << " = " << sum << "\n";
    }
    
    return 0;
}
