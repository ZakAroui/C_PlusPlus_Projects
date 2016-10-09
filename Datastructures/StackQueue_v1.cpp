#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;


struct Node{
    Node* next;
    Node* previous;
    int element;
};

struct List{
    Node* top;
    Node* last;
    int size;
};

struct ArrayList{
    int element[50];
    int size;
};


void insertAr(ArrayList listAQ, int input)  //Array stack and queue insertion
{
      listAQ.element[++listAQ.size]=input;
}

void insertStack(List* list1, int input)  //pointer stack push
{
    Node* n_in = (Node*) malloc(sizeof(Node));
    n_in->element= input;
    Node* index= list1->top;

        n_in->next= index->next;
        index->next= n_in;
        list1->size++;
}

void insertQueue(List* list2, int input)  //Pointer queue enqueue
{
    Node* nw_in = (Node*) malloc(sizeof(Node));
    Node* past_in = list2->top->next;
    nw_in->element = input;

    Node* indexT= list2->top;

        nw_in->next= indexT->next;
        nw_in->previous= past_in->previous;
        past_in->previous= nw_in;
        indexT->next= nw_in;
        list2->size++;
}

void printArrFrwrd(ArrayList list3)  // print the chosen Array forward
{

      cout<<"first ............";
    for(int i=1 ; i<= list3.size; i++)
    {
        cout<<" "<<list3.element[i];
    }
    cout<<"........last";
    cout<<endl;
}
void printPnt(List* list1) // print the chosen pointerlist forward
{
    Node* index= list1->top;
    cout<<"last............";
    for(int i=0; i<list1->size; i++)
    {
        index= index->next;
        cout<<" "<<index->element;
    }
    cout<<"............first ";
    cout<<endl;
  }
void printArrBack(ArrayList list3)//print the chosen arry backward
{
    cout<<"last ............";
    for(int i=list3.size; i>=1; i--)
    {
        cout<<" "<<list3.element[i];
    }
    cout<<"........first";
    cout<<endl;
}

void deleteStackAr(ArrayList list3)  // Array stack pop
{
    list3.size--;
}
void deleteQueueAr(ArrayList list4)  // Array queue dequeue
{
    for(int i=1;i<list4.size;i++)
    {
        list4.element[i]=list4.element[i+1];
    }
    list4.size--;
}

void deleteStack(List* list1)  //Pointer stack pop
{
    if(list1->size>0)
    {
        Node* index= list1->top;
        //Node* temp=index->next->next;

        index->next= index->next->next;
       // index->next->next=NULL;

        list1->size--;
    }
}

void deleteQueue(List* list2)  // Pointer queue dequeue
{
    Node* indexL= list2->last;
    Node* first_in= indexL->previous;
    Node* Pfirst_in= indexL->previous->previous;

    Pfirst_in->next= first_in->next;
    indexL->previous= Pfirst_in;
    first_in->next= NULL;
    first_in->previous= NULL;
    list2->size --;

}
bool PQempty(List* list1){return list1->top->next == list1->last;}
bool PSempty(List* list2){return list2->top-> == NULL;}
bool AQempty(){}
bool ASempty(){}

void initStckQue(List* PStck, List* PQue, ArrayList Astck, ArrayList Aque)  //initializing everthing
{
    PStck->top->next= NULL;

    PQue->top->next= PQue->last; PQue->top->previous= NULL;
    PQue->last->previous= PQue->top; PQue->last->next= NULL;

    PStck->size= 0; PQue->size= 0; Astck.size= 0; Aque.size= 0;
}

int main()
{
    List* listStack;       //Pointer stack
    List* listQueue;       //Pointer queue
    ArrayList Astack;  //Array stack
    ArrayList Aqueue;  //Array queue

    initStckQue(listStack, listQueue, Astack, Aqueue);
    int select,a; int ele;
    int b=1;
    while(b != 5)
    {
        system("cls");
        cout<<"choose : \n 1 for Array usage\n 2 for pointer usage \n 3 to exit"<<endl;
        cin>>select;

        while(select==1)
        {
                 system("cls");
                 cout<<" choose: \n 1 to insert stack \t\t 2 to insert queue \n 3 to delete stack \t\t 4 to delete queue \n 5 print Stack forward \t\t 6 to print queue forward \n 7 print Stack backward \t 8 to print queue backward \n 9 to go back"<<endl;
                 cin>>a;
                 switch(a)
                 {
                     case 1:
                          cout<<"enter the element"<<endl;
                          cin>>ele;
                          insertAr(Astack,ele);
                          cout<<"press a key to continue"<<endl;
                          _getch();
                          break;
                    case 2:
                         cout<<"enter the element"<<endl;
                          cin>>ele;
                          insertAr(Aqueue,ele);
                          cout<<"press a key to continue"<<endl;
                          _getch();
                          break;
                    case 3:
                          deleteStackAr(Astack);
                          cout<<"press a key to continue"<<endl;
                          _getch();
                          break;
                    case 4:
                          deleteQueueAr(Aqueue);
                          cout<<"press a key to continue"<<endl;
                          _getch();
                          break;
                    case 5:
                         printArrFrwrd(Astack);
                         cout<<"press a key to continue"<<endl;
                         _getch();
                         break;
                    case 6:
                         printArrFrwrd(Aqueue);
                         cout<<"press a key to continue"<<endl;
                         _getch();
                         break;
                    case 7:
                         printArrBack(Astack);
                         cout<<"press a key to continue"<<endl;
                         _getch();
                         break;
                    case 8:
                         printArrBack(Aqueue);
                         cout<<"press a key to continue"<<endl;
                         _getch();
                         break;
                    case 9:
                         select=0;
                         break;
                 }

        }
        while(select==2)
        {
                 system("cls");
                 cout<<" choose: \n 1 to insert stack \t 2 to insert queue \n 3 to delete stack \t 4 to delete queue \n 5 print Stack \t\t 6 to print queue \n 7 to go back"<<endl;
                 cin>>a;
                 switch(a)
                 {
                     case 1:
                          cout<<"enter the element"<<endl;
                          cin>>ele;
                          insertStack(listStack,ele);
                          cout<<"press a key to continue"<<endl;
                          _getch();
                          break;
                    case 2:
                         cout<<"enter the element"<<endl;
                          cin>>ele;
                          insertQueue(listQueue,ele);
                          cout<<"press a key to continue"<<endl;
                          _getch();
                          break;
                    case 3:
                          deleteStack(listStack);
                          cout<<"press a key to continue"<<endl;
                          _getch();
                          break;
                    case 4:
                          deleteQueue(listQueue);
                          cout<<"press a key to continue"<<endl;
                          _getch();
                          break;
                    case 5:
                         printPnt(listStack);
                         cout<<"press a key to continue"<<endl;
                         _getch();
                         break;
                    case 6:
                         printPnt(listQueue);
                         cout<<"press a key to continue"<<endl;
                         _getch();
                         break;
                    case 7:
                         select=0;
                         break;
                 }


        }
        while(select==3)
        {
              return 0;

        }

    }

}
