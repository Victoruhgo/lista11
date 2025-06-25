#include <stdio.h>
#include <math.h>

// Arredonda para um número específico de casas decimais
double arredondar(double valor, int casas) {
    double fator = pow(10.0, casas);
    return round(valor * fator) / fator;
}

// Versão que assume casas = 0
double arredondar_default(double valor) {
    return arredondar(valor, 0);
}
