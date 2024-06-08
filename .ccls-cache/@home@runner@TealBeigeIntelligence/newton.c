#include <stdlib.h>
#include "newton.h"
#include "mat.h"

double derivar(double (*f)(double), double x0) {
    const double delta = 1.0e-6; 
    double x1 = x0 - delta;
    double x2 = x0 + delta;
    double y1 = f(x1);
    double y2 = f(x2);
    return (y2 - y1) / (x2 - x1);
}

Newton newton_criar(double (*func)(double), double tol, int max_passos) {
    Newton n = (Newton)malloc(sizeof(NewtonStruct));
    n->func = func;
    n->tol = tol;
    n->max_passos = max_passos;
    return n;
}

void newton_destruir(Newton n) {
    free(n);
}

Status newton_procurar_zero(Newton n, double *x, Zero *zeros, int nr_raizes) {
    for (int i = 0; i < nr_raizes; i++) {
        double xi = x[i];
        for (int passo = 0; passo < n->max_passos; passo++) {
            double fxi = n->func(xi);
            double dfxi = derivar(n->func, xi);
            if (dfxi == 0.0) {
                zeros[i].status = ERRO;
                break;
            }
            double x_next = xi - fxi / dfxi;
            if (meuAbs(x_next - xi) < n->tol) {
                zeros[i].status = SUCESSO;
                zeros[i].zero = x_next;
                break;
            }
            xi = x_next;
        }
        if (zeros[i].status != SUCESSO) {
            zeros[i].status = ERRO;
        }
    }
    return SUCESSO;
}
