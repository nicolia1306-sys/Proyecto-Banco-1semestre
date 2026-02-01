#include<iostream>
#include<fstream>
#include<sstream>
#include "transacciones.h"
using namespace std;

void registrarTransaccion(Transaccion transacciones[], int &n, CuentaAhorro cuentasAhorro[], int nCuentasAhorro, CuentaCorriente cuentasCorrientes[], int nCuentasCorrientes) {
    cout << "\n===REGISTRAR TRANSACCIÓN===\n";
    transacciones[n].IDtransaccion = n + 9001; 

    cout << "Ingrese el número de cuenta: ";
    cin >> transacciones[n].NumerodeCuenta;

    cout << "Tipo de transacción (Depósito/Retiro): ";
    cin.ignore();
    getline(cin, transacciones[n].tipo);

    cout << "Ingrese el monto: ";
    cin >> transacciones[n].monto;
    cin.ignore();

    cout << "Ingrese la fecha: ";
    getline(cin, transacciones[n].fecha);

    cout << "Ingrese una descripción: ";
    getline(cin, transacciones[n].descripcion);

    // Buscar en cuentas de ahorro
    for(int i=0; i<nCuentasAhorro; i++) {
        if(cuentasAhorro[i].NumerodeCuenta == transacciones[n].NumerodeCuenta) {
            if(transacciones[n].tipo == "Depósito") {
                cuentasAhorro[i].saldo += transacciones[n].monto;
            } else if(transacciones[n].tipo == "Retiro") {
                if(transacciones[n].monto <= cuentasAhorro[i].saldo) {
                    cuentasAhorro[i].saldo -= transacciones[n].monto;
                } else {
                    cout << "Error: saldo insuficiente en cuenta de ahorro.\n";
                }
            }
        }
    }

    for(int i=0; i<nCuentasCorrientes; i++) {
        if(cuentasCorrientes[i].NumerodeCuenta == transacciones[n].NumerodeCuenta) {
            if(transacciones[n].tipo == "Depósito") {
                cuentasCorrientes[i].saldo += transacciones[n].monto;
            } else if(transacciones[n].tipo == "Retiro") {
                double saldoDisponible = cuentasCorrientes[i].saldo + cuentasCorrientes[i].limiteSobregiro;
                if(transacciones[n].monto <= saldoDisponible) {
                    cuentasCorrientes[i].saldo -= transacciones[n].monto;
                } else {
                    cout << "Error: monto excede el límite de sobregiro.\n";
                }
            }
        }
    }

    n++;
    cout << "Transacción registrada exitosamente\n";
}
void mostrarTransacciones(const Transaccion transacciones[], int n){
    cout << "\n===HISTORIAL DE TRANSACCIONES===\n";
    if(n == 0){
        cout << "No existen transacciones registradas\n";
        return;
    }
    for(int i=0; i<n; i++){
        cout << "\nID Transacción: " << transacciones[i].IDtransaccion << endl;
        cout << "Número de cuenta: " << transacciones[i].NumerodeCuenta << endl;
        cout << "Tipo: " << transacciones[i].tipo << endl;
        cout << "Monto: " << transacciones[i].monto << endl;
        cout << "Fecha: " << transacciones[i].fecha << endl;
        cout << "Descripción: " << transacciones[i].descripcion << endl;
    }
}

void guardarTransacciones(const Transaccion transacciones[], int n){
    ofstream archivo("transacciones.csv");
    if (!archivo.is_open()){
        cout << "Error al abrir el archivo\n";
        return;
    }
    archivo << "IDtransaccion, NumerodeCuenta, tipo, monto, fecha, descripcion\n";
    for (int i=0; i < n; i++){
        archivo << transacciones[i].IDtransaccion << ","
        << transacciones[i].NumerodeCuenta << ","
        << transacciones[i].tipo << ","
        << transacciones[i].monto << ","
        << transacciones[i].fecha << ","
        << transacciones[i].descripcion << "\n";
    }
    archivo.close();
    cout << "Transacciones guardadas en transacciones.csv exitosamente\n"; 
}

void cargarTransacciones(Transaccion transacciones[], int &n){
    ifstream archivo("transacciones.csv");
    if (!archivo.is_open()){
        cout << "No se pudo abrir el archivo transacciones.csv\n";
        return;
    }
    string linea;
    getline(archivo, linea); // ignorar encabezado
    n = 0;
    while (getline(archivo, linea)){
        if(linea.empty()) continue;
        stringstream ss(linea);
        string campo;
        getline(ss, campo, ','); transacciones[n].IDtransaccion = stoi(campo);
        getline(ss, campo, ','); transacciones[n].NumerodeCuenta = stoi(campo);
        getline(ss, campo, ','); transacciones[n].tipo = campo;
        getline(ss, campo, ','); transacciones[n].monto = stod(campo);
        getline(ss, campo, ','); transacciones[n].fecha = campo;
        getline(ss, campo, ','); transacciones[n].descripcion = campo;
        n++;
    }
    archivo.close();
    cout << "Transacciones cargadas desde transacciones.csv exitosamente\n";
}
void menuTransacciones(Transaccion transacciones[], int &nTransacciones,
                       CuentaAhorro cuentasAhorro[], int &nCuentasAhorro,
                       CuentaCorriente cuentasCorrientes[], int &nCuentasCorrientes) {
    int opcion;
    do {
        cout << "\n===MENU TRANSACCIONES===\n";
        cout << "1. Registrar Transacción\n";
        cout << "2. Mostrar Historial de Transacciones\n";
        cout << "3. Volver al Menú Principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch(opcion) {
            case 1:
                registrarTransaccion(transacciones, nTransacciones,
                                     cuentasAhorro, nCuentasAhorro,
                                     cuentasCorrientes, nCuentasCorrientes);
                break;
            case 2:
                mostrarTransacciones(transacciones, nTransacciones);
                break;
            case 3:
                guardarTransacciones(transacciones, nTransacciones);
                cout << "Datos guardados. Volviendo al menú principal...\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while(opcion != 3);
}