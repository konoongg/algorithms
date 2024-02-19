#include <stdlib.h>
#include <stdio.h>

typedef struct TSymNode {
    int Sym;
    struct TSymNode* Next;
    struct TSymNode* Last;
} TSymNode;

typedef struct TSym {
    struct TSymNode* Head;
    struct TSymNode* Tail;
} TSym;

void Push(TSym* list, int sym) {
    if (list->Head) {
        list->Tail->Next = (struct TSymNode*)malloc(sizeof(struct TSymNode));
        TSymNode* cur = list->Tail->Next;
        cur->Last = list->Tail;
        cur->Next = NULL;
        cur->Sym = sym;
        list->Tail = cur;
    }
    else {
        list->Tail = list->Head = (struct TSymNode*)malloc(sizeof(struct TSymNode));
        list->Head->Next = NULL;
        list->Head->Last = NULL;
        list->Head->Sym = sym;
    }

}

int Delete(TSym* list) {
    int symbol = list->Tail->Sym;
    if (list->Tail->Last) {
        TSymNode* cur = list->Tail->Last;
        cur->Next = NULL;
        list->Tail = cur;
    }
    else {
        list->Head = list->Tail = NULL;
    }
    return symbol;
}

void Math(TSym* parametrs, TSym* func) {
    int operand = Delete(func);
    int newSym = Delete(parametrs);
    if (operand == '|') {
        int IsScob;
        while ((IsScob = Delete(parametrs)) != '(') {
            newSym = newSym || IsScob;
        }
        Push(parametrs, newSym);

    }
    else if (operand == '&') {
        int IsScob;
        while ((IsScob = Delete(parametrs)) != '(') {
            newSym = newSym && IsScob;
        }
        Push(parametrs, newSym);
    }
    else if (operand == '!') {
        newSym += 1;
        newSym %= 2;
        Push(parametrs, newSym);
    }
}

int main(void) {
    TSym parametrs;
    parametrs.Head = parametrs.Tail = NULL;
    TSym func;
    func.Head = func.Tail = NULL;
    int c;
    while ((c = getchar()) != '\n') {
        if (c == 'f') {
            Push(&parametrs, 0);
        }
        else if (c == 't') {
            Push(&parametrs, 1);
        }
        else if (c == '(') {
            Push(&parametrs, '(');
        }
        else if (c == '!' || c == '|' || c == '&' ) {
            Push(&func, c);
        }
        else if (c == ')') {
            Math(&parametrs, &func);
        }
    }
    int lastSym = Delete(&parametrs);
    if (lastSym == 0) {
        printf("f");
    }
    else {
        printf("t");
    }
	return 0;
}

