#include <bits/stdc++.h>
using namespace std;
#define sz 6


class DirectedGraph {
    public: 
    int n, e;
    vector<int> adj[sz];

        DirectedGraph(int vertices, int edges) {
            n = vertices;
            e = edges;
        }

        void input() {
            for(int i=0; i<e; i++) {
                int beg, end;
                cin>>beg>>end;
                adj[beg].push_back(end);
            }
        }

        ~DirectedGraph() {
            // empty destructor
        }

        void topologicalSortDFS(int curVertex,int *visited,vector<int> &toposorted) {
            visited[curVertex] = 1;
            for(auto it: adj[curVertex]) {
                if(!visited[it]) {
                    topologicalSortDFS(it, visited, toposorted);
                }
            }
            toposorted.push_back(curVertex);
        }
};

int main() {
    int n = 6, e = 7;
    DirectedGraph d(n,e);
    
    d.input();

    int *visited = new int[n];
    for(int i=0; i<n; i++) {
        visited[i] = 0;
    }

    // d.topologicalSort(visited);
    vector<int> toposorted;
    d.topologicalSortDFS(0,visited, toposorted);
    reverse(toposorted.begin(), toposorted.end());

    for(auto x: toposorted) {
        cout<<x<<" ";
    }

    delete [] visited;

    return 0;
}
