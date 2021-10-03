#include <iostream>
using namespace std;

//QUICKSORT 

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

//partitioning function
int partition(int a[], int n, int low, int high) {
    //now take the pivot point of one's choice.
    //here we shall take last element as the pivot point
    int pivot = a[high];
    int i = (low - 1);
    
    for(int j=low; j<=high-1; j++) {
        // sorting the array one step at a time
        if(a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return (i+1);
}

// quicksort function
void quicksort(int a[], int n, int low, int high) {
    if(low < high) {
        // now we need to calculate the partitioning index(or basically),
        // the position of element being put at its correct place per iteration
        int p = partition(a,n,low,high);
        
        // now recursively calling the quicksort function to give result
        quicksort(a,n,low,p-1);
        quicksort(a,n,p+1,high);
    }
}

void printArray(int a[], int n) {
    for(int i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
}

int main() {
    int arr[] = {3, 2 , 5 , 1 , 0, 7, 5, 8};
    int n = 8;
    // parameters : array , size(opt), low and high
    quicksort(arr,n,0,n-1);
    printArray(arr,n);
	return 0;
}
