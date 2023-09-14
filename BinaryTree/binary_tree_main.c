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
        // 현재 노드부터 왼쪽 자식 노드로 이동하면서 스택에 노드를 저장
        for (; root; root = root->left)
            push(root);

        // 스택에서 노드를 꺼내어 출력하고, 꺼낸 노드의 오른쪽 자식으로 이동
        root = pop();
        if (!root)
            break; // 더 이상 처리할 노드가 없으면 반복 종료

        printf("[%d] ", root->data); // 노드 데이터 출력
        root = root->right; // 오른쪽 자식 노드로 이동
    }
}

void preorder_iter(TreeNode* root)
{
    while (1) {
        // 현재 노드를 출력하고 스택에 저장한 후, 왼쪽 자식 노드로 이동
        for (; root; root = root->left) {
            printf("[%d] ", root->data); // 노드 데이터 출력
            push(root);
        }

        // 스택에서 노드를 꺼내어 오른쪽 자식 노드로 이동
        root = pop();
        if (!root)
            break; // 더 이상 처리할 노드가 없으면 반복 종료

        root = root->right; // 오른쪽 자식 노드로 이동
    }
}

void postorder_iter(TreeNode* root)
{
    TreeNode* last = NULL; // 마지막으로 방문한 노드를 기록하는 변수
    while (1) {
        // 현재 노드부터 왼쪽 자식 노드로 이동하면서 스택에 노드를 저장
        for (; root; root = root->left)
            push(root);

        while (!root && top >= 0) {
            root = stack[top];
            // 오른쪽 자식이 없거나 이미 방문한 경우, 노드를 출력하고 스택에서 제거
            if (!root->right || root->right == last) {
                printf("[%d] ", root->data); // 노드 데이터 출력
                last = root; // 마지막으로 방문한 노드 업데이트
                pop();
                root = NULL;
            }
            else {
                root = root->right; // 오른쪽 자식 노드로 이동
            }
        }

        if (top < 0)
            break; // 처리할 노드 없으면 반복 종료
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

    printf("1. 전위 순회\n");
    preorder_iter(root);
    printf("\n\n");
    printf("2. 중위 순회\n");
    inorder_iter(root);
    printf("\n\n");
    printf("3. 후위 순회\n");
    postorder_iter(root);
    printf("\n\n");
    return 0;
}