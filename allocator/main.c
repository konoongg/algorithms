#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h>


struct Memory {
    int Start;
    int End ;
    struct  Memory* Last;
    struct  Memory* Next;
} ;

struct Memory* memory;
struct Memory** allocated;

int Alloc(int req, int index) {
    struct Memory* cur = memory;
    struct Memory* cur2 = NULL;
    while (cur != NULL) {
        if (cur->End - cur->Start + 1 >= req) {
            if (cur2 == NULL || cur->End - cur->Start > cur2->End- cur2->Start || (cur->End - cur->Start == cur2->End - cur2->Start && cur->Start < cur2->Start)) {
                cur2 = cur;
            }
        }
        cur = cur->Next;
    }
    if (cur2 != NULL) {
        struct Memory* newMemory = (struct Memory*)calloc(1, sizeof(struct Memory));
        newMemory->Start = cur2->Start;
        newMemory->End = cur2->Start + req - 1;
        allocated[index] = newMemory;
        cur2->Start += req;
        if (cur2->Start > cur2->End) {
            if (cur2->Last != NULL) {
                cur2->Last->Next = cur2->Next;
            }
            if (cur2->Next != NULL) {
                cur2->Next->Last = cur2->Last;
            }
            if (cur2 == memory) {
                memory = cur2->Next;
            }
            free(cur2);
        }
        return newMemory->Start;
    }
    else {
        return -1;
    }
}

void Free(int req) {
    struct Memory* cur = allocated[req];
    if (cur != NULL) {
        struct Memory* cur2 = memory;
        struct Memory* parent = NULL;
        while (cur2 != NULL && cur2->Start < cur->Start) {
            parent = cur2;
            cur2 = cur2->Next;
        }
        if (parent != NULL) {
            if (parent->End + 1 == cur->Start) {
                parent->End = cur->End;
                parent->Next = cur2;
                if (cur2 != NULL) {
                    cur2->Last = parent;
                }
                free(cur);
                cur = parent;
            }
            else {
                parent->Next = cur;
                cur->Last = parent;
            }
        }
        else {
            memory = cur;
        }
        if (cur2 != NULL && cur->End + 1 == cur2->Start) {
            cur->End = cur2->End;
            cur->Next = cur2->Next;
            if (cur2->Next != NULL) {
                cur2->Next->Last = cur;
            }
            free(cur2);
        }
        else {
            cur->Next = cur2;
            if (cur2 != NULL) {
                cur2->Last = cur;
            }
        }
        cur->Last = parent;

        allocated[req] = NULL;
    }
}


int main() {
    int sizeMem, countReq;
    scanf("%d %d", &sizeMem, &countReq);
    memory = (struct Memory*)malloc(sizeof(struct Memory));
    memory->Start = 1;
    memory->End = sizeMem;
    memory->Last = NULL;
    memory->Next = NULL;
    allocated = (struct Memory**)calloc(countReq + 1, sizeof(struct Memory));
    int req;
    for (int i = 0; i < countReq; ++i) {
        scanf("%d", &req);
        if (req > 0) {
            printf("%d\n", Alloc(req, i + 1));
        }
        else {
            Free(req * -1);
        }
    }
    return 0;
}
