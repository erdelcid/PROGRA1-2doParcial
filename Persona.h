#pragma once
#include <iostream>
using namespace std;

class Persona
{
	// Atributos
protected: int codigo = 0;
	// Constructor
protected:
	Persona() {
	}
	Persona(int cod) {
		codigo = cod;
	}
};

