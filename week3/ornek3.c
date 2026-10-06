#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* findMiddle(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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
    Node* clearPtr = *head;
    Node* nextNode = NULL;
    while (clearPtr != NULL) {
        nextNode = clearPtr->next;
        free(clearPtr);
        clearPtr = nextNode;
    }
    *head = NULL;
}

int main() {
    Node* head = NULL;

    Node* second = (Node*)malloc(sizeof(Node));
    Node* third = (Node*)malloc(sizeof(Node));
    Node* fourth = (Node*)malloc(sizeof(Node));
    Node* fifth = (Node*)malloc(sizeof(Node));

    head = (Node*)malloc(sizeof(Node));
    head->data = 10; head->next = second;
    second->data = 20; second->next = third;
    third->data = 30; third->next = fourth;
    fourth->data = 40; fourth->next = fifth;
    fifth->data = 50; fifth->next = NULL;

    printf("Mevcut Liste:\n");
    printList(head);

    Node* middle = findMiddle(head);
    if (middle != NULL) {
        printf("Listenin Ortasindaki Deger: %d\n", middle->data);
    }

    clear(&head);
    return 0;
}