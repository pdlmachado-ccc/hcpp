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
void dfs(vector<int> (&adj)[N], bool visited[N], int v, vector<int> &components){
     visited[v] = true;
     components.push_back(v);
     for (int neighbour : adj[v]){
        if (not visited[neighbour]){
            dfs(adj, visited, neighbour, components);
        }
     }
}

template <size_t N>
void checkComponents(vector<int> (&adj)[N], bool visited[N], int n, vector<int> &components){
    for(int i = 0; i < n; i++){
        if(find(components.begin(), components.end(), i) == components.end()){
            dfs(adj, visited, i, components);
            components.push_back(-1);
        }
    }
}

void scriptOutput(vector<int> &components, int caseNumber, vector<char> &translate){
    int count = 0;
    cout << "Case " << "#" << caseNumber << ":" << endl;
    for (int element : components){
        if(element == -1){
            count++;
            cout << endl;
        }else{
            cout << translate[element] << ",";
        }
        
    }
    cout << count << " connected components" << endl;
    cout << " " << endl;
}

template <size_t N>
void cleanUpTrash(vector<int> (&adj)[N], bool visited[N], vector<int> &components, int n){
    for (int j = 0; j < n; j++){
        visited[j] = false;
    }
    for(int k = 0; k < n; k++){
        adj[k].clear();
    }
    components.clear();
}

int main() {

    constexpr size_t MAXN = 10000;
    vector<int> adj[MAXN];  
    bool visited[MAXN];
    vector<char> translate = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    vector<int> components;
    int n, m, v, trials;

    cin >> trials;
    for (int i = 0; i < trials; i++){
        cin >> n >> m;
        readAdjListModified(adj, m, translate);
        checkComponents(adj, visited, n, components);
        scriptOutput(components, i+1, translate);
        cleanUpTrash(adj, visited, components, n);
    }
         
    return 0;
}