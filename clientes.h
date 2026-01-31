#ifndef CLIENTES_H
#define CLIENTES_H
#include "estructuras.h"
void registrarCliente(Cliente clientes[], int &n);
void mostrarClientes(const Cliente clientes[], int n);
int buscarClientePorCedula(const Cliente clientes[], int n, const std::string &cedula);
void modificarCliente(Cliente clientes[], int n);
void eliminarCliente(Cliente clientes[], int &n);
void guardarClientes(const Cliente clientes[], int n);
void cargarClientes(Cliente clientes[], int &n);

#endif //CLIENTES_H