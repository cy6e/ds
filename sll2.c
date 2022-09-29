#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;
void isf(){
    int ele;
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    printf("enter value:");
    scanf("%d",&ele);
    temp->data=ele;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        printf("%d is inserted\n",head->data);
        return;
    }
    temp->next=head;
    head=temp;
    printf("%d is inserted\n",head->data);
}

void def(){
    if(head==NULL){
        printf("empty list\n");
        return;
    }
    struct node *p;
    p=head;
    printf("%d is deleted\n",p->data);
    head=head->next;
    free(p);
}

void display(){
    struct node *temp=head;
    if(head==NULL){
        printf("list is empty\n");
        return;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void main(){
    int ch;
    printf("1.ins\n2.del\n3.display\n4.exit\n");
    while(1){
        printf("enter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:isf();
                break;
            case 2:def();
                break;
            case 3:display();
                break;
            case 4:exit(0);
            default:printf("invalid choice\n");
        }
    }
}
