#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hasta yapýsý (ID, Ýsim ve Durum bilgisi)
typedef struct Hasta {
    int id;
    char isim[50];
    char durum[20]; // "bekliyor", "muayenede", "tamamlandi"
    struct Hasta* sonraki; // Hem kuyruk, hem yýðýn, hem baðlý liste için pointer
} Hasta;

// Kuyruk (Queue) yapýsý
typedef struct {
    Hasta* bas;
    Hasta* son;
} Kuyruk;

// Yýðýn (Stack) yapýsý
typedef struct {
    Hasta* tepe;
} Yigin;

// Baðlý Liste (Linked List - Geçmiþ Kayýtlar) için baþ ve son iþaretçileri
typedef struct {
    Hasta* bas;
    Hasta* son;
} GecmisListe;

//  Fonksiyon Prototipleri
Kuyruk* kuyrukOlustur();
Yigin* yiginOlustur();
GecmisListe* gecmisListeOlustur();

void enqueue(Kuyruk* k, int id, const char* isim);
Hasta* dequeue(Kuyruk* k);

void push(Yigin* y, Hasta* h);
Hasta* pop(Yigin* y);

void gecmisEkle(GecmisListe* g, Hasta* h);

void durumlarýYazdir(Kuyruk* k, Yigin* y, GecmisListe* g);
void bellekTemizle(Kuyruk* k, Yigin* y, GecmisListe* g);

int main() {
    // Yapýlarýn oluþturulmasý
    Kuyruk* bekleyenKuyrugu = kuyrukOlustur();
    Yigin* muayeneOdasi = yiginOlustur();
    GecmisListe* gecmisKaitlar = gecmisListeOlustur();

    printf("=== 4. Hastalari belirtilen sirayla sisteme kaydediniz ===\n");
    enqueue(bekleyenKuyrugu, 1, "Ahmet");
    enqueue(bekleyenKuyrugu, 2, "Mehmet");
    enqueue(bekleyenKuyrugu, 3, "Ayse");

    printf("\n--- Baslangic Durumu (Tuum Hastalar Bekliyor) ---\n");
    durumlarýYazdir(bekleyenKuyrugu, muayeneOdasi, gecmisKaitlar);

    printf("\n=== 5. Ahmet'i muayeneye alip muayenesini tamamlayiniz ===\n");
    // Ahmet'i kuyruktan al, yýðýna ekle (durumu "muayenede" olur)
    Hasta* h1 = dequeue(bekleyenKuyrugu);
    if (h1 != NULL) {
        strcpy(h1->durum, "muayenede");
        push(muayeneOdasi, h1);
    }
    // Ahmet'in muayenesi bitti, yýðýndan çýkar, geçmiþe ekle (durumu "tamamlandi" olur)
    Hasta* b1 = pop(muayeneOdasi);
    if (b1 != NULL) {
        strcpy(b1->durum, "tamamlandi");
        gecmisEkle(gecmisKaitlar, b1);
    }

    printf("\n=== 6. Mehmet'i muayeneye alip muayenesini tamamlayiniz ===\n");
    // Mehmet'i kuyruktan al, yýðýna ekle
    Hasta* h2 = dequeue(bekleyenKuyrugu);
    if (h2 != NULL) {
        strcpy(h2->durum, "muayenede");
        push(muayeneOdasi, h2);
    }
    // Mehmet'in muayenesi bitti, yýðýndan çýkar, geçmiþe ekle
    Hasta* b2 = pop(muayeneOdasi);
    if (b2 != NULL) {
        strcpy(b2->durum, "tamamlandi");
        gecmisEkle(gecmisKaitlar, b2);
    }

    printf("\n=== 7. Ayse'yi bekleme kuyrugunda birakiniz ===\n");
    // Ayþe zaten kuyrukta bekliyor, ekstra iþlem yapmaya gerek yok.

    printf("\n=== Tum Islemler Sonrasi ===\n");
    durumlarýYazdir(bekleyenKuyrugu, muayeneOdasi, gecmisKaitlar);

    // Dinamik bellek sýzýntýlarýný (memory leak) önlemek için temizlik
    bellekTemizle(bekleyenKuyrugu, muayeneOdasi, gecmisKaitlar);

    return 0;
}

// Kuyruk Fonksiyonlarý 
Kuyruk* kuyrukOlustur() {
    Kuyruk* k = (Kuyruk*)malloc(sizeof(Kuyruk));
    k->bas = k->son = NULL;
    return k;
}

