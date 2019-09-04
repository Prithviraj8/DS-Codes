#include <iostream>

using namespace std;

class prims{
    private:
        int no_of_edges,no_of_vertices;
        int graph[10][10],visited[10],mindist[10];
    public:
        void input();
        void output();
        void spanningtree();
        prims(){
        no_of_edges=no_of_vertices=0;
        for(int i=0;i<10;i++)
        {
            visited[i]=mindist[i]=0;
            for(int j=0;j<10;j++)
            {
                graph[i][j]=0;
            }
        }
    }
};
void prims:: input(){
    int vertex1,vertex2,cost;
    cout<<"Enter number of nodes: ";
    cin>>no_of_vertices;
    cout<<"Enter number of edges: ";
    cin>>no_of_edges;
    for(int i=0;i<no_of_edges;i++){
        cout<<"Enter vertex1: ";
        cin>>vertex1;
        cout<<"Enter vertex2: ";
        cin>>vertex2;
        cout<<"Enter the cost of "<<vertex1<<" and "<<vertex2<<" ";
        cin>>cost;
        graph[vertex1][vertex2]=graph[vertex2][vertex1]=cost;
    }
}
void prims:: output(){
    for(int i=0;i<no_of_vertices;i++){
        cout<<endl;
        for(int j=0;j<no_of_vertices;j++){
            cout<<graph[i][j]<<"     ";
        }
    }
}
void prims:: spanningtree(){
    int min=99999,row,col,index=0;
    for(int i=0;i<no_of_vertices;i++){
            for(int j=i;j<no_of_vertices;j++){
                if(graph[i][j]<min&&graph[i][j]!=0){
                    min=graph[i][j];
                    row=i;
                    col=j;
                }
            }
    }
    visited[row]=visited[col]=1;
    mindist[index++]=min;

     for(int i=0;i<no_of_vertices-2;i++)
        {
            min=99999;
            for(int j=0;j<no_of_vertices;j++)
            {
                if(visited[j]==1)
                {
                    for(int k=0;k<no_of_vertices;k++)
                    {
                        if(graph[j][k]<min&&graph[j][k]!=0&&visited[k]==0)
                        {
                          min=graph[j][k];
                          row=j;
                          col=k;
                        }
                    }
                }
            }
          mindist[index++]=min;
          visited[row]=visited[col]=1;
        }
     int total=0;
     cout<<endl;
     cout<<"minimum distance path is: ";
     for(int i=0;i<no_of_vertices-1;i++)
        {
            cout<<" "<<mindist[i]<<" ";
            total=total+mindist[i];
        }
        cout<<endl<<"Total path cost is:  "<<total;
}
int main()
{
    prims p;
    p.input();
    p.spanningtree();
    p.output();
    return 0;
}
