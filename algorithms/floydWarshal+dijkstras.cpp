#include <bits/stdc++.h>
using namespace std;

// dijkstras shortest path calculation algorithm (from zero to other vertices)
// O(V^2) approach
// optimised approach makes us use min-priority queue (O(v + ElogV) time complexity)

// floyd-warshall gives us shortest distances between all the vertices(connected directly or indirectly both)
// complexity (O(N^3))

class graph {
    public:
    int n,e;
    int **adj;
        graph(int vertex, int edges) {
            n = vertex;
            e = edges;
            adj = new int*[n];
            for(int i=0; i<n; i++) {
                adj[i] = new int[n];
                for(int j=0; j<n; j++) {
                    adj[i][j] = 0;   
                }
            }
        }

        void input() {
            for(int i=0; i<e; i++) {
                int b,e,w;
                cin>>b>>e>>w;
                adj[b][e] = w;
                adj[e][b] = w;
            }
        }

        ~graph() {
            for(int i=0; i<n; i++) {
                delete[] adj[i];
            }
            delete[] adj;
        }

        int findMinVertex(int *distance, int *visited) {
            int minVertex = -1;
            for(int i=0; i<n; i++) {
                if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])) {
                    minVertex = i;
                }
            }
            return minVertex;
        }

        void dijkstras(int *visited) {
            int *distance = new int[n];
            for(int i=0; i<n; i++) {
                distance[i] = INT_MAX;
            }

            distance[0] = 0;

            for(int i=0; i<n-1; i++) {
                int minVertex = findMinVertex(distance, visited);
                visited[minVertex] = 1;
                for(int j=0; j<n; j++) {
                    if(adj[minVertex][j] != 0 && !visited[j]) {
                        int dist = distance[minVertex] + adj[minVertex][j];
                        if(dist < distance[j]) {
                            distance[j] = dist;
                        }
                    }
                }
            }

            for(int i=1; i<n; i++) {
                cout<<i<<" "<<distance[i]<<"\n";
            }

            delete[] distance;
        }

        void floydWarshall() {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    for(int k=0; k<n; k++) {
                        if (adj[i][j] > (adj[i][k] + adj[k][j])
                            && (adj[k][j] != INT_MAX
                                && adj[i][k] != INT_MAX))
                            adj[i][j] = adj[i][k] + adj[k][j];           
                    }
                    if(i == j) adj[i][j] = 0;
                }
            }

            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    cout<<adj[i][j]<<" ";
                }
                cout<<"\n";
            }
        } 
};

int main() {
    int n = 4, e = 5;
    graph g(n,e);

    g.input();

    int *visited = new int[n];

    for(int j=0; j<n; j++) {
        visited[j] = 0;
    }

    //g.dijkstras(visited);

    // g.floydWarshall();

    delete[] visited;
    return 0;
}
