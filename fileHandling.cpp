#include <iostream>
#include <fstream>
// #include <conio.h>

int main ()    //totrec variable keep track for total variable entered//Initially Record scanned are Zerovoid main()
{int totrec=0;
int choice;
while(1)
{
clrscr();
cout<<"Choose your choice\nNOTE : one choice for one record(except viewing data)\n";
cout<<"1) Scanning intial records\n";
cout<<"2) Appending records\n";
cout<<"3) Modifying or append records\n";
cout<<"4) Viewing records\n";
cout<<"5) Exit\n";
cout<<"Enter your choice : ";
cin>>choice;
switch (choice)
{
  case 1 :   {
         ofstream outfile;
         outfile.open("emp",ios::out);
         cout<<"\n\nPlease enter the details as per demanded\n";
         cout<<"\nEnter the name : ";
         char name[20];
         cin>>name;
         outfile<<name<<endl;
         cout<<"Enter Age : ";
         int age;
         cin>>age;
         outfile<<age<<endl;
         cout<<"Enter programming language known by him\her : ";
         char lang[25];
         cin>>lang;
         outfile<<lang<<endl;
         totrec= totrec + 1;
         outfile.close();
         }
         break;
  case 2 :   {
         ofstream outfile;
         outfile.open("emp",ios::app);
         cout<<"\n\nPlease enter the details as per demanded\n";
         cout<<"\nEnter the name : ";
         char name[20];
         cin>>name;
         outfile<<name<<endl;
         cout<<"Enter Age : ";
         int age;
         cin>>age;
         outfile<<age<<endl;
         cout<<"Enter programming language known by him : ";
         char lang[25];
         cin>>lang;
         outfile<<lang<<endl;
         totrec = totrec + 1;
         outfile.close();
         }
         break;
  case 3 :   {
         ofstream outfile;
         outfile.open("emp",ios::ate);
         cout<<"Are you interested in adding record\nenter y or n\n";
         char ans;
         cin>>ans;
         if(ans=='y' || ans=='Y')
         {
         cout<<"\n\nPlease enter the details as per demanded\n";
         cout<<"\nEnter the name : ";
         char name[20];
         cin>>name;
         outfile<<name<<endl;
         cout<<"Enter Age : ";
         int age;
         cin>>age;
         outfile<<age<<endl;
         cout<<"Enter programming language known by him : ";
         char lang[25];
         cin>>lang;
         outfile<<lang<<endl;
         totrec = totrec + 1;
         }
         outfile.close();
         }
         break;
  case 4 :   {
         ifstream infile;
         infile.open("emp",ios::in);
         constint size=80;
         char line[size];
         int counter=totrec;
         while(counter > 0)
         {
         infile.getline(line,size);
         cout<<"\n\nNAME     : "<<line<<endl;
         infile.getline(line,size);
         cout<<"AGE      : "<<line<<endl;
         infile.getline(line,size);
         cout<<"LANGUAGE : "<<line<<endl;
         counter--;
         }
         infile.close();
         }
         getch();
         break;
  case 5  :  gotoout;
  default :  cout<<"\nInvalid Choice\nTRY AGAIN\n";
  }
}
return 0;
}
