#include<iostream>
#include<fstream>
#include<sstream>
#include "cuentas.h"
using namespace std;

void registrarCuenta(CuentaAhorro cuentas[], int &n){
    cout << "\n===REGISTRAR CUENTA DE AHORRO===\n";
    cuentas[n].NumerodeCuenta = n + 1001; // ejemplo: cuentas empiezan en 1001
    cout << "Ingrese el ID del cliente: ";
    cin >> cuentas[n].IDcliente;
    cout << "Ingrese el saldo inicial: ";
    cin >> cuentas[n].saldo;
    cin.ignore();
    cout << "Ingrese la fecha de apertura: ";
    getline(cin, cuentas[n].fechadeApertura);
    cout << "Ingrese el tipo de moneda: ";
    getline(cin, cuentas[n].tipodemoneda);
    cout << "Ingrese la tasa de interés: ";
    cin >> cuentas[n].tasaInteres;
    cuentas[n].estado = "Activa";
    n++;
    cout << "Cuenta registrada exitosamente\n";
}

void mostrarCuentas(const CuentaAhorro cuentas[], int n){
    cout << "\n===LISTA DE CUENTAS DE AHORRO===\n";
    if(n == 0){
        cout << "No existen cuentas registradas\n";
        return;
    }
    for(int i=0; i<n; i++){
        cout << "\nNúmero de cuenta: " << cuentas[i].NumerodeCuenta << endl;
        cout << "ID Cliente: " << cuentas[i].IDcliente << endl;
        cout << "Saldo: " << cuentas[i].saldo << endl;
        cout << "Fecha de apertura: " << cuentas[i].fechadeApertura << endl;
        cout << "Tipo de moneda: " << cuentas[i].tipodemoneda << endl;
        cout << "Tasa de interés: " << cuentas[i].tasaInteres << endl;
        cout << "Estado: " << cuentas[i].estado << endl;
    }
}

int buscarCuentaPorNumero(const CuentaAhorro cuentas[], int n, int numero){
    for(int i=0; i<n; i++){
        if(cuentas[i].NumerodeCuenta == numero){
            return i;
        }
    }
    return -1;
}

void modificarCuenta(CuentaAhorro cuentas[], int n){
    int numero;
    cout << "Ingrese el número de cuenta: ";
    cin >> numero;
    int pos = buscarCuentaPorNumero(cuentas, n, numero);
    if(pos == -1){
        cout << "Cuenta no encontrada\n";
        return;
    }
    cout << "Modificando cuenta número: " << cuentas[pos].NumerodeCuenta << endl;
    cout << "Ingrese el nuevo saldo: ";
    cin >> cuentas[pos].saldo;
    cin.ignore();
    cout << "Ingrese el nuevo estado: ";
    getline(cin, cuentas[pos].estado);
    cout << "Datos de la cuenta actualizados correctamente\n";
}

void eliminarCuenta(CuentaAhorro cuentas[], int &n){
    int numero;
    cout << "Ingrese el número de cuenta a eliminar: ";
    cin >> numero;
    int pos = buscarCuentaPorNumero(cuentas, n, numero);
    if(pos == -1){
        cout << "Cuenta no encontrada\n";
        return;
    }
    for(int i=pos; i<n-1; i++){
        cuentas[i] = cuentas[i+1];
    }
    n--;
    cout << "Cuenta eliminada exitosamente\n";
}

void guardarCuentas(const CuentaAhorro cuentas[], int n){
    ofstream archivo("cuentas.csv");
    if (!archivo.is_open()){
        cout << "Error al abrir el archivo\n";
        return;
    }
    archivo << "NumerodeCuenta, IDcliente, saldo, fechadeApertura, estado, tipodemoneda, tasaInteres\n";
    for (int i=0; i < n; i++){
        archivo << cuentas[i].NumerodeCuenta << ","
        << cuentas[i].IDcliente << ","
        << cuentas[i].saldo << ","
        << cuentas[i].fechadeApertura << ","
        << cuentas[i].estado << ","
        << cuentas[i].tipodemoneda << ","
        << cuentas[i].tasaInteres << "\n";
    }
    archivo.close();
    cout << "Cuentas guardadas en cuentas.csv exitosamente\n"; 
}

void cargarCuentas(CuentaAhorro cuentas[], int &n){
    ifstream archivo("cuentas.csv");
    if (!archivo.is_open()){
        cout << "No se pudo abrir el archivo cuentas.csv\n";
        return;
    }
    string linea;
    getline(archivo, linea); // ignorar encabezado
    n = 0;
    while (getline(archivo, linea)){
        if(linea.empty()) continue;
        stringstream ss(linea);
        string campo;
        getline(ss, campo, ','); cuentas[n].NumerodeCuenta = stoi(campo);
        getline(ss, campo, ','); cuentas[n].IDcliente = stoi(campo);
        getline(ss, campo, ','); cuentas[n].saldo = stod(campo);
        getline(ss, campo, ','); cuentas[n].fechadeApertura = campo;
        getline(ss, campo, ','); cuentas[n].estado = campo;
        getline(ss, campo, ','); cuentas[n].tipodemoneda = campo;
        getline(ss, campo, ','); cuentas[n].tasaInteres = stod(campo);
        n++;
    }
    archivo.close();
    cout << "Cuentas cargadas desde cuentas.csv exitosamente\n";
}