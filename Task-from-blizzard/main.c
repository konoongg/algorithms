#include <stdlib.h>
#include <stdio.h>

struct TListNode {
    int Hp;
    int Dmg;
    struct TListNode* Next;
    struct TListNode* Last;
};


struct TPlayer {
    struct TListNode* Head;
    struct TListNode* Tail;
    int Size;
};

void InputCreature(struct TPlayer* player, int dmg, int hp) {
    if (player->Head) {
            player->Tail->Next = (struct TListNode*)malloc(sizeof(struct TListNode));
            struct TListNode* nearLast = player->Tail;
            player->Tail = player->Tail->Next;
            player->Tail->Last = nearLast;
            player->Tail->Dmg = dmg;
            player->Tail->Hp = hp;
            player->Tail->Next = NULL;
        
    }
    else {
        player->Tail = player->Head = (struct TListNode*)malloc(sizeof(struct TListNode));
        player->Head->Dmg = dmg;
        player->Head->Hp = hp;
        player->Head->Next = NULL;
        player->Head->Last = NULL;
    }
}

void InputPlayer(struct TPlayer* player) {
    int c;
    int status = 0;
    int parametr = 0;
    int countSC = player->Size;
    while (countSC > 0) {
        int hp, dmg;
        scanf_s(" (%d, %d)",&dmg ,&hp);
        //printf("%d %d \n", dmg, hp);
        InputCreature(player, dmg, hp);
        countSC -= 1;
    }
}

void Delete(struct TPlayer* player, struct TListNode* create) {
    if (create->Last) {
        struct TListNode* previous = create->Last;
        previous->Next = create->Next;
    }
    else {
        player->Head = create->Next;
        player->Head->Last = NULL;
        player->Tail->Next = create->Next;
    }
    player->Size -= 1;
}

void Fight(struct TListNode* firstCreat, struct TListNode* secondCreat) {
    firstCreat->Hp -= secondCreat->Dmg;
    secondCreat->Hp -= firstCreat->Dmg;
}

int main() {
    struct TPlayer firstPlayer;
    struct TPlayer secondPlayer;
    firstPlayer.Head = firstPlayer.Tail = NULL;
    secondPlayer.Head = secondPlayer.Tail = NULL;
    scanf_s("%d", &firstPlayer.Size);
    InputPlayer(&firstPlayer);
    scanf_s("%d", &secondPlayer.Size);
    //printf("%d", secondPlayer.Size);
    InputPlayer(&secondPlayer);
    firstPlayer.Tail->Next = firstPlayer.Head;
    secondPlayer.Tail->Next = secondPlayer.Head;
    struct TListNode* firstCur = firstPlayer.Head;
    struct TListNode* secondCur = secondPlayer.Head;
    while (firstPlayer.Size * secondPlayer.Size !=0) {
        Fight(firstCur, secondCur);
        if (firstCur->Hp <= 0) {
            Delete(&firstPlayer, firstCur);
        }
        if (secondCur->Hp <= 0) {
            Delete(&secondPlayer, secondCur );
        }
        firstCur = firstCur->Next;
        secondCur = secondCur->Next;
    }
    if (firstPlayer.Size == 0 && secondPlayer.Size == 0) {
        printf("0");
    }
    else if (firstPlayer.Size == 0 ) {
        printf("1");
    }
    else {
        printf("-1");
    }
    return 0;
}

