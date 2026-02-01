#include<iostream>
#include<fstream>
#include<sstream>
#include "cuentasCorrientes.h"
using namespace std;

void registrarCuentaCorriente(CuentaCorriente cuentas[], int &n){
    cout << "\n===REGISTRAR CUENTA CORRIENTE===\n";
    cuentas[n].NumerodeCuenta = n + 2001; // ejemplo: empiezan en 2001
    cout << "Ingrese el ID del cliente: ";
    cin >> cuentas[n].IDcliente;
    cout << "Ingrese el saldo inicial: ";
    cin >> cuentas[n].saldo;
    cin.ignore();
    cout << "Ingrese la fecha de apertura: ";
    getline(cin, cuentas[n].fechadeApertura);
    cout << "Ingrese el tipo de moneda: ";
    getline(cin, cuentas[n].tipodemoneda);
    cout << "Ingrese el límite de sobregiro: ";
    cin >> cuentas[n].limiteSobregiro;
    cuentas[n].estado = "Activa";
    n++;
    cout << "Cuenta corriente registrada exitosamente\n";
}

void mostrarCuentasCorrientes(const CuentaCorriente cuentas[], int n){
    cout << "\n===LISTA DE CUENTAS CORRIENTES===\n";
    if(n == 0){
        cout << "No existen cuentas corrientes registradas\n";
        return;
    }
    for(int i=0; i<n; i++){
        cout << "\nNúmero de cuenta: " << cuentas[i].NumerodeCuenta << endl;
        cout << "ID Cliente: " << cuentas[i].IDcliente << endl;
        cout << "Saldo: " << cuentas[i].saldo << endl;
        cout << "Fecha de apertura: " << cuentas[i].fechadeApertura << endl;
        cout << "Tipo de moneda: " << cuentas[i].tipodemoneda << endl;
        cout << "Límite de sobregiro: " << cuentas[i].limiteSobregiro << endl;
        cout << "Estado: " << cuentas[i].estado << endl;
    }
}
int buscarCuentaCorrientePorNumero(const CuentaCorriente cuentas[], int n, int numero){
    for(int i=0; i<n; i++){
        if(cuentas[i].NumerodeCuenta == numero){
            return i;
        }
    }
    return -1;
}
void modificarCuentaCorriente(CuentaCorriente cuentas[], int n){
    int numero;
    cout << "Ingrese el número de cuenta: ";
    cin >> numero;
    int pos = buscarCuentaCorrientePorNumero(cuentas, n, numero);
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
void eliminarCuentaCorriente(CuentaCorriente cuentas[], int &n){
    int numero;
    cout << "Ingrese el número de cuenta a eliminar: ";
    cin >> numero;
    int pos = buscarCuentaCorrientePorNumero(cuentas, n, numero);
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
void guardarCuentasCorrientes(const CuentaCorriente cuentas[], int n){
    ofstream archivo("cuentas_corrientes.csv");
    if (!archivo.is_open()){
        cout << "Error al abrir el archivo\n";
        return;
    }
    archivo << "NumerodeCuenta, IDcliente, saldo, fechadeApertura, estado, tipodemoneda, limiteSobregiro\n";
    for (int i=0; i < n; i++){
        archivo << cuentas[i].NumerodeCuenta << ", " 
        << cuentas[i].IDcliente << ", " 
        << cuentas[i].saldo << ", " 
        << cuentas[i].fechadeApertura << ", " 
        << cuentas[i].estado << ", " 
        << cuentas[i].tipodemoneda << ", " 
        << cuentas[i].limiteSobregiro << "\n";
    }
    archivo.close();
    cout << "Cuentas corrientes guardadas en cuentas_corrientes.csv exitosamente\n"; 
}
void cargarCuentasCorrientes(CuentaCorriente cuentas[], int &n){
    ifstream archivo("cuentas_corrientes.csv");
    if (!archivo.is_open()){
        cout << "No se pudo abrir el archivo, iniciando con 0 cuentas corrientes.\n";
        n = 0;
        return;
    }
    string linea;
    getline(archivo, linea); // saltar la cabecera
    n = 0;
    while (getline(archivo, linea)){
        stringstream ss(linea);
        string token;
        getline(ss, token, ','); cuentas[n].NumerodeCuenta = stoi(token);
        getline(ss, token, ','); cuentas[n].IDcliente = stoi(token);
        getline(ss, token, ','); cuentas[n].saldo = stod(token);
        getline(ss, token, ','); cuentas[n].fechadeApertura = token;
        getline(ss, token, ','); cuentas[n].estado = token;
        getline(ss, token, ','); cuentas[n].tipodemoneda = token;
        getline(ss, token, ','); cuentas[n].limiteSobregiro = stod(token);
        n++;
    }
    archivo.close();
    cout << "Cuentas corrientes cargadas desde cuentas_corrientes.csv exitosamente\n";
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