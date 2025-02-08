#include <stdio.h>

#define NUM_ESTADOS 8
#define NUM_CIDADES 4

typedef struct {
    char codigo[4];
    int populacao;
    float area;
    double pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Cidade;

void calcularPropriedades(Cidade *cidade) {
    cidade->densidade_populacional = (cidade->area > 0) ? cidade->populacao / cidade->area : 0;
    cidade->pib_per_capita = (cidade->populacao > 0) ? cidade->pib / cidade->populacao : 0;
}

int main() {
    Cidade cidades[NUM_ESTADOS][NUM_CIDADES];
    char estadoLetra;

    printf("Cadastro das cartas de cidades:\n\n");

    for (int i = 0; i < NUM_ESTADOS; i++) {
        estadoLetra = 'A' + i;

        for (int j = 0; j < NUM_CIDADES; j++) {
            snprintf(cidades[i][j].codigo, sizeof(cidades[i][j].codigo), "%c%02d", estadoLetra, j + 1);

            printf("Cadastro para a cidade %s:\n", cidades[i][j].codigo);

            printf("População: ");
            scanf("%d", &cidades[i][j].populacao);

            printf("Área (em km²): ");
            scanf("%f", &cidades[i][j].area);

            printf("PIB (em milhões): ");
            scanf("%lf", &cidades[i][j].pib);

            printf("Número de pontos turísticos: ");
            scanf("%d", &cidades[i][j].pontos_turisticos);

            // Calcula propriedades adicionais
            calcularPropriedades(&cidades[i][j]);

            printf("\n");
        }
    }

    printf("\n--- Dados das Cartas Cadastradas ---\n\n");

    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            printf("Cidade %s:\n", cidades[i][j].codigo);
            printf("População: %d habitantes\n", cidades[i][j].populacao);
            printf("Área: %.2f km²\n", cidades[i][j].area);
            printf("PIB: %.2f milhões\n", cidades[i][j].pib);
            printf("Pontos turísticos: %d\n", cidades[i][j].pontos_turisticos);
            printf("Densidade Populacional: %.2f habitantes por km²\n", cidades[i][j].densidade_populacional);
            printf("PIB per Capita: R$ %.2f milhões\n", cidades[i][j].pib_per_capita);
            printf("----------------------------\n");
        }
    }

    return 0;
}
