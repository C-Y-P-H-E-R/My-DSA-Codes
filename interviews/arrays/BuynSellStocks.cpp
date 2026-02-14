#include<iostream>
#include<vector>

using namespace std;

// O(N^2) + O(1) space
int bestTimeToBuynSellStocksNaive(vector<int> &arr)
{
    // Naive
    int n = arr.size();
    if(n == 0 || n == 1)
        return 0;
        
    int profit = 0;
    for(int i=0; i<n-1; i++)
    {
        int buyPrice = arr[i];
        for(int j = i+1; j<n; j++)
        {
            int sellPrice = arr[j];
            profit = max(profit, sellPrice - buyPrice);
        }
    }
    
    return profit;
}

// O(N) + O(1) space
int bestTimeToBuynSellStocksBest(vector<int> &arr)
{
    // Best
    int n = arr.size();
    if(n == 0 || n == 1)
        return 0;
        
    int profit = 0;
    int minElement = arr[0];
    for(int i=1; i<n; i++)
    {
        int currElement = arr[i];
        profit = max(profit, arr[i] - minElement);
        minElement = min(arr[i], minElement);
    }
    
    return profit;
}

int main()
{
    vector<int> input = {7, 10, 1, 3, 6, 9, 2};
    // int profit = bestTimeToBuynSellStocksNaive(input);
    int profit = bestTimeToBuynSellStocksBest(input);
    cout << "most profit = " << profit << "\n";
    return 0;
}
