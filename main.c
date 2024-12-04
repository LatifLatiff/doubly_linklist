#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    int ogrenci_no;
    char ad[50];
    char soyad[50];
    char bolum[50];
    int sinif;
    struct Node* prev;
    struct Node* next;
} Node;


Node* create_node(int ogrenci_no, char* ad, char* soyad, char* bolum, int sinif) {
    Node* yeni_dugum = (Node*)malloc(sizeof(Node));
    yeni_dugum->ogrenci_no = ogrenci_no;
    strcpy(yeni_dugum->ad, ad);
    strcpy(yeni_dugum->soyad, soyad);
    strcpy(yeni_dugum->bolum, bolum);
    yeni_dugum->sinif = sinif;
    yeni_dugum->prev = NULL;
    yeni_dugum->next = NULL;
    return yeni_dugum;
}

// Liste oluşturma
void create_list(Node** head) {
    if (*head != NULL) {
        printf("Liste zaten mevcut. Once listeyi yok edin.\n");
        return;
    }
    *head = NULL;
    printf("Bos liste olusturuldu.\n");
}

// Listeyi yok etme
void destroy_list(Node** head) {
    Node* gecici = *head;
    Node* temp;
    while (gecici != NULL) {
        temp = gecici;
        gecici = gecici->next;
        free(temp);
    }
    *head = NULL;
    printf("Liste yok edildi.\n");
}


void add_node(Node** head, int ogrenci_no, char* ad, char* soyad, char* bolum, int sinif) {
    Node* yeni_dugum = create_node(ogrenci_no, ad, soyad, bolum, sinif);
    if (*head == NULL) {
        *head = yeni_dugum;
        printf("Ogrenci listeye eklendi.\n");
        return;
    }

    Node* gecici = *head;
    while (gecici->next != NULL) {
        gecici = gecici->next;
    }
    gecici->next = yeni_dugum;
    yeni_dugum->prev = gecici;
    printf("Ogrenci listeye eklendi.\n");
}


void delete_node(Node** head, int ogrenci_no) {
    Node* gecici = *head;

    while (gecici != NULL && gecici->ogrenci_no != ogrenci_no) {
        gecici = gecici->next;
    }

    if (gecici == NULL) {
        printf("Silinecek ogrenci bulunamadı.\n");
        return;
    }

    if (gecici->prev != NULL) {
        gecici->prev->next = gecici->next;
    } else {
        *head = gecici->next;
    }

    if (gecici->next != NULL) {
        gecici->next->prev = gecici->prev;
    }

    free(gecici);
    printf("Ogrenci silindi.\n");
}

Node* search_node(Node* head, int ogrenci_no) {
    Node* gecici = head;
    while (gecici != NULL) {
        if (gecici->ogrenci_no == ogrenci_no) {
            return gecici;
        }
        gecici = gecici->next;
    }
    return NULL;
}


void display_list(Node* head) {
    Node* gecici = head;
    if (gecici == NULL) {
        printf("Liste bos.\n");
        return;
    }
    printf("Liste:\n");
    while (gecici != NULL) {
        printf("%d %s %s %s %d\n", gecici->ogrenci_no, gecici->ad, gecici->soyad, gecici->bolum, gecici->sinif);
        gecici = gecici->next;
    }
}


int main() {
    Node* bas = NULL;
    int secim, ogrenci_no, sinif;
    char ad[50], soyad[50], bolum[50];

    while (1) {
        printf("\n==== Cift Bagli Liste Menu ====\n");
        printf("1. Liste olustur\n");
        printf("2. Listeyi yok et\n");
        printf("3. Dugum ekle\n");
        printf("4. Dugum sil\n");
        printf("5. Dugum ara\n");
        printf("6. Listeyi goster\n");
        printf("7. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                create_list(&bas);
                break;
            case 2:
                destroy_list(&bas);
                break;
            case 3:
                printf("Ogrenci No: ");
                scanf("%d", &ogrenci_no);
                printf("Ad: ");
                scanf("%s", ad);
                printf("Soyad: ");
                scanf("%s", soyad);
                printf("Bolum: ");
                scanf("%s", bolum);
                printf("Sinif: ");
                scanf("%d", &sinif);
                add_node(&bas, ogrenci_no, ad, soyad, bolum, sinif);
                break;
            case 4:
                printf("Silmek istediginiz Ogrenci No: ");
                scanf("%d", &ogrenci_no);
                delete_node(&bas, ogrenci_no);
                break;
            case 5:
                printf("Aramak istediginiz Ogrenci No: ");
                scanf("%d", &ogrenci_no);
                Node* bulunan = search_node(bas, ogrenci_no);
                if (bulunan) {
                    printf("Bulundu: %d %s %s %s %d\n", bulunan->ogrenci_no, bulunan->ad, bulunan->soyad, bulunan->bolum, bulunan->sinif);
                } else {
                    printf("Ogrenci bulunamadı.\n");
                }
                break;
            case 6:
                display_list(bas);
                break;
            case 7:
                destroy_list(&bas);
                printf("Cıkıs yapılıyor...\n");
                return 0;
            default:
                printf("Gecersiz secim! Tekrar deneyin.\n");
        }
    }
}
