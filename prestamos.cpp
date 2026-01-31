#include<iostream>
#include<fstream>
#include<sstream>
#include "prestamos.h"
using namespace std;

void registrarPrestamo(Prestamo prestamos[], int &n){
    cout << "\n===REGISTRAR PRÉSTAMO===\n";
    prestamos[n].prestamo = n + 5001; // ejemplo: préstamos empiezan en 5001
    cout << "Ingrese el ID del cliente: ";
    cin >> prestamos[n].IDcliente;
    cout << "Ingrese el monto: ";
    cin >> prestamos[n].monto;
    cout << "Ingrese la tasa de interés: ";
    cin >> prestamos[n].tasaInteres;
    cout << "Ingrese el plazo en meses: ";
    cin >> prestamos[n].plazomeses;
    cin.ignore();
    cout << "Ingrese la fecha de inicio: ";
    getline(cin, prestamos[n].fechadeInicio);
    cout << "Ingrese la fecha de vencimiento: ";
    getline(cin, prestamos[n].fechaVencimiento);
    prestamos[n].estado = "Activo";
    prestamos[n].saldoPendiente = prestamos[n].monto;
    n++;
    cout << "Préstamo registrado exitosamente\n";
}

void mostrarPrestamos(const Prestamo prestamos[], int n){
    cout << "\n===LISTA DE PRÉSTAMOS===\n";
    if(n == 0){
        cout << "No existen préstamos registrados\n";
        return;
    }
    for(int i=0; i<n; i++){
        cout << "\nID Préstamo: " << prestamos[i].prestamo << endl;
        cout << "ID Cliente: " << prestamos[i].IDcliente << endl;
        cout << "Monto: " << prestamos[i].monto << endl;
        cout << "Tasa de interés: " << prestamos[i].tasaInteres << endl;
        cout << "Plazo (meses): " << prestamos[i].plazomeses << endl;
        cout << "Fecha de inicio: " << prestamos[i].fechadeInicio << endl;
        cout << "Fecha de vencimiento: " << prestamos[i].fechaVencimiento << endl;
        cout << "Saldo pendiente: " << prestamos[i].saldoPendiente << endl;
        cout << "Estado: " << prestamos[i].estado << endl;
    }
}

int buscarPrestamoPorID(const Prestamo prestamos[], int n, int id){
    for(int i=0; i<n; i++){
        if(prestamos[i].prestamo == id){
            return i;
        }
    }
    return -1;
}

void modificarPrestamo(Prestamo prestamos[], int n){
    int id;
    cout << "Ingrese el ID del préstamo: ";
    cin >> id;
    int pos = buscarPrestamoPorID(prestamos, n, id);
    if(pos == -1){
        cout << "Préstamo no encontrado\n";
        return;
    }
    cout << "Modificando préstamo ID: " << prestamos[pos].prestamo << endl;
    cout << "Ingrese el nuevo saldo pendiente: ";
    cin >> prestamos[pos].saldoPendiente;
    cin.ignore();
    cout << "Ingrese el nuevo estado: ";
    getline(cin, prestamos[pos].estado);
    cout << "Datos del préstamo actualizados correctamente\n";
}

void eliminarPrestamo(Prestamo prestamos[], int &n){
    int id;
    cout << "Ingrese el ID del préstamo a eliminar: ";
    cin >> id;
    int pos = buscarPrestamoPorID(prestamos, n, id);
    if(pos == -1){
        cout << "Préstamo no encontrado\n";
        return;
    }
    for(int i=pos; i<n-1; i++){
        prestamos[i] = prestamos[i+1];
    }
    n--;
    cout << "Préstamo eliminado exitosamente\n";
}

void guardarPrestamos(const Prestamo prestamos[], int n){
    ofstream archivo("prestamos.csv");
    if (!archivo.is_open()){
        cout << "Error al abrir el archivo\n";
        return;
    }
    archivo << "IDprestamo, IDcliente, monto, tasaInteres, plazomeses, fechadeInicio, fechaVencimiento, estado, saldoPendiente\n";
    for (int i=0; i < n; i++){
        archivo << prestamos[i].prestamo << ","
        << prestamos[i].IDcliente << ","
        << prestamos[i].monto << ","
        << prestamos[i].tasaInteres << ","
        << prestamos[i].plazomeses << ","
        << prestamos[i].fechadeInicio << ","
        << prestamos[i].fechaVencimiento << ","
        << prestamos[i].estado << ","
        << prestamos[i].saldoPendiente << "\n";
    }
    archivo.close();
    cout << "Préstamos guardados en prestamos.csv exitosamente\n"; 
}

void cargarPrestamos(Prestamo prestamos[], int &n){
    ifstream archivo("prestamos.csv");
    if (!archivo.is_open()){
        cout << "No se pudo abrir el archivo prestamos.csv\n";
        return;
    }
    string linea;
    getline(archivo, linea); // ignorar encabezado
    n = 0;
    while (getline(archivo, linea)){
        if(linea.empty()) continue;
        stringstream ss(linea);
        string campo;
        getline(ss, campo, ','); prestamos[n].prestamo = stoi(campo);
        getline(ss, campo, ','); prestamos[n].IDcliente = stoi(campo);
        getline(ss, campo, ','); prestamos[n].monto = stod(campo);
        getline(ss, campo, ','); prestamos[n].tasaInteres = stod(campo);
        getline(ss, campo, ','); prestamos[n].plazomeses = stoi(campo);
        getline(ss, campo, ','); prestamos[n].fechadeInicio = campo;
        getline(ss, campo, ','); prestamos[n].fechaVencimiento = campo;
        getline(ss, campo, ','); prestamos[n].estado = campo;
        getline(ss, campo, ','); prestamos[n].saldoPendiente = stod(campo);
        n++;
    }
    archivo.close();
    cout << "Préstamos cargados desde prestamos.csv exitosamente\n";
}