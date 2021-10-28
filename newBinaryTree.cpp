 #include<bits/stdc++.h>
 using namespace std;

class Node {
    public:
        int data;
        Node * left;
        Node * right;

        Node() {
            // Empty constructor
        }

        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class binaryTree {
    public:

        // binaryTree(Node * temp) {
        //     root = temp;
        // }

        void printBinaryTreeLevelWise(Node * temp) {
            if(temp == NULL) {
                cout<<"The tree is empty!!"<<"\n";
                return;
            }
            queue<Node*> q;
            q.push(temp);
            while(q.size() != 0) {
                Node * curr = q.front(); 
                q.pop();

                cout<<curr->data<<" : ";
                if(curr->left != NULL) {
                    q.push(curr->left);
                    cout<<curr->left->data<<" ";
                }
                if(curr->right != NULL) {
                    q.push(curr->right);
                    cout<<curr->right->data;
                }
                cout<<"\n";
            }
        }

        void createBinaryTree(Node * temp) {
            if(temp == NULL) {
                cout<<"The Entered root node is NULL"<<"\n";
                return;
            }
            queue<Node*>q;
            q.push(temp);
            while(q.size() != 0) {
                Node * curr = q.front();
                q.pop();

                int ldata, rdata;
                cin>>ldata>>rdata;
                
                if(ldata != -1) {
                    Node * leftNode = new Node(ldata);
                    curr -> left = leftNode;
                    q.push(leftNode);
                }
                if(rdata != -1) {
                    Node * rightNode = new Node(rdata);
                    curr -> right = rightNode;
                    q.push(rightNode);
                }
         }  
    }  

    int heightBinaryTree(Node * temp) {
        if(temp == NULL) {
            return 0;
        }
        int lh = 0, rh = 0;

        lh += heightBinaryTree(temp -> left);
        rh += heightBinaryTree(temp -> right);

        return max(lh, rh) + 1;
    }

    int countNodes(Node * temp) {
        if(temp == NULL) {
            return 0;
        }
        return 1 + countNodes(temp->left) + countNodes(temp -> right);
    }

    // Traversals
    // preorder : root first, children next
    void preorderTraversal(Node * temp) {
        if(temp == NULL) {
            return;
        }
        cout<<temp -> data<<" ";
        preorderTraversal(temp -> left);
        preorderTraversal(temp -> right);
    }

    // postorder : children first, root next
    void postorderTraversal(Node * temp) {
        if(temp == NULL) {
            return;
        }
        postorderTraversal(temp -> left);
        postorderTraversal(temp -> right);
        cout<<temp -> data<<" ";
    }

    // inorder: left -> root -> right 
    void inorderTraversal(Node * temp) {
        if(temp == NULL) {
            return;
        }
        inorderTraversal(temp -> left);
        cout<<temp -> data<<" ";
        inorderTraversal(temp -> right);
    }

    int maxElement(Node * temp) {
        if(temp == NULL) {
            return INT_MIN;
        }
        return max(temp -> data, max(maxElement(temp -> left), maxElement(temp -> right)));
    }

    // height and diameter of the tree as a pair
    pair<int, int> heightAndDiameter(Node * temp) {
        if(temp == NULL) {
            pair<int,int> p;
            p.first = 0;
            p.second = 0;
            return p;
        }

        pair<int, int> leftD = heightAndDiameter(temp -> left);
        pair<int, int> rightD = heightAndDiameter(temp -> right);

        int lh = leftD.first;
        int rh = rightD.first;
        int ld = leftD.second;
        int rd = rightD.second;

        int height = 1 + max(lh, rh);
        int dia = max(lh + rh, max(ld, rd));

        pair<int, int> ans;
        ans.first = height;
        ans.second = dia;

        return ans;
    }
};

// tree-1 : 2 1 0 -1 -1 -1 -1 -1
// tree-2 : 2 1 -1 -1 -1 -1

 int main() {
    binaryTree tree;

    Node * r = new Node(3);
    tree.createBinaryTree(r);
    // tree.printBinaryTreeLevelWise(r);

    // cout<<"The height of tree : "<<tree.heightBinaryTree(r)<<" ";
    // cout<<"The number of nodes present in the tree is : "<<tree.countNodes(r)<<"\n";
    // cout<<"The maximum element present in the tree is : "<<tree.maxElement(r)<<"\n";

    // cout<<"the height of the tree is : "<<tree.heightAndDiameter(r).first<<" and the diameter is "<<tree.heightAndDiameter(r).second<<"\n";


    return 0;
 }