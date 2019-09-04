#include <iostream>
using namespace std;
class node
{
      public:
            int data,lbit,rbit;
            node *left,*right;
};
class TBT {
    public:
 node *root;
 public:
  TBT(){
   root = NULL;
  }
  public:
         void create(node*);
            void inorder(node*);
            void preorder(node*);
};
node *curr,*temp,*head;
void TBT::create(node *head)
{
      root=new(node);
      cout<<"\nEnter root data:";
      cin>>root->data;
      head->left=root;
      head->lbit=1;
      root->left=head;
      root->right=head;
      root->lbit=0;
      root->rbit=0;
      char ch,ch1;
      do
      {
            curr=new(node);
            cout<<"Enter new data:";
            cin>>curr->data;
            curr->lbit=0;
            curr->rbit=0;
            temp=root;
            while(1)
            {
                  cout<<"\nDo you want to insert to the left/right of "<<temp->data<<"?l/r:";
                  cin>>ch;
                  if(ch=='l'||ch=='L')
                  {
                        if(temp->lbit==1)
                        {
                              temp=temp->left;
                        }
                        else
                        {
                              curr->left=temp->left;
                              temp->left=curr;
                              curr->right=temp;
                              temp->lbit=1;
                              break;
                        }
                  }
                  else
                  {
                        if(temp->rbit==1)
                        {
                              temp=temp->right;
                        }
                        else
                        {
                              curr->right=temp->right;
                              temp->right=curr;
                              curr->left=temp;
                              temp->rbit=1;
                              break;
                        }
                  }
            }
            cout<<"Do you want to continue?";
            cin>>ch1;
      }while(ch1=='y'||ch1=='Y');
}

void TBT::inorder(node *head)
{
      temp=head->left;
      while(temp!=head)
      {
            while(temp->lbit!=0)
                  temp=temp->left;
            while(temp->rbit!=1)
            {
                  cout<<temp->data;
                  temp=temp->right;
            }
            if(temp==head)
                  break;
            cout<<temp->data;
            temp=temp->right;
      }
}
void TBT::preorder(node *head)
{
      temp=head->left;
      while(temp!=head)
      {
            while(1)
            {
                  cout<<temp->data;
                  if(temp->lbit==0)
                        break;
                  else
                        temp=temp->left;
            }
            while(temp->rbit!=1)
            {
                  temp=temp->right;
            }
            temp=temp->right;
      }
}

int main()
{
      int choice;
      TBT tbt;
      do
      {
            cout<<"\n\n\n\n\n\tMenu\n1.Create root\n2.Inorder\n3.Preorder\n4.Exit\nEnter Choice:";
            cin>>choice;
            switch(choice)
            {
                  case 1:
                        head=new(node);
                        head->left=head;
                        head->right=head;
                        head->data=999;
                        head->lbit=0;
                        head->rbit=1;
                        tbt.create(head);
                        break;
                  case 2:
                        tbt.inorder(head);
                        break;
                  case 3:
                        tbt.preorder(head);
                        break;
                  case 4:
                        cout<<"enter wrong choice";
                        break;
                  default:
                        cout<<"\nEnter correct choice";
                        break;
            }
      }while(choice<4);
      return 0;
}
