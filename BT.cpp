#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createBinaryTree(){
    int data;
    cout<<"Enter the value: ";
    cin>>data;
    if(data==-1){
        return NULL;
    }
    struct node* nnode=new node;
    nnode->data=data;
    cout<<"Left of node: "<<data<<endl;
    nnode->left=createBinaryTree();
    nnode->right=createBinaryTree();
    return nnode;
}

