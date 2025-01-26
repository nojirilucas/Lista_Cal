// Arquivo 1: exercicio2a.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calcular_fatorial(int numero) {
    int resultado = 1;
    for (int i = numero; i >= 1; i--) {
        resultado *= i;
    }
    return resultado;
}

double aproximar_exponencial(int termos, double x) {
    double soma = 0;
    for (int i = 0; i <= termos; i++) {
        soma += pow(x, i) / (double)calcular_fatorial(i);
    }
    return soma;
}

double aproximar_exponencial_negativo(int termos, double x) {
    double soma = 0;
    for (int i = 0; i <= termos; i++) {
        soma += pow(x, i) / (double)calcular_fatorial(i);
    }
    return soma;
}

int main() {
    double resultado1, resultado2;
    double valores_x[10] = {0.00000356, -0.0001, 0.000000001, 0.3, 0.0000214, 123, -412, 40, 12, -4};
    int valores_n[10] = {2, 3, 5, 7, 11, 13, 17, 19, 27, 50};

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("Para n = %d e x = %lf\n", valores_n[i], valores_x[j]);
            if (valores_x[j] >= 0) {
                resultado1 = aproximar_exponencial(valores_n[i], valores_x[j]);
                printf("%lf\n", resultado1);
            } else {
                resultado1 = aproximar_exponencial(valores_n[i], valores_x[j]);
                resultado2 = aproximar_exponencial_negativo(valores_n[i], valores_x[j]);

                printf("Aproximação direta: %.10lf\n", resultado1);
                printf("Aproximação inversa: %.10lf\n", resultado2);
            }
        }
    }

    return 0;
}

// Arquivo 2: exercicio10.c
#include <stdio.h>
#include <stdlib.h>

int main() {
    double n, x;
    scanf("%lf %lf", &n, &x);

    double soma = 0;
    for (int k = 1; k <= n; k++) {
        soma += x;
    }

    double resultado = 10000.0 - soma;

    printf("Somatório: %.9lf\n", soma);
    printf("Resultado final: %.9lf\n", resultado);
    return 0;
}

// Arquivo 3: exercicio2b.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long calcular_fatorial(long long numero) {
    long long resultado = 1;
    for (long long i = numero; i >= 1; i--) {
        resultado *= i;
    }
    return resultado;
}

double aproximar_exponencial(int termos, double x) {
    double soma = 0;
    for (long long i = 1; i <= termos; i++) {
        long long aux = 1;
        double parcial = 1;
        while (aux <= i) {
            parcial *= x / aux;
            aux++;
        }
        soma += parcial;
    }
    soma++;
    return soma;
}

double aproximar_exponencial_negativo(int termos, double x) {
    double soma = 0;
    for (long long i = 1; i <= termos; i++) {
        long long aux = 1;
        double parcial = 1;
        while (aux <= i) {
            parcial *= x / aux;
            aux++;
        }
        soma += parcial;
    }
    soma++;
    return soma;
}

int main() {
    double resultado1, resultado2;
    double valores_x[10] = {0.00000356, -0.0001, 0.000000001, 0.3, 0.0000214, 123, -412, 40, 12, -4};
    long long valores_n[10] = {2, 3, 5, 7, 11, 13, 17, 19, 27, 50};

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("Para n = %lld e x = %lf\n", valores_n[i], valores_x[j]);
            if (valores_x[j] >= 0) {
                resultado1 = aproximar_exponencial(valores_n[i], valores_x[j]);
                printf("%lf\n", resultado1);
            } else {
                resultado1 = aproximar_exponencial(valores_n[i], valores_x[j]);
                resultado2 = aproximar_exponencial_negativo(valores_n[i], valores_x[j]);

                printf("Aproximação direta: %.10lf\n", resultado1);
                printf("Aproximação inversa: %.10lf\n", resultado2);
            }
        }
    }

    return 0;
}
