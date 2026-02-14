
#include<iostream>
#include<vector>
#include<algorithm>

// Insert and Merge Interval

using namespace std;

// Time Complexity - O(N^2) , Space Complexity - O(N)
vector<vector<int>> mergeIntevalNaive(vector<vector<int>> &arr)
{
    int n = arr.size();
    if(n <= 1)
        return arr;
    
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    
    for(int i=0; i<n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];
        
        if(!res.empty() && res.back()[1] >= end)
            continue;
        
        for(int j = i + 1; j < n; j++) {
            if(arr[j][0] <= end)
                end = max(end, arr[j][1]);
        }
        
        res.push_back({start, end});
    }
    
    return res;
}

// Time Complexity - O(NlogN) , Space Complexity - O(N)
vector<vector<int>> mergeIntevalBest(vector<vector<int>> &arr)
{
    int n = arr.size();
    if(n <= 1)
        return arr;
    
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    vector<int> active = arr[0];
    
    for(int i=1; i<n; i++)
    {
        if(arr[i][0] <= active[1]) {
            active[1] = max(active[1], arr[i][1]);
        } else {
            res.push_back(active);
            active = arr[i];
        }
    }
    
    if(!active.empty())
        res.push_back(active);
    
    return res;
}

vector<vector<int>> InsertOrMergeIntervals(vector<vector<int>> &arr, vector<int> &newInterval)
{
    arr.push_back(newInterval);
    return mergeIntevalNaive(arr);
}

int main()
{
    vector<vector<int>> input = {{1, 3}, {4, 5}, {6, 7}, {8, 10}};
    vector<int> newInterval = {5, 6};
    vector<vector<int>> output = InsertOrMergeIntervals(input, newInterval);
    
    for(auto &x: output)
        cout << x[0] << " " << x[1] << "\n";
    
    return 0;
}
