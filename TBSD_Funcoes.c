#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_PLACAS 10

char placas[MAX_PLACAS][8]; // Matriz para armazenar as placas
int resultados[MAX_PLACAS]; // Vetor para armazenar os resultados da validação
int modelo[MAX_PLACAS]; // Vetor para armazenar os modelos de cada placa
char placa[8];
int formatoValido = 1;
int numPlacas = 0;

int verificarFormato(char input[]) {
    for (int i = 0; i < 3; ++i) {
        if (!isalpha(input[i])) {
            return 0; 
        }
    }
    for (int i = 5; i < 7; ++i) {
        if (!isdigit(input[i])) {
            return 0;
        }
    }
    if (!isdigit(input[3])) {
        return 0;
    }
    return 1;
}

// Função para determinar o modelo da placa
int determinarModelo(char input[]) {
    if (!isalpha(input[4])) {
        return 0; // Modelo Antigo
    }
    if (!isdigit(input[4])) {
        return 1; // Modelo Novo (Mercosul)
    }
    return 0; 
}

// Função para coletar as placas
void coletarPlacas(char placas[][8], int resultados[], int modelo[], int *numPlacas) {
    
    while (*numPlacas < MAX_PLACAS) {
        char input[8];
        printf("Placa %d: ", *numPlacas + 1);
        scanf("%7s", input);

        if (strcasecmp(input, "FIM") == 0) {
            break;
        }

        // Verifica o formato da placa
        int formatoValido = verificarFormato(input);

        if (formatoValido) {
            strcpy(placas[*numPlacas], input);
            resultados[*numPlacas] = 1; 
        } else {
            printf("Formato inválido! Por favor, digite uma placa no formato ABC1234 ou ABC1D23.\n");
            strcpy(placas[*numPlacas], input);
            resultados[*numPlacas] = 0; 
        }

        // Determina o modelo da placa
        modelo[*numPlacas] = determinarModelo(input);

        (*numPlacas)++;
    }
}

// Função para armazenar as placas
void armazenarPlacas(char placas[][8], int resultados[], int modelo[], int numPlacas) {
    for (int i = 0; i < numPlacas; ++i) {
        if (resultados[i] == 1) {
            printf("Placa %d: %s - %s - %s\n", i + 1, placas[i], resultados[i] ? "Válido" : "Inválido", modelo[i] ? "Mercosul(Modelo Novo)" : "Placa Cinza(Modelo Antigo)");
        } else {
            printf("Placa %d: %s - %s\n", i + 1, placas[i], resultados[i] ? "Válido" : "Inválido");
        }
    }
}
