#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createBinaryTree()
{
    cout << "Enter the data: ";
    int value;
    cin >> value;

    if (value == -1)
        return NULL;

    struct node *nnode = new node;
    nnode->data = value;

    cout << "left of node: " << value << endl;
    nnode->left = createBinaryTree();

    cout << "right of node: " << value << endl;
    nnode->right = createBinaryTree();

    return nnode;
}

void preOrder(struct node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void levelOrder(struct node *root)
{
    queue<struct node *> q;
    q.push(root);
    while (!q.empty())
    {
        struct node *front = q.front();
        q.pop();
        cout << front->data << " ";
        if (front->left != NULL)
            q.push(front->left);
        if (front->right != NULL)
            q.push(front->right);
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

int maxHeight(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = maxHeight(root->left);
    int rightHeight = maxHeight(root->right);
    int height = max(leftHeight, rightHeight) + 1;
    return height;
}

int diameterBinaryTree(struct node *root)
{
    if (root == NULL)
        return 0;
    int option1 = diameterBinaryTree(root->left);
    int option2 = diameterBinaryTree(root->right);
    int option3 = maxHeight(root->left) + maxHeight(root->right);
    int diameter = max(option1, max(option2, option3));
    return diameter;
}

bool isBalanced(struct node *root)
{
    if (root == NULL)
        return true;

    int leftHeight = maxHeight(root->left);
    int rightHeight = maxHeight(root->right);
    bool currNodeAns = (abs(leftHeight - rightHeight) <= 1);

    if (currNodeAns && isBalanced(root->left) && isBalanced(root->right))
        return true;
    else
        return false;
}

struct node *LCA(struct node *root, struct node *p, struct node *q)
{
    if (root == NULL)
        return NULL;
    if (root == p)
        return p;
    if (root == q)
        return q;

    struct node *leftAns = LCA(root->left, p, q);
    struct node *rightAns = LCA(root->right, p, q);

    if (leftAns == NULL && rightAns == NULL)
        return NULL;

    else if (leftAns != NULL && rightAns == NULL)
        return leftAns;

    else if (leftAns == NULL && rightAns != NULL)
        return rightAns;
    else
        return root;
}

int searchInorder(int inorder[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (inorder[i] == element)
            return i;
    }
}

struct node *constructTreeFromPreorderAndInorder(int preorder[], int inorder[], int &preorderIndex, int inorderStart, int inorderEnd, int size)
{
    // base case
    if (preorderIndex >= size || inorderStart > inorderEnd)
        return NULL;

    // 1 case mai solve karta hun
    int element = preorder[preorderIndex];
    preorderIndex++;
    struct node *root = new node;
    root->data = element;

    // element search karna padega inorder mein
    int position = searchInorder(inorder, size, element); // takes O(N) time complexity, but using map we can do it in O(1)

    // baaki recursion sambhal lega
    root->left = constructTreeFromPreorderAndInorder(preorder, inorder, preorderIndex, inorderStart, position - 1, size);
    root->right = constructTreeFromPreorderAndInorder(preorder, inorder, preorderIndex, position + 1, inorderEnd, size);

    return root;
}

void createMapping(int inorder[], int size, map<int, int> &valueToIndexMap)
{
    for (int i = 0; i < size; i++)
    {
        int element = inorder[i];
        int index = i;
        valueToIndexMap[element] = index;
    }
}

struct node *constructTreeFromPreorderAndInorderMap(map<int, int> &valueToIndexMap, int preorder[], int inorder[], int &preorderIndex, int inorderStart, int inorderEnd, int size)
{
    // base case
    if (preorderIndex >= size || inorderStart > inorderEnd)
        return NULL;

    // 1 case mai solve karta hun
    int element = preorder[preorderIndex];
    preorderIndex++;
    struct node *root = new node;
    root->data = element;

    // element search karna padega inorder mein
    int position = valueToIndexMap[element];

    // baaki recursion sambhal lega
    root->left = constructTreeFromPreorderAndInorderMap(valueToIndexMap, preorder, inorder, preorderIndex, inorderStart, position - 1, size);
    root->right = constructTreeFromPreorderAndInorderMap(valueToIndexMap, preorder, inorder, preorderIndex, position + 1, inorderEnd, size);

    return root;
}

struct node *constructTreeFromPostorderAndInorder(int postorder[], int inorder[], int &postorderIndex, int inorderStart, int inorderEnd, int size)
{
    if (postorderIndex < 0 || inorderStart > inorderEnd)
        return NULL;

    int element = postorder[postorderIndex];
    postorderIndex--;
    struct node *root = new node;
    root->data = element;

    int position = searchInorder(inorder, size, element);

    root->right = constructTreeFromPostorderAndInorder(postorder, inorder, postorderIndex, position + 1, inorderEnd, size);
    root->left = constructTreeFromPostorderAndInorder(postorder, inorder, postorderIndex, inorderStart, position - 1, size);

    return root;
}

void printLeftViewUsingLevelOrder(struct node *root)
{
    queue<struct node *> q;
    q.push(root);
    q.push(NULL);
    cout<<(q.front())->data<<" ";
    while (!q.empty())
    {
        struct node *front = q.front();
        q.pop();
        struct node *front1 = q.front();
        if (front == NULL)
        {
            if (!q.empty()){
                q.push(NULL);
                cout<<front1->data<<" ";
            }
        }
        else
        {
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
        }
    }
}

void printLeftView(struct node *root, int level, vector<int> &leftView)
{
    if (root == NULL)
        return;

    if (level == leftView.size())
    {
        // iska matlab left view ki node milgyi h, store karlo
        leftView.push_back(root->data);
    }
    printLeftView(root->left, level + 1, leftView);
    printLeftView(root->right, level + 1, leftView);
}

void printRightView(struct node *root, int level, vector<int> &rightView)
{
    if (root == NULL)
        return;

    if (level == rightView.size())
    {
        // iska matlab right view ki node milgyi h , store karlo
        rightView.push_back(root->data);
    }
    printRightView(root->right, level + 1, rightView);
    printRightView(root->left, level + 1, rightView);
}

int main()
{
    struct node *root = createBinaryTree();
    cout << "PreOrder Traversal:\n";
    preOrder(root);
    cout << "\nInOrder Traversal:\n";
    inOrder(root);
    cout << "\nLevel Order Traversal:\n";
    levelOrder(root);
    cout << "\nLevel Order Traversal New Line:\n";
    levelOrderNewLine(root);
    cout << "\nMaximum Height of Tree: " << maxHeight(root) << endl;
    cout << "\nDiameter of Binary Tree: " << diameterBinaryTree(root) << endl;
    cout << "\nIs Tree Balanced: " << isBalanced(root) << endl;
    cout << "\nPrinting Left View using Level Order: " << endl;
    printLeftViewUsingLevelOrder(root);
    vector<int> leftView;
    printLeftView(root, 0, leftView);
    cout << "\n\nPrinting Left View: " << endl;
    for (int i = 0; i < leftView.size(); i++)
    {
        cout << leftView[i] << " ";
    }
    vector<int> rightView;
    printRightView(root, 0, rightView);
    cout << "\n\nPrinting rightView: " << endl;
    for (int i = 0; i < rightView.size(); i++)
    {
        cout << rightView[i] << " ";
    }

    // int preorder[]={2,8,10,6,4,12};
    // int inorder[]={10,8,6,2,4,12};
    // int preorderIndex=0;
    // int inorderStart=0;
    // int inorderEnd=5;
    // int size=6;
    // struct node* root=constructTreeFromPreorderAndInorder(preorder,inorder,preorderIndex,inorderStart,inorderEnd,size);
    // cout<<"Printing the Entire Tree:\n";
    // levelOrderNewLine(root);

    // int preorder[]={2,8,10,6,4,12};
    // int inorder[]={10,8,6,2,4,12};
    // int preorderIndex=0;
    // int inorderStart=0;
    // int inorderEnd=5;
    // int size=6;
    // map<int,int>valueToIndexMap;
    // createMapping(inorder,size,valueToIndexMap);
    // struct node* root=constructTreeFromPreorderAndInorderMap(valueToIndexMap,preorder,inorder,preorderIndex,inorderStart,inorderEnd,size);
    // cout<<"Printing the Entire Tree:\n";
    // levelOrderNewLine(root);

    // int postorder[]={10,6,8,12,4,2};
    // int inorder[]={10,8,6,2,4,12};
    // int postorderIndex=5;
    // int inorderStart=0;
    // int inorderEnd=5;
    // int size=6;
    // struct node* root=constructTreeFromPostorderAndInorder(postorder,inorder,postorderIndex,inorderStart,inorderEnd,size);
    // cout<<"Printing the Entire Tree:\n";
    // levelOrderNewLine(root);
    return 0;
}
