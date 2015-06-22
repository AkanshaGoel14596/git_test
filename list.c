#include<stdio.h>
struct node
{
    int value;
    struct node *next;
};

typedef struct node Node;
Node *head;
Node *tail;

void insert(int);
int fetch(int);
int main(int argc,char *argv[])
{
    int ch,index,value;


    while(1)
    {
    printf("\nenter your choice\n");
    printf("----------------------------------------------------------\n");
    printf("\n1-insert\n2-fetch\n3-exit\n");
    printf("-----------------------------------------------------------\n");
    scanf("\n%d",&ch);
    switch(ch)
    {
       case 1:
       printf("\nwhat you want to insert\n");
       scanf("%d",&value);
       insert(value);
       printf("element inserted successfully");
       break;


       case 2:
       printf("\nvalue at what index you want to fetch\n");
       scanf("%d",&index);
       value=fetch(index);
       printf("\nvalue at index%d  is %d\n",index,value);
       break;


       case 3:
       printf("exiting........");
       return 0;



       default:
       printf("invalid choice");
    }
    }


return 0;

}



void insert(int value)
{ Node newNode;
        newNode.value=value;
        //wNode.next=(Node*)malloc(sizeof(Node*));

    if(head==NULL)
    {
    head=(Node *)malloc(sizeof(Node*));
    tail=(Node *)malloc(sizeof(Node*));
        head=&newNode;
        tail=&newNode;

    }

    else
{
       //*tail).next=&newNode;
        //il=&newNode;
tail->next=(Node *)malloc(sizeof(Node*));
tail->next=&newNode;

}
}



int fetch(int index)
{ int i;
    if(head==NULL)
     {


        return -1;
    }
    Node element=*head;
    for(i=0;i<index;i++)
    {
        if(element.next==NULL)
        {
            return -1;
        }
        element=*(element.next);

    }
    return element.value;

}
