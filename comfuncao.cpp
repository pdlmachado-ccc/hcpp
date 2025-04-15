#include <iostream>
#include <vector>
#include <array>

using namespace std;

using ADJ_type = std::vector<std::vector<int>>;

ADJ_type readADJList(int x, int y) {
    ADJ_type adjc(x+1);
    adjc.reserve(x+1); // Cria vetores vazios para cada vértice
    for(int i = 0; i < y; i++)
    {
        int u, v;
        cin >> u >> v;
        adjc[u].push_back(v);
        adjc[v].push_back(u);
    }
    return adjc;
}

int main()
{
    int n,m;
    cin >> n >> m;
    // adjacency list for undirected graph
    // time complexity: O(2E)
    ADJ_type adj;
    adj = readADJList(n,m);
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