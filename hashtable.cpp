#include <iostream>
using namespace std;

class student {

  int rollNo;
  string name;
  char grade;
friend class hashing;
public:
    student(){
      rollNo = -1;
      name = " ";
      grade = '-';
    }

};

int MAX = 10;
char ch;

class hashing {
  student hashtable[10];
public:
    void display();
  void linearPbwr();
  void linearPbwor();
};

void hashing::linearPbwor(){
  int loc,flag,i;
  student obj;
    do{
      std::cout << "Enter student details" << '\n';
      cin >> obj.rollNo >> obj.name >> obj.grade;
      loc = obj.rollNo % 10;

      if(hashtable[loc].rollNo == -1){
        hashtable[loc].rollNo = obj.rollNo;
        hashtable[loc].name = obj.name;
        hashtable[loc].grade = obj.grade;
      }else{
          i = loc + 1;
          flag = 0;
          while (i != loc) {
            if (hashtable[i].rollNo == -1) {
                flag = 1;
                hashtable[loc].rollNo = obj.rollNo;
                hashtable[loc].name = obj.name;
                hashtable[loc].grade = obj.grade;
                break;
            }
            i = (i+1) % 10;
            flag = 0;

            if (flag == 0) {
              std::cout << "No record" << '\n';
              break;
            }
          }
      }
      std::cout << "Want to add more?" << '\n';
      cin >> ch;
    }while (ch == 'y'|| ch == 'Y');

}

void hashing::linearPbwr()
{
     int ,roll,flag=0;
     string name;
     char grade;
      char ch;
      int newloc;
       student temp;
     do
     {
          cout<<"Enter Students Data"<<endl;
          cout<<"Roll_No:\t";
          cin>>roll;
          cout<<"NAME:\t";
          cin>>name;
          cout<<"Grade:\t";
          cin>>grade;

          int loc;
          loc=roll%MAX;
          if(hashing[loc].roll==-1)
          {
               hashtable[loc].roll=roll;
               hashtable[loc].name=name;
               hashtable[loc].grade=grade;

          }
          else
              {
              newloc=(hashing[loc].roll)%MAX;
                    temp.roll=roll;
                    temp.name=name;
                    temp.grade=grade;
               if(loc!=newloc)
               {

                    temp.roll=hashtable[loc].roll;
                    temp.name=hashtable[loc].name;
                    temp.grade=hashtable[loc].grade;
                    hashtable[loc].roll=roll;
                    hashtable[loc].name=name;
                    hashtable[loc].grade=grade;

               }


               int i;
               i=(loc+1)%MAX;

               while(i!=loc)
               {
                    if(hashing[i].roll==-1)
                    {
                        hashtable[i].roll=temp.roll;
                        hashtable[i].name=temp.name;
                        hashtable[i].grade=temp.grade;
                        flag=1;
                        break;
                    }
                    i=(i+1)%MAX;
               }
               if(flag==0)
               {
                    cout<<"Hashtable FULL"<<endl;
               }

               }

     cout<<"Do you want to add more??";
     cin>>ch;
     }while(ch=='y');

}


void hashing::display(){
  std::cout << "student details are::" << '\n';
  std::cout << "Roll NO "<<'\t'<<"Name"<<'\t'<<"Grade" << '\n';
  for (int i = 0; i < 10; i++) {
        std::cout <<hashtable[i].rollNo << '\t' << hashtable[i].name<<'\t'<<hashtable[i].grade << '\n';
  }
}


int main() {
  hashing obj;
  obj.linearPbwor();
  obj.display();

  return 0;
}
