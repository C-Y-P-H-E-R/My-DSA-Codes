#include<iostream>
#include<stack>
#include<set>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
        ~Node() {
            
        }
};

void Print(Node *head) {
            while(head != NULL) {
                cout << head->data << " -> ";
                head = head->next;
            }
            cout << " NULL";
            cout << "\n";
        }

// Add this helper function
void deleteList(Node* head) {
    // Break cycle first if present
    Node* curr = head;
    set<Node*> visited;
    
    while(curr != NULL && visited.count(curr) == 0) {
        visited.insert(curr);
        curr = curr->next;
    }
    
    // Now delete all unique nodes
    for(Node* node : visited) {
        delete node;
    }
}

// Time complexity = O(N), space complexity = O(1)
Node * reverseLinkedListIterative(Node *head) 
{
    if(head == NULL || head->next == NULL)
        return head;
    
    Node *prev = NULL;
    Node *curr = head;
    Node *after = head->next;
    
    while(after != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = after;
        after = after->next;
    }
    
    curr->next = prev;
    
    // delete(prev);
    // delete(after);
    
    return curr;
}

// Time Complexity = O(N) , Space Complexity = O(1) + O(N) [recursion stack]
Node * reverseLinkedListRecursive(Node *head)
{
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    Node *newHead = reverseLinkedListRecursive(head->next);
    
    // head->next is the last node in each recursion stage
    head->next->next = head;
    head->next = NULL;
    
    return newHead;
}

// Time Complexity = O(N) , Space Complexity = O(N)
Node * reverseLinkedListUsingStack(Node *head)
{
    if(head == NULL || head -> next == NULL)
        return head;
    
    stack<Node*> s;
    
    // pushing all elements in stack till last
    while(head->next != NULL)
    {
        s.push(head);
        head = head->next;
    }
    
    Node *newHead = head;
    // emptying stack with reversal
    while(!s.empty())
    {
        Node *curr = s.top();
        s.pop();
        
        head -> next = curr;
        curr -> next = NULL;
        head = curr;
    }
    
    return newHead;
}

int main()
{
    Node *head = NULL;
    Node *newNode = new Node(1);
    head = newNode;
    
    // adding remaining nodes 
    newNode = new Node(2);
    head->next = newNode;
    newNode = new Node(3);
    head->next->next = newNode;
    
    Node * curr = head->next->next;
    newNode = new Node(4);
    head->next->next->next = newNode;
    newNode = new Node(5);
    head->next->next->next->next = newNode;
    
    if(head == NULL) {
        cout << "head pointint to null" << "\n";
        return 0;
    }
    
    Print(head);
    // Node *newHead = reverseLinkedListIterative(head);
    // Node *newHead = reverseLinkedListRecursive(head);
    Node *newHead = reverseLinkedListUsingStack(head);
    Print(newHead);
    
    deleteList(newHead);
    
    return 0;
}
