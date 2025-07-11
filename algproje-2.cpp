// En Yakýn Ekleme Sezgiseli
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define iller 82 // Türkiye'deki illerin sayýsý
#define DOSYA_ADI "Mesafe.txt" // mesafe verilerinin bulunduðu dosyanýn adý

int main()
{
    int i, j, k, x, y, indis;
    int dizi[iller][iller];
    int kontrol[iller] = {0};
    int tur[iller+1] = {0};

    // mesafe verilerini dosyadan oku ve matrise kaydet
    FILE *fp = fopen(DOSYA_ADI, "r");
    if (fp == NULL) {
        printf("Dosya acilamadi.\n");
        return 1;
    }

    for (i = 1; i <= iller - 1; i++) {
        for (j = 1; j <= iller - 1; j++) {
            fscanf(fp, "%d", &dizi[i][j]);
        }
    }

    fclose(fp);

    // rastgele bir sehir sec ve kontrol dizisine ekle
    srand(time(NULL));
    x = 1 + rand() % (iller - 1);
    kontrol[x] = 1;
    tur[1] = x;

    // en yakin sehire git
    for (k = 2; k <= iller; k++) {
        int enk = INT_MAX;
        for (i = 1; i <= iller - 1; i++) {
            if (kontrol[i] == 1) {
                for (j = 1; j <= iller - 1; j++) {
                    if (kontrol[j] == 0 && dizi[i][j] < enk) {
                        enk = dizi[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        kontrol[y] = 1;
        tur[k] = y;
    }

    // turu ekrana yazdir
    printf("Tur: ");
    for (i = 1; i <= iller; i++) {
        printf("%d ", tur[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}


