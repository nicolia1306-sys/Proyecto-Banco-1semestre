#include<iostream>
#include "menus.h"
#include "cuentas.h"
#include "cuentasCorrientes.h"
#include "prestamos.h"
#include "garantes.h"
#include "transacciones.h"
using namespace std;
void menuPrincipal(){
    Cliente clientes[100];
    int n = 0;
    cargarClientes(clientes, n);
    CuentaAhorro cuentas[100];
    int nCuentas = 0;
    cargarCuentas(cuentas, nCuentas);
    CuentaCorriente cuentasCorrientes[100];
    int nCuentasCorrientes = 0;
    cargarCuentasCorrientes(cuentasCorrientes, nCuentasCorrientes);
    Prestamo prestamos[100]; int nPrestamos = 0;
    cargarPrestamos(prestamos, nPrestamos);
    Garante garantes[100]; int nGarantes = 0;
    cargarGarantes(garantes, nGarantes);
    Transaccion transacciones[100]; int nTransacciones = 0;
    cargarTransacciones(transacciones, nTransacciones);
    int opcion;
    do{
        cout << "\n===MENU PRINCIPAL===\n";
        cout << "1. Gestionar Clientes\n";
        cout << "2. Gestionar Cuentas de Ahorro\n";
        cout << "3. Gestionar Cuentas Corrientes\n";
        cout << "4. Gestionar Préstamos\n";
        cout << "5. Gestionar Garantes\n";
        cout << "6. Gestionar Transacciones\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                menuClientes(clientes, n);
                break;
            case 2:
                menuCuentas(cuentas, nCuentas);
                break;
                
            case 3:
                menuCuentasCorrientes(cuentasCorrientes, nCuentasCorrientes);
                break;
            case 4:  menuPrestamos(prestamos, nPrestamos);
                break;
            case 5:  menuGarantes(garantes, nGarantes);
                break;
            case 6:  menuTransacciones(transacciones, nTransacciones, cuentas, nCuentas);
                break;
            case 7:  cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
        }
    }while(opcion != 7);
}
void menuClientes(Cliente clientes[], int &n){
    int opcion;
    do{
        cout << "\n===MENU CLIENTES===\n";
        cout << "1. Registrar Cliente\n";
        cout << "2. Mostrar Clientes\n";
        cout << "3. Modificar Cliente\n";
        cout << "4. Eliminar Cliente\n";
        cout << "5. Volver al Menú Principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                registrarCliente(clientes, n);
                break;
            case 2:
                mostrarClientes(clientes, n);
                break;
            case 3:
                modificarCliente(clientes, n);
                break;
            case 4:
                eliminarCliente(clientes, n);
                break;
            case 5:
                guardarClientes(clientes, n);
                cout << "Datos Guardados.Volviendo al menú principal...\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
        }
    }while(opcion != 5);
}
void menuCuentas(CuentaAhorro cuentas[], int &n){
    int opcion;
    do{
        cout << "\n===MENU CUENTAS DE AHORRO===\n";
        cout << "1. Registrar Cuenta\n";
        cout << "2. Mostrar Cuentas\n";
        cout << "3. Modificar Cuenta\n";
        cout << "4. Eliminar Cuenta\n";
        cout << "5. Volver al Menú Principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch(opcion){
            case 1: registrarCuenta(cuentas, n); break;
            case 2: mostrarCuentas(cuentas, n); break;
            case 3: modificarCuenta(cuentas, n); break;
            case 4: eliminarCuenta(cuentas, n); break;
            case 5: guardarCuentas(cuentas, n);
                    cout << "Datos guardados. Volviendo al menú principal...\n";
                    break;
            default: cout << "Opción inválida. Intente de nuevo.\n";
        }
    }while(opcion != 5);
}
void menuPrestamos(Prestamo prestamos[], int &n){
    int opcion;
    do{
        cout << "\n===MENU PRÉSTAMOS===\n";
        cout << "1. Registrar Préstamo\n";
        cout << "2. Mostrar Préstamos\n";
        cout << "3. Modificar Préstamo\n";
        cout << "4. Eliminar Préstamo\n";
        cout << "5. Volver al Menú Principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch(opcion){
            case 1: registrarPrestamo(prestamos, n); break;
            case 2: mostrarPrestamos(prestamos, n); break;
            case 3: modificarPrestamo(prestamos, n); break;
            case 4: eliminarPrestamo(prestamos, n); break;
            case 5: guardarPrestamos(prestamos, n);
                    cout << "Datos guardados. Volviendo al menú principal...\n";
                    break;
            default: cout << "Opción inválida. Intente de nuevo.\n";
        }
    }while(opcion != 5);
}

void menuGarantes(Garante garantes[], int &n){
    int opcion;
    do{
        cout << "\n===MENU GARANTES===\n";
        cout << "1. Registrar Garante\n";
        cout << "2. Mostrar Garantes\n";
        cout << "3. Modificar Garante\n";
        cout << "4. Eliminar Garante\n";
        cout << "5. Volver al Menú Principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch(opcion){
            case 1: registrarGarante(garantes, n); break;
            case 2: mostrarGarantes(garantes, n); break;
            case 3: modificarGarante(garantes, n); break;
            case 4: eliminarGarante(garantes, n); break;
            case 5: guardarGarantes(garantes, n);
                    cout << "Datos guardados. Volviendo al menú principal...\n";
                    break;
            default: cout << "Opción inválida. Intente de nuevo.\n";
        }
    }while(opcion != 5);
}
void menuCuentasCorrientes(CuentaCorriente cuentas[], int &n){
    int opcion;
    do{
        cout << "\n===MENU CUENTAS CORRIENTES===\n";
        cout << "1. Registrar Cuenta Corriente\n";
        cout << "2. Mostrar Cuentas Corrientes\n";
        cout << "3. Modificar Cuenta Corriente\n";
        cout << "4. Eliminar Cuenta Corriente\n";
        cout << "5. Volver al Menú Principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch(opcion){
            case 1: registrarCuentaCorriente(cuentas, n); break;
            case 2: mostrarCuentasCorrientes(cuentas, n); break;
            case 3: modificarCuentaCorriente(cuentas, n); break;
            case 4: eliminarCuentaCorriente(cuentas, n); break;
            case 5: guardarCuentasCorrientes(cuentas, n);
                    cout << "Datos guardados. Volviendo al menú principal...\n";
                    break;
            default: cout << "Opción inválida. Intente de nuevo.\n";
        }
    }while(opcion != 5);
}
void menuTransacciones(Transaccion transacciones[], int &n, CuentaAhorro cuentas[], int nCuentas){
    int opcion;
    do{
        cout << "\n===MENU TRANSACCIONES===\n";
        cout << "1. Registrar Transacción\n";
        cout << "2. Mostrar Historial de Transacciones\n";
        cout << "3. Volver al Menú Principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch(opcion){
            case 1: registrarTransaccion(transacciones, n, cuentas, nCuentas); break;
            case 2: mostrarTransacciones(transacciones, n); break;
            case 3: guardarTransacciones(transacciones, n);
                    cout << "Datos guardados. Volviendo al menú principal...\n";
                    break;
            default: cout << "Opción inválida. Intente de nuevo.\n";
        }
    }while(opcion != 3);
}