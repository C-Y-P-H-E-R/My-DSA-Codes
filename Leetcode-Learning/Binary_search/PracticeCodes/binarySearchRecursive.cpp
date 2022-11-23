#include <bits/stdc++.h>
using namespace std;

int bsAlgorithmRecursive(vector<int> &v, int low , int high ,int ele) {
    if(low > high) return -1;

    int mid = low + (high - low) / 2;
    
    if(v[mid] == ele) return mid;
    else if(v[mid] < ele) return bsAlgorithmRecursiveHelper(v, mid + 1, high, ele);  
    else if(v[mid] > ele) return bsAlgorithmRecursiveHelper(v, low, mid - 1, ele);

    return -1;
}

int main() {
    vector<int> v = {1,2,6,7,9};

    // recursive binary search
    // bAlgoRecursive(array, low, high, element) 
    int ans = bsAlgorithmRecursive(v, 0, 8, 8);

    cout << ans << "\n";

    return 0;
}
