#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;
class graph{
public:
void preparelist(unordered_map<int,list<int>>&adj,vector<vector<int>>&edges,int v,int e){
for(int i=0;i<e;i++){
int u=edges[i][0];
int v=edges[i][1];
adj[u].push_back(v);
adj[v].push_back(u);
}
}

};
void dfs(  unordered_map<int,list<int>>&adj,int node,unordered_map<int,bool>&visited,vector<int>&componet){
componet.push_back(node);
visited[node]=true;
for(auto i:adj[node]){
    if(!visited[i]){
        dfs(adj,i,visited,componet);
       
    }
}

}
int dfsp(int vertices,unordered_map<int,list<int>>&adj){
    vector<int>component;
    int count=0;
    unordered_map<int,bool>visited;
    for(int i=0;i<vertices;i++){
if(!visited[i]){
    dfs(adj,i,visited,component);
    count++;
}
    }
    return count;
}
int main(){
    graph g;
    int vertices;
    cout<<"enter vertices"<<endl;
    int edgess;
    cout<<"enter edges"<<endl;
    cin>>edgess;
    int u,v;
    vector<vector<int>>edges;
    for(int i=0;i<edgess;i++){
cout<<"enter "<<endl;
cin>>u;
cin>>v;
edges.push_back({u, v});

    }
    unordered_map<int,list<int>>adj;
    g.preparelist(adj,edges,vertices,edgess);
    int ans=dfsp(vertices,adj);
    cout<<ans<<endl;
}
