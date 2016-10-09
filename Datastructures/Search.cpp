#include<iostream>
#define nb 4
#include<stdlib.h>
using namespace std;

int sT = 0;
typedef struct node
        {
            int parent;
            int left;
            int right;
            float freq;
            unsigned checked;
        }Node;

char alphabet[nb];
Node tree[2*nb-1];

void initialize()
{
    cout<<"Initializing... \n\n";
    int i=0;
    for (i; i<nb;i++)
    {
        cout<<"Enter a character \n";
        cin>> (alphabet)[i] ;
        cout<<"Enter its frequency \n";
        cin>>((tree)[i].freq);
        (tree[i]).parent =-1;
        (tree[i]).left =-1;
        (tree[i]).right =-1;
        tree[i].checked=0;
    }
    for(i=nb;i<2*nb-1;i++)
    {
        (tree)[i].freq=1;
        (tree)[i].parent=-1;
        (tree)[i].left=-1;
        (tree)[i].right=-1;
        tree[i].checked=0;
    }
}
void huffman()
{
    unsigned cursor,smlstLeft,smlstRight;
    cursor=nb;

    while (cursor < (2*nb-1))
    {
        int i=0,j=0;
        while (tree[i].checked==1)
            i++;
        smlstLeft=i;
        for(i=smlstLeft; i < cursor ; i++)
        {
            if (tree[i].parent== -1 && tree[i].checked==0 && tree[i].freq<=tree[smlstLeft].freq)
                smlstLeft=i;
        }
        tree[smlstLeft].checked=1;

        while (tree[j].checked==1)
            j++;
        smlstRight=j;
        for(j=smlstRight; j < cursor ; j++)
        {
            if (tree[j].parent== -1 && tree[j].checked==0 && tree[j].freq<=tree[smlstRight].freq)
                smlstRight=j;
        }
        tree[smlstRight].checked=1;

        (tree)[smlstLeft].parent=cursor;
        (tree)[smlstRight].parent=cursor;
        (tree)[cursor].freq=(tree)[smlstLeft].freq+(tree)[smlstRight].freq;
        (tree)[cursor].left=smlstLeft;
        (tree)[cursor].right=smlstRight;
        cout<<"Node with frequency "<< tree[cursor].freq<< "\nleft is "<< tree[smlstLeft].freq<< " right is "<< tree[smlstRight].freq<<endl<<endl;
        cursor++;
    }
}
void displaytree(int cursor)
{

       if(tree[cursor].left!=-1 && tree[cursor].right!=-1){
           for(int s=0;s<sT;s++)
               cout<<"\n\t";
               sT++;
            cout<<tree[cursor].freq;
            displaytree(tree[cursor].left);
            cout<<"\t";displaytree(tree[cursor].right);
        }
       else{
           cout<<"\t";
           cout<<tree[cursor].freq <<" : "<<alphabet[cursor]<<endl;}
    /*for (int i=0; i < ( 2*nb-1);i++)
    {
        cout<<"node " <<i<< "\t parent "<<tree[i].parent<<"\n\t left"<<tree[i].left<<" \t right"<<tree[i].right<<"\t frequency"<<tree[i].freq<<endl;
    }*/
}
void Code(char ch)
{
    unsigned  i=0;
    char codeChr[nb];
    int cursor=0,temp;
    int gb=0;

    for (int sb=0;sb<nb;sb++)
        if(ch!=alphabet[sb])
            gb++;
        if (gb==nb)
             cout<<"character doesn't exist!!!"<<endl;
        else{
        while (alphabet[cursor]!=ch)
            cursor++;
    while (tree[cursor].parent!=-1 )
    {
        temp=tree[cursor].parent;
        if (cursor == tree [temp].left)
        {
            codeChr[i++]='0';
        }
        else
        {
            codeChr[i++]='1';
        }
        cursor=temp;
    }
    cout<<"The code for character "<<ch<<" is: "<<endl;
    int j=i-1;
    while( j >= 0)
    {
        cout<<codeChr[j];
        j--;
    }
    cout<<endl;
        }
}
int main()
{
    char character;
    initialize();
    huffman();
    displaytree(6);
    while(1){
    cout<<"\nEnter the character you want to know the code\n"<<endl;
    cin>>character;
    Code(character);
    }
    return 0;
}
