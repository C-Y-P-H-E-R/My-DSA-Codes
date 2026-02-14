#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Time complexity - O(N^2) , Space complexity - O(N) -- as the substituent arrays do not grow quadratically
vector<vector<int>> mergeIntervalsNaive(vector<vector<int>> &arr)
{
    // Naive
    int n = arr.size();
    vector<vector<int>> res;
    if(n <= 1)
        return arr;
    
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];
        
        if(!res.empty() && res.back()[1] >= end)
            continue;
        
        for(int j = i + 1; j < n; j++)
            if(arr[j][0] <= end)
                end = max(end, arr[j][1]);
        
        res.push_back({start, end});
        
    }
    
    return res;
}

// Time complexity - O(NlogN) , Space complexity - O(N)
vector<vector<int>> mergeIntervalsBest(vector<vector<int>> &arr)
{
    // Naive
    int n = arr.size();
    vector<vector<int>> res;
    
    if(n <= 1)
        return arr;
    
    sort(arr.begin(), arr.end());
    vector<int> active = arr[0];
    
    for(int i=1; i<n; i++)
    {
        if(arr[i][0] <= active[1])
        {
            active[1] = max(active[1], arr[i][1]);
        } else {
            res.push_back(active);
            active = arr[i];
        }
    }
    
    // if active still is not empty
    if(!active.empty())
        res.push_back(active);
    
    return res;
}

int main()
{
    vector<vector<int>> input = {
        {1,3},
        {2,4},
        {6,8},
        {9,10},
    };
    // vector<vector<int>> input = {{7, 8}, {1, 5}, {2, 4}, {4, 6}};
    // vector<vector<int>> mergedIntervals = mergeIntervalsNaive(input);
    vector<vector<int>> mergedIntervals = mergeIntervalsBest(input);
    
    for(int i=0; i<mergedIntervals.size(); i++)
        cout << mergedIntervals[i][0] << " " << mergedIntervals[i][1] << "\n";
    
    return 0;
}
