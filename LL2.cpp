#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *create_LL()
{
    struct node *start = NULL;
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
    return (start);
}

void intersection(struct node *start1, struct node *start2)
{
    struct node *temp1 = start1;
    while (temp1 != NULL)
    {
        struct node *temp2 = start2;
        while (temp2 != NULL)
        {
            if (temp1->data == temp2->data)
            {
                cout << "Intersection of LL: " << temp1->data << endl;
                break;         //return;
            }

            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

int main()
{
    struct node *start1 = create_LL();
    cout << endl;
    struct node *start2 = create_LL();
    intersection(start1, start2);
    return 0;
}