#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next=NULL;
        }

};

void insertAtHead(Node* &head,int data){
    Node*node=new Node(data);

    node->next=head;
    head=node;
    node->data = data;

    // return head;
}

void insertAtEnd(Node* &head,int data){
    Node*node=new Node(data);
    Node*temp=head;
    
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=node;
    // return head;
}

void insertAtPosition(Node* &head,int data,int pos){
    int i=1;
    Node* temp=head,*prev;
    Node*node=new Node(data);

    while(i<pos && temp!=NULL){
        i++;
        prev=temp;
        temp=temp->next;
    }
    node->next=prev->next;
    prev->next=node;


}


int middleNode(Node* &head){
    Node* temp1;
    Node* temp2;
    temp1=temp2=head;

    while( temp2!=NULL && temp2->next!=NULL){
        temp2=temp2->next->next;
        temp1=temp1->next;
    }
    cout<<temp1->data<<endl;
}

void printAllNodes(Node* &head){
    Node*temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void last_itr(Node* &head){
    Node*temp=head;

    while(temp->next!=NULL){
        // cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}

void deleteFromHead(Node* &head){
    Node* temp=head;
    head=head->next;
    delete temp;
}

void deleteFromEnd(Node* &head){
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;

}

void deleteFromPosition(Node* head,int pos){
    Node* temp=head,*prev;
    int i=1;
    while(i<pos){
        if(temp->next==NULL){
            cout<<"Index Out of Bound!"<<endl;
        }
        i++;
        prev=temp;
        temp=temp->next;
    }
    // Node* del=prev->next;
    prev->next=prev->next->next;
    delete temp;
}

int main(){
    Node* head=NULL;
    
    // inserting at the beginning  
    insertAtHead(head,7);
    insertAtHead(head,6);
    insertAtHead(head,5);
    insertAtHead(head,9);
    insertAtHead(head,9);
    insertAtHead(head,21);


    //inserting at the end
    insertAtEnd(head,69);
    last_itr(head);
    // printAllNodes(head);

    //insert at specific location suppose that list is 1 index
    // insertAtPosition(head,89,3);



    /*                                   #### Deletion in a linked list ####                                    */



    // delete from head

    // deleteFromHead(head);

    // delete from tail

    // deleteFromEnd(head);

    // deleteFromPosition(head,2);

    // middleNode(head);

    // traversal in linked list

    printAllNodes(head);

    
return 0;
}