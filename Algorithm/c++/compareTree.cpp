#include<iostream>
#include<stdio.h>
using namespace std;
//��������ȵ������� 1 ���ڵ���� 2 ����������Ӧ��Ȼ��߻��������
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
