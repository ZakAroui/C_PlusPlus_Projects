#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

typedef struct Node{
    int element;
    Node* next;
    Node* prev;
}Node;

class arrayQueue
{
public:
    arrayQueue()
	{
		f=0;
		r=0;
	};
    void enqueue(int element)
	{
		if((f+1)==r)
			cout<<"The queue is full."<<endl;
		else{
			list[f]= element;
			f= (f+1)%100;
		}
	};
	void dequeue()
	{
		if(!isEmpty())
		{
			cout<<list[r]<<" has been removed."<<endl;
			r= (r+1)%100;
		}
		else
			cout<<"The Queue is empty."<<endl;
	};
    bool isEmpty()
	{
		return f==r;
	};
    int front()
	{
		return list[f-1];
    };
    int back()
	{
		return list[r];
    };
    void travForward()
{
    if(!isEmpty()){
        if(f>r)
        {
            for(int i=r; i<f; i++)
            {
                cout<<list[i]<<" ";
            }
            cout<<endl;
        }
        else{
            int i=r;
            while(1)
            {
                cout<<list[i]<<" ";
                if(i=f-1)
                    return;
                if(i=100)
                    i=0;
                else
                    i++;
            }
        }
    }
            else
                cout<<"The queue is empty"<<endl;
};
    void travBackward()
	{
        if(!isEmpty()){
            if(f>r)
            {
                for(int i=f-1; i>=r; i--)
                {
                    cout<<list[i]<<" ";
                }
                cout<<endl;
            }
            else{
                int i=f;
                while(1)
                {
                    cout<<list[i]<<" ";
                    if(i=r)
                        return;
                    if(i=0)
                        i=100;
                    else
                        i--;
                }
            }
        }
                else
                    cout<<"The queue is empty"<<endl;
    };
    ~arrayQueue(){};
private:
    int list[101];
    int f,r;
};

class arrayStack
{
public:
arrayStack()
{
    f=0;
};

bool isEmpty(){ return f==0;};

int front()
{
    return list[f];
};

void pop()
{
    if(!isEmpty())
    {
        cout<<list[f-1]<<" has been removed."<<endl;
        f--;
    }
    else
        cout<<"The Stack is empty."<<endl;
}
void push(int element)
{
    if(f==101)
        cout<<"The stack is full."<<endl;
    else{
        list[f]= element;
        f++;
    }
};

void travBackward()
{
    if(!isEmpty()){
        for(int i=0; i<f; i++)
        {
            cout<<list[i]<<" ";
        }
        cout<<endl;
    }
            else
                cout<<"The stack is empty"<<endl;
};
void travForward()
    {
        if(!isEmpty()){
            for(int i=f-1; i>=0; i--)
            {
                cout<<list[i]<<" ";
            }
            cout<<endl;
        }
                else
                    cout<<"The stack is empty"<<endl;
};
~arrayStack()
{

};
private:
    int list[101];
    int f;
};

class nodeQueue
{
public:
nodeQueue()
{
    head= (Node*)malloc(sizeof(Node));
    rear= (Node*)malloc(sizeof(Node));
    head->element= NULL;
    rear->element= NULL;
    head->next= rear;
    rear->prev= head;
    head->prev= NULL;
    rear->next= NULL;
};

bool isEmpty(){ return head->next==rear;};

int front()
{
    return head->next->element;
};

int back()
{
    return rear->prev->element;
};

void dequeue()
{
    if(!isEmpty())
    {
        Node* old_n= rear->prev;
        Node* new_n= old_n->prev;
        rear->prev= new_n;
        new_n->next= rear;
        old_n->next= NULL;
        old_n->prev= NULL;
        cout<<old_n->element<<" has been removed."<<endl;
    }
    else
        cout<<"The Queue is empty."<<endl;
};
void enqueue(int element)
{
    Node* old_n= head->next;
    Node* new_n=(Node*)malloc(sizeof(Node));
    new_n->element= element;
    new_n->prev= head;
    new_n->next= old_n;
    old_n->prev= new_n;
    head->next= new_n;
};

void travForward()
{
    if(!isEmpty()){
        Node* index= head->next;
        while(index->next!=NULL)
        {
            cout<<index->element<<" ";
            index= index->next;
        }
        cout<<endl;
    }
            else
                cout<<"The queue is empty"<<endl;
};
void travBackward()
{
    {
        if(!isEmpty()){
            Node* index= rear->prev;
            while(index->prev!=NULL)
            {
                cout<<index->element<<" ";
                index= index->prev;
            }
            cout<<endl;
        }
                else
                    cout<<"The queue is empty"<<endl;
    }
};
~nodeQueue()
{
};
private:
    Node* head;
    Node* rear;
};

