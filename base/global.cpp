#include <iostream>
#include <vector>
#include <array>

using namespace std;

int n, m;
using ADJ_type = std::vector<std::vector<int>>;

int main()
{
    cin >> n >> m;
    // adjacency list for undirected graph
    // time complexity: O(2E)
    ADJ_type adj;

    adj.reserve(n+1); // Cria vetores vazios para cada vértice

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n+1; i++){
        cout << "Vertice " << i << ":";
        for (int j = 0; j < adj[i].size(); j++){
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "Fim";
    return 0;
}