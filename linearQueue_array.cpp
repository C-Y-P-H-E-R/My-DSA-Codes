#include <iostream>
using namespace std;

class Queue {
    public:
        int *arr;
        int cap;
        int f;
        int b;
        
        Queue(int n) {
            arr = new int[n];
            cap = n;
            f = -1;
            b = -1;
        }
        
        bool isEmpty() {
            return f == b;
        }
        
        bool isFull() {
            return b - f == cap - 1;
        }
        
        void push(int data) {
            if(isFull()) {
                cout<<"Queue is full!!"<<"\n";
                return;
            }
            if(f == b && f == -1) {
                ++f;
                arr[++b] = data;
                return;
            }
            arr[++b] = data;
        }
        
        int pop() {
            if(isEmpty() && f == -1) {
                cout<<"Queue is Empty!!"<<"\n";
                // f = b = -1;
                f = b = -1;
                return -100000;
            }
            int popped = arr[f];
            f++;
            return popped;
        }
        
        int returnSize() {
            return b - f + 1;
        }
        
        void printQueue() {
            for(int i=f; i<=b; i++) {
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
        
        int front() {
            if(isEmpty()) {
                cout<<"The Queue is empty!!"<<"\n";
                return -100000;
            }
            return arr[f];
        }
        
        int back() {
            if(isEmpty()) {
                cout<<"The Queue is empty!!"<<"\n";
                return -100000;
            }
            return arr[b];
        }
};

int main() {
// 	Queue q(6);
// 	q.push(1);
// 	q.push(2);
// 	q.push(3);
// 	q.push(4);
// 	q.push(5);
// 	q.push(6);
// 	q.push(7);
    
    // q.pop();

    // cout<<q.front()<<"\n";
    // cout<<q.back()<<"\n";
    
// 	q.printQueue();
	
// 	cout<<"Element popped! : "<<q.pop()<<"\n";
// 	cout<<"Element popped! : "<<q.pop()<<"\n";
	
// 	cout<<q.returnSize()<<"\n";
// 	q.printQueue();
	
	return 0;
}
