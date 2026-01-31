#ifndef CUENTAS_CORRIENTES_H
#define CUENTAS_CORRIENTES_H
#include "estructuras.h"

void registrarCuentaCorriente(CuentaCorriente cuentas[], int &n);
void mostrarCuentasCorrientes(const CuentaCorriente cuentas[], int n);
int buscarCuentaCorrientePorNumero(const CuentaCorriente cuentas[], int n, int numero);
void modificarCuentaCorriente(CuentaCorriente cuentas[], int n);
void eliminarCuentaCorriente(CuentaCorriente cuentas[], int &n);
void guardarCuentasCorrientes(const CuentaCorriente cuentas[], int n);
void cargarCuentasCorrientes(CuentaCorriente cuentas[], int &n);

#endif //CUENTAS_CORRIENTES_H