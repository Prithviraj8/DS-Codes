#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string.h>
class binarynode
{
 public:
   string keyword;
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

void BST::insert()
{
 char choice;
 binarynode *temp;
 binarynode *curr;
 int flag;
 do
  {
   if(root==NULL)
    {
     root=new binarynode();
     cout<<"enter keyword of root\n";
     cin>>root->keyword;
     cout<<"enter meaning of root\n";
     cin>>root->meaning;
     root->left=root->right=NULL;
    }
   else
   {
    temp=root;
    curr=new binarynode();
    cout<<"enter the keyword\n";
    cin>>curr->keyword;
    cout<<"enter the meaning\n";
    cin>>curr->meaning;
    curr->left=curr->right=NULL;
    flag=0;

while (flag==0)
 {
      if (temp->keyword > curr->keyword)
       {
        if (temp->left==NULL)
          {
            flag=1;
            temp->left=curr;
          }
        else
          temp=temp->left;
       }

      else if ( temp->keyword < curr->keyword)
         {
           if (temp->right==NULL)
            {
             flag=1;
             temp->right=curr;
            }
           else
             temp=temp->right;
         }
       else
          flag=1;
       }
   }
    cout<<"do you want to continue Y or N\n";
    cin>>choice;
  }while(choice=='Y' || choice=='y');
}
void BST::remove()
{
  string key;
        binarynode * temp = root;
        binarynode * parent;
        binarynode * curr = new binarynode();
        curr = NULL;
        cout << "Enter the word to be deleted: ";
        cin >> key;
        while(temp != NULL)
        {
                if(key == temp->keyword)
                {
                        curr = temp;
                        break;
                }
                else if(key < temp->keyword)
                {
                        parent = temp;
                        temp = temp->left;
                }
                else if(key > temp->keyword)
                {
                        parent = temp;
                        temp = temp->right;
                }
        }
        if(curr == NULL)
        {
                cout <<"Element not found!" << endl;
                return;
        }
        else
        {
                if(curr == root)
                {
                        if(curr->right == NULL)
                        {
                                root = root->left;
                                curr->left = NULL;
                                delete curr;
                        }
                        else if(curr->left == NULL)
                        {
                                root = root->right;
                                curr->right = NULL;
                                delete curr;
                        }
                        else
                        {
                                root = root->right;
                                temp = curr->left;
                                binarynode * s = root;
                                while(s->left != NULL)
                                {
                                        s = s->left;
                                }
                                s->left = temp;
                                curr->left = curr->right = NULL;
                                delete curr;
                        }
                }
                else
                {
                        if(curr->left == NULL && curr->right == NULL)
                        {
                                if(curr == parent->left)
                                {
                                        parent->left = NULL;
                                }
                                else
                                {
                                        parent->right = NULL;
                                }
                                delete curr;
                        }
                        else if(curr->right == NULL)
                        {
                                if(curr == parent->left)
                                {
                                        parent->left = curr->left;
                                }
                                else
                                {
                                        parent->right = curr->left;
                                }
                                curr->left = NULL;
                                delete curr;
                        }
                        else if(curr->left == NULL)
                        {
                                if(curr == parent->left)
                                {
                                        parent->left = curr->right;
                                }
                                else
                                {
                                        parent->right = curr->right;
                                }
                                curr->right = NULL;
                                delete curr;
                        }
                        else
                        {
                                binarynode * temp1 = curr->right;
                                temp = curr->left;
                                binarynode * s = temp1;
                                while(s->left != NULL)
                                {
                                        s = s->left;
                                }
                                s->left = temp;
                                if(curr == parent->left)
                                {
                                        parent->left = temp1;
                                }
                                else
                                {
                                        parent->right = temp1;
                                }
                                curr->left = curr->right = NULL;
                                delete curr;
                        }
                }
        }
}
void BST::mirror_r(binarynode *root)
{
   binarynode *temp;
   if (root == NULL)
        return;
   temp = root->left;
   root->left = root->right;
   root->right = temp;
      if(root->left!=NULL)
      mirror_r(root->left);
      if(root->right!=NULL)
       mirror_r(root->right);
}
void BST::search()
{
  binarynode *temp= root;
  string word;
  bool found=false;
  cout<<"enter the word to be found\n";
  cin>>word;
  while(temp!=NULL){
    if (temp->keyword==word){
        found = true;
        break;
    }
    else if (word < temp->keyword){
        temp=temp->left;
    }
    else {
        temp=temp->right;
    }
  }
  if (found == true)
    {
    cout<<"the word is:"<<temp->keyword<<"was found"<<endl;
    }
    else{
     cout<<"the word is:"<<word<<"was not found"<<endl;
    }
}
int BST:: depth_r()
{
  int d;
  d =depth_r(root);
  cout<<"height of the tree:"<<d;
  return 0;
}
int BST:: depth_r(binarynode *root)
{
int leftdepth=0,rightdepth=0;
 if(root==NULL)
  return 0;
 else
 {
  leftdepth=depth_r(root->left);
  rightdepth=depth_r(root->right);
  if(leftdepth>rightdepth)
  return ++leftdepth;
  else
  return ++rightdepth;
}
}
void BST::mirror_r()
{
    mirror_r(root);
    print_inorder_rec();
}

//Inorder
void BST::print_inorder_rec()
{
 cout<<"  ";
 inorder_rec(root);
 cout<<"  ";
}

void BST::inorder_rec(binarynode *root)
{
  if(root!=NULL)
  {
   inorder_rec(root->left);
   cout<<root->keyword<<" ";
   inorder_rec(root->right);
  }
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
   cout<<root->keyword<<" ";
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
  cout<<root->keyword<<" ";
 }
}





int main()
{
 BST BST;
 int ch;
 do
 {
  cout<<"\n1.Insert a node in binary tree\n";
  cout<<"2.Recursive Inorder traversal\n";
  cout<<"3.Recursive preorder traversal\n";
  cout<<"4.Recursive postorder traversal\n";
  cout<<"5.delete a node from tree\n";
  cout<<"6.mirror image of binary search tree\n";
  cout<<"7.Search a word\n";
  cout<<"8.height of the tree\n";
  cout<<"9.Exit\n";
  cout<<"Enter your choice\n";
  cin>>ch;
  switch(ch)
  {
   case 1:
    BST.insert();
    break;
   case 2:
    cout<<"Recursive Inorder traversal\n";
    BST.print_inorder_rec();
    break;
   case 3:
    cout<<"Recursive preorder traversal\n";
    BST.print_preorder_rec();
    break;
   case 4:
    cout<<"Recursive postorder traversal\n";
    BST.print_postorder_rec();
    break;
   case 5 :
    BST.remove();
    break;
   case 6 :
    cout<<"Recursive mirror image"<<endl;
    BST.mirror_r();
    break;
   case 7:
    BST.search();
    break;
   case 8:
      BST.depth_r();
   case 9:
    exit(1);
  }
 }while(ch<9);
 return 0;
}
