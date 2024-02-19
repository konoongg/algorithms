#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct TNode {
    int Value;
    struct TNode* Left;
    struct TNode* Right;
    struct TNode* Parent;
};

struct Ttree {
    struct TNode* Head;
};

struct TStackNode {
    struct TNode* Value;
    struct TStackNode* Next;
    struct TStackNode* Parent;
};

struct TStack {
    int Size;
    struct TStackNode* Head;
    struct TStackNode* Tail;

};
struct Ttree* GetFreeNode(struct TNode* parent, int value) {
    struct TNode* tmp = (struct TNode*)malloc(sizeof(struct TNode));
    tmp->Left = tmp->Right = NULL;
    tmp->Value = value;
    tmp->Parent = parent;
    return tmp;
}

void AddValueTree(struct TNode** node, int value) {
    if ((*node) == NULL) {
        (*node) = GetFreeNode(NULL, value);
    }
    else if (value > (*node)->Value) {
        AddValueTree(&((*node)->Right), value);
    }
    else if (value < (*node)->Value) {
        AddValueTree(&((*node)->Left), value);
    }
}

void AddValueStack(struct TStack* stack, struct TNode* node) {
    if (stack->Head) {
        stack->Tail->Next = (struct TStackNode*)malloc(sizeof(struct TStackNode));
        struct TStackNode* cur = stack->Tail;
        stack->Tail = stack->Tail->Next;
        stack->Tail->Parent = cur;
    }
    else {
        stack->Tail = stack->Head = (struct TStackNode*)malloc(sizeof(struct TStackNode));
        stack->Tail->Parent = NULL;
    }
    stack->Tail->Value = node;
    stack->Size += 1;
}

void FindTreeNode(struct TNode* node, struct TStack* stack, int value) {
    AddValueStack(stack, node);
    if (node->Value == value) {
        return;
    }
    else if (node->Value < value) {
        FindTreeNode(node->Right, stack, value);
    }
    else if (node->Value > value) {
        FindTreeNode(node->Left, stack, value);
    }
}

void LCA(struct TStack* firstStack, struct TStack* secondStack) {
    if (firstStack->Tail->Value->Value == secondStack->Tail->Value->Value) {
        printf("%d", firstStack->Tail->Value->Value);
        return;
    }
    else if (firstStack->Size >= secondStack->Size) {
        firstStack->Tail = firstStack->Tail->Parent; \
            firstStack->Size -= 1;
        LCA(firstStack, secondStack);
    }
    else if (firstStack->Size < secondStack->Size) {
        secondStack->Tail = secondStack->Tail->Parent;
        secondStack->Size -= 1;
        LCA(firstStack, secondStack);
    }

}

int main() {
    int height;
    scanf("%d \n", &height);
    int firstNode, secondNode;
    scanf("%d %d \n", &firstNode, &secondNode);
    char c = getchar();
    int num = 0;
    struct Ttree tree;
    tree.Head = NULL;
    while (c != '\n' && c != EOF) {
        if (c >= 48 && c <= 58) {
            num *= 10;
            num += c - '0';
        }
        else  if (num != 0 && c == ' ') {
            AddValueTree(&(tree.Head), num);
            num = 0;
        }
        c = getchar();
    }
    struct TStack firstStack;
    firstStack.Size = 0;
    firstStack.Head = firstStack.Tail = NULL;
    FindTreeNode(tree.Head, &firstStack, firstNode);
    struct TStack secondStack;
    secondStack.Size = 0;
    secondStack.Head = secondStack.Tail = NULL;
    FindTreeNode(tree.Head, &secondStack, secondNode);
    LCA(&firstStack, &secondStack);
    return 0;
}
