/*
list of topics:-
    1) Input in generic tree(level order and per-node)
    2) printing generic tree(Level order)
    3) printing generic tree(children first approach)
    4) number of nodes
    5) Tree traversals(preorder,postorder)
    7) calculating height of the generic tree.
    8) Depth in generic tree
    9) calculating number of leaf nodes.
*/




#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Treenode {
    public: 
    T data;
    vector<Treenode<T>*> child; 
    Treenode(T data) {
        this->data = data;
    }

    ~Treenode() {
        for(int i=0; i<child.size(); i++) delete child[i];
    }
};

Treenode<int> * Levelwisetakeinput() {
    int rootdata,n;
    cout<<"Enter root data"<<endl;
    cin>>rootdata;
    Treenode<int> *root = new Treenode<int>(rootdata);
    queue<Treenode<int>*> pending;
    pending.push(root);
    while(pending.size() != 0) {
        Treenode<int> *front = pending.front();
        pending.pop();
        cout<<"Enter the no of children of the "<<front->data<<"th root"<<endl;
        cin>>n;
        for(int i=0; i<n; i++) {
            int val;
            cout<<"Enter input for the "<<i+1<<" child"<<endl;
            cin>>val;
            Treenode<int> *ch = new Treenode<int>(val);
            pending.push(ch);
            front->child.push_back(ch);
        }
    }
    return root;
}

void printTree(Treenode<int> *root) {
    if(root == NULL) return;
    cout<<root->data<<":";
    for(int i=0; i<root->child.size(); i++) {
        cout<<root->child[i]->data<<",";
    }
    cout<<endl;
    for(int i=0; i<root->child.size(); i++) {
        printTree(root->child[i]);
    }
}

void printLevelWise(Treenode<int>* root)
{
    if (root==NULL) return;
    queue<Treenode<int> *> q;  // Create a queue
    q.push(root); 
    while (!q.empty())
    {
        int n = q.size();
        while (n > 0)
        {  
            Treenode<int>* p = q.front();
            q.pop();
            cout << p->data << " ";
  
            for (int i=0; i<p->child.size(); i++)
                q.push(p->child[i]);
            n--;
        }
        cout << endl;
    }
}

int Totalnodes(Treenode<int> *root) {
    if(root == NULL) {
        return 0;
    }
    int ans = 1;
    for(int i=0; i<root->child.size(); i++) {
        ans += Totalnodes(root->child[i]);
    }
    return ans;
}

int getHeight(Treenode<int> *root){

    if (root->child.size()==0) {
        return 1;
    }
    int height;
    for (Treenode<int>* childNode  : root->child) {
        int childHeight = getHeight(childNode);
        if (childHeight>height) {
            height = childHeight;
        }
    }
    return height + 1;
}

void depth(Treenode<int> *root, int k) {
    if(k == 0) {
        cout<<root->data<<endl;
    } 
    for(int i=0; i<root->child.size(); i++) {
        depth(root->child[i],k-1);
    }
}

int numleafnode(Treenode<int>* root) {
    int ans = 0,val=-1;
    if(root == NULL) return 0;
    if(root->child.size() == 0) return 1; 
    for(int i=0; i<root->child.size(); i++) {
        ans += numleafnode(root->child[i]);
        val = max(val,ans);
    }
    return val;
}

//root first -> children next
void preorder(Treenode<int> *root) {
    if(root == NULL) {
        return;
    }
    cout<<root->data<<" ";
    for(int i=0; i<root->child.size(); i++) {
        preorder(root->child[i]);
    }
}

//children first -> root last
void postorder(Treenode<int> *root) {
    if(root == NULL) {
        return;
    }
    for(int i=0; i<root->child.size(); i++) {
        preorder(root->child[i]);
    }
    cout<<root->data<<" ";
}

//Tree -> 1 2 2 3 2 4 5 1 7 0 1 6 1 8 1 9 0 0

int main() {
    // Treenode<int> *root = new Treenode<int>(1); 
    // Treenode<int> *ch1 = new Treenode<int>(2);
    // Treenode<int> *ch2 = new Treenode<int>(3);
    // Treenode<int> *ch3 = new Treenode<int>(4);
    // Treenode<int> *root= Levelwisetakeinput();
    // root->child.push_back(ch1);
    // root->child.push_back(ch2);
    // root->child.push_back(ch3);
    // printLevelWise(root);
    // printTree(root);
    // int cnt = Totalnodes(root);
    // cout<<cnt<<endl;
    // int h = getHeight(root);
    // depth(root,1);
    // int n = numleafnode(root);
    // cout<<n<<endl;
    // preorder(root);

    // delete root;
    return 0;
}
