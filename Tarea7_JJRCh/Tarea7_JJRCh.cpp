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
using std::exception;

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

void accion(BSTDictionary<int, string>* dict1, BSTDictionary<int, string>* dict2, int opcionint) {
	int llave;
	string valor;
	string borrado;
	try {
		switch (opcionint) {
		case 1:
			cout << "Ingrese la llave: ";
			cin >> llave;
			cout << "Ingrese el valor: ";
			getline(cin, valor);
			dict1->insert(llave, valor);
			break;
		case 2:
			cout << "Ingrese la llave: ";
			cin >> llave;
			borrado = dict1->remove(llave);
			cout << "se borró el valor: " << borrado;
			break;

		case 3:
			cout << "Ingrese la llave: ";
			cin >> llave;
			valor = dict1->getValue(llave);
			cout << "Valor: " << valor;
			break;

		case 4:
			cout << "Ingrese la llave: ";
			cin >> llave;
			cout << "Ingrese el nuevo valor: ";
			cin >> valor;
			dict1->setValue(llave, valor);
			break;

		case 5:
			cout << "Llave: ";
			cin >> llave;
			cout << (dict1->contains(llave) ? "Sí existe" : "No existe") << endl;
			break;

		case 6:
			dict1->clear();
			cout << "Diccionario vaciado." << endl;
			break;
			
		case 7:
			List<int>*keys = dict1->getKeys();
			cout << "Llaves: ";
			keys->goToStart();
			while (!keys->atEnd()) {
				cout << keys->getElement() << ", ";
				keys->next();
			}
			cout << endl;
			delete keys;
			break;

		case 8:
			List<string>*values = dict1->getValues();
			cout << "Valores: ";
			values->goToStart();
			while (!values->atEnd()) {
				cout << values->getElement() << ", ";
				values->next();
			}
			cout << endl;
			delete values;
			break;
		}
	}
	catch (const exception& e) {
		cout << "Error: " << e.what() << "\n";
	}
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
	int opcionint;
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
			opcionint = stoi(opcion);
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
			accion(diccionario1, diccionario2, opcionint);
		else {
			accion(diccionario2, diccionario1, opcionint);
		}
	} while (opcion != "11");
	delete diccionario1;
	delete diccionario2;
}