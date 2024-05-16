
#include <stdio.h>
#include <stdlib.h>

void construiesteMatriceAdiacenta(const char* numeFisier, int** matriceAdiacenta, int* n, int* m) {
    FILE* fisier = fopen(numeFisier, "r");
    if (fisier == NULL) {
        printf("Eroare la deschiderea fisierului.\n");
        exit(1);
    }

    fscanf(fisier, "%d %d", n, m);

    *matriceAdiacenta = (int*)malloc((*n) * (*n) * sizeof(int));

    int i, j;
    for (i = 0; i < *n; i++) {
        for (j = 0; j < *n; j++) {
            (*matriceAdiacenta)[i * (*n) + j] = 0;
        }
    }

    int x, y;
    for (i = 0; i < *m; i++) {
        fscanf(fisier, "%d %d", &x, &y);
        (*matriceAdiacenta)[(x - 1) * (*n) + (y - 1)] = 1;
        (*matriceAdiacenta)[(y - 1) * (*n) + (x - 1)] = 1;
    }

    fclose(fisier);
}

void afisareMatriceAdiacenta(int* matriceAdiacenta, int n) {
    int i, j;
    printf("Matricea de adiacenta:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriceAdiacenta[i * n + j]);
        }
        printf("\n");
    }
}

void noduriGradMaxim(int* matriceAdiacenta, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        int grad = 0;
        for (j = 0; j < n; j++) {
            grad += matriceAdiacenta[i * n + j];
        }
        if (grad == n - 1) {
            printf("Nodul %d are gradul maxim.\n", i + 1);
        }
    }
}

int main() {
    int* matriceAdiacenta;
    int n, m;

    construiesteMatriceAdiacenta("lista.txt", &matriceAdiacenta, &n, &m);
    afisareMatriceAdiacenta(matriceAdiacenta, n);
    noduriGradMaxim(matriceAdiacenta, n);

    free(matriceAdiacenta);

    return 0;
}
