#include <iostream>
#include <vector>

using namespace std;


void dfs(vector<vector<int>>& graph,vector<bool>& visited, int node){
    visited[node]=true;
    for(int neighbor : graph[node]){
        if(!visited[neighbor]){
            dfs(graph, visited, neighbor);
        }
    }
}
int countConnectedComponents(vector<vector<int>>& graph, int n){
    vector<bool> visited(n, false);
    int count=0;
    for (int i=0;i<n; ++i){
        if (!visited[i]){
            dfs(graph, visited, i);
            ++count;
        }
    }
    return count;
}
int main(){
    int N,M;
    cin>>N>>M;
    vector<vector<int>>graph(N);
    for(int i=0; i<M;++i){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int numComponents=countConnectedComponents(graph, N);
    cout<<"Number of distinct groups of connected islands: "<<numComponents<<endl;
    return 0;
}
