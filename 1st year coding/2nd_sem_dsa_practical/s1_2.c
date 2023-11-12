//polly addition

#include<stdio.h>
#include<stdlib.h>

typedef struct st
{
    int coef;
    int power;
    struct st* next;
}Node;

Node* creat_node(int coef,int power)
{
    Node* tmp=(Node*)malloc(sizeof(Node));
    tmp->coef=coef;
    tmp->power=power;
    tmp->next=NULL;
}

void append(Node** head,int coef,int power)
{
    Node* temp=creat_node(coef,power);
    Node* curr= *head;
    if(*head==NULL)
    {
        *head=temp;
        return;
    }
    while (curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;
}

Node* padd(Node* h1,Node* h2)
{
    Node* h3=NULL;
    while (h1!= NULL && h2!= NULL)
    {
        if(h1->power>h2->power)
        {
            append(&h3,h1->power,h1->coef);
            h1=h1->next;
        }
        else if(h2->power>h1->power)
        {
            append(&h3,h2->coef,h2->power);
            h2=h2->next;
        }
        else
        {
            append(&h3,h1->coef+h2->coef,h1->power);
            h1=h1->next;
            h2=h2->next;
        }
    }

    while (h1!=NULL)
    {
        append(&h3,h1->coef,h1->power);
        h1=h1->next;
    }
    while (h2!=NULL)
    {
        append(&h3,h2->coef,h2->power);
        h2=h2->next;
    }
    return h3;
}

void display(Node* head)
{
    while (head->next!=NULL)
    {
        printf("%dx^%d",head->coef,head->power);
        head=head->next;
    }
    
}


int main()
{
    Node* h1=NULL;
    Node* h2=NULL;
    Node* h3=NULL;

    append(&h1,7,2);
    append(&h1,2,1);
    append(&h1,1,0);
    append(&h2,5,5);
    append(&h2,3,2);
    append(&h2,2,2);

    h3=padd(h1,h2);

    display(h3);
    


    return 0;
}