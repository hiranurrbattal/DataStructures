#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char name[50];
    struct Song* next;
    struct Song* prev;
} Song;

void addSongToEnd(Song** head, char* name) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->name, name);
    newSong->next = NULL;
    newSong->prev = NULL;

    if (*head == NULL) {
        *head = newSong;
    }
    else {
        Song* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newSong;
        newSong->prev = current;
    }
    printf("Sarki eklendi: %s\n", name);
}

void removeSong(Song** head, char* name) {
    if (*head == NULL) {
        printf("Liste bos!\n");
        return;
    }

    Song* current = *head;
    while (current != NULL && strcmp(current->name, name) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Sarki bulunamadi!\n");
        return;
    }

    if (current == *head) {
        *head = current->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
    }
    else {
        current->prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
    }

    free(current);
    printf("Sarki silindi: %s\n", name);
}

void playNext(Song** current) {
    if (*current != NULL && (*current)->next != NULL) {
        *current = (*current)->next;
        printf("Simdi caliniyor: %s\n", (*current)->name);
    }
    else {
        printf("Sonraki sarki yok!\n");
    }
}

void playPrevious(Song** current) {
    if (*current != NULL && (*current)->prev != NULL) {
        *current = (*current)->prev;
        printf("Simdi caliniyor: %s\n", (*current)->name);
    }
    else {
        printf("Onceki sarki yok!\n");
    }
}

void displayPlaylist(Song* head) {
    if (head == NULL) {
        printf("Liste bos!\n");
        return;
    }
    Song* current = head;
    printf("--- Oynatma Listesi ---\n");
    while (current != NULL) {
        printf("- %s\n", current->name);
        current = current->next;
    }
}

int main() {
    Song* head = NULL;
    Song* currentPlaying = NULL;

    addSongToEnd(&head, "Sarki 1");
    addSongToEnd(&head, "Sarki 2");
    addSongToEnd(&head, "Sarki 3");

    currentPlaying = head;
    displayPlaylist(head);

    playNext(&currentPlaying);
    playPrevious(&currentPlaying);

    removeSong(&head, "Sarki 2");
    displayPlaylist(head);

    return 0;
}