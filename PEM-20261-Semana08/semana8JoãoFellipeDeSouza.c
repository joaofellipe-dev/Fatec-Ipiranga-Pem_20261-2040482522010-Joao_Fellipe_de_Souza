#include <stdio.h>

void processarCarga(float *ptr_vetor, int n) {
    float soma = 0.0, media = 0.0;
    
    for (int i = 0; i < n; i++) {
        soma += *(ptr_vetor + i);
    }
    media = soma / n;
    
    printf("\n--- Relatorio de Processamento ---");
    printf("\nMedia calculada: %.2f kg\n", media);

    for (int i = 0; i < n; i++) {
        float limite = media * 1.10;
        
        if (*(ptr_vetor + i) > limite) {
            printf("Ajustando pacote %d: %.2f -> ", i + 1, *(ptr_vetor + i));
            *(ptr_vetor + i) = *(ptr_vetor + i) * 0.95;
            printf("%.2f (Correcao de -5%% aplicada)\n", *(ptr_vetor + i));
        }
    }
    printf("----------------------------------\n");
}

int main() {
    float pesos[10] = {120.5, 80.0, 150.2, 95.0, 110.0, 135.5, 88.0, 102.0, 145.0, 90.0};
    int tamanho = 10;

    printf("Pesos ANTES do processamento:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("[%.2f] ", pesos[i]);
    }
    printf("\n");

    processarCarga(pesos, tamanho);

    printf("\nPesos APOS o processamento (Calibrados):\n");
    for (int i = 0; i < tamanho; i++) {
        printf("[%.2f] ", pesos[i]);
    }
    printf("\n");

    return 0;
}