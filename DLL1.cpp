#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
        nnode->prev = NULL;
        if (start == NULL)
        {
            temp = start = nnode;
        }
        else
        {
            temp->next = nnode;
            nnode->prev = temp;
            temp = nnode;
        }
        cout << "Do you want to insert more node: ";
        cin >> ch;
    }
}

void insert_beg()
{
    struct node *nnode = new node;
    cout << "Enter data: ";
    cin >> nnode->data;
    nnode->prev = NULL;
    if (start == NULL)
    {
        nnode->next = NULL;
        start = nnode;
    }
    else
    {
        nnode->next = start;
        start->prev = nnode;
        start = nnode;
    }
}

void insert_end()
{
    struct node *nnode = new node;
    cout << "Enter data: ";
    cin >> nnode->data;
    nnode->next = NULL;
    if (start == NULL)
    {
        nnode->prev = NULL;
        start = nnode;
    }
    else
    {
        struct node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        nnode->prev = temp;
        temp->next = nnode;
        temp = nnode;
    }
}

void insert_mid()
{
    struct node *nnode = new node;
    cout << "Enter data that you want to insert: ";
    cin >> nnode->data;
    nnode->next = NULL;
    nnode->prev = NULL;
    int value;
    cout << "Enter value after which you want to insert: ";
    cin >> value;
    if (start == NULL)
    {
        start = nnode;
        return;
    }
    struct node *temp = start;
    while (temp->data != value)
    {
        temp = temp->next;
    }
    nnode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = nnode;
    temp->next = nnode;
    nnode->prev = temp;
}

void delete_beg()
{
    if (start == NULL)
    {
        cout << "Linked List is already empty" << endl;
        return;
    }
    if (start->next == NULL)
    {
        delete (start);
        start = NULL;
        return;
    }
    struct node *temp = start;
    start = start->next;
    start->prev = NULL;
    delete (temp);
}

void delete_end()
{
    if (start == NULL)
    {
        cout << "Linked List is already empty" << endl;
        return;
    }
    if (start->next == NULL)
    {
        delete (start);
        start = NULL;
        return;
    }
    // struct node* temp=start;
    // while(temp->next->next!=NULL){
    //     temp=temp->next;
    // }
    // struct node* ptr=temp->next;
    // temp->next=NULL;
    // delete(ptr);
    // or
    struct node *temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete (temp);
}

void delete_mid()
{
    int data;
    cout << "Enter node to be deleted: ";
    cin >> data;
    if (start == NULL)
    {
        cout << "Linked List is already empty" << endl;
        return;
    }
    if (start->data == data)
    {
        start = start->next;
        delete (start->prev);
        start->prev = NULL;
        return;
    }
    struct node *temp = start;
    while (temp->data != data)
    {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    delete (temp);
}

void size(){
    int count=0;
    struct node* temp=start;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    cout<<"Size: "<<count<<endl;
}

void palindrome(){
    int count=0;
    struct node* tail=start;
    struct node* head=start;
    while(tail->next!=NULL){
        count++;
        tail=tail->next;
    }
    count+=2;
    int c=count/2;
    while(c--){
        if(head->data==tail->data){
            head=head->next;
            tail=tail->prev;
            continue;
        }
        else{
            cout<<"Not a palindrome";
            return;
        }
    }
    cout<<"It is a palindrome";
}

void display()
{
    struct node *temp = start;
    if (start == NULL)
    {
        cout << "Linked List is empty" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
    }
}

int main()
{
    create();
    display();
    palindrome();
}