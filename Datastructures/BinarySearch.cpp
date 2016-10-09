#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>

using namespace std;

typedef struct node{
    string element;
    node* right;
    node* left;
}node;

typedef struct tree{
    node* head;
}tree;

void init(tree* t,string str)
{
    t->head= (node*)malloc(sizeof(node));
    t->head->element=str;
    t->head->left= NULL;
    t->head->right= NULL;
}

void insert(tree* t,string str)
{
    node* index= t->head;
    bool done= false;
    while(!done)
    {
        if(str==index->element)
        {
            cout<<"name already exist"<<endl;
            done=true;
        }
        if(str<index->element)
        {
            if(index->left==NULL)
            {
                node* temp= (node*)malloc(sizeof(node));
                temp->element= str;
                temp->left= NULL;
                temp->right=  NULL;
                index->left= temp;
                done= true;
            }
            else
                index= index->left;
        }
        else
        {
            if(index->right==NULL)
            {
                node* temp= (node*)malloc(sizeof(node));
                temp->element= str;
                temp->left= NULL;
                temp->right=  NULL;
                index->right= temp;
                done= true;
            }
            else
                index= index->right;
        }
    }
}

void in_order(node* n)
{
    if(n!=NULL)
    {
        in_order(n->left);
        cout<< n->element << endl;
        in_order(n->right);
    }
}
void pre_order(node* n)
{
    if(n!=NULL)
    {

        cout<< n->element << endl;
        pre_order(n->left);
        pre_order(n->right);
    }
}
void post_order(node* n)
{
    if(n!=NULL)
    {

        post_order(n->left);
        post_order(n->right);
        cout<< n->element << endl;
    }
}



int main()
{
    tree* t1= (tree*)malloc(sizeof(tree));

    int main_choice;
    string name("bado");

    cout<<"Welcome to the Binary Search Tree program"<<endl;
    cout<<"Press a key."<<endl;
   // _getch();
   // system("cls");
    cout<<"enter a name to initalize the BST"<<endl;
    cin>>name;
    init(t1, name);

     while(1)
        {

            cout<<"1. To enter a new name."<<endl;
            cout<<"2. To do the in order traversal of the BST."<<endl;
            cout<<"3. To do the pre order traversal of the BST ."<<endl;
            cout<<"4. To do the post order traversal of the BST."<<endl;
            cout<<"5. To Exit."<<endl;
            cin>>main_choice;
            switch(main_choice)
            {
            case 1:
                cout<< "enter the name you want to add"<<endl;
                cin>>name;
                insert(t1, name);

                break;
            case 2:
               in_order(t1->head);

                break;
            case 3:
                pre_order(t1->head);

                break;
            case 4:
                post_order(t1->head);

                break;
            case 5:
                return 0;
            default:
                cout<<"Incorrect choice."<<endl;

            }
        }
}
