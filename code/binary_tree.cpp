#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *left, *right;
    node(int v) {
        val = v;
        left = right = NULL;
    }
};

void insert(node* &root, int v) {
    if (root == NULL) 
        root = new node(v);
    else if (v < root->val)
        insert(root->left, v);
    else
        insert(root->right, v);
}

void inorder(node* &root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int heightHelper(node* &root, int depth) {
    static int mdepth = -1;
    if (root == NULL) 
        mdepth = max(mdepth, depth);
    else {
        heightHelper(root->left, depth+1);
        heightHelper(root->right, depth+1);
    }
    return mdepth;
}
int height(node* &root) {
    return heightHelper(root, -1);
}
int main() {
    int a[] ={5,3,1,4,7,6,8};sort(a,a+7);

    node *root = NULL;
    for (int i=0;i<7;i++)
       insert(root, a[i]);
    inorder(root);
    cout << endl;
    cout << height(root) << endl;
}