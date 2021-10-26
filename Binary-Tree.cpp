/*
list of topics:-
    1) Input in binary tree(level order and per-node)
    2) printing binary tree(Level order)
    3) printing binary tree(children first approach)
    4) number of nodes
    5) Tree traversals(preorder,inorder,postorder)
    6) Building binary tree from tree traversals(inorder & preorder)
    7) calculating height and diameter of the binary tree.
*/


#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BTnode {
    public:
    T data;
    BTnode<T>* left;
    BTnode<T>* right;
    BTnode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~BTnode() {
        delete left;
        delete right;
    }
};

void printBtree(BTnode<int> *root) {
    if(root == NULL) {
        return;
    }
    cout<<root->data<<": ";
    if(root->left != NULL) {
        cout<<"L"<<root->left->data<<" ";
    }
    if(root->left != NULL) {
        cout<<"R"<<root->right->data<<" ";
    }
    cout<<endl;
    printBtree(root->left);
    printBtree(root->right);
}

void printLevelWise(BTnode<int>* root) {
    if(root == NULL) {
        return;
    } 
    queue<BTnode<int>*> level;
    level.push(root);
    while(level.size() != 0) {
        BTnode<int>* f = level.front();
        level.pop();
        cout<<f->data<<": ";
        if(f->left != NULL) {
            cout<<"L"<<f->left->data<<" ";
            level.push(f->left);
        }
        if(f->right != NULL) {
            cout<<"R"<<f->right->data<<" ";
            level.push(f->right);
        }
        cout<<endl;
    }
}

BTnode<int>* Input() {
    int val;
    cout<<"Enter value to be entered ";
    cin>>val;
    if(val == -1) {
        return NULL;
    }
    BTnode<int> *root = new BTnode<int>(val);
    BTnode<int> *leftchild = Input();
    BTnode<int> *rightchild = Input();
    root->left = leftchild;
    root->right = rightchild;
    return root;
}

BTnode<int>* InputLevelWise() {
    int val;
    cout<<"Enter value ";
    cin>>val;
    if(val == -1) {
        return NULL;
    }
    BTnode<int>* root = new BTnode<int>(val);
    queue<BTnode<int>*> level;
    level.push(root);
    while(level.size() != 0) {
        BTnode<int> *f = level.front();
        level.pop();
        int val1, val2;
        cout<<"Enter the left element of "<<f->data<<endl;
        cin>>val1;
        if(val1 != -1) {
            BTnode<int>*child = new BTnode<int>(val1);
            f->left = child;
            level.push(child);
        }
        cout<<"Enter the right element of "<<f->data<<endl;
        cin>>val2;
        if(val2 != -1) {
            BTnode<int> *child = new BTnode<int>(val2);
            f->right = child;
            level.push(child);
        }
    }
    return root;
}

int countnodes(BTnode<int>* root) {
    // -----> WAY-1
        // int ans = 1;
        // if(root == NULL) return 0;
        // if(root->left != NULL) {
        //     ans += countnodes(root->left);
        // } 
    
        // if (root->right != NULL) {
        //     ans += countnodes(root->right);
        // }
        // return ans;
        // ----> WAY-2
        if(root == NULL) {
            return 0;
        }

        return 1 + countnodes(root->left) + countnodes(root->right);
}

//left->root->right
void Inorder(BTnode<int>* root) {
    if(root == NULL) {
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

//root->left->right
void Preorder(BTnode<int>* root) {
    if(root == NULL) {
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

//left->right->root
void Postorder(BTnode<int>* root) {
    if(root == NULL) {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

BTnode<int> *buildTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE) {
    if(inS > inE) {
        return NULL;
    }
    int rootdata = pre[preS];
    int rootpos = -1;
    for(int i= inS; i<=inE; i++) {
        if(in[i] == rootdata) {
            rootpos = i;
            break;
        }
    }
    int linS = inS;
    int linE = rootpos - 1;
    int lpreS = preS + 1;
    int lpreE = linE - linS + lpreS;
    int rpreS = lpreE + 1;
    int rpreE = preE;
    int rinS = rootpos + 1;
    int rinE = inE;
    BTnode<int>* root = new BTnode<int>(rootdata);
    root->left = buildTreeHelper(in,pre,linS,linE,lpreS,lpreE);
    root->right = buildTreeHelper(in,pre,rinS,rinE,rpreS,rpreE);

    return root;
}

BTnode<int> * buildTree(int *in, int *pre, int size) {
    return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}

//O(n) - complexity
pair<int,int> heightDiameter(BTnode<int>* root) {
    if(root == NULL) {
        pair<int,int> p;
        p.second = 0;
        p.first = 0;
        return p;
    }
    pair<int,int> leftval = heightDiameter(root->left);
    pair<int,int> rightval = heightDiameter(root->right);
    
    int lh = leftval.first;
    int rh = rightval.first;
    int ld = leftval.second;
    int rd = rightval.second;
    
    int height = 1 + max(lh,rh);
    int diameter = max(lh + rh, max(ld,rd));
    
    pair<int,int> ans;
    ans.first = height;
    ans.second = diameter;

    return ans;
}

int mxElement(BTnode<int>* root) {
    // int ans = INT_MIN;
    if(root == NULL) {
        return INT_MIN;
    } 
    return max(root->data,max(mxElement(root->left), mxElement(root->right)));
} 

// Tree -> 1 2 3 4 5 -1 7 -1 -1 -1 6 -1 8 -1 9 -1 -1 -1 -1

int main() {
    // BTnode<int> *root = new BTnode<int>(1);
    // BTnode<int> *leftchild = new BTnode<int>(2);
    // BTnode<int> *rightchild = new BTnode<int>(3);
    // root->left = leftchild;
    // root->right = rightchild;

    // taking input from user in binary tree
    // BTnode<int> *root = Input();
    BTnode<int> *root = InputLevelWise();
    pair<int,int> p = heightDiameter(root);
    cout<<"Height: "<<p.first<<endl;
    cout<<"Diameter: "<<p.second<<endl;
    // int in[] = {4,2,5,6,9,1,3,7,8};
    // int pre[] = {1,2,4,5,6,9,3,7,8};
    // int size = 9;
    // BTnode<int> *root = buildTree(in, pre, size);
    // printLevelWise(root);
    // int cnt = countnodes(root);
    // cout<<cnt<<endl;
    // Inorder(root);
    // Preorder(root);
    // Postorder(root);
    delete root;
    return 0;
}
