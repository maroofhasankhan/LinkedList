#include <iostream>
using namespace std;

struct Node
{
    //public:
    int data;
    Node *next;
};
void transverse(Node *head)
{
    Node *temp=head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
struct Node * insertinbeging(struct Node *head, int data)
{
    struct Node *ptr;
    ptr = new Node;
    ptr->data = data;
    ptr->next = head;
    head=ptr;
    return head;
}  
void insertinpos(struct Node *head, int data,int position)
{
    struct Node *ptr,*p;
    ptr = new Node;
    p=head;
    int i=0;
    while (i!=position-1)
    {
        p=p->next;
        i +=1;
    }
    ptr->data = data;
    ptr->next=p->next;
    p->next=ptr;

}  
void insertatend(struct Node *head, int data)
{
    struct Node *ptr,*p;
    ptr = new Node;
    p=head;
    while(p->next != NULL)
    {
        p=p->next;
    }
    ptr->data = data;
    p->next=ptr;
    ptr->next=NULL;
}
struct Node * deleteatbeg(struct Node *head)
{
    struct Node *ptr=head;
    head = head->next;
    free(ptr);
    return head;
}
void deleteatpos(struct Node *head,int position)
{
    int i=0;
    struct Node *p,*q;
    p=head;
    q=head->next;
    while(i!=position-1)
    {
        i++;
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
}
void deleteatend(struct Node *head)
{
    struct Node *p,*q;
    p=head;
    q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
}
int main()
{
    struct Node *first, *head;
    first = new Node;
    first->data = 10;
    first->next = NULL;
    head = first;
    // transverse(head);
    head= insertinbeging(head,40);
    head= insertinbeging(head,58);
    head= insertinbeging(head,27);
    insertinpos(head,69,2);
    insertatend(head,465);
    insertatend(head,72);
    insertatend(head,65);

    transverse(head);
    // head=deleteatbeg(head);
    deleteatpos(head,2);
    // deleteatend(head);
    cout<<"\n after deletion\n";
    transverse(head);

    return 0;
}
