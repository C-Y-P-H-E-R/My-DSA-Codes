#include <bits/stdc++.h>
using namespace std;

int countRotations(vector<int> &v) {
    int n = v.size();

    // idea is to modify binary search to find an element having larger elements on both sides.
    // once done, this its index would give the number of rotations that took place.

    int low=0, high=n-1;
    int mid;

    while(low <= high) {
        
        // if the array is originally sorted
        // then return the first index as answer (0)
        // means no rotations have taken place
        if(v[low] <= v[high]) return low;

        mid = low + (high - low) / 2;

        // calculating the elements adjacent to mid
        // in circular fashion
        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;

        // if mid element is smaller than both next element and prev element
        // return mid
        if(v[mid] <= v[next] && v[mid] <= v[prev]) {
            return mid;
        }
        else if(v[mid] <= v[high]) {
            // the right part of array is sorted.
            // the answer must exist in the left part
            high = mid - 1;
        } else if(v[mid] >= v[low]) {
            low = mid + 1;
        } else if(v[mid] <= v[high]) {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> v = {9,1,2,3,4,5,6,7,8};

    int ans = countRotations(v);

    (ans == -1) ? 
    cout << "rotations not possible!" << "\n" : 
    cout << "the number of rotations is: " << ans << "\n";
    
    return 0;
}
