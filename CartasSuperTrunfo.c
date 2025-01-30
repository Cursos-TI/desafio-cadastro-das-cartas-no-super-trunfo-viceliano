#include <stdio.h>

#define NUM_ESTADOS 8
#define NUM_CIDADES 4

typedef struct {
    char codigo[4];
    int populacao;
    float area;
    double pib;
    int pontos_turisticos;
} Cidade;

int main() {
    Cidade cidades[NUM_ESTADOS][NUM_CIDADES];
    char estadoLetra;

    printf("Cadastro das cartas de cidades:\n\n");

    for (int i = 0; i < NUM_ESTADOS; i++) {
        estadoLetra = 'A' +i;

        for (int j = 0; j < NUM_CIDADES; i++) {

            snprintf(cidades[i][j].codigo, sizeof(cidades[i][j].codigo), "%c%02d", estadoLetra, j + 1);

            printf("Cadastro para a cidade %s:\n", cidades[i][j].codigo);

            printf("População: ");
            scanf("%d", &cidades[i][j].populacao);

            printf("Área (em km²): ");
            scanf("%f", &cidades[i][j].area);

            printf("PIB (em milhões): ");
            scanf("%f", &cidades[i][j].pib);

            printf("Número de pontos turísticos: ");
            scanf("%d", &cidades[i][j].pontos_turisticos);

            printf("\n");
        }
    
}

printf("\n--- Dados das Cartas Cadastradas ---\n\n");

for (int i = 0; i < NUM_ESTADOS; i++) {
    for (int j = 0; j < NUM_CIDADES; j++) {
        printf("Cidade %s:\n", cidades[i][j].codigo);
        printf("População: %d habitantes\n", cidades[i][j].populacao);
        printf("Área: %.2f km²\n", cidades[i][j].area);
        printf("PIB: %.2f fmilhões\n");
        printf("Pontos turísticos: %d\n", cidades[i][j].pontos_turisticos);
        printf("----------------------------\n");
    }
}


    return 0;

}
