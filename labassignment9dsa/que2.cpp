#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>
#include<set>
using namespace std;
class graph{
    public:
    void dfs(int node ,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj,vector<int>&component){
component.push_back(node);
visited[node]=1;
//hrek connceted node ke liye call
for(auto i:adj[node]){
    if(!visited[i]){
        dfs(i,visited,adj,component);
    }
}

    }
vector<vector<int>>dfs(int v,int e,vector<vector<int>>&edges){
unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
    int u=edges[i][0];
    int v=edges[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
}
vector<vector<int>>ans;
unordered_map<int,bool>visited;
for(int i=0;i<v;i++){
    if(!visited[i]){
    vector<int>component;
    dfs(i,visited,adj,component);
    ans.push_back(component);
    }

}
return ans;
    }
    
};
int main(){
    graph g;
    vector<int>ans;
    int vertex;
    cout<<"enter vertex"<<endl;
    cin>>vertex;
       int e;
    cout << "enter number of edges: ";
    cin >> e;

    vector<vector<int>> edges;

    cout << "enter edges (u v): \n";
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    vector<vector<int>>ans=g.dfs(vertex,e,edges);
    for(int i:ans){
        cout<<i<<"";
    }
}
