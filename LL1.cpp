#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *start = NULL;

void create_LL()
{
    struct node *temp;
    int ch = 1;
    while (ch)
    {
        struct node *nnode = new node;
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

void count(int key)
{
    int count = 0;
    struct node *temp = start;
    while (temp != NULL)
    {
        if (key == temp->data)
        {
            count++;
        }
        temp = temp->next;
    }
    cout << "Count: " << count << endl;
}

int countAndDelete(int key)
{
    int count = 0;
    while (start != NULL && start->data == key)
    {
        struct node *temp = start;
        start = start->next;
        delete (temp);
        count++;
    }
    struct node *ptr = start;
    while (ptr != NULL && ptr->next != NULL)
    {
        if (ptr->next->data == key)
        {
            struct node *temp = ptr->next;
            ptr->next = temp->next;
            delete (temp);
            count++;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    return count;
}

void middle_LL()
{
    if (start == NULL)
    {
        cout << "Linked List is empty";
    }
    else
    {
        int count = 1;
        struct node *temp = start;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        int middle = count / 2;
        int c = 1;
        temp = start;
        while (c != middle)
        {
            temp = temp->next;
            c++;
        }
        cout << "Middle of Linked List: " << temp->data << endl;
    }
}

void reverse_LL()
{
    struct node *prev = NULL, *temp = start, *next = NULL;

    while (temp != NULL)
    {
        next = temp->next; // Store next node
        temp->next = prev; // Reverse current node’s pointer
        prev = temp;       // Move prev and temp one step forward
        temp = next;
    }
    start = prev; // Update head to the new first node
}

void rotate_LL()
{
    int k;
    cout << "Enter k: ";
    cin >> k;
    while (k--)
    {
        struct node *temp = start;
        struct node *ptr;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        ptr = temp->next;
        struct node *nnode = new node;
        nnode->data = ptr->data;
        nnode->next = start;
        start = nnode;
        delete (ptr);
        temp->next = NULL;
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
    display_LL();
    // int key;
    // cout << "Enter key: ";
    // cin >> key;
    // int c=countAndDelete(key);
    middle_LL();
    // reverse_LL();
    rotate_LL();
    display_LL();
    return 0;
}