void enqueue(Kuyruk* k, int id, const char* isim) {
    Hasta* yeniHasta = (Hasta*)malloc(sizeof(Hasta));
    yeniHasta->id = id;
    strcpy(yeniHasta->isim, isim);
    strcpy(yeniHasta->durum, "bekliyor");
    yeniHasta->sonraki = NULL;

    if (k->son == NULL) {
        k->bas = k->son = yeniHasta;
        return;
    }
    k->son->sonraki = yeniHasta;
    k->son = yeniHasta;
}

Hasta* dequeue(Kuyruk* k) {
    if (k->bas == NULL) {
        printf("Hata: Kuyruk bos!\n");
        return NULL;
    }
    Hasta* temp = k->bas;
    k->bas = k->bas->sonraki;
    if (k->bas == NULL) {
        k->son = NULL;
    }
    temp->sonraki = NULL; // Baðlantýyý kopar
    return temp;
}

// Yýðýn Fonksiyonlarý
Yigin* yiginOlustur() {
    Yigin* y = (Yigin*)malloc(sizeof(Yigin));
    y->tepe = NULL;
    return y;
}

void push(Yigin* y, Hasta* h) {
    h->sonraki = y->tepe;
    y->tepe = h;
}

Hasta* pop(Yigin* y) {
    if (y->tepe == NULL) {
        printf("Hata: Yigin bos!\n");
        return NULL;
    }
    Hasta* temp = y->tepe;
    y->tepe = y->tepe->sonraki;
    temp->sonraki = NULL; // Baðlantýyý kopar
    return temp;
}

// Baðlý Liste (Geçmiþ Kayýtlar) Fonksiyonlarý 
GecmisListe* gecmisListeOlustur() {
    GecmisListe* g = (GecmisListe*)malloc(sizeof(GecmisListe));
    g->bas = g->son = NULL;
    return g;
}

void gecmisEkle(GecmisListe* g, Hasta* h) {
    h->sonraki = NULL;
    if (g->bas == NULL) {
        g->bas = g->son = h;
        return;
    }
    g->son->sonraki = h;
    g->son = h;
}

// Listeleme ve Durum Gösterme Fonksiyonu 
void durumlarýYazdir(Kuyruk* k, Yigin* y, GecmisListe* g) {
    // 1. Bekleyen Hastalar
    printf("--- Bekleyen Hastalar ---\n");
    if (k->bas == NULL) {
        printf("Hasta yok.\n");
    }
    else {
        Hasta* curr = k->bas;
        while (curr != NULL) {
            printf("Hasta ID: %d, Isim: %s, Durum: %s\n", curr->id, curr->isim, curr->durum);
            curr = curr->sonraki;
        }
    }

    // 2. Muayene Odasýndaki Hastalar
    printf("--- Muayene Odasindaki Hastalar ---\n");
    if (y->tepe == NULL) {
        printf("Hasta yok.\n");
    }
    else {
        Hasta* curr = y->tepe;
        while (curr != NULL) {
            printf("Hasta ID: %d, Isim: %s, Durum: %s\n", curr->id, curr->isim, curr->durum);
            curr = curr->sonraki;
        }
    }

    // 3. Tamamlanan Hastalar
    printf("--- Tamamlanan Hastalar ---\n");
    if (g->bas == NULL) {
        printf("Hasta yok.\n");
    }
    else {
        Hasta* curr = g->bas;
        while (curr != NULL) {
            printf("Hasta ID: %d, Isim: %s, Durum: %s\n", curr->id, curr->isim, curr->durum);
            curr = curr->sonraki;
        }
    }
}

// Bellek Temizleme Fonksiyonu 
void bellekTemizle(Kuyruk* k, Yigin* y, GecmisListe* g) {
    // Kalan kuyruk elemanlarý
    Hasta* curr = k->bas;
    while (curr != NULL) {
        Hasta* silinecek = curr;
        curr = curr->sonraki;
        free(silinecek);
    }
    free(k);

    // Kalan yýðýn elemanlarý
    curr = y->tepe;
    while (curr != NULL) {
        Hasta* silinecek = curr;
        curr = curr->sonraki;
        free(silinecek);
    }
    free(y);

    // Geçmiþ liste elemanlarý
    curr = g->bas;
    while (curr != NULL) {
        Hasta* silinecek = curr;
        curr = curr->sonraki;
        free(silinecek);
    }
    free(g);
}