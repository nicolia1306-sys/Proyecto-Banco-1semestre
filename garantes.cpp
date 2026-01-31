#include<iostream>
#include<fstream>
#include<sstream>
#include "garantes.h"
using namespace std;

void registrarGarante(Garante garantes[], int &n){
    cout << "\n===REGISTRAR GARANTE===\n";
    garantes[n].IDgarante = n + 7001; // ejemplo: IDs de garantes empiezan en 7001
    cin.ignore();
    cout << "Ingrese el nombre: ";
    getline(cin, garantes[n].nombre);
    cout << "Ingrese el apellido: ";
    getline(cin, garantes[n].apellido);
    cout << "Ingrese la cédula: ";
    getline(cin, garantes[n].cedula);
    cout << "Ingrese la relación con el cliente: ";
    getline(cin, garantes[n].relacion);
    cout << "Ingrese los ingresos mensuales: ";
    getline(cin, garantes[n].ingresosmensuales);
    cout << "Ingrese la dirección: ";
    getline(cin, garantes[n].direccion);
    cout << "Ingrese el teléfono: ";
    getline(cin, garantes[n].telefono);
    garantes[n].estado = "Activo";
    n++;
    cout << "Garante registrado exitosamente\n";
}

void mostrarGarantes(const Garante garantes[], int n){
    cout << "\n===LISTA DE GARANTES===\n";
    if(n == 0){
        cout << "No existen garantes registrados\n";
        return;
    }
    for(int i=0; i<n; i++){
        cout << "\nID Garante: " << garantes[i].IDgarante << endl;
        cout << "Nombre: " << garantes[i].nombre << endl;
        cout << "Apellido: " << garantes[i].apellido << endl;
        cout << "Cédula: " << garantes[i].cedula << endl;
        cout << "Relación: " << garantes[i].relacion << endl;
        cout << "Ingresos mensuales: " << garantes[i].ingresosmensuales << endl;
        cout << "Dirección: " << garantes[i].direccion << endl;
        cout << "Teléfono: " << garantes[i].telefono << endl;
        cout << "Estado: " << garantes[i].estado << endl;
    }
}

int buscarGarantePorCedula(const Garante garantes[], int n, const std::string &cedula){
    for(int i=0; i<n; i++){
        if(garantes[i].cedula == cedula){
            return i;
        }
    }
    return -1;
}

void modificarGarante(Garante garantes[], int n){
    string cedula;
    cout << "Ingrese la cédula del garante: ";
    cin >> cedula;
    int pos = buscarGarantePorCedula(garantes, n, cedula);
    if(pos == -1){
        cout << "Garante no encontrado\n";
        return;
    }
    cout << "Modificando datos del garante ID:" << garantes[pos].IDgarante << endl;
    cin.ignore();
    cout << "Ingrese el nuevo teléfono: ";
    getline(cin, garantes[pos].telefono);
    cout << "Ingrese el nuevo estado: ";
    getline(cin, garantes[pos].estado);
    cout << "Datos del garante actualizados correctamente\n";
}

void eliminarGarante(Garante garantes[], int &n){
    string cedula;
    cout << "Ingrese la cédula del garante a eliminar: ";
    cin.ignore();
    getline(cin, cedula);
    int pos = buscarGarantePorCedula(garantes, n, cedula);
    if(pos == -1){
        cout << "Garante no encontrado\n";
        return;
    }
    for(int i=pos; i<n-1; i++){
        garantes[i] = garantes[i+1];
    }
    n--;
    cout << "Garante eliminado exitosamente\n";
}

void guardarGarantes(const Garante garantes[], int n){
    ofstream archivo("garantes.csv");
    if (!archivo.is_open()){
        cout << "Error al abrir el archivo\n";
        return;
    }
    archivo << "IDgarante, nombre, apellido, cedula, relacion, ingresosmensuales, direccion, telefono, estado\n";
    for (int i=0; i < n; i++){
        archivo << garantes[i].IDgarante << ","
        << garantes[i].nombre << ","
        << garantes[i].apellido << ","
        << garantes[i].cedula << ","
        << garantes[i].relacion << ","
        << garantes[i].ingresosmensuales << ","
        << garantes[i].direccion << ","
        << garantes[i].telefono << ","
        << garantes[i].estado << "\n";
    }
    archivo.close();
    cout << "Garantes guardados en garantes.csv exitosamente\n"; 
}

void cargarGarantes(Garante garantes[], int &n){
    ifstream archivo("garantes.csv");
    if (!archivo.is_open()){
        cout << "No se pudo abrir el archivo garantes.csv\n";
        return;
    }
    string linea;
    getline(archivo, linea); // ignorar encabezado
    n = 0;
    while (getline(archivo, linea)){
        if(linea.empty()) continue;
        stringstream ss(linea);
        string campo;
        getline(ss, campo, ','); garantes[n].IDgarante = stoi(campo);
        getline(ss, campo, ','); garantes[n].nombre = campo;
        getline(ss, campo, ','); garantes[n].apellido = campo;
        getline(ss, campo, ','); garantes[n].cedula = campo;
        getline(ss, campo, ','); garantes[n].relacion = campo;
        getline(ss, campo, ','); garantes[n].ingresosmensuales = campo;
        getline(ss, campo, ','); garantes[n].direccion = campo;
        getline(ss, campo, ','); garantes[n].telefono = campo;
        getline(ss, campo, ','); garantes[n].estado = campo;
        n++;
    }
    archivo.close();
    cout << "Garantes cargados desde garantes.csv exitosamente\n";
}