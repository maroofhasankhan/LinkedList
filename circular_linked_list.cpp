#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    
    int data;
    Node *next;
};
void transverse(Node *head)
{
    Node *temp=head;
    do
    {
        cout << temp->data << endl;
        temp = temp->next;
    }while (temp != head);

}
struct Node * insertatbeg(Node *head,int data)
{
    Node *temp,*p=head->next;
    temp=new Node;
    temp->data = data;
    while (p->next != head)
    {
        p=p->next;
    }
    temp->next = head;
    head=temp;
    p->next=temp;
    return head;
}
void insertatpos(Node *head,int data,int position)
{
    int i=0;
    Node *temp,*p=head;
    temp=new Node;
    while(i!= position-1)
    {
        i++;
        p=p->next;
    }
    temp->data= data;
    temp->next=p->next;
    p->next=temp;
}
void insertatend(Node *head,int data)
{
    struct Node *temp,*p=head->next;
    temp=new Node; 
    while(p->next != head)
    {
        p=p->next;
    }
    temp->data= data;
    temp->next=head;
    p->next=temp;

}
// void insertatend(Node *head, int data)
// {
//     Node *temp = new Node;
//     temp->data = data;
//     temp->next = head;
//     if (head == NULL)
//     {
//         head = temp;
//         return;
//     }
//     Node *p = head;
//     while (p->next != head)
//     {
//         p = p->next;
//     }
//     p->next = temp;
// }
struct Node * deleteatbeg(Node *head)
{
    Node *p=head,*j;
    j=head->next;
    while(j->next != head)
    {
        j=j->next;
    }
    head=head->next;
    j->next=head;
    free(p);
    return head;
}
void deleteatpos(Node *head,int position)
{
    int i=0;
    struct Node * p=head,*q=head->next;
    while(i < position-1)
    {
        i +=1;
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
}
void deleteatend(Node *head)
{
    Node *temp=head ,*p=head->next;
    while(p->next->next != head)
    {
        p=p->next;
    }
    free(p->next);
    p->next=head;
    // p=p->next;

}
int main()
{
    Node *head,*first;
    first=new Node;
    first->data=10;
    head=first;
    first->next=head;

    head=insertatbeg(head,68);
    head=insertatbeg(head,62);
    head=insertatbeg(head,6);
    insertatpos(head,8,2);
    insertatpos(head,8,1);
    insertatend(head,98);
    // head=deleteatbeg(head);
    deleteatpos(head,3);
    deleteatend(head);
    transverse(head);
    return 0;
}