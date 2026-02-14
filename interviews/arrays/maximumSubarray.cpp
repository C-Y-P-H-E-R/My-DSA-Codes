#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Time Complexity - O(N^3), Space Complexity - O(1)
int maxSumNaive(vector<int> &arr) {
    int n = arr.size();
    if(n == 0) return 0;
    
    int maxSum = INT_MIN;
    for(int i=0; i<n; i++) // Fixed: was i<n-1
    {
        for(int j=i; j<n; j++) 
        {
            int localSum = 0;
            for(int k=i; k<=j; k++)
                localSum += arr[k];
            
            maxSum = max(maxSum, localSum);
        }
    }
    
    return maxSum;
}

// Time Complexity - O(N), Space Complexity - O(1)  // FIXED!
int maxSumBest(vector<int> &arr) {
    int n = arr.size();
    if(n == 0) return 0;
    
    int maxSum = INT_MIN;
    int currSum = 0;
    
    for(int i=0; i<n; i++)
    {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);
        if(currSum < 0)
            currSum = 0;
    }
    
    return maxSum;
}

int main()
{
    vector<int> input = {2, 3, -8, 7, -1, 2, 3};
    // vector<int> input = {-2, -4};
    // vector<int> input = {5, 4, 1, 7, 8};
    
    // int maxSum = maxSumNaive(input);
    int maxSum = maxSumBest(input);
    
    cout << "max sum of a subarray = " << maxSum << "\n"; 
    return 0;
}
