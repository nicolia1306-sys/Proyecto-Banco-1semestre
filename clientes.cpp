#include<iostream>
#include<fstream>
#include <sstream>
#include "clientes.h"
using namespace std;
void registrarCliente(Cliente clientes[], int &n){
    cout << "\n===REGISTRAR CLIENTE===\n";
    clientes[n].IDcliente = n + 1;
    cout << "Ingrese el nombre: ";
    cin.ignore();
    getline(cin, clientes[n].nombre);
    cout << "Ingrese el apellido: ";
    getline(cin, clientes[n].apellido);
    cout << "Ingrese la cédula:";
    getline(cin, clientes[n].cedula);
    cout << "Ingrese la dirección: ";
    getline(cin, clientes[n].direccion);
    cout << "Ingrese el número de telefono: ";
    getline(cin, clientes[n].telefono);
    cout << "Ingrese su correo electronico: ";
    getline(cin, clientes[n].correo);
    cout << "Ingrese la fecha de registro: ";
    getline(cin, clientes[n].fechadeRegistro);
    clientes[n].estado = "Activo";
    n++;
    cout << "Cliente registrado exitosamente\n";
}
void mostrarClientes(const Cliente clientes[], int n){
    cout << "\n===LISTA DE CLIENTES===\n";
    if(n == 0){
        cout << "No existen clientes registrados\n";
        return;
    }
    for(int i=0; i<n; i++){
        cout << "\nCliente ID: " << clientes[i].IDcliente << endl;
        cout << "Nombre: " << clientes[i].nombre << endl;
        cout << "Apellido: " << clientes[i].apellido << endl;
        cout << "Cédula: " << clientes[i].cedula << endl;
        cout << "Dirección: " << clientes[i].direccion << endl;
        cout << "Teléfono: " << clientes[i].telefono << endl;
        cout << "Correo electrónico: " << clientes[i].correo << endl;
        cout << "Fecha de registro: " << clientes[i].fechadeRegistro << endl;
        cout << "Estado: " << clientes[i].estado << endl;
    }
}
int buscarClientePorCedula(const Cliente clientes[], int n, const std::string &cedula){
    for(int i = 0; i < n; i++){
        if(clientes[i].cedula == cedula){
            return i;
        }
    }
    return -1;
}
void modificarCliente(Cliente clientes[], int n){
    string cedula;
    cout << "Ingrese la cédula del cliente: ";
    cin >> cedula;
    int pos = buscarClientePorCedula(clientes, n, cedula);

    if(pos == -1){
        cout << "Cliente no encontrado\n";
        return;
    }
    cout << "Modificando datos del cliente ID:" << clientes[pos].IDcliente << endl;
    cout << "Ingrese el nuevo nombre: ";
    cin.ignore();
    getline(cin, clientes[pos].nombre);
    cout << "Ingrese el nuevo apellido: ";
    getline(cin, clientes[pos].apellido);
    cout << "Ingrese la nueva dirección: ";
    getline(cin, clientes[pos].direccion);
    cout << "Ingrese el nuevo número de teléfono: ";
    getline(cin, clientes[pos].telefono);
    cout << "Ingrese el nuevo correo electrónico: ";
    getline(cin, clientes[pos].correo);
    cout << "Datos del cliente actualizados correctamente\n";
}
void eliminarCliente(Cliente clientes[], int &n){
    string cedula;
    cout << "Ingrese la cédula del cliente a eliminar: ";
    cin.ignore();
    getline(cin, cedula);
    int pos = buscarClientePorCedula(clientes, n, cedula);
    if(pos == -1){
        cout << "Cliente no encontrado\n";
        return;
    }
    for(int i=pos; i<n-1; i++){
        clientes[i] = clientes[i+1];
    }
    n--;
    cout << "Cliente eliminado exitosamente\n";
}
void guardarClientes(const Cliente clientes[], int n){
ofstream archivo("clientes.csv");
if (!archivo.is_open()){
    cout << "Error al abrir el archivo\n";
    return;
}
archivo << "IDcliente, nombre, apellido, cedula, direccion, telefono, correo, fechadeRegistro, estado\n";
for (int i=0; i < n; i++){
    archivo << clientes[i].IDcliente << ", " 
    << clientes[i].nombre << ", " 
    << clientes[i].apellido << ", " 
    << clientes[i].cedula << ", " 
    << clientes[i].direccion << ", " 
    << clientes[i].telefono << ", " 
    << clientes[i].correo << ", " 
    << clientes[i].fechadeRegistro << ", " 
    << clientes[i].estado << "\n";
}
archivo.close();
cout << "Clientes guardados en clientes.csv exitosamente\n"; 
}
void cargarClientes(Cliente clientes[], int &n){
    ifstream archivo("clientes.csv");
    if (!archivo.is_open()){
        cout << "No se pudo abrir el archivo clientes.csv\n";
        return;
    }

    string linea;
    getline(archivo, linea); // ignorar encabezado

    n = 0;
    while (getline(archivo, linea)){
        if(linea.empty()) continue;

        stringstream ss(linea);
        string campo;

        getline(ss, campo, ','); clientes[n].IDcliente = stoi(campo);
        getline(ss, campo, ','); clientes[n].nombre = campo;
        getline(ss, campo, ','); clientes[n].apellido = campo;
        getline(ss, campo, ','); clientes[n].cedula = campo;
        getline(ss, campo, ','); clientes[n].direccion = campo;
        getline(ss, campo, ','); clientes[n].telefono = campo;
        getline(ss, campo, ','); clientes[n].correo = campo;
        getline(ss, campo, ','); clientes[n].fechadeRegistro = campo;
        getline(ss, campo, ','); clientes[n].estado = campo;

        n++;
    }

    archivo.close();
    cout << "Clientes cargados desde clientes.csv exitosamente\n";
}