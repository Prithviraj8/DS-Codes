#include <iostream>
using namespace std;
#define MAX = 10;
class student {

  int rollNo;
  string name;
  char grade;
public:
    student(){
      rollNo = -1;
      name = " ";
      grade = '-';
    }
  friend class hashig;

};

class hashig{
  student hashtable[10];
public:
    void linearPbwr();
    void linearPbwor();
    void display();
};

void hashig::linearPbwor(){

  student data;
    char ch;
    int loc,i,newloc,flag = 0;
    do{
    std::cout << "Enter roll no & name & grade " << '\n';
    std::cin >> data.rollNo >> data.name >> data.grade;
    loc = (data.rollNo%10);
    if(hashtable[loc].rollNo ==  -1){
        hashtable[loc].rollNo = data.rollNo;
        hashtable[loc].name = data.name;
        hashtable[loc].grade = data.grade;
    }else{

        newloc = (loc+1) % 10;
        while (newloc!=loc) {
          if(hashtable[newloc].rollNo ==  -1){
             flag = 1;
              hashtable[newloc].rollNo = data.rollNo;
              hashtable[newloc].name = data.name;
              hashtable[newloc].grade = data.grade;
              break;
          }

          newloc = (newloc+1)%10;
          flag = 0;

          if(flag == 0){
            std::cout << "No Record found" << '\n';
          }
        }
    }


    std::cout << "Wanna add more ?" << '\n';
    std::cin >> ch;
  }while (ch == 'y' || ch == 'Y');
}


void hashig :: linearPbwr(){

    student data,temp;
      char ch;
      int loc,newloc,flag = 0;
      do{
      std::cout << "Enter roll no & name & grade " << '\n';
      std::cin >> data.rollNo >> data.name >> data.grade;
      loc = (data.rollNo%10);
      if(hashtable[loc].rollNo ==  -1){
          hashtable[loc].rollNo = data.rollNo;
          hashtable[loc].name = data.name;
          hashtable[loc].grade = data.grade;
      }else{

          newloc = (hashtable[loc].rollNo + 1) % 10;
          if(newloc!=loc) {
               flag = 1;
               temp.rollNo = hashtable[newloc].rollNo;
               temp.name = hashtable[newloc].name;
               temp.grade = hashtable[newloc].grade;

               hashtable[loc].rollNo=data.rollNo;
               hashtable[loc].name=data.name;
               hashtable[loc].grade=data.grade;
          }

            int i;
            i=(loc+1)%10;

            while(i!=loc)
            {
                 if(hashtable[i].rollNo==-1)
                 {
                     hashtable[i].rollNo=temp.rollNo;
                     hashtable[i].name=temp.name;
                     hashtable[i].grade=temp.grade;
                     flag=1;
                     break;
                 }
                 i=(i+1)%10;
            }
            if(flag == 0){
              std::cout << "No Record found" << '\n';
            }
          }



      std::cout << "Wanna add more ?" << '\n';
      std::cin >> ch;
    }while (ch == 'y' || ch == 'Y');
}
void hashig :: display(){
  std::cout << "ROLL \t"<<"NAME \t"<<"GRADE \t" << '\n';
  for(int i =0;i<10;i++){
    std::cout << hashtable[i].rollNo<<"\t"<<hashtable[i].name<<"\t"<<hashtable[i].grade << '\n';
  }

}
int main(){

  hashig obj;
  // obj.linearPbwor();
  obj.linearPbwr();
  obj.display();
  return 0;
}
