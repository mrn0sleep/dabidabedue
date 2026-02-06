#include <stdio.h>
#include "head.h"

int main() {
    List L;
    create(&L);

    insert(&L, 10);
    insert(&L, 20);
    insert(&L, 30);

    printf("Jumlah data: %d\n", length(L));

    Node *hasil = search(L, 20);
    if(hasil != NULL)
        printf("Data ditemukan\n");

    removeData(&L, 20);
    printf("Jumlah setelah hapus: %d\n", length(L));

    destroy(&L);
}
