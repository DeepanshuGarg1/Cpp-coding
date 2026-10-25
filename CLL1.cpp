#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *start = NULL;

void create()
{
    struct node *nnode, *temp;
    int ch = 1;
    while (ch)
    {
        nnode = new node;
        cout << "Enter data: ";
        cin >> nnode->data;
        nnode->next = NULL;
        if (start == NULL)
        {
            temp = start = nnode;
            nnode->next = start;
        }
        else
        {
            temp->next=nnode;
            nnode->next=start;
            temp=nnode;
        }
        cout << "Do you want to insert more data: ";
        cin >> ch;
    }
}

void split(){
    struct node* temp=start;
    int count=0;
    while(temp->next!=start){
        count++;
        temp=temp->next;
    }
    count+=2;
    int mid=count/2;
    struct node* ptr=start;
    while(--mid){
        ptr=ptr->next;
    }
    struct node*start1;
    start1=ptr->next;
    ptr->next=start;
    struct node* ptr1=start;
    while(ptr1->next!=start){
        cout<<ptr1->data<<"\t";
        ptr1=ptr1->next;
    }
    cout<<ptr1->data<<endl;
    temp->next=start1;
    struct node* temp1=start1;
    while(temp1->next!=start1){
        cout<<temp1->data<<"\t";
        temp1=temp1->next;
    }
    cout<<temp1->data;
}

// void insert_beg(){
//     struct node* nnode=new node;
//     cout<<"Enter data: ";
//     cin>>nnode->data;
//     nnode->next==NULL;
//     if(start==NULL){
//     }
// }

void display(){
    struct node* temp=start;
    while(temp->next!=start){
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<temp->data;
}

int main()
{
    create();
    display();
    cout<<endl;
    split();
}