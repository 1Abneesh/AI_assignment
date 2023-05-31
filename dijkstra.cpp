#include<bits/stdc++.h>
using namespace std;
class Dijkstra{
    int edge,vertices;
    int **graph;
    public:
    Dijkstra(int v=5){
        this->vertices = v;
        graph = new int*[vertices+1];
        for(int i=0;i<vertices;i++){
            graph[i] = new int[vertices+1];
            for(int j=0;j<vertices;j++){
             graph[i][j] = 0;   
            }
        }
    }
    void add_edge(){
    cout<<"Please enter the number of edges do you want\n";
    cin>>edge;
    cout<<"Please enter the u,v,w for every edge\n";
    for(int i=0;i<edge;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
}


void Show_graph(){
    cout<<"The graph is\n";
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void dijkstra_algo(int source=0){
    int dist[vertices];
    memset(dist,999999,sizeof(dist));
    bool final[vertices] = {false};
    dist[source] = 0;
    // final[0] = true;
    for(int count=0;count<vertices-1;count++){
        int u =-1;
        for(int i=0;i<vertices;i++){
            if(!final[i] && (u==-1 || dist[i]<dist[u])){
                u=i;
            }
        }
        final[u] = true;
    
    for(int x=0;x<vertices;x++){
        if(graph[u][x] !=0 && !final[x]){
            dist[x] = min(dist[x],dist[u]+graph[u][x]);
        }
    }
    }
    cout<<"The minimum distance from:-"<<source<<" is:\n";
    for(int i=0;i<vertices;i++){
        cout<<dist[i]<<" ";
    }
}
void prim_algo(int source=0){
    int dist[vertices];
    memset(dist,999999,sizeof(dist));
    bool final[vertices] = {false};
    dist[source] = 0;
    // final[0] = true;
    int res=0;
    for(int count=0;count<vertices-1;count++){
        int u =-1;
        for(int i=0;i<vertices;i++){
            if(!final[i] && (u==-1 || dist[i]<dist[u])){
                u=i;
            }
        }
        final[u] = true;
        res+=dist[u];
    for(int x=0;x<vertices;x++){
        if(graph[u][x] !=0 && !final[x]){
            dist[x] = min(dist[x],graph[u][x]);
        }
    }
    }
    cout<<"\nThe cost of mst is :- "<<res;
    // for(int i=0;i<vertices;i++){
    //     cout<<dist[i]<<" ";
    // }
}
};

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
          if (arr[j] < arr[min_idx])
              min_idx = j;
        }
        if (min_idx!=i)
            swap(arr[min_idx], arr[i]);
    }
}
 

int main(){
    cout<<"Dijkstra \n";
    cout<<"Enter the number of vertices\n";
    int v;
    cin>>v;
    Dijkstra d(v);
    d.add_edge();
    d.Show_graph();
    cout<<"Enter the source to calculate minimum distance from it\n";
    int src;
    cin>>src;
    d.dijkstra_algo(src);
    d.prim_algo();
    cout<<"\nSelection sort\n";
    int a[]={2,4,1,5,8,3};
    selectionSort(a,6);
    for(auto it:a){
        cout<<it<<" ";
    }
    return 0;
}
