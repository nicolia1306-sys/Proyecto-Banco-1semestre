#ifndef CUENTAS_H
#define CUENTAS_H
#include "estructuras.h"

void registrarCuenta(CuentaAhorro cuentas[], int &n);
void mostrarCuentas(const CuentaAhorro cuentas[], int n);
int buscarCuentaPorNumero(const CuentaAhorro cuentas[], int n, int numero);
void modificarCuenta(CuentaAhorro cuentas[], int n);
void eliminarCuenta(CuentaAhorro cuentas[], int &n);
void guardarCuentas(const CuentaAhorro cuentas[], int n);
void cargarCuentas(CuentaAhorro cuentas[], int &n);

#endif //CUENTAS_H