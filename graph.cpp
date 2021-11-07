#include <bits/stdc++.h>
using namespace std;

class graph {
    public:
        int **adj;
        int *visited;
        int n,e;
        static int findPathVar;

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

        void hasPathDFS(int &ans, int start, int end) {
            visited[start] = 1;
            if(start == end) {
                ans = 1;
                return;
            }

            for(int i=0; i<n; i++) {
                if(start == i) continue;

                if(adj[start][i] == 1 && !visited[i]) {
                    hasPathDFS(ans, i, end);
                    if(ans == 1) {
                        return;
                    }
                } 
            }
        }

        void findPathDFS(vector<int> &ans, int start, int end) {
            visited[start] = 1;
            if(start == end) {
                ans.push_back(end);
                findPathVar = 1;
                visited[end] = 1;
                return;
            }

            for(int i=0; i<n; i++) {
                if(start == i) continue;

                if(adj[start][i] == 1 && !visited[i]) {
                    findPathDFS(ans, i, end);
                    if(findPathVar == 1) {
                        ans.push_back(start);
                        return;
                    }
                }
            }
        }

        void isConnected(int s) {
            visited[s] = 1;
            for(int i=0; i<n; i++) {
                if(s == i) continue;

                if(adj[s][i] == 1 && !visited[i]) {
                    isConnected(i);
                }
            }
        }

        bool cycleDetectionUtil(int s, int parent) {
            visited[s] = 1;
            for(int i=0; i<n; i++) {
                if(s == i) continue;

                if(adj[s][i] == 1) {
                    if(visited[i] == 0) {
                        if(cycleDetectionUtil(i, s)) return true;
                    } else if(i != parent) return true;
                }
            }
            return false;
        }

        bool cycleDetection() {
            for(int i=0; i<n; i++) {
                if(!visited[i]) {
                    if(cycleDetectionUtil(i, -1)) {
                        return true;
                    }
                }
            }
            return false;
        }
};

int graph :: findPathVar = -1;

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

// 0 1
// 1 2
// 2 3
// 3 4
// 4 0
// 5 6
// 4 2

int main() {

	int n = 11, e = 6;
    // cin>>n>>e;
    graph g(n,e);

    g.inputAdj();

    // int etf;
    // cin>>etf;

    // printDFS(&g, n);

    // printBFS(&g, n);

    // int ans = -1;
    // int start, end;
    // cin>>start>>end;
    
    // ------ HAS-PATH (WITH DFS) --------- 
    // g.hasPathDFS(ans, start, end);
    
    // if(ans == 1) {
    //     cout<<"YES"<<endl;
    // } else {
    //     cout<<"NO"<<endl;
    // }


    // ------ FIND-PATH (WITH DFS) -------
    // vector<int> ans;
    // g.findPathDFS(ans, start, end);
    // if(ans.size() == 1 && ans[0] == end) {
    //     cout<<"start and end are same!!"<<"\n";
    // } else {
    //     for(int i=0; i<ans.size(); i++) {
    //         cout<<ans[i]<<" ";
    //     }
    //     cout<<"\n";
    // }

    // ------ ISCONNECTED (WITH DFS) ------
    // int s;
    // cin>>s;

    // g.isConnected(s);
    // int res = 0;
    // for(int i=0; i<n; i++) {
    //     if(g.visited[i] == 1) res++;
    // }

    // if(res == n) cout<<"Connected"<<"\n";
    // else cout<<"Not Connected"<<"\n";

    // ------ finding cycles in graph (DFS) ----

    // bool ans = g.cycleDetection(); 
    // cout<<ans<<" ";   

	return 0;
}

