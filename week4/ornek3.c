#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PrintJob {
    char fileName[50];
    struct PrintJob* next;
} PrintJob;

typedef struct Queue {
    PrintJob* front;
    PrintJob* rear;
} Queue;

void enqueuePrintJob(Queue* q, char* fileName) {
    PrintJob* newJob = (PrintJob*)malloc(sizeof(PrintJob));
    strcpy(newJob->fileName, fileName);
    newJob->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newJob;
    }
    else {
        q->rear->next = newJob;
        q->rear = newJob;
    }
    printf("Yeni dosya eklendi: %s\n", fileName);
}

void processNextJob(Queue* q) {
    if (q->front == NULL) {
        printf("Kuyruk bos, yazdirilacak is yok!\n");
        return;
    }
    PrintJob* temp = q->front;
    printf("Yazdiriliyor ve kuyruktan cikariliyor: %s\n", temp->fileName);
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

void showQueue(Queue q) {
    if (q.front == NULL) {
        printf("Kuyruk bos!\n");
        return;
    }
    PrintJob* current = q.front;
    printf("--- Yazici Kuyrugu ---\n");
    while (current != NULL) {
        printf("- %s\n", current->fileName);
        current = current->next;
    }
}

int main() {
    Queue q;
    q.front = q.rear = NULL;

    enqueuePrintJob(&q, "belge1.pdf");
    enqueuePrintJob(&q, "odev.docx");

    showQueue(q);

    processNextJob(&q);
    showQueue(q);

    return 0;
}