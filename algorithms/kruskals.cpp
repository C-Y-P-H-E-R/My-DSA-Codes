#include <bits/stdc++.h>
using namespace std;

// kruskals algorithm for minimum spanning tree

class edge {
    public:
        int beg, end;
        int weight;
        edge() {
            // empty constructor
        }
        edge(int b, int e, int w) {
            beg = b;
            end = e;
            weight = w;
        }
};

bool cmp(edge a, edge b) {
    return a.weight < b.weight;
}

int findParent(int child, int *parent) {
    if(parent[child] == child) {
        return child;
    }
    return findParent(parent[child], parent);
}

void kruskals(edge *ob, int n) {
    int *parent = new int[n];

    for(int i=0; i<n; i++) {
        parent[i] = i;
    }

    int cnt = 0;
    int i=0;
    vector<edge> ans;

    while(cnt != n-1) {
        int sourceParent = findParent(ob[i].beg,parent);
        int destParent = findParent(ob[i].end,parent);

        // this is important to ensure that while finding min. spanning tree, we don't end up creating a cycle.
        if(sourceParent != destParent) {
            edge temp;
            temp.beg = ob[i].beg;
            temp.end = ob[i].end;
            temp.weight = ob[i].weight;
            ans.push_back(temp);
            parent[sourceParent] = destParent;
            cnt++;
        }
        i++;
    }

    for(auto x: ans) {
        if(x.beg < x.end) {
            cout<<x.beg<<" "<<x.end<<" "<<x.weight<<"\n";
        } else {
            cout<<x.end<<" "<<x.beg<<" "<<x.weight<<"\n";
        }
    }

    delete [] parent;
}

int main() {
    int n = 4, e = 5;
    edge *ob = new edge[e]; 

    for(int j = 0; j<e; j++) {
        int b,e,w;
        cin>>b>>e>>w;
        ob[j] = edge(b,e,w);
        // ob[j] = new edge();
    }

    sort(ob, ob + e, cmp);

    kruskals(ob, n);

    delete [] ob;
    return 0;
}
