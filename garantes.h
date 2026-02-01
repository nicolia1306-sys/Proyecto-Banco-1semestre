#ifndef GARANTES_H
#define GARANTES_H
#include "estructuras.h"

void registrarGarante(Garante garantes[], int &n);
void mostrarGarantes(const Garante garantes[], int n);
int buscarGarantePorCedula(const Garante garantes[], int n, const std::string &cedula);
void modificarGarante(Garante garantes[], int n);
void eliminarGarante(Garante garantes[], int &n);
void guardarGarantes(const Garante garantes[], int n);
void cargarGarantes(Garante garantes[], int &n);
void menuGarantes(Garante garantes[], int &nGarantes);
#endif //GARANTES_H