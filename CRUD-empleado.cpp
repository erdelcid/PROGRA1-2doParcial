
#include <iostream>
#include <string>
#include <conio.h>
#include "Empleado.h"

using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (SHORT)x - 1;
    coord.Y = (SHORT)y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
	char  opcion;
	string puesto, puesto2;
	int codigo = 0;

	do
	{
		system("cls"); system("color F6");
		gotoxy(19, 5); cout << "PROGRAMACION 1";
		gotoxy(21, 6); cout << "2do PARCIAL";
		gotoxy(18, 8); cout << "Eduardo Del Cid";
		gotoxy(19, 9); cout << "5990-21-21461";
		gotoxy(18, 12); cout << "1. C - INSERTAR";
		gotoxy(18, 13); cout << "2. R - LEER";
		gotoxy(18, 14); cout << "3. U - MODIFICAR";
		gotoxy(18, 15); cout << "4. D - ELIMINAR";
		gotoxy(18, 16); cout << "0. SALIR";
		gotoxy(28, 18); cout << "Opcion: ";

		gotoxy(36, 18); cin >> opcion;
		cin.ignore();
		//			gotoxy(36,16); cin >> opcion;

		switch (opcion)
		{
		case '1':
		{
			system("cls"); system("color F6");

			cout << "Ingrese Puesto: ";
			getline(cin, puesto);

			Empleado c = Empleado(codigo, puesto);
			c.crear();
			c.leer();

			gotoxy(1, 25); _getch();
		}
		break;

		case '2':
		{
			system("cls"); system("color F6");

			Empleado c = Empleado(codigo, puesto);
			c.leer();

			gotoxy(1, 25); _getch();
		}
		break;

		case '3':
		{
			system("cls"); system("color F6");

			Empleado c = Empleado(codigo, puesto);
			c.leer();

			cout << "Codigo de Puesto a Modificar: ";
			cin >> codigo;
			cin.ignore();
			cout << "Nuevo nombre de Puesto: ";
			getline(cin, puesto);

			Empleado u = Empleado(codigo, puesto);
			u.modificar();
			u.leer();

			gotoxy(1, 25); _getch();
		}
		break;

		case '4':
		{
			system("cls"); system("color F6");

			Empleado c = Empleado(codigo, puesto);
			c.leer();

			cout << "Codigo de Puesto a Eliminar: ";
			cin >> codigo;
			cin.ignore();

			Empleado e = Empleado(codigo, puesto);
			e.eliminar();
			e.leer();

			gotoxy(1, 25); _getch();
		}
		break;

		case '0':
			break;

		default:
		{
			gotoxy(28, 20); cout << "OPCION INVALIDA.";
			gotoxy(1, 25); _getch();
		}
		break;

		}
	} while (opcion != '0');
 
//    system("pause");
    return 0;
}
