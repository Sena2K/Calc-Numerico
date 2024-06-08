#ifndef NEWTON_H
#define NEWTON_H

typedef enum {ERRO, SUCESSO} Status;

typedef struct {
    Status status;
    double zero;
} Zero;

typedef struct NewtonStruct* Newton;

typedef struct NewtonStruct {
    double (*func)(double);
    double tol;
    int max_passos;
} NewtonStruct;

Newton newton_criar(double (*func)(double), double tol, int max_passos);
void newton_destruir(Newton n);
Status newton_procurar_zero(Newton n, double *x, Zero *zeros, int nr_raizes);

#endif
