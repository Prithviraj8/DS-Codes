/*Read marks of  student of 2nd year in an  online exam of a subject.
 Find out max and min obtained in that subject using head dtata structure.*/
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

void heap::maxHeap(int *a,int i,int n){
//   int i = 1;
//   char ch;
//
//   do{
//     int marks[i],mark;
//     std::cout << "Enter your marks." << '\n';
//     std::cin >> mark;
//     marks[i] = mark;
//     i++;
//     insertMax(marks,i);
//     std::cout << "Want to enter more marks?" << '\n';
//     std::cin >> ch;
//   }while (ch == 'Y'||ch == 'y');
//   dispMax(i);
// }
// void heap::insertMax(int marks[],int i){
//     int temp;
//     temp = marks[i];
//     while (i > 1 && marks[i/2] < marks[i]) {
//       /* code */
//       marks[i] = marks[i/2];
//       i = i/2;
//     }
//     marks[i] = temp;
int j, temp;
temp = a[i];
j = 2 * i;
while (j <= n)
{
    if (j < n && a[j+1] > a[j])
        j = j + 1;
    if (temp > a[j])
        break;
    else if (temp <= a[j])
    {
        a[j / 2] = a[j];
        j = 2 * j;
    }
}
a[j/2] = temp;
return;

}
void heap::build_maxheap(int *a,int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        maxHeap(a,i,n);
    }
}
void heap::minHeap(int *a,int i,int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && a[j+1] < a[j])
            j = j + 1;
        if (temp < a[j])
            break;
        else if (temp >= a[j])
        {
            a[j/2] = a[j];
            j = 2 * j;
        }
    }
    a[j/2] = temp;
    return;
}
// void heap::insertMin(int marks[],int i){
//
// }
void heap::build_minheap(int *mark, int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        minHeap(mark,i,n);
    }
}
void heap::dispMax(int val){
  std::cout << "Value is "<<val << '\n';
  for(int i=0;i<val-1;i++){
    std::cout << marks[i] << '\n';
  }
}

int main() {
  /* code */
  heap func;
  int n, i, x;
  int ch;
  char ch2;
     cout<<"enter no of elements of array\n";
     cin>>n;
     int marks[20];
     for (i = 1; i <= n; i++)
     {
         cout<<"enter element"<<(i)<<endl;
         cin>>marks[i];
     }

  do {

     std::cout << "Want to check max heap or min heap?" << '\n';
     std::cout << "1 : Min heap" << '\n';
     std::cout << "2: Max Heap" << '\n';
     std::cin >> ch;

     switch (ch) {
       case 1:
        func.build_minheap(marks, n);
        cout<<"Min Heap\n";
        for (i = 1; i <= n; i++)
        {
            cout<<marks[i]<<endl;
          }
          break;
       case 2:
        func.build_maxheap(marks,n);
        cout<<"Max Heap\n";
        for (i = 1; i <= n; i++)
        {
          cout<<marks[i]<<endl;
        }
        break;
        default:
          std::cout << "Wrong input" << '\n';
     }
     std::cout << "Want to continue? Y or N" << '\n';
     std::cin >> ch2;
   } while(ch2 == 'y' || ch2 == 'Y');
  return 0;
}
