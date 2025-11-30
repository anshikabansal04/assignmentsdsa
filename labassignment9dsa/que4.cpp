#include<iostream>
#include<set>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;
class graph{
public:
vector<int>dijkstra(vector<vector<int>>&edges,int v,int e,int source){
unordered_map<int,list<pair<int,int>> >adj;
for(int i=0;i<e;i++){
    int u=edges[i][0];
    int v=edges[i][1];
    int w=edges[i][2];
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}
vector<int>distnace(v);
for(int i=0;i<v;i++){
    distnace[i]=INT_MAX;
}
set<pair<int,int>>st;
st.insert(make_pair(0,source));
while(!st.empty()){
    auto top=*(st.begin());
    int nodedis=top.first;
    int topnode=top.second;
    st.erase(st.begin());
    for(auto neighour:adj[topnode]){
        if(nodedis+neighour.second<distnace[neighour.first]){
auto record=st.find(make_pair(distnace[neighour.first],neighour.first));
if(record!=st.end()){
    st.erase(record);
}
distnace[neighour.first]=nodedis+neighour.second;
st.insert(make_pair(distnace[neighour.first],neighour.first));
        }
    }
}
return distnace;
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
    int s;
    cout<<"enter source node:"<<endl;
    cin>>s;
    vector<vector<int>> edges;

    cout << "enter edges (u v): \n";
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    vector<int>ans=g.dijkstra(edges,vertex,e,s);
    for(int i:ans){
        cout<<i<<"";
    }
    return 0;
}
