#include  <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node n1, n2, n3, newNode;
    n1.data = 10;
    n2.data = 20;
    n3.data = 30;
    newNode.data = 40;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &newNode;
    newNode.next = NULL;

    struct Node* current = &n1;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    return 0;
}