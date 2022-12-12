/// Tree library
///
/// All the methods & features of Binary_Tree data structure

#include <iostream>

using namespace std;

// Define the structure of a Binary_Tree node
typedef struct Node
{
    int key;
    Node *parent;
    Node *left;
    Node *right;
};

// print a Binary_Tree in "Pre_Order" mode
static void preOrder(Node t){
    if (&t != NULL){
        cout << t.key << ", ";
        if(t.left != NULL) preOrder(*t.left);
        if(t.right != NULL) preOrder(*t.right);
    }
}

// Print a Binary_Tree in "In_Order" mode
static void inOrder(Node t){
    if (&t != NULL){
        if(t.left != NULL) inOrder(*t.left);
        cout << t.key << ", ";
        if(t.right != NULL) inOrder(*t.right);
    }
}

// Print a Binary_Tree "Post_Order" mode
static void postOrder(Node t){
    if (&t != NULL){
        if(t.left != NULL) postOrder(*t.left);
        if(t.right != NULL) postOrder(*t.right);
        cout << t.key << ", ";
    }
}

int main(int argc, char const *argv[])
{
    Node node1 = {1, NULL, NULL, NULL};
    Node node2 = {2, NULL, NULL, NULL};
    Node root = {0, NULL, &node1, &node2};

    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);

    return 0;
}

