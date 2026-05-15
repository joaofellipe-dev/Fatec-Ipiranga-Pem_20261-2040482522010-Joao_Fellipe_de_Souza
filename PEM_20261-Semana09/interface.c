#include <stdio.h>
#include "interface.h"
#include "recursao.h"

void exibirMenu() {
    printf("\n=== Conversor e Calculadora Cientifica (CUCC) ===\n");
    printf("1. Converter Decimal para Binario\n");
    printf("2. Calcular Potencia\n");
    printf("3. Somar Digitos de um Numero\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

void executarOpcao(int opcao) {
    int num, base, exp;

    switch (opcao) {
        case 1:
            printf("Digite um numero decimal inteiro (positivo): ");
            scanf("%d", &num);
            printf("Binario: ");
            if (num == 0) {
                printf("0");
            } else {
                decToBin(num);
            }
            printf("\n");
            break;
            
        case 2:
            printf("Digite a base: ");
            scanf("%d", &base);
            printf("Digite o expoente (>= 0): ");
            scanf("%d", &exp);
            if (exp < 0) {
                printf("Erro: O expoente deve ser maior ou igual a zero.\n");
            } else {
                printf("Resultado: %d\n", potencia(base, exp));
            }
            break;
            
        case 3:
            printf("Digite um numero inteiro: ");
            scanf("%d", &num);
            // Converte para positivo caso o usuário digite um número negativo
            if (num < 0) {
                num = -num;
            }
            printf("Soma dos digitos: %d\n", somaDigitos(num));
            break;
            
        case 0:
            printf("Saindo do sistema...\n");
            break;
            
        default:
            printf("Opcao invalida. Tente novamente.\n");
    }
}