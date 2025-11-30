#include<iostream>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
#include<vector>
class graph{
public:
void preparelist(vector<vector<pair<int,int>>>&adj,vector<vector<int>>edges,int e){
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        adj[u].push_back({v,w});
    }

}
};
vector<int> dijkratasalgo(int v,vector<vector<pair<int,int>>>&adj,int k){
set<pair<int,int>>s;
vector<int>distance(v);
for(int i=0;i<v;i++){
    distance[i]=INT_MAX;
}
distance[k]=0;
s.insert(make_pair(0,k));
while(!s.empty()){
auto top=*(s.begin());
   s.erase(s.begin());
   int topdis=top.first;
   int node=top.second;
   for(auto neighour:adj[node]){
    if(topdis+neighour.second<distance[neighour.first]){
auto record=s.find({distance[neighour.first],neighour.first});
if(record!=s.end()){
    s.erase(record);
}
distance[neighour.first]=topdis+neighour.second;
s.insert(make_pair(distance[neighour.first], neighour.first));
    }
   }
}


return distance;
}
int main(){
    int vertices;
    int e;
    cout<<"enter vertices"<<endl;
    cin>>vertices;
    cout<<"enter edges"<<endl;
    cin>>e;
    vector<vector<int>>edges;
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u;
        cin>>v;
        cin>>w;
        edges.push_back({u,v,w});
    }
    vector<vector<pair<int,int>>>adj(vertices);
    graph g;
    g.preparelist(adj,edges,e);
    int k;
    cout<<"enter source node"<<endl;
    cin>>k;
    vector<int>ams=dijkratasalgo(vertices,adj,k);
    int ans = *max_element(ams.begin(), ams.end()); // skip index 0
if(ans == INT_MAX) ans = -1;
cout << ans << endl;
    return 0;
}
