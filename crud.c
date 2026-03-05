#include <stdio.h>
#include <string.h>

#define TAM 10
#define TAM_NOME 50

int main() {
    int idProdutos[TAM] = {0};
    char nomesProdutos[TAM][TAM_NOME];
    int opcao, i, busca, encontrado;

    do {
        printf("\n--- SISTEMA CRUD DE PRODUTOS ---\n");
        printf("1. Inclusao\n2. Consulta\n3. Alteracao\n4. Exclusao\n5. Listar Todos\n0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao); 

        switch(opcao) {
            case 1: 
                encontrado = 0;
                for(i = 0; i < TAM; i++) {
                    if(idProdutos[i] == 0) { 
                        printf("Digite o ID do produto: ");
                        scanf("%d", &idProdutos[i]);
                        
                        printf("Digite o nome do produto: ");
                        getchar(); 
                        fgets(nomesProdutos[i], TAM_NOME, stdin);
                        nomesProdutos[i][strcspn(nomesProdutos[i], "\n")] = 0;

                        printf("Produto cadastrado com sucesso!\n");
                        encontrado = 1;
                        break;
                    }
                }
                if(!encontrado) printf("Erro: Sistema cheio!\n");
                break;

            case 2: 
                printf("Digite o ID para busca: ");
                scanf("%d", &busca);
                encontrado = 0;
                for(i = 0; i < TAM; i++) {
                    if(idProdutos[i] == busca && busca != 0) {
                        printf("Produto encontrado!\n");
                        printf("Indice: %d | ID: %d | Nome: %s\n", i, idProdutos[i], nomesProdutos[i]);
                        encontrado = 1;
                        break;
                    }
                }
                if(!encontrado) printf("Produto nao encontrado.\n"); 
                break;
                
            case 3: 
                printf("Digite o ID que deseja alterar: ");
                scanf("%d", &busca);
                encontrado = 0;
                for(i = 0; i < TAM; i++) {
                    if(idProdutos[i] == busca && busca != 0) {
                        printf("Digite o novo ID: ");
                        scanf("%d", &idProdutos[i]);
                        
                        printf("Digite o novo nome: ");
                        getchar();
                        fgets(nomesProdutos[i], TAM_NOME, stdin);
                        nomesProdutos[i][strcspn(nomesProdutos[i], "\n")] = 0;

                        printf("Alteracao realizada!\n");
                        encontrado = 1;
                        break;
                    }
                }
                if(!encontrado) printf("ID nao localizado para alteracao.\n");
                break;

            case 4: 
                printf("Digite o ID para excluir: ");
                scanf("%d", &busca);
                encontrado = 0;
                for(i = 0; i < TAM; i++) {
                    if(idProdutos[i] == busca && busca != 0) {
                        idProdutos[i] = 0;
                        strcpy(nomesProdutos[i], "");
                        printf("Produto removido com sucesso!\n");
                        encontrado = 1;
                        break;
                    }
                }
                if(!encontrado) printf("Produto nao localizado.\n");
                break;

            case 5: 
                printf("\n--- Lista de Produtos Cadastrados ---\n");
                for(i = 0; i < TAM; i++) {
                    if(idProdutos[i] != 0) {
                        printf("Indice [%d]: ID: %d | Nome: %s\n", i, idProdutos[i], nomesProdutos[i]);
                    }
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}