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

    int count = 0;
    struct Node* current = &n1;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    printf("Eleman sayisi: %d\n", count);
    return 0;
}