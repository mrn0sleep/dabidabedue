#ifndef head_H
#define head_H

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
} List;

void create(List *L);
int isEmpty(List L);
Node* allocate(int x);
void deallocate(Node *P);
void insert(List *L, int x);
Node* search(List L, int x);
void removeData(List *L, int x);
void destroy(List *L);
int length(List L);

#endif
