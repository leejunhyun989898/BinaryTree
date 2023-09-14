#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define SIZE 100

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
} TreeNode;

int top = -1;
TreeNode* stack[SIZE];

void push(TreeNode* p)
{
    if (top < SIZE - 1)
        stack[++top] = p;
}

TreeNode* pop()
{
    TreeNode* p = NULL;
    if (top >= 0)
        p = stack[top--];
    return p;
}

void inorder_iter(TreeNode* root)
{
    while (1) {
        // ���� ������ ���� �ڽ� ���� �̵��ϸ鼭 ���ÿ� ��带 ����
        for (; root; root = root->left)
            push(root);

        // ���ÿ��� ��带 ������ ����ϰ�, ���� ����� ������ �ڽ����� �̵�
        root = pop();
        if (!root)
            break; // �� �̻� ó���� ��尡 ������ �ݺ� ����

        printf("[%d] ", root->data); // ��� ������ ���
        root = root->right; // ������ �ڽ� ���� �̵�
    }
}

void preorder_iter(TreeNode* root)
{
    while (1) {
        // ���� ��带 ����ϰ� ���ÿ� ������ ��, ���� �ڽ� ���� �̵�
        for (; root; root = root->left) {
            printf("[%d] ", root->data); // ��� ������ ���
            push(root);
        }

        // ���ÿ��� ��带 ������ ������ �ڽ� ���� �̵�
        root = pop();
        if (!root)
            break; // �� �̻� ó���� ��尡 ������ �ݺ� ����

        root = root->right; // ������ �ڽ� ���� �̵�
    }
}

void postorder_iter(TreeNode* root)
{
    TreeNode* last = NULL; // ���������� �湮�� ��带 ����ϴ� ����
    while (1) {
        // ���� ������ ���� �ڽ� ���� �̵��ϸ鼭 ���ÿ� ��带 ����
        for (; root; root = root->left)
            push(root);

        while (!root && top >= 0) {
            root = stack[top];
            // ������ �ڽ��� ���ų� �̹� �湮�� ���, ��带 ����ϰ� ���ÿ��� ����
            if (!root->right || root->right == last) {
                printf("[%d] ", root->data); // ��� ������ ���
                last = root; // ���������� �湮�� ��� ������Ʈ
                pop();
                root = NULL;
            }
            else {
                root = root->right; // ������ �ڽ� ���� �̵�
            }
        }

        if (top < 0)
            break; // ó���� ��� ������ �ݺ� ����
    }
}


TreeNode s1 = { 4, NULL,NULL };
TreeNode s2 = { 5, NULL,NULL };
TreeNode s3 = { 3, &s1,&s2 };
TreeNode s4 = { 6, NULL,NULL };
TreeNode s5 = { 2, &s3,&s4 };
TreeNode s6 = { 10, NULL,NULL };
TreeNode s7 = { 11, NULL,NULL };
TreeNode s8 = { 8, NULL,NULL };
TreeNode s9 = { 9, &s6,&s7 };
TreeNode s10 = { 7, &s8,&s9 };
TreeNode s11 = { 1, &s5,&s10 };
TreeNode* root = &s11;

int main(void)
{

    printf("1. ���� ��ȸ\n");
    preorder_iter(root);
    printf("\n\n");
    printf("2. ���� ��ȸ\n");
    inorder_iter(root);
    printf("\n\n");
    printf("3. ���� ��ȸ\n");
    postorder_iter(root);
    printf("\n\n");
    return 0;
}