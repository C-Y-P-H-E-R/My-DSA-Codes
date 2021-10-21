#include <iostream>
using namespace std;

class node {
  public:
    int key;
    int data;
    node *next;
    
    node() {
        key = -2;
        data = -2;
        next = NULL;
    }
    
    node(int k, int d) {
        key = k;
        data = d;
        next = NULL;
    }
};

class stack {
    public: 
        
    node *top;
        
        stack() {
            top = NULL;
        }
        
        bool isEmpty() {
            return top == NULL;
        }
        
        int returnSize() {
            return this->top->key;
        }
        
        void push(int k, int d) {
            node* newNode = new node(k,d);
            if(isEmpty()) {
                top = newNode;
                // cout<<top->data<<" ";
                return;
            }
            newNode -> next = top;
            top = newNode;
        }

        int pop() {
            if(isEmpty()) {
                cout<<"Stack Underflow"<<"\n";
                return -1;
            }
            node *temp = new node;
            temp = top; 
            top = top->next;
            return temp->data;
        }
        
        int peek() {
            return top->data;
        }
        
        void printStack() {
            node *curr = new node;
            curr = top;
            while(curr != NULL) {
                cout<<curr->data<<" ";
                curr = curr->next;
            }
            // cout<<curr->data<<endl;
            delete curr;
        }
};


int main() {
	stack s;
	s.push(1,3);
	s.push(2,6);
	s.push(3,9);
	s.push(4,12);
	s.push(5,15);
// 	s.pop();
    
    // s.printStack();
    
    // cout<<"this was popped!! - "<<s.pop()<<"\n";
    // cout<<s.peek()<<"\n";
    cout<<s.returnSize()<<"\n";
	return 0;
}
