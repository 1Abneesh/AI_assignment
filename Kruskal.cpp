#include<bits/stdc++.h>
using namespace std;

class dsu
{
    vector<int> size;
    vector<int> parent;
public:
    dsu(int n)
    {
        size.resize(n + 1,1);
        parent.resize(n + 1, 0);
        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
        }
    }
    int finduparent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = finduparent(parent[node]);
    }
    void unionbysize(int u, int v)
    {
        int up_u = finduparent(u);
        int up_v = finduparent(v);
        if (up_u == up_v)
        {
            return;
        }
        if (size[up_u] < size[up_v])
        {
            parent[up_u] = up_v;
            size[up_v] +=size[up_u];
        }
        else if (size[up_v] < size[up_u])
        {
            parent[up_v] = up_u;
            size[up_u] +=size[up_v];
        }
        else
        {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};


	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int minst=0;
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                edges.push_back({it[1],{i,it[0]}});
            }
        }
        sort(edges.begin(),edges.end());
        
        dsu d(V);
        
        for(int i=0;i<edges.size();i++){
            int wt = edges[i].first;
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            if(d.finduparent(u) == d.finduparent(v)){
                continue;
            }
            else{
                minst += wt;
                d.unionbysize(u,v);
            }
        }
        return minst;
    }

int main(){
    int V,edges;
    cout<<"Enter the number of vertices\n";
    cin>>V;
    vector<vector<int>> adj[V];
    cout<<"Enter the number of edges\n";
    cin>>edges;
    
    for(int i=0;i<edges;i++){
        int u,v,w;
        cout<<"Enter u , v and w for the edges\n";
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    cout<<"MST of the given graph is\n";
    cout<<spanningTree(V,adj)<<"\n";
    return 0;
}