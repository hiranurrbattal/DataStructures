#include <stdio.h>
#include <stdlib.h>

// Düðüm yapýsý
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Yeni düðüm oluþturma yardýmcý fonksiyonu
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Soru 1: BST'ye eleman ekleme (insert)
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    // Ayný deðer tekrar verilirse yeni düðüm oluþturma
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Soru 1: Inorder dolaþma (Sol -> Kök -> Sað)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Soru 2: Aðaçta deðer arama (Bulunduysa 1, bulunamadýysa 0 döndürür)
int search(struct Node* root, int value) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == value) {
        return 1;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    else {
        return search(root->right, value);
    }
}

// Soru 2: Aðaçtaki en küçük deðeri bulma (En soldaki düðüm)
int findMin(struct Node* root) {
    struct Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

int main() {
    struct Node* root = NULL;
    int numbers[] = { 40, 20, 60, 10, 30, 50, 70 };

    // Aðacý oluþturma ve elemanlarý ekleme
    for (int i = 0; i < 7; i++) {
        root = insert(root, numbers[i]);
    }

    // Soru 1 için Inorder çýktýsý kontrolü
    printf("Inorder: ");
    inorder(root);
    printf("\n\n");

    // Soru 2 main fonksiyonu entegrasyonu
    if (search(root, 30))
        printf("30 agacta bulundu.\n");
    else
        printf("30 agacta bulunamadi.\n");

    if (search(root, 90))
        printf("90 agacta bulundu.\n");
    else
        printf("90 agacta bulunamadi.\n");

    if (root != NULL)
        printf("En kucuk eleman: %d\n", findMin(root));

    return 0;
}

/*
 
 KISA DEÐERLENDÝRME SORULARI YANITLARI:
 
 1. 25 deðeri eklenirse hangi düðümün altýna yerleþir?
    -> 30 düðümünün sol çocuðu olarak yerleþir.

 2. Inorder fonksiyonunda printf() ilk satýra taþýnýrsa hangi dolaþma elde edilir?
    -> Preorder (Kök -> Sol -> Sað) dolaþýmý elde edilir.

 3. findMin() içinde left yerine right takip edilirse hangi deðer bulunur?
    -> Aðaçtaki en büyük deðer (maksimum / en saðdaki düðüm) bulunur.
  
*/