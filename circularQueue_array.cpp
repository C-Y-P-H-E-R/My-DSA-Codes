#include <iostream>
using namespace std;

class Cqueue {
    public:
        int *arr;
        int f,b;
        int capacity;
        
        Cqueue(int n) {
            arr = new int[n];
            for(int i=0; i<n; i++) {
                arr[i] = 0;
            }
            f = b = -1;
            capacity = n;
        }
        
        bool isFull() {
            return ((b - f == capacity - 1) || (f == b + 1));
        }
        
        bool isEmpty() {
            return ((f == -1 && b == -1) || (f == b + 1));
        }
        
        void push(int data) {
            if(f == b && f == -1) {
                f++;
                arr[++b] = data;
                return;
            }
            
            if(isFull()) {
                cout<<"the queue is full!!"<<"\n";
                return;
            }
            
            if(b == capacity - 1) {
                b = -1;    
            }
            
            arr[++b] = data;
        }
        
        int pop() {
            if(isEmpty()) {
                cout<<"The queue is empty!!"<<"\n";
                f = b = -1;
                return -10000;
            }
            
            int popped = arr[f];
            arr[f] = -1;
            
            if(f == capacity - 1) {
                f = 0;
            } else {
                f++;
            }
            
            return popped;
        }
        
        int returnSize() {
            return (f < b) ? (b - f + 1) : (capacity - (f - b));
        }
        
        void printQueue() {
            if(isEmpty()) {
                cout<<"The queue is empty"<<"\n";
                return;
            }
            for(int i=0; i<capacity; i++) {
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
        
        int front() {
            if(isEmpty()) {
                f = b = -1;
                return -10000;
            }
            return arr[f];
        }
        
        int back() {
            if(isEmpty()) {
                f = b = -1;
                return -10000;
            }
            return arr[b];
        }
};

int main() {
	Cqueue q(5);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
    
    cout<<"the element in the front is: "<<q.front()<<"\n";
    cout<<"the element in the rear is: "<<q.back()<<"\n";
    
	q.pop();
	q.pop();
	
	q.printQueue();
	
	return 0;
}
