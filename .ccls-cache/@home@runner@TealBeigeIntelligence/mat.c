#include <stdio.h>

#define INFINITO 1e30
#define TOLERANCIA 1e-10

double fatorialMeu(int n) {
    double resultado = 1.0;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

double powerMeu(double base, int exp) {
    double resultado = 1.0;
    for (int i = 0; i < exp    ; i++) {
        resultado *= base;
    }
    return resultado;
}

double meuAbs(double x) {
    return x < 0 ? -x : x;
}

double sinMeu(double x) {
    double resultado = 0.0;
    double termo = x;
    int n = 1;
    resultado += termo;
    do {
        termo = (-termo * x * x) / ((2 * n) * (2 * n + 1));
        resultado += termo;
        n++;
    } while (meuAbs(termo) > TOLERANCIA);
    return resultado;
}

double cosMeu(double x) {
    double resultado = 1.0;
    double termo = 1.0;
    int n = 1;
    do {
        termo = (-termo * x * x) / ((2 * n - 1) * (2 * n));
        resultado += termo;
        n++;
    } while (meuAbs(termo) > TOLERANCIA);
    return resultado;
}

double expMeu(double x) {
    double resultado = 1.0;
    double termo = 1.0;
    int n = 1;
    do {
        termo *= x / n;
        resultado += termo;
        n++;
    } while (meuAbs(termo) > TOLERANCIA);
    return resultado;
}

double lnMeu(double x) {
    if (x <= 0) {
        return -INFINITO;
    }
    double resultado = 0.0;
    double termo = (x - 1) / (x + 1);
    double termoAoQuadrado = termo * termo;
    double numerator = termo;
    int n = 1;
    do {
        resultado += numerator / (2 * n - 1);
        numerator *= termoAoQuadrado;
        n++;
    } while (meuAbs(numerator / (2 * n - 1)) > TOLERANCIA);
    return 2 * resultado;
}

double sqrtMeu(double x) {
    if (x < 0) {
        return -INFINITO;
    }
    if (x == 0) {
        return 0;
    }
    double resultado = x;
    double ultimoResultado;
    do {
        ultimoResultado = resultado;
        resultado = 0.5 * (ultimoResultado + x / ultimoResultado);
    } while (meuAbs(ultimoResultado - resultado) > TOLERANCIA);
    return resultado;
}
