#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Word {
    char text[50];
    struct Word* next;
} Word;

void pushWord(Word** top, char* text) {
    Word* newWord = (Word*)malloc(sizeof(Word));
    strcpy(newWord->text, text);
    newWord->next = *top;
    *top = newWord;
}

void popWord(Word** top) {
    if (*top == NULL) {
        printf("Geri alinacak kelime yok!\n");
        return;
    }
    Word* temp = *top;
    *top = (*top)->next;
    printf("Undo (Geri alindi): %s\n", temp->text);
    free(temp);
}

void showWords(Word* top) {
    if (top == NULL) {
        printf("-> (Bos)\n");
        return;
    }
    char arr[100][50];
    int count = 0;
    Word* current = top;
    while (current != NULL) {
        strcpy(arr[count++], current->text);
        current = current->next;
    }
    printf("-> ");
    for (int i = count - 1; i >= 0; i--) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int main() {
    Word* top = NULL;

    pushWord(&top, "Merhaba");
    pushWord(&top, "Dunya");
    showWords(top);

    popWord(&top);
    showWords(top);

    return 0;
}