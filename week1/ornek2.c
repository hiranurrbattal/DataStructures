#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
=========================================================
 2. SORU: Palindrom Sayi Kontrolu
=========================================================
 T(n) Zaman Maliyeti: c1 + c2 * k (k basamak sayisi)
 O(n) Zaman Karmasikligi: O(log n) veya O(k)
 S(n) Alan Karmasikligi: O(1) - Sabit bellek alani harcar.
*/
int main() {
    int sayi, orijinal, ters = 0, kalan;

    printf("\n--- Palindrom Kontrolu ---\n");
    printf("Bir tam sayi giriniz: ");
    scanf("%d", &sayi);

    orijinal = sayi;

    while (sayi > 0) {
        kalan = sayi % 10;
        ters = (ters * 10) + kalan;
        sayi = sayi / 10;
    }

    if (orijinal == ters) {
        printf("%d bir palindrom sayidir.\n", orijinal);
    }
    else {
        printf("%d bir palindrom sayi degildir.\n", orijinal);
    }

    return 0;
}