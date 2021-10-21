#include <iostream>
using namespace std;


class stack {
    
    public: 
    int top;
    int *arr;
    int capacity;
    
    stack(int n) {
        this->arr = new int[n];
        this->top = -1;
        this->capacity = n; 
    };
    ~stack() {
        delete [] arr;
    };
    void push(int x) {
        if(this->isFull()) {
            cout<<"Stack overflow"<<"\n";
            return;
        }
        this->arr[++top] = x;
    };
    int pop() {
        if(top == -1) {
            cout<<"Underflow"<<"\n";
            return -1;
        }
        // cout<<(this->arr[top])<<"\n";
        return this->arr[top--];
        
    };
    
    int returnSize() {
        return (this->top + 1);
    }
    
    bool isFull() {
        return this->top == (this->capacity - 1);
    }
    
    bool isEmpty() {
        return this->top == -1;
    }
    
    int peek() {
        return this->arr[top];
    }
};  

int main() {
	stack s(3);
	s.push(1);
	s.push(3);
	s.push(4);
// 	s.pop();
	cout<<s.pop()<<"\n";
// 	s.pop();
// 	cout<<s.returnSize()<<"\n";
    cout<<s.peek()<<"\n";
	return 0;
}
