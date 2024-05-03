#include <iostream>
#include <vector>
#include <queue>
#include <climits>


using namespace std;


vector<int> findSeparationLevels(const vector<vector<int>>& graph, int source){
    int n=graph.size();
    vector<int> levels(n, -1);
    vector<bool> visited(n, false);
    queue<int>q;
    visited[source]=true;
    levels[source]=0;
    q.push(source);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v : graph[u]){
            if(!visited[v]){
                visited[v]=true;
                levels[v]=levels[u]+1;
                q.push(v);
            }
        }
    }
    return levels;
}
int main(){
    int n, m;
    cout<<"Enter the number of users (nodes) in the network: ";
    cin>>n;
    cout<<"Enter the number of friendships (edges) in the network: ";
    cin>>m;
    vector<vector<int>> graph(n);
    cout<<"Enter "<<m<<" friendships (pairs of users):\n";
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> separationLevels=findSeparationLevels(graph, 0);
    cout<<"Separation levels from source user (user 0):\n";
    for(int i = 0; i < n; ++i){
        cout<<"User "<<i<<": "<<separationLevels[i]<<endl;
    }
    return 0;
}
