#include <bits/stdc++.h>
using namespace std;

void DFSRec(vector<vector<int>> &adj, vector<bool>& visited, int index) {
    visited[index] = true;
    cout << index <<" ";
    for(int i : adj[index]) {
        if(visited[i] == false) {
            DFSRec(adj, visited, i);
        }
    }
}

void DFS(vector<vector<int>> &adj, int index) {
    vector<bool> visited(adj.size(), false);
    DFSRec(adj, visited, index);
}

void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int V = 5; 
    vector<vector<int>> adj(V);
  
    vector<vector<int>> edges={{1, 2},{1, 0},{2, 0},{2, 3},{2, 4}};
    for (auto &e : edges) addEdge(adj, e[0], e[1]);

    int s = 1;
    cout << "DFS from source: " << s << endl;
    DFS(adj, s);

    return 0;
}