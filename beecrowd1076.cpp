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
void dfs_modified(vector<int> (&adj)[N], bool visited[N], int v, int &count){
     visited[v] = true;
     for (int neighbour : adj[v]){
        if (not visited[neighbour]){
            dfs_modified(adj, visited, neighbour, count);
            count++;
        }
     }
     count++;
}

int main() {

    constexpr size_t MAXN = 10000;
    vector<int> adj[MAXN];  
    bool visited[MAXN];
    int n, m, v, trials;
    int count = 0;
    cin >> trials;

    for (int i = 0; i < trials; i++){
        cin >> v;
        cin >> n >> m;
        readAdjList(adj, m);
        dfs_modified(adj,visited,v,count);
        cout << count - 1 << endl;
        count = 0; 
        for (int j = 0; j < n; j++){
            visited[j] = false;
        }
        for(int k = 0; k < n; k++){
            adj[k].clear();
        }
    }

    return 0;
}