#pragma once
#include "mysql.h"
#include <iostream>
using namespace std;

class ConexionBD {
private:     MYSQL* conectarBD;
public :
	void abrir_conexion() {
		conectarBD = mysql_init(0);
		conectarBD = mysql_real_connect(conectarBD, "localhost", "usr_empresa", "#Abril30.", "db_empresa", 3306, NULL, 0);
	}

	MYSQL* getConectar() {
		return conectarBD;
	}

	void cerrar_conexion() {
		mysql_close(conectarBD);
	}
};

