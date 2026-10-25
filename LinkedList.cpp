#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *start = NULL;

void create_LL()
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
        }
        else
        {
            temp->next = nnode;
            temp = temp->next;
        }
        cout << "Enter your choise to insert more node: ";
        cin >> ch;
    }
}

void insert_beg()
{
    struct node *nnode, temp;
    nnode = new node;
    cout << "Enter data to be inserted at beginning: ";
    cin >> nnode->data;
    if (start == NULL)
    {
        nnode->next = NULL;
        start = nnode;
    }
    else
    {
        nnode->next = start;
        start = nnode;
    }
}

void insert_end()
{
    struct node *nnode, *temp;
    nnode = new node;
    cout << "Enter data to be inserted at end: ";
    cin >> nnode->data;
    nnode->next = NULL;
    if (start == NULL)
    {
        start = nnode;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nnode;
    }
}

void insert_middle()
{
    struct node *nnode = new node;
    struct node *temp = start;
    cout << "Enter new node to be inserted: ";
    cin >> nnode->data;
    if (start == NULL)
    {
        nnode->next = NULL;
        start = nnode;
        return;
    }
    int value;
    cout << "Enter value after which new node be inserted: ";
    cin >> value;
    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Value not found in the list" << endl;
        delete nnode;
        return;
    }
    nnode->next = temp->next;
    temp->next = nnode;
}

void delete_beg()
{
    struct node *temp=start;
    if (start == NULL)
    {
        cout << "Linked List is already empty";
    }
    else
    {
        start = temp->next;
        delete (temp);
    }
}

void delete_end()
{
    struct node *temp, *ptr;
    ptr = temp = start;
    if (start == NULL)
    {
        cout << "Linked List is empty";
        return;
    }
    if (start->next == NULL)
    {
        delete start;
        start = NULL;
        return;
    }

    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    temp = ptr->next;
    delete (temp);
    ptr->next = NULL;
}

void delete_specific()
{
    int value;
    cout << "Enter node to be deleted: ";
    cin >> value;
    struct node *temp, *ptr;
    temp = start;
    if(start==NULL)
    {
        cout<<"Linked List is empty";
        return;
    }
    if(value==start->data){
        start=start->next;
        delete temp;
        return;
    }
    while (temp->next != NULL && temp->next->data != value)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        cout << "Value not found in the list." << endl;
        return;
    }
    ptr = temp->next;
    temp->next = ptr->next;
    delete (ptr);
}

void search()
{
    struct node *temp = start;
    int data;
    int position = 0;
    bool found = false;
    cout << "Enter data to be searched for: ";
    cin >> data;
    if (start == NULL)
    {
        cout << "Linked List is empty";
    }
    else
    {
        while (temp != NULL)
        {
            if (data == temp->data)
            {
                cout << "Position: " << position << endl;
                found = true;
            }
            position++;
            temp = temp->next;
        }
        if (!found)
        {
            cout << "Data not found in the list." << endl;
        }
    }
}

void display_LL()
{
    struct node *temp = start;
    if (start == NULL)
        cout << "Linked List is empty";
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
    }
    cout << endl;
}

int main()
{
    create_LL();
    insert_beg();
    insert_end();
    display_LL();
    cout << endl;
    insert_middle();
    display_LL();
    cout << endl;
    delete_specific();
    display_LL();
    cout<<endl;
    delete_specific();
    display_LL();
    delete_beg();
    display_LL();
    cout << endl;
    delete_end();
    display_LL();
    return 0;
}