#include <iostream>
#include <stdexcept>
#include <String>
#include "BSTDictionary.h"

using std::cout;
using std::endl;
using std::runtime_error;
using std::getline;
using std::string;
using std::cin;

void mostrarDiccionario(BSTDictionary<int, string>* D) {
	if (D->isEmpty()) {
		cout << "El diccionario está vacío" << endl;
		return;
	}
	D->print();
}

string menu() {
	string result = "1. Insertar";
	result += "\n2. Eliminar";
	result += "\n3. Obtener valor";
	result += "\n4. Modificar valor";
	result += "\n5. Verificar si existe una llave";
	result += "\n6. Vaciar diccionario";
	result += "\n7. Obtener llaves";
	result += "\n8. Obtener valores";
	result += "\n9. Juntar diccionarios";
	result += "\n10. Juntar lista de llaves y lista de valores";
	result += "\n11. Salir";
	return result;
}

int main() {
	BSTDictionary<int, string>* diccionario1 = new BSTDictionary<int, string>();
	BSTDictionary<int, string>* diccionario2 = new BSTDictionary<int, string>();
	string opcion;
	do {
		cout << "Diccionario 1: " << endl;
		mostrarDiccionario(diccionario1);
		cout << endl;
		cout << "Diccionario 2: " << endl;
		mostrarDiccionario(diccionario2);
		cout << endl << endl;
		menu();
		cout << "Ingrese una opción: ";
		getline(cin, opcion);
	} while (opcion != "11");
}