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
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << ": ";

        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << "\n";
    }
}

template <size_t N>
void dfs(vector<int> (&adj)[N], bool visited[N], int v){
     visited[v] = true;
     cout << v << " ";
     for (int neighbour : adj[v]){
        if (not visited[neighbour]){
            dfs(adj, visited, neighbour);
            cout << v << " ";
        }
     }
}

int main() {
    constexpr size_t MAXN = 10000;
    vector<int> adj[MAXN];  
    bool visited[MAXN];
    int n, m, v;
    cin >> n >> m;
    readAdjList(adj, m);       
    printAdjList(adj, n);
    cout << "RUN DFS" << endl;
    cin >> v;
    dfs(adj,visited,v);    
    cout << "\nFIM\n";
    return 0;
}