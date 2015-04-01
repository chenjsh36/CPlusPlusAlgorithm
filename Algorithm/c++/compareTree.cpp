#include<iostream>
#include<stdio.h>
using namespace std;
//两棵树相等的条件是 1 根节点相等 2 左右子树对应相等或者互换后相等
// same return 0 when different return 1;
int compareTree(TreeNode *tree1, TreeNode *tree2) {
    if (tree1==NULL && tree2==NULL) {
        return 0;
    }
    if (tree1 != NULL && tree2 == NULL) {
        return 1;
    }
    if (tree1 == NULL && tree2 != NULL) {
        return 1;
    }
    if (tree1->c != tree2->c) {
        return 1;
    }
    return ((compareTree(tree1->left,tree2->left) && coompareTree(tree1->right, tree2->right))||
            (compareTree(tree1->left,tree2->right) && coompareTree(tree1->left, tree2->right)));
}
