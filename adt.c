#include <stdio.h>
#include <stdlib.h>
#include "head.h"

void create(List *L) {
    L->head = NULL;
}

int isEmpty(List L) {
    return L.head == NULL;
}

Node* allocate(int x) {
    Node *P = (Node*)malloc(sizeof(Node));
    if(P != NULL) {
        P->data = x;
        P->next = NULL;
    }
    return P;
}

void deallocate(Node *P) {
    free(P);
}

void insert(List *L, int x) {
    Node *P = allocate(x);
    if(P == NULL) return;

    P->next = L->head;
    L->head = P;
}

Node* search(List L, int x) {
    Node *temp = L.head;
    while(temp != NULL) {
        if(temp->data == x) return temp;
        temp = temp->next;
    }
    return NULL;
}

void removeData(List *L, int x) {
    Node *temp = L->head;
    Node *prev = NULL;

    while(temp != NULL) {
        if(temp->data == x) {
            if(prev == NULL)
                L->head = temp->next;
            else
                prev->next = temp->next;

            deallocate(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void destroy(List *L) {
    Node *temp = L->head;
    while(temp != NULL) {
        Node *hapus = temp;
        temp = temp->next;
        deallocate(hapus);
    }
    L->head = NULL;
}

int length(List L) {
    int count = 0;
    Node *temp = L.head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;

