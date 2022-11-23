#include <bits/stdc++.h>
using namespace std;

int searchInCircularlySorted(vector<int> &v, int ele) {
    int n = v.size();

    int low = 0, high = n-1;
    int mid;

    while(low <= high) {

        mid = low + (high - low) / 2;

        // if the target element is found, return index;
        if(v[mid] == ele) return mid;

        // if the mid element is smaller than the element on the high end
        // then check if the target element lies in between the mid and the high element
        // assign values based on the results
        if(v[mid] <= v[high]) {
            if(ele > v[mid] && ele <= v[high]) {    
                low = mid + 1;
            } else {    
                high = mid - 1;
            }
        } 
        // if the mid element is larger than the element on the high end
        // then too check if the target element lies in the interval between mid and low 
        else {
            if(ele < v[mid] && ele >= v[low]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
    }

    return -1;
}

int main() {
    vector<int> v = {9,1,2,3,4,5,6,7,8};

    // searching for an element in a  circularly sorted array
    int ans = searchInCircularlySorted(v, 8);
    
    if(ans != -1) {
        cout << "the element found at pos: " << ans << "\n";
    } else {
        cout << "no such element exists!" << "\n";
    }

    return 0;
}
