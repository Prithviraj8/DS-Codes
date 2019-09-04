#define MAX 20
#include<iostream>
#include<string>
// #include<stdio>
using namespace std;

class Prim{


  int mat[MAX][MAX];
  char ch;
  int vertices;

public:
     Prim()
     {
      std::cout << "Enter no of vertices" << '\n';
      std::cin >> vertices;
      mat[vertices][vertices];

        for(int i=0;i<vertices;i++){
          for(int j=0;j<vertices;j++){
            mat[i][j] = INT_MAX;
          }
        }
      }

    void create_adjMat(){

      for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){

            if(mat[i][j] == INT_MAX){
              std::cout << "Is "<<i<<" a neighbour of "<<j << '\n';
              std::cin >> ch;

              if(ch == 'y'|| ch == 'Y'){
                std::cout << "Enter cost of path" << '\n';
                std::cin >> mat[i][j];
                mat[j][i] = mat[i][j];
              }
            }
        }
      }
    }

    void display_adjMat(){
      for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
          if(mat[i][j]!=INT_MAX){
            cout << mat[i][j] << "\t";
          }else{
            cout << "*\t";
          }
        }
        std::cout << endl ;

      }
    }


    void MST(){

        int stv,nearest[vertices],mincost = 0;
        std::cout << "Enter starting vertex" << '\n';
        std::cin >> stv;
        nearest[stv] = -1;

        for(int i=0;i<vertices;i++){
          if(i!=stv)
            nearest[i] = stv;
        }

        int r=0;
        int min;
        for(int i=1;i<vertices;i++){

          min = INT_MAX;
          int j;
          for(int k=0;k<vertices;k++){
          if(nearest[k] !=1 && mat[k][nearest[k]] < min ){
            j=k;
            min = mat[k][nearest[k]];
          }
        }

      std::cout << "minimum edge with selected cost is "<<min<<" from " <<nearest[j] <<" to " << j << '\n';
      r=r+1;
      nearest[j] = -1;
      mincost = mincost + mat[j][nearest[j]];

      for(int k=0;k<vertices;k++){
        if(nearest[k]!=-1 && mat[k][nearest[k]] > mat[k][j])
          nearest[k]=j;
      }
    }
      std::cout << "Minimum cost is " <<mincost<< '\n';
    }
};


int main(){

  Prim obj;
  obj.create_adjMat();
  obj.display_adjMat();
  obj.MST();

return 0;
}
