#include <stdio.h>

void subset_sum_min(int S[], int n, int subset[], int* subset_size) {
    // Calculăm suma totală a mulțimii S
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += S[i];
    }

    // Calculăm suma minimă a unei submulțimi
    int curr_sum = 0;
    int min_sum = total_sum;
    int min_subset_size = 0;

    for (int i = 0; i < n; i++) {
        curr_sum += S[i];

        // Verificăm dacă suma curentă este mai mică decât suma minimă găsită până acum
        if (curr_sum <= min_sum) {
            min_sum = curr_sum;
            min_subset_size = i + 1;
        }
    }

    // Construim submulțimea cu suma minimăa
    *subset_size = min_subset_size;
    for (int i = 0; i < min_subset_size; i++) {
        subset[i] = S[i];
    }
}

int main() {
    int S[] = { -8, -5, -3, 2, 6, 7 };
    int n = sizeof(S) / sizeof(S[0]);

    int subset[10];
    int subset_size;

    subset_sum_min(S, n, subset, &subset_size);

    printf("Submultimea cu suma minima: ");
    for (int i = 0; i < subset_size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");

    return 0;
}
