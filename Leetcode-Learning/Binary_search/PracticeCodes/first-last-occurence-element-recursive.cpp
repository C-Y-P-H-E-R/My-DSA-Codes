#include <bits/stdc++.h>
using namespace std;

int findExtremes(vector<int> &v, int low, int high, int ele, char ch) {
    // base condition
    // cout << low << " " << high << " " << ch << "\n";
    if((low + 1) >= high) {
        int toBeReturned = -1;
        
        if(ch == 'l') {
            if(v[low] == ele) toBeReturned = low ;
			
			else if(v[high] == ele) toBeReturned = high ;
			
        } else {
            if(v[high] == ele) toBeReturned = high ;
			
			else if(v[low] == ele) toBeReturned = low ;
        }
		
        return toBeReturned;
    } 
    
    // recursive calls
    int mid = low + (high - low) / 2;
    
    if(v[mid] == ele) {
        if(ch == 'l') {
            // cout 
            return findExtremes(v, low, mid, ele, ch);
        } else {
            return findExtremes(v, mid, high, ele, ch);
        } 
    } else if(v[mid] < ele) {
        return findExtremes(v, mid + 1, high, ele, ch);
    } else if(v[mid] > ele) {
        return findExtremes(v, low, mid - 1, ele, ch);
    }

    return -1;
}

pair<int, int> findExtremesHelper(vector<int> &v, int low, int high, int ele) {
    pair<int,int> temp;
    int mid = low + (high - low) / 2;

    temp.first = findExtremes(v, low, high, ele, 'l');
    temp.second = findExtremes(v, low, high, ele, 'r');

    return temp;
}

int main() {
    
    vector<int> v = {7,7,7,7,7,7,7,7};

    pair<int, int> ans = findExtremesHelper(v, 0, 8, 7);

    cout << ans.first << " " << ans.second << "\n";

    return 0;
}
