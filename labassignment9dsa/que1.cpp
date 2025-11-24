#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>
#include<set>
using namespace std;
class graph{
    public:
    void preparelsit(unordered_map<int,list<int>>&adj,vector<pair<int,int>>&edges){
for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
        int v=edges[i].second;
    adj[u].push_back(v);
      adj[v].push_back(u);
}
    }
     void pront(unordered_map<int,list<int>>adj){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }

vector<int> bfs(unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited,vector<int>&ans,int nodes){
        queue<int>q;
q.push(nodes);
visited[nodes]=true;
while(!q.empty()){
    int frontnode=q.front();
    q.pop();
    ans.push_back(frontnode);
    for(auto i:adj[frontnode]){
        if(!visited[i]){
            q.push(i);
            visited[i]=1;
        }
    }
}
return ans;
    }
 vector<int>bfs(int vertex,vector<pair<int,int>>edges){
    vector<int>ans;
    unordered_map<int,list<int>>adj;
unordered_map<int,bool>visited;
preparelsit(adj,edges);
for(int i=0;i<vertex;i++){
if(!visited[i]){
    bfs(adj,visited,ans,i);
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

    vector<pair<int,int>> edges;

    cout << "enter edges (u v): \n";
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    ans=g.bfs(vertex,edges);
    for(int i:ans){
        cout<<i<<"";
    }
}qu