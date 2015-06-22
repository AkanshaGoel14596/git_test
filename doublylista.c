#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
	struct node *previous;
};

typedef struct node Node;

Node *head=NULL;
Node *tail=NULL;

void insert();
int fetch(int);
void display();
void find(int);
int main(int argc, char *argv[])
{
	int choice;
	int value;
	int index;
	while(1) {
		printf("\nWhat do you want to do?\n\n");
		printf("1. Insert \n2. Fetch \n3. display \n4. find\n5. exit\n");
		scanf("%d", &choice);

		switch(choice)
    {
			case 1:
			    insert();
                printf("\nInserted the value into linkedList\n");
				break;
			case 2:
				printf("\nValue at what index you want to fetch\n");
				scanf("%d", &index);
				value = fetch(index);
				printf("\nValue at index %d is %d\n", index, value); //need to fetch real value
				break;
			case 3:
                printf("displaying the data");
                display();
                break;
            case 4:
                printf("enter the element that you wants to find in the list\n");
                scanf("%d",&value);
                find(value);
                break;
			case 5:
				printf("\nExiting...\n");
				return 0;
			default:
				break;
		}
	}
}

//It insert values to the list
void insert()
{   Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    printf("\nEnter the value you want to insert!\n");
    scanf("%d",&temp->value);

	if(head == NULL)
    {
		head=temp;
		tail=temp;
        tail->next=NULL;
        head->previous=NULL;

	}

	else
    {
		tail->next=temp;
		temp->previous=tail;
		tail=temp;
		tail->next=NULL;


	}
}
//it feches values
int fetch(int index)
 {    int c=0;

    int i;
	if(head == NULL)
 {
		return -1;
 }

	Node *pointer1 = head;
	Node *pointer2 = tail;
if(index>=0)
{


	for (i = 0; i < index; i++)
    {
		if(pointer1->next == NULL)
        {
			return -1;
		}
		pointer1 = pointer1->next;
	}
	return pointer1->value;

}
if(index<0)
{
   for (i = 0;pointer1!=NULL ; i++)
   {
       c=c+1;
       pointer1=pointer1->next;

   }
   printf("total=%d",c);

   for(i=c;i>=(c+index+1);i--)
   {
       if(pointer2->previous==NULL)
       {
           return -1;
       }
       pointer2=pointer2->previous;
   }
return pointer2->value;


}


}


void display()
{

    if(head==NULL)
    {
        printf("list is empty");

    }

    Node *pointer2=head;
   while(pointer2!=NULL)
    {
        printf("\n%d",((*pointer2).value));
        pointer2=pointer2->next;
    }

}






void find(int value)
{
     int i;
    Node *pointer=head;

    for(i=0;pointer!=NULL;i++)
    {
        if(((*pointer).value)==value)
        {
            printf("element found at %d position",i);
            break;
        }
      pointer=pointer->next;

   }



}
