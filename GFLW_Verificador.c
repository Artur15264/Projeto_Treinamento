#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "GFLW_Funcoes.h"

#define MAX_PLACAS 10

int main() {
    char placas[MAX_PLACAS][8]; // Matriz para armazenar as placas
    int resultados[MAX_PLACAS]; // Vetor para armazenar os resultados
    int modelo[MAX_PLACAS];
    int numPlacas = 0;
    
    printf("Digite as placas no formato (ABC1234 ou ABC1D23). Digite 'FIM' para encerrar:\n");

    // Coleta e armazena as placas
    coletarPlacas(placas, resultados, modelo, &numPlacas);

    // Exibe os resultados
    printf("\n\nResultados:\n\n");
    armazenarPlacas(placas, resultados, modelo, numPlacas);

    return 0;
}
