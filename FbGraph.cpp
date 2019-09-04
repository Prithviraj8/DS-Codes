
#include<iostream>            //including the input-output stream header file
using namespace std;        //using the standard name space to resolve ambiguity

class node                    //declaring a class
{
    int ID;
    string username;
    node * next;
public:

    node()
    {
        ID = 0;
        username = "\0";
        next = NULL;
    }
    friend class graph;        //declaring a friend class
};

class stack                    //declaring a class
{
    int top;
    int datastack[20];
public:
    stack()
    {
        top = -1;
    }

    void push(int temp)                //function to push an element onto the stack
    {
        top++;
        datastack[top] = temp;
    }
    int isempty()                    //function to check whether the stack is empty or not
    {
        if(top == -1)
            return 1;
        else
            return 0;
    }
    int pop()                        //function to pop an element from the stack
    {
        if(isempty() != 1)
        {
            int temp = datastack[top];
            top--;
            return temp;
        }
        else
            return 0;
    }
    friend class graph;        //declaring a friend class
};

class queue                    //declaring a class
{
    int front, rear;
    int dataqueue[20];
public:
    queue()
    {
        front = rear = -1;
    }

    void enqueue(int temp)                //function to add an element to the queue
    {
        rear++;
        dataqueue[rear] = temp;
    }
    int isempty()                        //function to check whether the queue is empty or not
    {
        if(rear == front)
            return 1;
        else
            return 0;
    }
    int dequeue()                        //function to delete an element from the queue
    {
        if(isempty() != 1)
        {
            front++;
            int temp = dataqueue[front];
            return temp;
        }
        else
            return 0;
    }
    friend class graph;        //declaring a friend class
};

class graph                    //declaring a class
{
    int NoV;
    node * head[10];
public:
   graph()
{
        NoV = 0;
        cout<<"Please enter the number of vertices."<<endl;
        cin>>NoV;
        for(int i = 0; i < NoV; i++)
        {
            head [i] = new node;
            head[i]->ID = i;
            cout<<"Please enter the user-name of user #"<<head[i]->ID<<"."<<endl;
            cin>>head[i]->username;
        }
}
    void create();                    //function to create the graph
    void DFS_R();                    //driver function to perform depth first traversal of the graph recursively
    void DFS_R(int , int *);        //workhorse function to perform depth first traversal of the graph recursively
    void DFS_NR(int);                //function to perform depth first traversal of the graph non - recursively
    void BFS_NR(int);                //function to perform breadth first traversal of the graph non - recursively
};


void graph :: create ()
{
    for(int i = 0; i < NoV; i++)
    {
        node * temp = head[i];
        cout<<"Please enter the friends of user #"<<head[i]->ID<<"."<<endl;
         int dw;
        do
        {
            int id;
            cout<<"Please enter the friend's ID."<<endl;
            cin>>id;
            if(id == head[i]->ID)
            {
                cout<<"Can't be your own friend "<<endl;
            }
            else
            {
                node * current = new node;
                current->ID = id;
                current->username = head[id]->username;
                temp->next = current;
                temp = temp->next;
            }
            cout<<"Do you want to add more friends?   \n1.Yes \n2.No"<<endl;
            cin>>dw;
        }while(dw == 1);
    }
}

void graph :: DFS_R()                                //driver function
{
    int visited[10];
    for(int i = 0; i < NoV; i++)
        visited[i] = 0;
    int sv;
    cout<<"Please enter the ID of starting user."<<endl;
    cin>>sv;
    DFS_R(sv, visited);
    cout<<endl;
}
void graph :: DFS_R(int v, int visited[10])            //workhorse function
{
    cout<<head[v]->username<<"\t";
    visited[v] = 1;
    node * temp = head[v]->next;
    if(visited[temp->ID] == 0)
        DFS_R(temp->ID, visited);
    else
    {
        temp = temp->next;
        if(temp != NULL && visited[temp->ID] == 0)
            DFS_R(temp->ID, visited);
    }
}

void graph :: DFS_NR(int v)
{
    int visited[10];
    for(int i = 0; i < NoV; i++)
        visited[i] = 0;
    stack S;
    S.push(v);
    visited[v] = 1;
    do
    {
        v = S.pop();
        cout<<head[v]->username<<"\t";
        node * temp = head[v]->next;
        while(temp != NULL)
        {
            if(visited[temp->ID] == 0)
            {
                S.push(temp->ID);
                visited[temp->ID] = 1;
            }
            temp = temp->next;
        }
    }while(S.isempty() != 1);
    cout<<endl;
}

void graph :: BFS_NR(int v)
{
    int visited[10];
    for(int i = 0; i < NoV; i++)
        visited[i] = 0;
    queue Q;
    Q.enqueue(v);
    visited[v] = 1;
    while(Q.isempty() != 1)
    {
        v = Q.dequeue();
        cout<<head[v]->username<<"\t";
        node * temp = head[v]->next;
        while(temp != NULL)
        {
            if(visited[temp->ID] == 0)
            {
                Q.enqueue(temp->ID);
                visited[temp->ID] = 1;
            }
            temp = temp->next;
        }
    }
    cout<<endl;
}


int main()                    //declaring and defining the main method
{
    graph G;                //creating an object of the class
    int choice;            //declaring variables
    do
    {
        cout<<"Please select from the following choices..."<<endl;
        cout<<"1. Create the network"<<endl;
        cout<<"2. Depth first traversal (recursive)"<<endl;
        cout<<"3. Depth first traversal (non-recursive)"<<endl;
        cout<<"4. Breadth first traversal "<<endl;
        cout<<"5. Exit"<<endl;
        cin>>choice;        //accepting the choice of the user
        switch(choice)        //switch - case block
        {
        case 1 : G.create();
                 break;
        case 2 : G.DFS_R();
                 break;
        case 3 : {int sv;
                 cout<<"Please enter ID of the starting user."<<endl;
                 cin>>sv;
                 G.DFS_NR(sv);
                 break;}
        case 4 : {int sv;
                 cout<<"Please enter ID of the starting user."<<endl;
                 cin>>sv;
                 G.BFS_NR(sv);
                 break;}
        case 5 : break;
        default : cout<<"An invalid choice has been entered!"<<endl;
        }
    }while(choice != 5);
    return 0;
}
