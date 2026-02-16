#include<iostream>
#include<vector>

using namespace std;

// Time Complexity = O(N) + Space Complexity = O(1)
void sortZeroesOnesTwosNaive(vector<int> &arr)
{
    int n = arr.size();
    int k = 0;
    
    for(int i=0; i<n; i++)
    {
        if(arr[i] == 0)
        {
            swap(arr[i], arr[k]);
            k++;
        }
    }
    
    for(int i=0; i<n; i++)
    {
        if(arr[i] == 1)
        {
            swap(arr[i], arr[k]);
            k++;
        }
    }
    
    for(int i=k; i<n; i++)
    {
        arr[i] = 2;
    }
}

// Time Complexity = O(N), Space Complexity = O(1)
void sortZeroesOnesTwosOptimal(vector<int> &arr)
{
    // Dutch National Flag Algorithm.
    int n = arr.size();
    int low = 0, mid = 0, high = n - 1;
    
    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else // arr[mid] == 2
        {
            swap(arr[mid], arr[high]);
            high--;
            // Don't increment mid here!
        }
    }
}

int main()
{
    vector<int> input = {0, 1, 2, 0, 1, 2};
    
    for(auto &x: input)
    {
        cout << x << " ";
    }
    cout << "\n";
    
    // sortZeroesOnesTwosNaive(input);
    sortZeroesOnesTwosOptimal(input);
    
    for(auto &x: input)
    {
        cout << x << " ";
    }
    cout << "\n";
    
    return 0;
}
