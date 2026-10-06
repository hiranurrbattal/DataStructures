#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
=========================================================
 1. SORU: 10 Elemanli Dizi Islemleri
=========================================================
 T(n) Zaman Maliyeti: c1 + c2 * n + c3 * n
 O(n) Zaman Karmasikligi: O(n) - Donguler n kez doner.
 S(n) Alan Karmasikligi: O(n) - 10 elemanli dizi.
*/
int main() {
    int dizi[10];
    int i;

    printf("\n--- Dizi Islemleri ---\n");
    printf("Lutfen 10 adet tamsayi giriniz:\n");
    for (i = 0; i < 10; i++) {
        printf("%d. elemani giriniz: ", i + 1);
        scanf("%d", &dizi[i]);
    }

    printf("\ndizinin elemanlari:\n");
    for (i = 0; i < 10; i++) {
        printf("dizi[%d] = %d\n", i, dizi[i]);
    }

    return 0;
}