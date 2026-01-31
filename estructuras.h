#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include <string>
using namespace std; 
struct Cliente{
    int IDcliente;
    string nombre;
    string apellido;
    string cedula;
    string direccion;
    string telefono;
    string correo;
    string fechadeRegistro;
    string estado;
};
struct CuentaCorriente{
    int NumerodeCuenta;
    int IDcliente;
    double saldo;
    string fechadeApertura;
    string estado;
    string tipodemoneda;
    double limiteSobregiro; 
};
struct CuentaAhorro{
    int NumerodeCuenta;
    int IDcliente;
    double saldo;
    string fechadeApertura;
    string estado;
    string tipodemoneda;
    double tasaInteres;
};
struct Prestamo{
    int prestamo;
    int IDcliente;
    int plazomeses;
    double monto;
    double tasaInteres;
    string fechadeInicio;
    string fechaVencimiento;
    string estado;
    double saldoPendiente;
};
struct Garante{
    int IDgarante;
    string nombre;
    string apellido;
    string cedula;
    string relacion;
    string ingresosmensuales;
    string direccion;
    string telefono;
    string estado;
};
struct Transaccion{
    int IDtransaccion;
    int NumerodeCuenta;
    string tipo; // "Depósito", "Retiro", "Transferencia"
    double monto;
    string fecha;
    string descripcion;
};
#endif //ESTRUCTURAS_H