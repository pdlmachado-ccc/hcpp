#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int translateInput(char u, vector<char> &translate){
    int id = 0;
    for (int i = 0; i < translate.size(); i++){
        if (translate[i] == u){
            id = i;
        }
    }
    return id;
}

template <size_t N>
void readAdjListModified(vector<int> (&adj)[N], int m, vector<char> &translate) {
    int idU = 0;
    int idV = 0;
    for (int i = 0; i < m; i++) {
        char u, v;
        cin >> u >> v;
        idU = translateInput(u, translate);
        idV = translateInput(v, translate);
        adj[idU].push_back(idV);
        adj[idV].push_back(idU);
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
void dfs(vector<int> (&adj)[N], bool visited[N], int v, vector<int> &components, vector<int> &alreadyPassed){
    visited[v] = true;
    components.push_back(v);
    alreadyPassed.push_back(v);
    for (int neighbour : adj[v]){
        if (not visited[neighbour]){
            dfs(adj, visited, neighbour, components, alreadyPassed);
        }
     }
}

template <size_t N>
void checkComponents(vector<int> (&adj)[N], bool visited[N], int n, vector<int> &components, vector<vector<int>> &componentsList, vector<int> &alreadyPassed){
    for(int i = 0; i < n; i++){
        if(find(alreadyPassed.begin(), alreadyPassed.end(), i) == alreadyPassed.end()){
            dfs(adj, visited, i, components, alreadyPassed);
            sort(components.begin(), components.end());
            componentsList.push_back(components);
            components.clear();
        }
    }
}

void scriptOutput(vector<vector<int>> &componentsList, int caseNumber, vector<char> &translate){
    int count = 0;
    cout << "Case " << "#" << caseNumber << ":" << endl;
    for (int i = 0; i < componentsList.size(); i++){
        for(int j = 0; j < componentsList[i].size();j++){
            cout << translate[componentsList[i][j]] << ",";
        }
        cout << endl;
        count++;
    }
    cout << count << " connected components" << endl;
}

template <size_t N>
void cleanUpTrash(vector<int> (&adj)[N], bool visited[N], vector<vector<int>> &componentsList, int n, vector<int> &alreadyPassed){
    for (int j = 0; j < n; j++){
        visited[j] = false;
    }
    for(int k = 0; k < n; k++){
        adj[k].clear();
    }
    componentsList.clear();
    alreadyPassed.clear();
}

int main() {

    constexpr size_t MAXN = 10000;
    vector<int> adj[MAXN];  
    bool visited[MAXN];
    vector<char> translate = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    vector<int> components;
    vector<vector<int>> componentsList;
    vector<int> alreadyPassed;
    int n, m, v, trials;

    cin >> trials;
    for (int i = 0; i < trials; i++){
        cin >> n >> m;
        readAdjListModified(adj, m, translate);
        checkComponents(adj, visited, n, components, componentsList, alreadyPassed);
        scriptOutput(componentsList, i+1, translate);
        cleanUpTrash(adj, visited, componentsList, n, alreadyPassed);
    }
         
    return 0;
}