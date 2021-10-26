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

BTnode<int> * searchBST(BTnode<int>* root, int v) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data == v) {
        return root;
    } else if(v < root->data) {
        return searchBST(root->left, v);
    } else {
        return searchBST(root->right, v);
    }
}

void printBetween(BTnode<int>* root, int l, int r) {
    if(root == NULL) {
        return;
    }
    if(root->data >= l && root->data<=r) {
        cout<<root->data<<endl;
    }
    if(root->data > l) {
        printBetween(root->left, l, r);
    }
    if(root->data <= r) {
        printBetween(root->right, l, r);
    }
}

// Tree -> 1 2 3 4 5 -1 7 -1 -1 -1 6 -1 8 -1 9 -1 -1 -1 -1

int main() {
    BTnode<int>* root = InputLevelWise();
    // printLevelWise(root);
    // printBetween(root,1,2);
    BTnode<int> *ans = searchBST(root,2);
    if(ans == NULL) {
        cout<<"Value not present"<<endl;
    } else {
        cout<<ans->data<<endl; 
    }
    delete root;
    return 0;
}