#include <iostream>
#include "menus.h"
#include "clientes.h"
#include "cuentas.h"
#include "cuentascorrientes.h"
#include "prestamos.h"
#include "garantes.h"
#include "transacciones.h"
using namespace std;

void menuPrincipal() {
    Cliente clientes[100]; int n = 0;
    cargarClientes(clientes, n);

    CuentaAhorro cuentas[100]; int nCuentas = 0;
    cargarCuentas(cuentas, nCuentas);

    CuentaCorriente cuentasCorrientes[100]; int nCuentasCorrientes = 0;
    cargarCuentasCorrientes(cuentasCorrientes, nCuentasCorrientes);

    Prestamo prestamos[100]; int nPrestamos = 0;
    cargarPrestamos(prestamos, nPrestamos);

    Garante garantes[100]; int nGarantes = 0;
    cargarGarantes(garantes, nGarantes);

    Transaccion transacciones[100]; int nTransacciones = 0;
    cargarTransacciones(transacciones, nTransacciones);
    int opcion;
    do {
        cout << "\n=== MENU PRINCIPAL ===\n";
        cout << "1. Gestionar Clientes\n";
        cout << "2. Gestionar Cuentas de Ahorro\n";
        cout << "3. Gestionar Cuentas Corrientes\n";
        cout << "4. Gestionar Préstamos\n";
        cout << "5. Gestionar Garantes\n";
        cout << "6. Gestionar Transacciones\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1: menuClientes(clientes, n); break;
            case 2: menuCuentas(cuentas, nCuentas, n); break;
            case 3: menuCuentasCorrientes(cuentasCorrientes, nCuentasCorrientes); break;
            case 4: menuPrestamos(prestamos, nPrestamos); break;
            case 5: menuGarantes(garantes, nGarantes); break;
            case 6: menuTransacciones(transacciones, nTransacciones, cuentas, nCuentas, cuentasCorrientes, nCuentasCorrientes); break;
            case 7: cout << "Saliendo del programa...\n"; break;
            default: cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while(opcion != 7);
}