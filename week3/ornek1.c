#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void addOrdered(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
    }
    else {
        Node* current = *head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void removeNode(Node** head, int value) {
    if (*head == NULL) return;

    if ((*head)->data == value) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node* current = *head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

int count(Node* head) {
    int cnt = 0;
    Node* current = head;
    while (current != NULL) {
        cnt++;
        current = current->next;
    }
    return cnt;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void clear(Node** head) {
    Node* current = *head;
    Node* nextNode = NULL;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}

int main() {
    Node* head = NULL;

    addOrdered(&head, 23);
    addOrdered(&head, 11);
    addOrdered(&head, 5);
    addOrdered(&head, 9);
    addOrdered(&head, 6);
    addOrdered(&head, 4);
    addOrdered(&head, 12);
    addOrdered(&head, 24);

    printf("Sirali Liste:\n");
    printList(head);
    printf("Toplam Dugum Sayisi: %d\n\n", count(head));

    printf("11 degeri listeden siliniyor...\n");
    removeNode(&head, 11);
    printList(head);
    printf("Silindikten sonra dugum sayisi: %d\n", count(head));

    clear(&head);
    return 0;
}