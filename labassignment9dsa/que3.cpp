#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}
void makeset(vector<int>&parent,vector<int>&rank,int n){
    for(int i=0;i<n;i++){
      parent[i]=i;
      rank[i]=0;
    }
}
int findparent(vector<int>&parent,int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node]=findparent(parent,parent[node]);
}
void unjion(int u,int v,vector<int>&parent,vector<int>&rank){
    u=findparent(parent,u);
    v=findparent(parent,v);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
   else if(rank[u]>rank[v]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}
int minimum(vector<vector<int>>&edges,int n){
    sort(edges.begin(),edges.end(),cmp);
    vector<int>parent(n);
    vector<int>rank(n);
    makeset(parent,rank,n);
    int minw=0;
    for(int i=0;i<edges.size();i++){
        int u=findparent(parent,edges[i][0]);
         int v=findparent(parent,edges[i][1]);
         int w=edges[i][2];
         if(u!=v){
minw+=w;//adding only that weight which not forms cycle?
            unjion(u,v,parent,rank);
         }
    }
return minw;
}
int main(){
    vector<vector<int>>edges;
    int n;
    cout<<"enter numbner of vertices"<<endl;
    cin>>n;
    int e;
    cout<<"enter number of edges"<<endl;
    cin>>e;
        cout << "enter edges (u v): \n";
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    int minweighttree;
    minweighttree=minimum(edges,n);
    cout<<"ans is "<<minweighttree<<endl;
    return 0;
}
/*
#include<iostream>
#include<set>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;
class graph{
public:
vector<pair<pair<int,int>,int>>prims(int n,int m,vector<pair<pair<int,int>,int>>&g){
unordered_map<int,list<pair<int,int>> >adj;
for(int i=0;i<g.size();i++){
  int u=g[i].first.first;
  int v=g[i].first.second;
  int w=g[i].second;
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}
vector<int>key(n+1);
vector<bool>mst(n+1);
vector<int>parent(n+1);
for(int i=0;i<=n;i++){
    key[i]=INT_MAX;
    parent[i]=-1;
    mst[i]=false;
}
key[1]=0;
parent[1]=-1;
for(int i=0;i<n;i++){
    int mini=INT_MAX;
    int u;
    for(int v=0;v<=n;v++){
        if(mst[v]==false && key[v]<mini){
            u=v;
            mini=key[v];
        }
    }
    mst[u]=true;
    for(auto it:adj[u]){
        int v=it.first;
        int w=it.second;
        if(mst[v]==false && w<key[v]){
parent[v]=u;
key[v]=w;
        }
    }
}
vector<pair<pair<int,int>,int>>result;
for(int i=2;i<=n;i++){
    result.push_back({{parent[i],i},key[i]});

}
return result;
}
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int,int>,int>> g;

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.push_back({{u, v}, w});
    }
    graph obj;  
    vector<pair<pair<int,int>,int>> ans = obj.prims(n, m, g);
    cout << "MST Edges:\n";
    for(auto e : ans) {
        cout << e.first.first << " - " << e.first.second 
             << "  weight = " << e.second << endl;
    }
    return 0;
}
*/
