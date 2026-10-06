#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAt(Node** head, int value, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (position <= 0 || *head == NULL) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    int index = 0;

    while (current->next != NULL && index < position - 1) {
        current = current->next;
        index++;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void deleteAt(Node** head, int position) {
    if (*head == NULL) return;

    if (position == 0) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node* current = *head;
    int index = 0;

    while (current->next != NULL && index < position - 1) {
        current = current->next;
        index++;
    }

    if (current->next == NULL) {
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
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

    insertAt(&head, 10, 0);
    insertAt(&head, 20, 1);
    insertAt(&head, 5, 0);
    insertAt(&head, 15, 2);

    printf("Pozisyona Gore Eklendikten Sonra:\n");
    printList(head);

    deleteAt(&head, 1);
    printf("1. pozisyon silindikten sonra:\n");
    printList(head);

    clear(&head);
    return 0;
}