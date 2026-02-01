#ifndef TRANSACCIONES_H
#define TRANSACCIONES_H
#include "estructuras.h"

void registrarTransaccion(Transaccion transacciones[], int &n, CuentaAhorro cuentasAhorro[], int nCuentasAhorro, CuentaCorriente cuentasCorrientes[], int nCuentasCorrientes);
void mostrarTransacciones(const Transaccion transacciones[], int n);
void guardarTransacciones(const Transaccion transacciones[], int n);
void cargarTransacciones(Transaccion transacciones[], int &n);
void menuTransacciones(Transaccion transacciones[], int &nTransacciones, CuentaAhorro cuentasAhorro[], int &nCuentasAhorro, CuentaCorriente cuentasCorrientes[], int &nCuentasCorrientes);
#endif //TRANSACCIONES_H