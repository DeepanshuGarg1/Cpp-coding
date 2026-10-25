#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insertIntoBST(struct node *root, int data)
{
    // pehli node aap create kr rahe hai
    if (root == NULL)
    {
        root = new node;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    // its not the first node
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void createBST(struct node *&root)
{
    cout << "Enter Data: ";
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cout << "Enter Data: ";
        cin >> data;
    }
}

void levelOrderNewLine(struct node *root)
{
    queue<struct node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        struct node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << front->data << " ";
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
        }
    }
}

struct node *minValue(struct node *root)
{
    if (root == NULL)
    {
        cout << "No Minimum value" << endl;
        return NULL;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct node *maxValue(struct node *root)
{
    if (root == NULL)
    {
        cout << "No Maximum value" << endl;
        return NULL;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

// bool searchInBST(struct node *root, int target)
// {
//     if(root==NULL)
//         return false;

//     if(root->data==target)
//         return true;

//     bool leftAns= searchInBST(root->left,target);
//     bool rightAns=searchInBST(root->right,target);
//     return leftAns||rightAns;
// }

bool searchInBST(struct node *root, int target)
{
    // base case
    if (root == NULL)
        return false;

    // 1 case mujhe solve krna h
    if (root->data == target)
        return true;

    // baaaki recursion sambhal lega
    bool leftAns = false;
    bool rightAns = false;
    if (target > root->data)
        rightAns = searchInBST(root->right, target);
    else
        leftAns = searchInBST(root->left, target);

    return leftAns || rightAns;
}

struct node *deleteFromBST(struct node *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == target)
    {
        // ab delete karenge
        // 4 cases
        if (root->left == NULL && root->right == NULL)
        {
            // 1 case -> leaf node
            delete root;
            return NULL;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            // 2 case -> left me NULL and right NON NULL
            struct node *childSubtree = root->right;
            delete root;
            return childSubtree;
        }
        else if (root->right == NULL && root->left != NULL)
        {
            // 3 case -> left non null and right null
            struct node *childSubtree = root->left;
            delete root;
            return childSubtree;
        }
        // 4 case -> left NON NULL && right NON NULL
        else
        {
            // a -> left subtree ki max value lao
            struct node *maxLeft = maxValue(root->left);
            // replacement
            root->data = maxLeft->data;
            // delete actual maxi wali node
            root->left = deleteFromBST(root->left, target);
            return root;
        }
    }
    else if (target > root->data)
    {
        root->right = deleteFromBST(root->right, target);
    }
    else
    {
        root->left = deleteFromBST(root->left, target);
    }
    return root;
}

int main()
{
    struct node *root = NULL;
    createBST(root);
    levelOrderNewLine(root);

    struct node *minNode = minValue(root);
    if (minNode == NULL)
        cout << "There is no node in tree, so no min value" << endl;
    else
        cout << "Min Value: " << minNode->data << endl;

    struct node *maxNode = maxValue(root);
    if (maxNode == NULL)
        cout << "There is no node in tree, so no min value" << endl;
    else
        cout << "Max Value: " << maxNode->data << endl;

    int target;
    cout << "Enter the target: ";
    cin >> target;
    while (target != -1)
    {
        bool ans = searchInBST(root, target);
        if (ans == true)
        {
            cout << "Found" << endl;
        }
        else
        {
            cout << "Not Found" << endl;
        }
        cout << "Enter the target: ";
        cin >> target;
    }

    int target1;
    cout << "Enter the value of target: " << endl;
    cin >> target1;
    while (target1 != -1)
    {
        root = deleteFromBST(root, target1);
        cout << "\nPrinting Level Order Traversal: " << endl;
        levelOrderNewLine(root);
        cout << "Enter the value of target: " << endl;
        cin >> target1;
    }

    return 0;
}