class nodeStack
{
public:
nodeStack()
{
    head= (Node*)malloc(sizeof(Node));
    rear= (Node*)malloc(sizeof(Node));
    head->element= NULL;
    rear->element= NULL;
    head->next= rear;
    rear->prev= head;
    head->prev= NULL;
    rear->next= NULL;
};

bool isEmpty(){ return head->next==rear;};

int front()
{
    return head->next->element;
};

void pop()
{
    if(!isEmpty())
    {
        Node* old_n= head->next;
        Node* new_n= old_n->next;
        head->next= new_n;
        new_n->prev= head;
        old_n->next= NULL;
        old_n->prev= NULL;
        cout<<old_n->element<<" has been removed."<<endl;
    }
    else
        cout<<"The stack is empty."<<endl;
};
void push(int element)
{
    Node* old_n= head->next;
    Node* new_n=(Node*)malloc(sizeof(Node));
    new_n->element= element;
    new_n->prev= head;
    new_n->next= old_n;
    old_n->prev= new_n;
    head->next= new_n;
};

void travForward()
{
    if(!isEmpty()){
        Node* index= head->next;
        while(index->next!=NULL)
        {
            cout<<index->element<<" ";
            index= index->next;
        }
        cout<<endl;
    }
            else
                cout<<"The stack is empty"<<endl;
};
void travBackward()
    {
        if(!isEmpty()){
            Node* index= rear->prev;
            while(index->prev!=NULL)
            {
                cout<<index->element<<" ";
                index= index->prev;
            }
            cout<<endl;
        }
                else
                    cout<<"The stack is empty"<<endl;
};
~nodeStack()
{

};
private:
    Node* head;
    Node* rear;
};

