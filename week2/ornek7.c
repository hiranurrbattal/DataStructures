#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node n1, n2, n3, n4;
    n1.data = 10;
    n2.data = 20;
    n3.data = 30;
    n4.data = 40;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = NULL;

    int aranan;
    printf("Aranan sayiyi girin: ");
    scanf("%d", &aranan);

    int bulundu = 0;
    struct Node* current = &n1;
    while (current != NULL) {
        if (current->data == aranan) {
            bulundu = 1;
            break;
        }
        current = current->next;
    }

    if (bulundu) {
        printf("Bulundu!\n");
    }
    else {
        printf("Bulunamadi!\n");
    }

    return 0;
}