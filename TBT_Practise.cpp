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

void TBT :: create(node *head){
    root = new (node);
    std::cout << "Enter root data " << '\n';
    std::cin >> root->data;
    head->left = root;
    head->lbit = 1;
    root->left = head;
    root->right = head;
    root->lbit = root->rbit = 0;

    char ch,ch2;
    do {
      curr = new(node);
      std::cout << "Enter new data " << '\n';
      std::cin >> curr->data;
      curr->lbit = 0;
      curr->rbit = 0;
      temp = root;

      while (1) {
      std::cout << "Add this to the left of "<<temp->data<<" or the right ??" << '\n';
      std::cin >> ch;
      if(ch == 'l'||ch=='L'){
        if(temp->lbit == 1){
          temp = temp->left;
        }else{
          curr->left = temp->left;
          temp->left = curr;
          curr->right = temp;
          temp->lbit = 1;
          break;
        }
      }else{
        if(temp->rbit == 1){
          temp = temp->right;
        }else{
          curr->right = temp->right;
          temp->right = curr;
          curr->left = temp;
          temp->rbit = 1;
          break;
        }
      }

    }

          std::cout << "Want to add more ??" << '\n';
          std::cin >> ch2;
  }while(ch2=='Y'||ch2=='y');
}

void TBT :: inorder(node *head){
  std::cout << "------------INORDER-----------" << '\n';
  temp=head->left;
  while(temp!=head)
  {
        while(temp->lbit!=0)
              temp=temp->left;
              // cout<<temp->data<<" ";
        while(temp->rbit!=1)
        {
              cout<<temp->data<<" ";
              temp=temp->right;
        }
        // if(temp==head)
        //       break;
        cout<<temp->data;
        temp=temp->right;
  }
}

void TBT :: preorder(node *head){
  std::cout << "\n---------PREORDER -----"<<head->data << '\n';
    temp = head->left;
    while (temp!=head) {
      /* code */
      while (1) {
        std::cout << temp->data;

      if(temp->lbit == 1){
        temp=temp->left;
      }else{break;}
      while (temp->rbit!=1) {
        temp = temp->right;
      }
      temp = temp->right;
    }
  }

}


int main() {
  /* code */
  TBT func;
  head = new(node);
  // std::cout << "Enter head data" << '\n';
  head->data = 999;
  head->left = head->right = head;
  head->lbit = 0;
  head->rbit = 1;
  func.create(head);
  func.inorder(head);
  func.preorder(head);
  return 0;
}
