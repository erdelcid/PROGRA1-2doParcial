#pragma once
#include "mysql.h"
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"

using namespace std;

class Empleado : Persona {
	// Atributos
private: string puesto;
	// Constructor
public:
	Empleado() {
	}
	Empleado(int cod, string pue) : Persona(cod) {
		puesto = pue;
	}

	// Metodos
	// set (modificar)

	// Metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string INSERT = "INSERT INTO Empleado (puesto) values ('" + puesto + "');";
			const char* i = INSERT.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso EXITOSO...." << endl;
			}
			else {
				cout << "*** ERROR al Insertar información ***" << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultadoq;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consultaBD = "SELECT * FROM empleado;";
			const char* c = consultaBD.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultadoq = mysql_store_result(cn.getConectar());

				cout << endl << "CODIGO EMPLEADO      PUESTO" << endl;
				cout << "---------------      ---------------------------------" << endl;
				while (fila = mysql_fetch_row(resultadoq)) {
					cout << "       " << fila[0] << "             " << fila[1] << endl;
				}
				cout << endl;
			}
			else {
				cout << " *** ERROR al Consultar informacion ***" << endl;
			}

		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}

	void modificar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string cd = to_string(codigo);
			string MODIFICAR = "UPDATE Empleado SET puesto = '" + puesto + "' WHERE codigo_empleado = '" + cd + "';";
			const char* i = MODIFICAR.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Modificacion EXITOSA...." << endl;
			}
			else {
				cout << "*** ERROR al Modificar informacion ***" << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string cd = to_string(codigo);
			string ELIMINAR = "DELETE FROM Empleado WHERE codigo_empleado = '" + cd + "';";
			const char* i = ELIMINAR.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion EXITOSA...." << endl;
			}
			else {
				cout << "*** ERROR al Eliminar informacion ***" << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}

};

