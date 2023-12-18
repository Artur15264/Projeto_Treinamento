#ifndef FUNCOES_H
#define FUNCOES_H

int verificarFormato(char input[]);
int determinarModelo(char input[]);
void coletarPlacas(char placas[][8], int resultados[], int modelo[], int *numPlacas);
void armazenarPlacas(char placas[][8], int resultados[], int modelo[], int numPlacas);

#endif