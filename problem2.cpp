#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


void addEdge(vector<unordered_set<int>>& adjList, int u, int v) {
    adjList[u].insert(v);
    adjList[v].insert(u);
}
bool isConnected(const vector<unordered_set<int>>& adjList, int u, int v) {
    return adjList[u].count(v) > 0;
}
int main() {
    int n, m;
    cout<<"Enter the number of nodes (n): ";
    cin>>n;
    cout<<"Enter the number of edges (m): ";
    cin>>m;
    vector<unordered_set<int>> adjList(n);
    cout<<"Enter "<<m<<" pairs of nodes (from 0 to n-1) for bidirectional graph:\n";
    for(int i = 0; i<m; ++i) {
        int u, v;
        cin>>u>>v;
        addEdge(adjList, u, v);
    }
    int N;
    cout<<"Enter the number of queries (N): ";
    cin>>N;
    cout<< "Enter "<<N<<" queries (pair of nodes) to check for direct connection:\n";
    for(int i = 0; i<N; ++i){
        int u, v;
        cin>>u>>v;
        if(isConnected(adjList, u, v)) {
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}
