#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node n;
    n.data = 10;
    n.next = NULL;

    printf("Veri: %d -> NULL\n", n.data);
    return 0;
}