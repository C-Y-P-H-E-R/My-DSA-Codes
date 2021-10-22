#include <iostream>
using namespace std;

class node {
    public: 
        int data;
        node *next;
        
        node(int d) {
            data = d;
        }
};

class Queue {
    public:
        node *front;
        node *back;
        
        Queue() {
            front = NULL;
            back = NULL;
        }
        
        bool isEmpty() {
            return front == back;
        }
        
        void push(int data) {
            node *newNode = new node(data);
            if(isEmpty() && front == NULL) {
                front = back = newNode;
                return;
            }
            back -> next = newNode;
            back = newNode;
        }
        
        int pop() {
            if(isEmpty() && front == NULL) {
                cout<<"Queue is Empty!!"<<"\n";
                return -100000;
            }
            int popped = front -> data;
            front = front -> next;
            return popped;
        }
        
        int returnSize() {
            node *f1 = new node(-1);
            
            f1 = front;
            
            int cnt = 0;
            while(f1 != back) {
                cnt++;
                f1 = f1 -> next;
            }
            
            delete f1;
            return ++cnt;
        }
        
        void printQueue() {
            node *f1 = new node(-1);
            
            f1 = front;
            if(isEmpty() && front == NULL) {
                cout<<"The Queue is empty!!"<<"\n";
                return;
            }
            
            while(f1 != back) {
                cout<<f1 -> data<<" ";
                f1 = f1 -> next;
            }
            cout<<f1->data<<" ";
            
            cout<<"\n";
            delete f1;
        }
        
        int f() {
            if(isEmpty()) {
                cout<<"The Queue is empty!!"<<"\n";
                return -100000;
            }
            return front->data;
        }
        
        int b() {
            if(isEmpty()) {
                cout<<"The Queue is empty!!"<<"\n";
                return -100000;
            }
            return back->data;
        }
};

int main() {
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
// 	q.push(5);
// 	q.push(6);
// 	q.push(7);
    
    // q.pop();

    // cout<<q.f()<<"\n";
    // cout<<q.b()<<"\n";
    
// 	q.printQueue();
	
// 	cout<<"Element popped! : "<<q.pop()<<"\n";
// 	cout<<"Element popped! : "<<q.pop()<<"\n";
	
	cout<<q.returnSize()<<"\n";
// 	q.printQueue();
	
	return 0;
}
