
#include<stack>
#include<iostream>
using namespace std;

class Node
{
  int data;
  Node *left,*right;
  friend class BinaryTree;

public:
  Node()
  {
    data=-999;
    left=NULL;
    right=NULL;
  }
};

class BinaryTree
{
public:
    Node* root;

    BinaryTree()
    {
      root=NULL;
      //root=new Node();
    }


    Node* create_tree_NR(Node* root)
    {
      char choice;
      do {

        if(root==NULL)
        {
          root=new Node();
          cout<<"\nEnter root data:";
          cin>>root->data;
          root->left=root->right=NULL;
        }
        else
        {
          Node* temp=root;
          int flag=0;
          Node* curr=new Node();
          cout<<"\nEnter data:";
          cin>>curr->data;
          curr->left=curr->right=NULL;

          while(flag!=1)
          {
            char ch;
            cout<<"\nEnter "<<temp->data<<"'s L/R:";
            cin>>ch;
            if(ch=='L')
            {
              if(temp->left==NULL)
              {
                temp->left=curr;flag=1;
              }
              else
                temp=temp->left;
            }

            else if (ch=='R')
            {
              if(temp->right==NULL)
              {
                temp->right=curr;flag=1;
              }
              else
                temp=temp->right;
            }
          }
          //root=temp;
          temp=root;
        }
        cout<<"Continue? Y | N\n";
        cin>>choice;

      } while(choice=='Y');

      return root;
    }


    Node* create_tree_rec(Node* root)
    {
      if(root==NULL)
      {
        root=new Node();
        cout<<"\nEnter root data:";
        cin>>root->data;
        root->left=root->right=NULL;
        create_tree_rec(root);
      }
      else{
      char ch;
      cout<<"\nL or R or U of "<<root->data<<"?";
      cin>>ch;
      if(ch=='L')
      {
        Node* curr=new Node();
        cout<<"\nEnter data:";
        cin>>curr->data;
        curr->left=curr->right=NULL;
        if(root->left==NULL)
          root->left=curr;

        create_tree_rec(root->left);

        if(root->right!=NULL)
          create_tree_rec(root->right);
      }

      if(ch=='R')
      {
        Node* curr=new Node();
        cout<<"\nEnter data:";
        cin>>curr->data;
        curr->left=curr->right=NULL;
        if(root->right==NULL)
          root->right=curr;

        create_tree_rec(root->right);
        if(root->left!=NULL)
          create_tree_rec(root->left);
      }
      if(ch=='U')
      {
        create_tree_rec(root);
      }
    }
      return root;
    }


    void preorder_traversal(Node* root)
    {
      if(root!=NULL)
      {
        cout<<root->data<<"\t";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
      }
    }


    void preorder_traversal_NR(Node* root)
    {
      stack <Node*> s;
      Node* temp=root;
      while(1)
      {
        while(temp!=NULL)
        {
          cout<<temp->data<<"\t";
          s.push(temp);
          temp=temp->left;
        }
        if(s.empty())break;

        if(!s.empty())
        {
          temp=s.top();
          s.pop();
        }
        temp=temp->right;
      }
    }

    void inorder_traversal(Node* root)
    {
      if(root!=NULL)
      {
        inorder_traversal(root->left);
        cout<<root->data<<"\t";
        inorder_traversal(root->right);
      }
    }

    void inorder_traversal_NR(Node* root)//only print statement location changed
    {
      stack <Node*> s;
      Node* temp=root;
      while(1)
      {
        while(temp!=NULL)
        {
          //cout<<temp->data<<"\t";
          s.push(temp);
          temp=temp->left;
        }
        if(s.empty())break;

        if(!s.empty())
        {
          temp=s.top();
          cout<<temp->data<<"\t";
          s.pop();
        }
        temp=temp->right;
      }
    }
    void postorder_traversal(Node* root)
    {
      if(root!=NULL)
      {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout<<root->data<<"\t";

      }
    }
    void postorder_traversal_NR(Node* root)
    {
      stack <Node*> s;
      Node* temp=root;
      while(1)
      {
        while(temp!=NULL)
        {
          //cout<<temp->data<<"\t";
          s.push(temp);
          temp=temp->left;
        }
        if(s.top()->right==NULL)
        {
          temp=s.top();
          s.pop();
          cout<<temp->data<<"\t";
        }

        while(!s.empty() && s.top()->right == temp)
        {
          temp=s.top();
          cout<<temp->data<<"\t";
          s.pop();
        }
        if(s.empty())break;

        temp=s.top()->right;
      }
    }
    void erase_tree_NR(Node* root)
    {
      stack <Node*> s;
      Node* temp=root;
      while(1)
      {
        while(temp!=NULL)
        {
          //cout<<temp->data<<"\t";
          s.push(temp);
          temp=temp->left;
        }
        if(s.top()->right==NULL)
        {

          temp=s.top();
          Node* current=temp;
          s.pop();

          cout<<temp->data<<"\t";
          delete current;
        }

        while(!s.empty() && s.top()->right == temp)
        {
          temp=s.top();
          Node* current=temp;
          cout<<temp->data<<"\t";
          s.pop();
          delete current;
        }
        if(s.empty())break;

        temp=s.top()->right;
      }
    }
    void erase_tree(Node* root)
    {
      if(root==NULL)return;
      erase_tree(root->left);
      erase_tree(root->right);
      cout<<"Deleting"<<root->data<<endl;
      delete root;
    }

};
int main()
{
  BinaryTree* b=new BinaryTree();
  //stack <int> s;


  int choice;
  do {
    cout<<"\n___________________________________";
    cout<<"\n0. Exit\n1. Create Tree (Non Recursive)\n2. Create Tree (Recursive) (Whacko)\n3. Display Preorder (Recursive)\n4. Display Preorder (Non Recursive)\n5. Display Inorder (Recursive)\n6. Display Inorder (Non Recursive)\n7. Display Postorder (Recursive)\n8. Display Postorder (Non Recursive)\n9. Erase tree (Recursive)\n10. Erase tree (Non-Recursive)"<<endl;
    cin>>choice;
    switch(choice)
    {
      case 1:b->root=b->create_tree_NR(b->root);
             break;

      case 2:b->root=b->create_tree_rec(b->root);
             break;

      case 3:b->preorder_traversal(b->root);
             break;

      case 4:b->preorder_traversal_NR(b->root);
             break;

      case 5:b->inorder_traversal(b->root);
             break;

      case 6:b->inorder_traversal_NR(b->root);
             break;

      case 7:b->postorder_traversal(b->root);
             break;

      case 8:b->postorder_traversal_NR(b->root);
             break;

      case 9:b->erase_tree(b->root);
            b->root=NULL;
            break;

      case 10:b->erase_tree_NR(b->root);
              b->root=NULL;
              break;
    }
  } while(choice!=0);

  return 0;
}
