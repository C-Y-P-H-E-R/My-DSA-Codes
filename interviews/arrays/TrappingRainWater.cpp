#include<iostream>
#include<vector>

using namespace std;

// Time Complexity = O(N^2) + Space Complexity O(1)
int trappedRainWaterNaive(vector<int> &arr)
{
    // Naive
    int n = arr.size();
    if(n <= 1)
        return 0;
        
    int trappedWater = 0;
    for(int i=1; i<n - 1; i++)
    {
        // finding out largest element on the left
        int leftLargest = arr[i];
        for(int j=0; j<i; j++)
        {
            leftLargest = max(leftLargest, arr[j]);
        }
        
        // finding out largest element on the right
        int rightLargest = arr[i];
        for(int j=i+1; j<n; j++)
        {
            rightLargest = max(rightLargest, arr[j]);
        }
        
        trappedWater += min(leftLargest, rightLargest) - arr[i];
    }
    
    return trappedWater;
}

// Time Complexity = O(N) and Space complexity = O(N)
int trappedRainWaterBetter1(vector<int> &arr)
{
    // Better (Using prefix and suffix max for each index)
    int n = arr.size();
    if(n <= 1)
        return 0;
        
    vector<int> prefix(n, 0);
    vector<int> suffix(n, 0);
    int trappedWater = 0;
    
    int maxPrefix = arr[0];
    prefix[0] = arr[0];
    for(int i=1; i<n; i++) {
        maxPrefix = max(maxPrefix, arr[i]);
        prefix[i] = maxPrefix;
    }
    
    int maxSuffix = arr[n-1];
    suffix[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--) {
        maxSuffix = max(maxSuffix, arr[i]);
        suffix[i] = maxSuffix;
    }
    
    for(int i=0; i<n; i++)
    {
        trappedWater += min(prefix[i], suffix[i]) - arr[i];
    }
    
    return trappedWater;
}

// Time Complexity = O(N) and Space complexity = O(1)
int trappedRainWaterBest(vector<int> &arr)
{
    // Better (Using Two Pointers)
    int n = arr.size();
    if(n <= 1)
        return 0;
    
    int trappedWater = 0;    
    int left = 0, right = n - 1;
    
    int leftLargest = arr[left++];
    int rightLargest = arr[right--];
    while(left <= right)
    {
        if(leftLargest >= rightLargest)
        {
            trappedWater += max(0, rightLargest - arr[right]);
            rightLargest = max(rightLargest, arr[right]);
            right = right - 1;
        } else {
            trappedWater += max(0, leftLargest - arr[left]);
            leftLargest = max(leftLargest, arr[left]);
            left = left + 1;
        }
    }
    
    return trappedWater;
}

int main()
{
    vector<int> input = {3, 0, 1, 0, 4, 0, 2};
    // int trappedWater = trappedRainWaterNaive(input);
    // int trappedWater = trappedRainWaterBetter1(input);
    // int trappedWater = trappedRainWaterBest(input);
    
    cout << "Trapped Water = " << trappedWater << "\n";
    
    return 0;
}
