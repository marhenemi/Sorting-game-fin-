#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// asetetaan sallitut arvauskerrat
int sal_ARVAUSKERTOJA = 5;


// Sekoitetaan numerot 1, 2, 3 ja 4, kuten Googgeli meitä ohjeistaa
void sekoita_numerot(int numerot[]) {
    for (int i = 0; i < 4; i++) {
        numerot[i] = i + 1; 
    }

    srand(time(NULL));

    for (int i = 0; i < 4; i++) {
        int swap_index = rand() % 4;
        
        // määritetään, että yhtä lukua tulee vain kerran:
        int temp = numerot[i];
        numerot[i] = numerot[swap_index];   // sekoitetaan
        numerot[swap_index] = temp;
    }
} 

// tarkastetaan pelaajan syöttämä arvo
int tarkista_arvaus(int arvaus[], int oikea_jarjestys[]) {
    int oikein_paikoillaan = 0;     //montako arvauksesta on oikein paikoillaan

    for (int i = 0; i < 4; i++) {
        if (arvaus[i] == oikea_jarjestys[i]) {
            oikein_paikoillaan++;
        }
    }

    return oikein_paikoillaan;
}


// paljastetaan oikea järjestys
void tulosta_jarjestys(int jarjestys[]) {
    printf("Oikea järjestys: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", jarjestys[i]);
    }
    printf("\n");
}



int main() {
    int oikea_jarjestys[4];
    int arvaus[4];
    int arvauskertoja = 0;

    sekoita_numerot(oikea_jarjestys);

    printf("\n\n\n* N U M E R O A R V A U S P E L I *\n\n");
    printf("Arvaa numeroiden 1, 2, 3 ja 4 oikea järjestys. Syötä arvaus muodossa X X X X\n");
    printf("Sinulla on %d arvauskertaa.\n", sal_ARVAUSKERTOJA);

    while (arvauskertoja < sal_ARVAUSKERTOJA) {
        printf("Syötä arvauksesi (1 2 3 4): ");
        scanf("%d %d %d %d", &arvaus[0], &arvaus[1], &arvaus[2], &arvaus[3]);

        int oikein_paikoillaan = tarkista_arvaus(arvaus, oikea_jarjestys);

        if (oikein_paikoillaan == 4) {
            printf("Wohooo! Arvasit oikean järjestyksen!\n");
            break;
        } else {
            printf("Oikeita numeroita oikeilla paikoilla: %d\n", oikein_paikoillaan);
            arvauskertoja++;
            printf("Sinulla on jäljellä %d arvauskertaa.\n", sal_ARVAUSKERTOJA - arvauskertoja);
        }
    }

    if (arvauskertoja == sal_ARVAUSKERTOJA) {
        tulosta_jarjestys(oikea_jarjestys);
        printf("Et arvannut oikeaa järjestystä. Better luck next time!\n");
    }

    return 0;
}