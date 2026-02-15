#include<iostream>
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
            this->next = NULL;
        }
};

void Print(Node *head) {
            while(head != NULL) {
                cout << head->data << " ->";
                head = head->next;
            }
            cout << " ->";
            cout << "\n";
        }

// Time complexity = O(N) , space complexity = O(N)    
bool DetectCycleUsingHashSet(Node* head) {
    if(head == NULL || head->next == NULL)
        return false;

    Node * curr = head;
    set<Node*> s;
    while(curr != NULL)
    {
        if(s.count(curr) > 0)
            return true;
        
        s.insert(curr);
        curr = curr -> next;
    }
    
    return false;
}

// Time complexity = O(N) and Space Complexity = O(1)
bool DetectCycleUsingFastSlowPtr(Node * head)
{   
    // Using floyd's Fast and Slow ptrs
    if(head == NULL || head->next == NULL)
        return false;
    
    Node *fast = head;
    Node *slow = head;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
        
        if(slow == fast)
            return true;
    }
    
    return false;
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
    
    
    // bool isCyclic = DetectCycleUsingHashSet(head);
    bool isCyclic = DetectCycleUsingFastSlowPtr(head);
    if(isCyclic)
        cout << "There is a cycle present !" << "\n";
    else
        cout << "No cycle Present" << "\n";
    
    // Print(head);
    deleteList(head);
    return 0;
}
