#ifndef PRESTAMOS_H
#define PRESTAMOS_H
#include "estructuras.h"

void registrarPrestamo(Prestamo prestamos[], int &n);
void mostrarPrestamos(const Prestamo prestamos[], int n);
int buscarPrestamoPorID(const Prestamo prestamos[], int n, int id);
void modificarPrestamo(Prestamo prestamos[], int n);
void eliminarPrestamo(Prestamo prestamos[], int &n);
void guardarPrestamos(const Prestamo prestamos[], int n);
void cargarPrestamos(Prestamo prestamos[], int &n);

#endif //PRESTAMOS_H