#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL;

void insertInEnd(int element){
    struct node *temp,*p;
    temp=(struct node * )malloc(sizeof(struct node));
    temp->data=element;
    temp->link=NULL;

    p=head;
    if(head==NULL){
        head=temp;
    }else{
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
}

void insertInFront(int element){
    struct node *temp,*p;
    temp=(struct node * )malloc(sizeof(struct node));
    temp->data=element;
    temp->link=NULL;

    if(head==NULL){
        head=temp;
    }else
    {
        p=head;
        temp->link=p;
        head=temp;
    }
}


void insertInPosition(int pos,int element){
    struct node *temp,*p,*q;
    temp=(struct node * )malloc(sizeof(struct node));
    temp->data=element;
    temp->link=NULL;

    if(pos==0){
        insertInFront(element);
        return;
    }
    int i;
    p=head;
    q=head;
    for(i=0;i<pos-2;i++){
        p=p->link;
    }
    temp->link=p->link;
    p->link=temp;

}

void deleteInEnd(){
     struct node *p,*j;
     p=head;
     while(p->link!=NULL)
    {
        j=p;
        p=p->link;
    }
    j->link=NULL;
    free(p);
}


void deleteInFront(){
     struct node *p;
     p=head;
     head=p->link;
     p->link=NULL;
    free(p);
}

void deleteInPosition(int pos){
    struct node *p,*q;
    if(pos==0){
        deleteInEnd();
        return;
    }
    int i;
    p=head;
    q=head;
    for(i=0;i<pos-2;i++){
        p=p->link;
        q=p->link;
    }
    p->link=q->link;
    q->link=NULL;

}





void displayElements(){
    struct node *p;
    p=head;
    while(p!=NULL){
        printf("%d \t",p->data);
        p=p->link;
    }
    printf("\n");
}


int main()
{
    insertInEnd(10);
    insertInEnd(20);
    insertInEnd(30);
    insertInEnd(40);
    insertInEnd(50);
    displayElements();

    insertInFront(5);
    displayElements();

    insertInEnd(40);
    displayElements();

    insertInFront(2);
    displayElements();

    deleteInEnd();
    displayElements();

    deleteInFront();
    displayElements();

    insertInPosition(3,25);
    displayElements();

    deleteInPosition(4);
    displayElements();


    return 0;
}
