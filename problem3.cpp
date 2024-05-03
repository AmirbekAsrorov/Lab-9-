#include <iostream>
#include <vector>
#include <queue>
using namespace std;


const int INF = -1;

void findSeparationLevels(int N, const vector<vector<int>>& graph, vector<int>& levels){
    queue<int> q;
    vector<bool> visited(N, false);
    q.push(0);
    levels[0]=0;
    visited[0]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for (int v : graph[u]){
            if (!visited[v]){
                levels[v]=levels[u]+1;
                visited[v]=true;
                q.push(v);
            }
        }
    }
}
int main(){
    int N, M;
    cin>>N>>M;
    vector<vector<int>> graph(N);
    vector<int> levels(N, INF);
    for(int i = 0; i < M; ++i){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    findSeparationLevels(N, graph, levels);
    for(int i = 0; i < N; ++i){
        cout<<levels[i]<<" ";
    }
    cout<<endl;
    return 0;
}
