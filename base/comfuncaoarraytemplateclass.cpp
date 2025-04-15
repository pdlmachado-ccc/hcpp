#include <iostream>
#include <vector>
using namespace std;

template <size_t N>
class Graph {
public:
    vector<int> adj[N];  // Array of vectors

    void readAdjList(int m) {
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);  // Undirected graph
        }
    }

    void printAdjList(int n) const {
        for (int i = 1; i <= n; i++) {
            cout << "Vertex " << i << ": ";
            for (int v : adj[i]) {
                cout << v << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph<100005> g;  // Create graph with array size 100005

    g.readAdjList(m);
    g.printAdjList(n);

    cout << "Fim\n";
    return 0;
}