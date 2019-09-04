#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string.h>
class binarynode
{
 public:
   int data;
   string meaning;
   binarynode *left;
   binarynode *right;
};
class BST
{
 private:
   binarynode *root;
   void inorder_rec(binarynode *);
   void preorder_rec(binarynode *);
   void postorder_rec(binarynode *);
   int depth_r(binarynode *);
 public:
   BST()
   {
    root=NULL;
   }
   void insert();
   void mirror_r(binarynode *);
   void mirror_r();
   void search();
   void remove();
   int depth_r();
   void print_inorder_rec();
   void print_preorder_rec();
   void print_postorder_rec();
};

binarynode *curr,*temp;
void BST :: insert(){
  // binarynode *temp;
  // binarynode *curr;
  char ch;
    do {
        if(root == NULL){
          root = new binarynode();
          std::cout << "Enter root data" << '\n';
          std::cin >> root->data;
          root->left = root->right = NULL;
        }else{

            curr = new binarynode();
            std::cout << "Enter data" << '\n';
            std::cin >> curr->data;
            curr->left = curr->right = NULL;
            temp=root;
            int flag = 0;
            while (flag == 0) {


            if(temp->data > curr->data){
              if(temp->left == NULL){
                flag = 1;
                temp->left = curr;
              }else{
                temp = temp->left;
              }
            }else if(temp->data < curr->data){
              if(temp->right == NULL){
                flag = 1;
                temp->right = curr;
              }else{
                temp = temp->right;
              }
            }
          }
        }

        std::cout << "Want to continue?" << '\n';
        std::cin >> ch;
    } while(ch == 'y'||ch=='Y');
}



// void BST :: remove(){
//
//     binarynode *curr2,*node;
//     temp = root;
//     int flag =0;
//     curr = new binarynode();
//     std::cout << "Enter data found. " << '\n';
//     std::cin >> node->data;
//       while (flag == 0) {
//         if (temp->left != NULL ) {
//           // if(temp->left != NULL ){
//             curr = temp->left;
//             if(curr->data == node->data){
//                 flag =1;
//                 // delete curr;
//
//                 if(curr->left != NULL){
//                   temp->left = curr->left;
//                   curr2 = temp->left;
//                   if(curr->right != NULL){
//                     curr2->right = curr->right;
//                   }
//                   delete curr;
//               }else{
//                 temp->left = NULL;
//               }
//               // delete curr;
//             }else{
//               flag = 0;
//               temp = temp->left;
//             }
//           }
//
//           // }
//           while (temp->right != NULL) {
//           // temp = root;
//               binarynode *curr2 = new binarynode();
//               curr = temp->right;
//               if(curr->data == node->data){
//                 flag = 1;
//                   if(curr->right != NULL){
//                     curr2 = curr ->right;
//                     if(temp->data < curr2->data){
//                       temp->right = curr2;
//                       if(curr->left != NULL){
//                           curr2->left = curr->left;
//                       }
//                       delete curr;
//                     }else if(curr->left != NULL){
//                       curr2 = curr->left;
//                       temp->right = curr2;
//                       curr2->right = curr->right;
//                       delete curr;
//                     }
//                   }
//               }
//             }
//           }
//
//           if(flag == 0){
//             std::cout << "Element not found" << '\n';
//           }else{
//             print_inorder_rec();
//           }
//         }

void BST :: remove(){
  binarynode * temp = root;
  binarynode * parent;
  binarynode * curr = new binarynode();
  curr = NULL;
  int key;
  cout << "Enter the word to be deleted: ";
  cin >> key;

  while (temp != NULL) {
    if(key == temp->data){
      curr = temp;
      break;
    }else if(key < temp->data){
      parent = temp;
      temp = temp->left;

    }else{
      parent = temp;
      temp = temp->right;
    }
  }
  if(curr == NULL)
  {
          cout <<"Element not found!" << endl;
          return;
  }
  else{
    if(curr == root){
      if(curr->right == NULL){
        root = root->left;
        curr->left = NULL;
        delete curr;
      }else if(curr->left == NULL){
        root = root->right;
        curr->right = NULL;
        delete curr;
      }
      else{
        root = root->right;
        temp = curr->left;

        binarynode *s = root;
        while (s->left !=  NULL) {
          s = s->left;
        }
        s->left = temp;
        curr->left = curr->right = NULL;
        delete curr;
      }


    }else{
        if(curr->left == NULL && curr->right == NULL){
          if(curr == parent->left){
            parent->left = NULL;
          }else if(curr == parent->right){
            parent->right = NULL;
          }
          delete curr;
        }
        else if(curr->right == NULL){
          if(curr == parent->left){
            parent->left = curr->left;
          }else if(curr == parent->right){
            parent->right = curr->left;
          }
          delete curr;
        }
        else if(curr->left == NULL){
          if(curr == parent->left){

            parent->left = curr->right;

          }else if(curr == parent->right){

            parent->right = curr->right;

          }
          delete curr;
        }
        else{
          binarynode *temp1 = curr->right;
          temp = curr -> left;
          binarynode * s = temp1;
          while(s->left != NULL)
          {
                  s = s->left;
          }
          s->left = temp;
          if(curr == parent->left){
            parent->left = temp1;
          }else{
            parent->right = temp1;
          }
          curr->left = curr->right = NULL;
          delete curr;
        }
    }
  }
  print_inorder_rec();
}




//INORDER
void BST :: print_inorder_rec(){
  inorder_rec(root);
}
void BST :: inorder_rec(binarynode *node){
    if(node != NULL){
      inorder_rec(node->left);
      std::cout <<node->data<<" ";
      inorder_rec(node->right);
    }
    // std::cout <<'\n';
}

//PREORDER
void BST::print_preorder_rec()
{
 cout<<"  ";
 preorder_rec(root);
 cout<<"  ";
}

void BST::preorder_rec(binarynode *root)
{
 if(root!=NULL)
 {
   cout<<root->data<<" ";
   preorder_rec(root->left);
   preorder_rec(root->right);
 }
}

//postorder
void BST::print_postorder_rec()
{
 cout<<"  "<<endl;
 postorder_rec(root);
 cout<<"  "<<endl;
}

void BST::postorder_rec(binarynode *root)
{
 if(root!=NULL)
 {
  postorder_rec(root->left);
  postorder_rec(root->right);
  cout<<root->data<<" ";
 }
}

int main(){
  BST obj;
  obj.insert();
  std::cout << "--------INORDER------" << '\n';
  obj.print_inorder_rec();
  std::cout << "\n--------PREORDER-----" << '\n';
  obj.print_preorder_rec();
  std::cout << "\n-------POSTORDER------" << '\n';
  obj.print_postorder_rec();

  obj.remove();
}
