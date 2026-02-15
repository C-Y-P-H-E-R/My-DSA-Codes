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

// Time complexity = O(N) , Space Complexity = O(1)
Node * removeNthElementFromBegin(Node *head, int N)
{
    if(head == NULL || N < 1)
        return head;
    
    // Special case: removing first node
    if(N == 1) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    Node *curr = head;
    Node *prev = NULL;
    int k = N;
    
    while(curr != NULL && k > 1)
    {
        prev = curr;
        curr = curr->next;
        k--;
    }
    
    // Check if Nth node exists
    if(curr == NULL) {
        return head; // or return NULL based on your requirement
    }
    
    // Remove the node
    prev->next = curr->next;
    delete curr;
    
    return head;
}

Node * removeNthElementFastSlowPtr(Node *head, int N)
{
    if(head == NULL || N < 1)
        return head;
    
    Node *slow = head;
    Node *fast = head;
    
    // Move fast pointer N steps ahead
    for(int i = 0; i < N; i++)
    {
        if(fast == NULL)
            return head; // N is larger than list length
        fast = fast->next;
    }
    
    // Special case: removing the head node
    if(fast == NULL) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    // Move both pointers until fast reaches the last node
    while(fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    // Remove the node after slow
    Node *nodeToBeDeleted = slow->next;
    slow->next = slow->next->next;
    delete nodeToBeDeleted;
    
    return head;
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
    // Node *newHead = removeNthElementFromBegin(head, 2);
    Node *newHead = removeNthElementFastSlowPtr(head, 2);
    Print(newHead);
    
    deleteList(newHead);
    
    return 0;
}
