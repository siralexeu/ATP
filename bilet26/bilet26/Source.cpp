//Cavaler Alexandru Grupa 1028 AN 1 Seria F
// biletul 26 - studentii care au obtinut cel mai mic punctaj la teme
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nr;
    char nume[30];
    int grupa;
    char puncte[30];
    char pct_teme[10];
    char pct_examen[50];
} student;

void ListareBtoT(const char* numeBin, const char* numeText) {
    FILE* f, * g;
    student s;
    int n = 0;

    f = fopen(numeBin, "rb");
    if (!f) {
        printf("Fisierul binar nu s-a deschis\n");
        return;
    }

    g = fopen(numeText, "w");
    if (!g) {
        printf("Fisierul text nu s-a putut crea\n");
        fclose(f);
        return;
    }

    while (fread(&s, sizeof(student), 1, f) == 1) {
        fprintf(g, "%-5d %-30s %-5d %-10s %-10s %-10s\n", ++n, s.nume, s.grupa, s.puncte, s.pct_teme, s.pct_examen);
    }

    fclose(f);
    fclose(g);
}

int main() {
    FILE* f;
    student s, s_min;
    int min_teme = 11;

    f = fopen("02.Fis_secv_Puncte", "rb");
    if (!f) {
        printf("\nFisierul nu poate fi deschis\n");
        return 1;
    }

    while (fread(&s, sizeof(student), 1, f) == 1) {
        int teme = 0;
        for (int i = 0; i < 10; i++) {
            if (s.pct_teme[i] == '1') {
                teme++;
            }
        }
        if (teme < min_teme) {
            min_teme = teme;
            s_min = s;
        }
    }

    fclose(f);

    if (min_teme == 11) {
        printf("Nu exista studenti in fisier.\n");
        return 1;
    }

    printf("Studentul cu cel mai mic punctaj la teme:\n");
    printf("Numar matricol: %d\n", s_min.nr);
    printf("Nume si prenume: %s\n", s_min.nume);
    printf("Grupa: %d\n", s_min.grupa);
    printf("Puncte proba practica: %s\n", s_min.puncte);
    printf("Puncte la teme: %s\n", s_min.pct_teme);
    printf("Puncte examen: %s\n", s_min.pct_examen);

    ListareBtoT("02.Fis_secv_Puncte", "raport01.txt");

    return 0;
}
