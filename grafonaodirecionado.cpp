#include <iostream>
#include <vector>
using namespace std;

template <size_t N>
void readAdjList(vector<int> (&adj)[N], int m) {
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

template <size_t N>
void printAdjList(const vector<int> (&adj)[N], int n) {
    for (int i = 0; i <= n; i++) {
        cout << "Vertex " << i << ": ";
        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << "\n";
    }
}

int main() {
    constexpr size_t MAXN = 10000;
    vector<int> adj[MAXN];  // Declare array of vectors

    int n, m;
    cin >> n >> m;
    readAdjList(adj, m);       // Calls the template function
    printAdjList(adj, n);      // Calls the template function
    
    cout << "Fim\n";
    return 0;
}