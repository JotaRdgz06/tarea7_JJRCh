#include <iostream>
#include <stdexcept>
#include <string>
#include "BSTDictionary.h"

using std::cout;
using std::endl;
using std::runtime_error;
using std::getline;
using std::string;
using std::cin;
using std::stoi;

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

void accion(BSTDictionary<int, string>* dict1, BSTDictionary<int, string>* dict2, string opcion) {

}

bool esNumero(string& tam) {
	for (char c : tam) {
		if (!isdigit(c))
			return false;
	}
	return true;
}

int main() {
	setlocale(LC_ALL, "");
	BSTDictionary<int, string>* diccionario1 = new BSTDictionary<int, string>();
	BSTDictionary<int, string>* diccionario2 = new BSTDictionary<int, string>();
	string opcion;
	do {
		cout << "Diccionario 1: " << endl;
		mostrarDiccionario(diccionario1);
		cout << endl;
		cout << "Diccionario 2: " << endl;
		mostrarDiccionario(diccionario2);
		cout << endl;
		cout << menu();
		cout << endl << "Ingrese una opción: ";
		getline(cin, opcion);
		while (!esNumero(opcion) || opcion < "1" || opcion > "11") {
			cout << "Opción no válida, intente de nuevo" << endl;
			cout << endl << menu() << endl;
			cout << endl << "Ingrese una opción: ";
			getline(cin, opcion);
		}

		string dicSelection;
		cout << "Con cual diccionario quiere trabajar?\n";
		cout << "1. Diccionario 1\n";
		cout << "2. Diccionario 2\n";
		getline(cin, dicSelection);

		while (!esNumero(dicSelection) || dicSelection < "1" || dicSelection > "2") {
			cout << endl << "Opción no válida, intente de nuevo" << endl;
			cout << "Con cual diccionario quiere trabajar?\n";
			cout << "1. Diccionario 1\n";
			cout << "2. Diccionario 2\n";
			getline(cin, dicSelection);
		}

		if (dicSelection == "1")
			accion(diccionario1, diccionario2, opcion);
		else {
			accion(diccionario2, diccionario1, opcion);
		}
	} while (opcion != "11");
	delete diccionario1;
	delete diccionario2;
}