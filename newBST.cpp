#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node * left;
        Node * right;

        Node() {
            // empty constructor
        }

        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }

};

class binarySearchTree {
    public:
        void createTree(Node * temp) {
            if(temp == NULL) {
                cout<<"The Root is NULL"<<"\n";
                return;
            }
            queue<Node*> q;
            q.push(temp);
            while(q.size() != 0) {
                Node * curr = q.front();
                q.pop();
                int ldata, rdata;
                cin>>ldata>>rdata;
                if(ldata != -1) {
                    Node * leftNode = new Node(ldata);
                    q.push(leftNode);
                    curr -> left = leftNode;
                }

                if(rdata != -1) {
                    Node * rightNode = new Node(rdata);
                    q.push(rightNode);
                    curr -> right = rightNode;
                }
            }
        }

        void printBST(Node * temp) {
            if(temp == NULL) {
                cout<<"The tree is empty!!"<<"\n";
                return;
            }
            queue<Node*> q;
            q.push(temp);

            while(q.size() != 0) {
                Node * curr = q.front();
                q.pop();

                cout<<curr -> data<<" : ";
                if(curr -> left != NULL) {
                    cout<<curr->left->data<<" ";
                    q.push(curr->left);
                }
                if(curr -> right != NULL) {
                    cout<<curr->right->data<<" ";
                    q.push(curr->right);
                }
                cout<<"\n";
            }
        }

        Node* searchBST(Node * temp, int val) {
            if(temp == NULL) {
                return NULL;
            }
            if(temp -> data == val) {
                return temp;
            }

            if(temp -> data > val) {
                return searchBST(temp -> left, val);
            } else {
                return searchBST(temp -> right, val);
            }
        }

        void printBetween(Node * temp, int l, int r) {
            if(temp == NULL) {
                return;
            }
            if(temp -> data <= r && temp -> data >= l) {
                cout<<temp -> data<<" ";
            }

            if(temp -> data > l) {
                printBetween(temp -> left, l, r);
            } 

            if(temp -> data <= r) {
                printBetween(temp -> right, l, r);
            }
        }
};

// tree-1 : 2 1 0 -1 -1 -1 -1 -1
// tree-2 : 2 1 -1 -1 -1 -1

int main() {
    Node * root = new Node(3);
    binarySearchTree tree;

    tree.createTree(root);
    // tree.printBST(root);
    // if(tree.searchBST(root, 4)) {
    //     cout<<"found!!"<<"\n";
    // } else {
    //     cout<<"Not Found!!"<<"\n";
    // }

    tree.printBetween(root, 1, 2);

    delete root;
    return 0;
}