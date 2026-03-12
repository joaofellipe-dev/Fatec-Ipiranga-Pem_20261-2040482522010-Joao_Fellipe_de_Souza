#include <stdio.h>

char matriz[3][3];

void reset() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            matriz[i][j] = ' ';
}

void display() {
    printf("\n %c | %c | %c \n", matriz[0][0], matriz[0][1], matriz[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", matriz[1][0], matriz[1][1], matriz[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n\n", matriz[2][0], matriz[2][1], matriz[2][2]);
}

char check() {
    for(int i = 0; i < 3; i++) {
        if(matriz[i][0] != ' ' &&
           matriz[i][0] == matriz[i][1] &&
           matriz[i][1] == matriz[i][2])
            return matriz[i][0];
    }

    for(int i = 0; i < 3; i++) {
        if(matriz[0][i] != ' ' &&
           matriz[0][i] == matriz[1][i] &&
           matriz[1][i] == matriz[2][i])
            return matriz[0][i];
    }

    if(matriz[0][0] != ' ' &&
       matriz[0][0] == matriz[1][1] &&
       matriz[1][1] == matriz[2][2])
        return matriz[0][0];

    
    if(matriz[0][2] != ' ' &&
       matriz[0][2] == matriz[1][1] &&
       matriz[1][1] == matriz[2][0])
        return matriz[0][2];

    return ' ';
}

int main() {
    int x, y, jogadas = 0;
    char vencedor = ' ';

    x = -1;
    y = -1;

    reset();

    while(vencedor == ' ' && jogadas < 9) {
        display();

        char jogador = (jogadas % 2 == 0) ? 'X' : 'O';

        printf("Jogador %c, digite linha e coluna (0-2): ", jogador);
        
       
        if (scanf("%d %d", &x, &y) != 2) {
            printf("Entrada inválida! Digite dois números.\n");
            
            while(getchar() != '\n'); 
            continue;
        }

        if(x < 0 || x > 2 || y < 0 || y > 2 || matriz[x][y] != ' ') {
            printf("Movimento invalido! Tente novamente.\n");
            continue;
        }

        matriz[x][y] = jogador;
        vencedor = check();
        jogadas++;
    }

    display();

    if(vencedor != ' ')
        printf("Parabens! O vencedor e: %c\n", vencedor);
    else
        printf("Empate! Deu velha.\n");

    return 0;
}
