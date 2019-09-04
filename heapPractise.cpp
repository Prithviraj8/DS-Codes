#include <iostream>
using namespace std;

class heap {
 int n;
 public:
   int marks[];

     void maxHeap(int *,int,int);
     void minHeap(int *,int,int);
     void insertMax(int[],int);
     void insertMin(int[],int);
     void dispMax(int);
     void build_minheap(int *,int);
     void build_maxheap(int *,int);

};

void heap :: build_maxheap(int  *a,int n){
    for(int j = n/2;j>=1;j--){
        maxHeap(a,j,n);
    }
}

void heap :: maxHeap(int *a, int i, int n){

  int temp = a[i];
  int j = 2 * i;
  while (j<=n) {
    if(j<n && a[j+1] > a[j]){
      j++;
    }
    if(temp > a[j]){
      break;
    }else if(temp <= a[j]){
        a[j/2] = a[j];
        j = 2 * j;
    }
  }
  a[j/2] = temp;
  return;
}


void heap :: build_minheap(int *a, int n){
    for(int j = n/2;j>=1;j--){
        minHeap(a,j,n);
    }
}

void heap :: minHeap(int *a, int i, int n){      
  int temp = a[i];
  int j = 2 * i;
  while (j<=n) {
    if(j<n && a[j+1] < a[j]){
      j++;
    }
    if(temp < a[j]){
      break;
    }else if(temp >= a[j]){
        a[j/2] = a[j];
        j = 2 * j;
    }
  }
  a[j/2] = temp;
  return;
}



int main(){
  int n;
  heap func;
  std::cout << "Enter no. of elements" << '\n';
  std::cin >> n;
  int a[n];
  printf("Enter elements \n");
  for(int i=0;i<n;i++){
    std::cin >> a[i];
  }
  func.build_minheap(a,n);
  std::cout << "MAX HEAP IS " << '\n';
  for (int i = 1; i <= n; i++)
  {
      cout<<a[i]<<endl;
  }
  return 0;
}
