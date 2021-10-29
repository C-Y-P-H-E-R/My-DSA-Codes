#include <bits/stdc++.h>
using namespace std;

class graph {
    public:
        int **adj;
        int *visited;
        int n,e;

        graph(int vert, int edges) {
            e = edges;
            n = vert;
            adj = new int*[n];

            for(int i=0; i<n; i++) {
                adj[i] = new int[n];
                for(int j=0; j<n; j++) {
                    adj[i][j] = 0;
                }
            }
            
            visited = new int[n];
            for(int i=0; i<n; i++) {
                visited[i] = 0;
            }

        }

        void inputAdj() {
            for(int i=0; i<e; i++) {
                int l,r;
                cin>>l>>r;
                adj[l][r] = 1;
                adj[r][l] = 1;
            }
        }

        void DFS(int k) {
            cout<<k<<" ";
            visited[k] = 1;
            for(int i=0; i<n; i++) {
                if(k == i) continue;

                if(adj[k][i] == 1) {
                    if(visited[i]) {
                        continue;
                    }
                    DFS(i);
                }
            }
        }

        void BFS(int k) {
            visited[k] = 1;
            queue<int> q;
            q.push(k);
            
            while(q.size() != 0) {
                int curr = q.front();
                q.pop();
                cout<<curr<<" ";
                for(int i=0; i<n; i++) {
                    if(i == curr) continue;

                    if(adj[curr][i] == 1 && visited[i] != 1) {
                        q.push(i);
                        visited[i] = 1;
                    }   
                }
            }
        }
        
        ~graph() {
            for(int i=0; i<n; i++) {
                delete[] adj[i];
            }
            delete[] adj;
            delete[] visited;
        }
};

void printDFS(graph *g, int sz) {
    for(int i=0; i<sz; i++) {
        if(!g -> visited[i]) {
            g->DFS(i);
        }
    }
}

void printBFS(graph *g, int sz) {
    for(int i=0; i<sz; i++) {
        if(!g -> visited[i]) {
            g -> BFS(i);
        }
    }
}

int main() {

	int n = 7, e = 6;
    // cin>>n>>e;
    graph g(n,e);

    g.inputAdj();

    // int etf;
    // cin>>etf;

    // printDFS(&g, n);

    printBFS(&g, n);

	return 0;
}
