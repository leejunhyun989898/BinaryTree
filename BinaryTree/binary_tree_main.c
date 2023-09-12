#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
} TreeNode;

//              1
//        2         7
//     3     6   8     9
//  4     5         10   11
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
TreeNode* node = &s11;
// 전위 순회 함수
void preorder(TreeNode* node) {
    if (node != NULL) {
        printf("%d ", node->data); // 노드 데이터 출력
        preorder(node->left);      // 왼쪽 서브트리 순회
        preorder(node->right);     // 오른쪽 서브트리 순회
    }
}

// 중위 순회 함수
void inorder(TreeNode* node) {
    if (node != NULL) {
        inorder(node->left);      // 왼쪽 서브트리 순회
        printf("%d ", node->data); // 노드 데이터 출력
        inorder(node->right);     // 오른쪽 서브트리 순회
    }
}

// 후위 순회 함수
void postorder(TreeNode* node) {
    if (node != NULL) {
        postorder(node->left);    // 왼쪽 서브트리 순회
        postorder(node->right);   // 오른쪽 서브트리 순회
        printf("%d ", node->data); // 노드 데이터 출력
    }
}

int main(void) {
    TreeNode* n1, * n2, * n3, * n4, * n5, * n6, * n7, * n8, * n9, * n10, * n11;
    n1 = (TreeNode*)malloc(sizeof(TreeNode));
    n2 = (TreeNode*)malloc(sizeof(TreeNode));
    n3 = (TreeNode*)malloc(sizeof(TreeNode));
    n4 = (TreeNode*)malloc(sizeof(TreeNode));
    n5 = (TreeNode*)malloc(sizeof(TreeNode));
    n6 = (TreeNode*)malloc(sizeof(TreeNode));
    n7 = (TreeNode*)malloc(sizeof(TreeNode));
    n8 = (TreeNode*)malloc(sizeof(TreeNode));
    n9 = (TreeNode*)malloc(sizeof(TreeNode));
    n10 = (TreeNode*)malloc(sizeof(TreeNode));
    n11 = (TreeNode*)malloc(sizeof(TreeNode));

    //노드생성
    n1->data = 1;
    n1->left = n2;
    n1->right = n7;
    n2->data = 2;
    n2->left = n3;
    n2->right = n6;
    n3->data = 3;
    n3->left = n4;
    n3->right = n5;
    n4->data = 4;
    n4->left = NULL;
    n4->right = NULL;
    n5->data = 5;
    n5->left = NULL;
    n5->right = NULL;
    n6->data = 6;
    n6->left = NULL;
    n6->right = NULL;
    n7->data = 7;
    n7->left = n8;
    n7->right = n9;
    n8->data = 8;
    n8->left = NULL;
    n8->right = NULL;
    n9->data = 9;
    n9->left = n10;
    n9->right = n11;
    n10->data = 10;
    n10->left = NULL;
    n10->right = NULL;
    n11->data = 11;
    n11->left = NULL;
    n11->right = NULL;

    printf("< Array Tree >\n\n");
    printf("1. Preorder: ");
    preorder(n1); // 전위 순회 호출
    printf("\n\n");

    printf("2. Inorder: ");
    inorder(n1); // 중위 순회 호출
    printf("\n\n");

    printf("3. Postorder: ");
    postorder(n1); // 후위 순회 호출
    printf("\n\n");

    // 메모리 해제
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);
    free(n7);
    free(n8);
    free(n9);
    free(n10);
    free(n11);

    printf("< Link Tree >\n\n");
    printf("1. Preorder: ");
    preorder(node); // 전위 순회 호출
    printf("\n\n");

    printf("2. Inorder: ");
    inorder(node); // 중위 순회 호출
    printf("\n\n");

    printf("3. Postorder: ");
    postorder(node); // 후위 순회 호출
    printf("\n");

    return 0;
}