#include <stdio.h>
#include <stdlib.h>
#include "mat.h"
#include "newton.h"

double f(double x);

int main() {
    double tolerancia = 1e-5;
    int max_passos = 10;
    double x[] = {-1, 1};  
    int nr_raizes = sizeof(x) / sizeof(x[0]);  

    Zero *zeros = (Zero *)malloc(nr_raizes * sizeof(Zero));
    if (zeros == NULL) {
        return EXIT_FAILURE;
    }

    Newton n = newton_criar(&f, tolerancia, max_passos);
    Status status = newton_procurar_zero(n, x, zeros, nr_raizes);

    if (status == SUCESSO) {
        for (int i = 0; i < nr_raizes; i++) {
            if (zeros[i].status == SUCESSO) {
                printf("Vizinhança de x=%g => Raiz encontrada: %g\n", x[i], zeros[i].zero);
            } else {
                printf("Não foi encontrada uma raiz na vizinhança de x=%g\n", x[i]);
            }
        }
    }

    newton_destruir(n);

    free(zeros);

    return 0;    
}

// Função f(x)
// Esta função utilizará as funções elementares desenvolvidas em mat.c
double f(double x) { return sqrtMeu(2); }