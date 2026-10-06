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

    int sum = 0;
    struct Node* current = &n1;
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }

    printf("Toplam: %d\n", sum);
    return 0;
}