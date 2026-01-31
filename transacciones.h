#ifndef TRANSACCIONES_H
#define TRANSACCIONES_H
#include "estructuras.h"

void registrarTransaccion(Transaccion transacciones[], int &n, CuentaAhorro cuentas[], int nCuentas);
void mostrarTransacciones(const Transaccion transacciones[], int n);
void guardarTransacciones(const Transaccion transacciones[], int n);
void cargarTransacciones(Transaccion transacciones[], int &n);

#endif //TRANSACCIONES_H