int main()
{
    arrayQueue* q1= new arrayQueue();
    nodeQueue* q2= new nodeQueue();
    arrayStack* s1= new arrayStack();
    nodeStack* s2= new nodeStack();
    int main_choice, sec_choice, input;
    while(1)
        {
            system("cls");
            cout<<"1. To use array Stack."<<endl;
            cout<<"2. To use node Stack."<<endl;
            cout<<"3. To use array Queue."<<endl;
            cout<<"4. To use node Queue."<<endl;
            cout<<"5. To Exit."<<endl;
            cin>>main_choice;
            switch(main_choice)
            {
            case 1:
                while(main_choice==1)
                {
                    system("cls");
                    cout<<"1. To push an element."<<endl;
                    cout<<"2. To pop an element."<<endl;
                    cout<<"3. To print in forward the stack."<<endl;
                    cout<<"4. To print in backward the stack."<<endl;
                    cout<<"5. To Exit."<<endl;
                    cin>>sec_choice;
                    switch(sec_choice)
                    {
                    case 1:
                        cout<<"Enter an integer."<<endl;
                        cin>>input;
                        s1->push(input);
                        cout<<"Press a key."<<endl;
                        _getch();
                        break;
                    case 2:
                        s1->pop();
                        cout<<"Press a key."<<endl;
                        _getch();
                        break;
                    case 3:
                        cout<<"The stack contains: "<<endl;
                        s1->travForward();
                        cout<<"Press a key."<<endl;
                        _getch();
                        break;
                    case 4:
                        cout<<"The stack contains: "<<endl;
                        s1->travBackward();
                        cout<<"Press a key."<<endl;
                        _getch();
                        break;
                    case 5:
                        main_choice=0;
                        break;
                    default:
                        cout<<"Incorrect choice."<<endl;
                        cout<<"Press a key."<<endl;
                        _getch();
                    }
                }
                break;
            case 2:
                while(main_choice==2)
                {
                    system("cls");
                    cout<<"1. To push an element."<<endl;
                    cout<<"2. To pop an element."<<endl;
                    cout<<"3. To print in forward the stack."<<endl;
                    cout<<"4. To print in backward the stack."<<endl;
                    cout<<"5. To Exit."<<endl;
                    cin>>sec_choice;
                    switch(sec_choice)
                    {
                    case 1:
                        cout<<"Enter an integer."<<endl;
                        cin>>input;
                        s2->push(input);
                        cout<<"Press a key."<<endl;
                        _getch();
                        break;
                    case 2:
                        s2->pop();
                        cout<<"Press a key."<<endl;
                        _getch();
                        break;
                    case 3:
                        cout<<"The stack contains: "<<endl;
                        s2->travForward();
                        cout<<"Press a key."<<endl;
                        _getch();
                        break;
                    case 4:
                        cout<<"The stack contains: "<<endl;
                        s2->travBackward();
                        cout<<"Press a key."<<endl;
                        _getch();
                        break;
                    case 5:
                        main_choice=0;
                        break;
                    default:
                        cout<<"Incorrect choice."<<endl;
                        cout<<"Press a key."<<endl;
                        _getch();
                    }
                }
                break;
            case 3:
                while(main_choice==3)
                {
                    system("cls");
                    cout<<"1. To enqueue an element."<<endl;
                    cout<<"2. To dequeue an element."<<endl;
                    cout<<"3. To print in forward the queue."<<endl;
                    cout<<"4. To print in backward the queue."<<endl;
                    cout<<"5. To Exit."<<endl;
                    cin>>sec_choice;
                    switch(sec_choice)
                    {
                    case 1:
                        cout<<"Enter an integer."<<endl;
                        cin>>input;
                        q1->enqueue(input);
                        cout<<"Press a key."<<endl;
                        _getch();
                        break;
                    case 2:
                        q1->dequeue();
                        cout<<"Press a key."<<endl;
                        _getch();
                        break;
                    case 3:
                        cout<<"The queue contains: "<<endl;
                        q1->travForward();
                        cout<<"Press a key."<<endl;
                        _getch();
                        break;
                    case 4:
                        cout<<"The queue contains: "<<endl;
                        q1->travBackward();
                        cout<<"Press a key."<<endl;
                        _getch();
                        break;
                    case 5:
                        main_choice=0;
                        break;
                    default:
                        cout<<"Incorrect choice."<<endl;
                        cout<<"Press a key."<<endl;
                        _getch();
                    }
                }
                break;
            case 4:
                while(main_choice==4)
                {
                    system("cls");
                    cout<<"1. To enqueue an element."<<endl;
                    cout<<"2. To dequeue an element."<<endl;
                    cout<<"3. To print in forward the queue."<<endl;
                    cout<<"4. To print in backward the queue."<<endl;
                    cout<<"5. To Exit."<<endl;
                    cin>>sec_choice;
                    switch(sec_choice)
                    {
                    case 1:
                        cout<<"Enter an integer."<<endl;
                        cin>>input;
                        q2->enqueue(input);
                        cout<<"Press a key."<<endl;
                        _getch();
                        break;
                    case 2:
                        q2->dequeue();
                        cout<<"Press a key."<<endl;
                        _getch();
                        break;
                    case 3:
                        cout<<"The queue contains: "<<endl;
                        q2->travForward();
                        cout<<"Press a key."<<endl;
                        _getch();
                        break;
                    case 4:
                        cout<<"The queue contains: "<<endl;
                        q2->travBackward();
                        cout<<"Press a key."<<endl;
                        _getch();
                        break;
                    case 5:
                        main_choice=0;
                        break;
                    default:
                        cout<<"Incorrect choice."<<endl;
                        cout<<"Press a key."<<endl;
                        _getch();
                    }
                }
                break;
            case 5:
                delete s1;
                delete s2;
                delete q1;
                delete q2;
                return 0;
            default:
                cout<<"Incorrect choice."<<endl;
                cout<<"Press a key."<<endl;
                _getch();
            }
        }
}

