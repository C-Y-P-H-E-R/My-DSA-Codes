#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        vector<Node*> childNodes;

        Node() {
            // empty constructor
        }

        Node(int d) {
            data = d;
        }
};

class genericTree {
    Node * root;
    int height;
    public:

        genericTree(Node * temp) {
            root = temp;
            height = INT_MIN;
        }

        void createTree() {
            queue<Node*> q;
            q.push(root);
            while(q.size() != 0) {
                Node * curr = q.front();
                q.pop();
                int n;
                cout<<"Enter the number of children for "<<curr->data<<" ";
                cin>>n;
                for(int i=0; i<n; i++) {
                    int val;
                    cout<<"Data to be stored in child number "<<i+1<<" ";
                    cin>>val;
                    Node * newNode = new Node(val);
                    curr -> childNodes.push_back(newNode);
                    q.push(newNode);
                }
            }
            cout<<"\n";
        }
   
        void insertNode(int d, int parent) {
            if(root == NULL) {
                root -> data = d;
                return;
            }
            Node * newNode = new Node(d);
            queue<Node*> pending;
            pending.push(root);

            while(pending.size() != 0) {
                Node * curr = pending.front();
                pending.pop(); 
                if(curr -> data == parent) {
                    curr -> childNodes.push_back(newNode);
                    break;
                }
                for(int i=0; i<curr -> childNodes.size(); i++) {
                    pending.push(curr -> childNodes[i]);
                }
            }
        }

        void printTreeLevelWise() {
            if(root == NULL) {
                cout<<"The tree is empty!!"<<"\n";
                return;
            }
            queue<Node*> pending;
            pending.push(root);

            while(pending.size() != 0) {
                Node * curr = pending.front();
                pending.pop();
                cout<<curr -> data<<" : ";

                if(curr -> childNodes.size() == 0) {
                    cout<<"No children";
                }  else {
                    for(int i=0; i<curr->childNodes.size(); i++) {
                        cout<<curr -> childNodes[i] -> data<<" ";
                        pending.push(curr -> childNodes[i]);    
                    }
                }

                cout<<"\n";
            }
        }

        int totalNodes() {
            if(root == NULL) {
                return 0;
            }
            queue<Node*> q;
            q.push(root);
            int cnt = 0;
            while(q.size() != 0) {
                Node * curr = q.front();
                q.pop();
                for(int i=0; i<curr->childNodes.size(); i++) {
                    q.push(curr->childNodes[i]);
                }
                cnt++;
            }
            return cnt;
        }

        int totalNodesRecursively(Node * temp) {
            if(root == NULL) {
                return 0;
            }
            int ans = 1;
            for(int i=0; i<temp->childNodes.size(); i++) {
                ans += totalNodesRecursively(temp -> childNodes[i]);
            }
            return ans;        
        }

        int heightRecursively(Node * temp) {
            if(temp == NULL) {
                height = 0;
                return height;
            }
            if(temp -> childNodes.size() == 0) {
                return 1;
            }
            for(int i=0; i<temp->childNodes.size(); i++) {
                int h = heightRecursively(temp->childNodes[i]);
                if(h > height) {
                    height = h;
                }    
            }
            return ++height;
        }

        void depthRecursively(Node * temp , int k) {
            if(temp == NULL) {
                return;
            }
            if(k == 0) {
                cout<<"Element : "<<temp -> data<<"\n";
            }
            for(int i=0; i<temp->childNodes.size(); i++) {
                depthRecursively(temp->childNodes[i], k-1);    
            }
        }

        int numOfLeafNodesRecursively(Node * temp) {
            if(temp->childNodes.size() == 0) {
                return 1;
            }
            int n = 0;
            for(int i=0; i<temp->childNodes.size(); i++) {
                n += numOfLeafNodesRecursively(temp->childNodes[i]);
            }
            return n;
        }

        //traversals
        // pre-order traversal --> root first, children next
        void preorderTraversal(Node * temp) {
            if(temp == NULL) {
                return;
            }
            cout<<temp->data<<" ";
            for(int i=0; i<temp->childNodes.size(); i++) {
                preorderTraversal(temp->childNodes[i]);
            }
        }

        //post-order traversal --> children first, root last
        void postorderTraversal(Node * temp) {
            if(temp == NULL) {
                return;
            }
            for(int i=0; i<temp->childNodes.size(); i++) {
                postorderTraversal(temp->childNodes[i]);
            }
            cout<<temp->data<<" ";
        }
};

int main() {
	// your code goes here
    int rootData = 3;
    Node *r = new Node(rootData);

    genericTree tree(r);
    // tree.insertNode(1,3);
    // tree.insertNode(2,3);
    // tree.insertNode(4,2);
    tree.createTree();
    // tree.insertNode(4,2);

    // cout<<"The Height of tree : "<<tree.heightRecursively(r)<<"\n";
    // tree.depthRecursively(r,0);
    // cout<<"number of leaf nodes: "<<tree.numOfLeafNodesRecursively(r)<<"\n";
    // tree.printTreeLevelWise();
    // tree.preorderTraversal(r);
    // tree.postorderTraversal(r);
	return 0;
}

