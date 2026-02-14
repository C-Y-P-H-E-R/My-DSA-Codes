#include<iostream>
#include<vector>

using namespace std;

// Time Complexity - O(N^2) + Space Complexity O(1)
int containerWithMaxWaterNaive(vector<int> &arr)
{
    // naive
    int n = arr.size();
    int maxWater = 0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int vertical = min(arr[i], arr[j]);
            maxWater = max(maxWater, vertical * (j - i));
        }
    }
    
    return maxWater;
}

// Time Complexity = O(N), Space Complexity = O(1)
int containerWithMaxWaterBest(vector<int> &arr)
{
    // Best
    int n = arr.size();
    int left = 0, right = n - 1;
    int maxWater = 0;
    while(left < right)
    {
        int vertical = min(arr[left], arr[right]);
        maxWater = max(maxWater, vertical * (right - left));
        if(arr[left] == vertical)
        {
            left = left + 1;
        } else {
            right = right - 1;
        }
    }
    
    return maxWater;
}



int main()
{
    vector<int> input = {1, 5, 4, 3};
    int maxWater = containerWithMaxWaterBest(input);
    cout << "max water to that can be stored = " << maxWater << "\n";
    return 0;
}
