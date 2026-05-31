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

bool esNumero(string& tam) {
	for (char c : tam) {
		if (!isdigit(c))
			return false;
	}
	return true;
}

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
			cin.ignore();
			cout << "Ingrese el valor: ";
			getline(cin, valor);
			dict1->insert(llave, valor);
			cout << endl;
			break;
		case 2:
			cout << "Ingrese la llave: ";
			cin >> llave;
			cin.ignore();
			borrado = dict1->remove(llave);
			cout << "se borró el valor: " << borrado << endl;
			break;

		case 3:
			cout << "Ingrese la llave: ";
			cin >> llave;
			cin.ignore();
			valor = dict1->getValue(llave);
			cout << "Valor: " << valor << endl;
			break;

		case 4:
			cout << "Ingrese la llave: ";
			cin >> llave;
			cin.ignore();
			cout << "Ingrese el nuevo valor: ";
			getline(cin, valor);
			dict1->setValue(llave, valor);
			break;

		case 5:
			cout << "Llave: ";
			cin >> llave;
			cin.ignore();
			cout << (dict1->contains(llave) ? "Sí existe" : "No existe") << endl;
			break;

		case 6:
			dict1->clear();
			cout << "Diccionario vaciado" << endl;
			break;
			
		case 7: {
			List<int>* keys = dict1->getKeys();
			cout << "Llaves: ";
			keys->goToStart();
			while (!keys->atEnd()) {
				cout << keys->getElement();
				if (!keys->atEnd())
					cout << ", ";
				keys->next();
			}
			cout << endl;
			delete keys;
			break;
		}
		case 8: {
			List<string>* values = dict1->getValues();
			cout << "Valores: ";
			values->goToStart();
			while (!values->atEnd()) {
				cout << values->getElement();
				if (!values->atEnd())
					cout << ", ";
				values->next();
			}
			cout << endl;
			delete values;
			break;
		}

		case 9: {
			dict1->update(dict2);
			cout << "Diccionario actualizado: ";
			dict1->print();
			cout << endl;
			break;
		}

		case 10:
			string tamañoLista;
			int key;
			string value;
			cout << "Ingrese el tamaño de la lista: ";
			getline(cin, tamañoLista);
			if (!esNumero(tamañoLista) || stoi(tamañoLista) < 1) {
				throw runtime_error("El tamaño debe ser un entero positivo");
			}
			List<int>* keys = new LinkedList<int>();
			List<string>* values = new LinkedList<string>();
			cout << "Ingrese " << tamañoLista << " llaves:" << endl;
			for (int i = 0; i < stoi(tamañoLista); i++) {
				cout << "Llave " << i + 1 << ": ";
				cin >> key;
				cin.ignore();
				keys->append(key);
			}
			cout << "Ingrese " << tamañoLista << " valores:" << endl;
			for (int i = 0; i < stoi(tamañoLista); i++) {
				cout << "Valor " << i + 1 << ": ";
				getline(cin, value);
				values->append(value);
			}

			dict1->zip(keys, values);
			cout << "Diccionario nuevo: ";
			dict1->print();
			cout << endl;
			delete keys;
			delete values;
			break;
		}
	}
	catch (const exception& e) {
		cout << "Error: " << e.what() << "\n";
	}
}

int main() {
	setlocale(LC_ALL, "");
	BSTDictionary<int, string>* diccionario1 = new BSTDictionary<int, string>();
	BSTDictionary<int, string>* diccionario2 = new BSTDictionary<int, string>();
	string opcion;
	int opcionint;
	do {
		cout << endl;
		cout << "Diccionario 1: " << endl;
		mostrarDiccionario(diccionario1);
		cout << endl;
		cout << "Diccionario 2: " << endl;
		mostrarDiccionario(diccionario2);
		cout << endl;
		cout << menu();
		cout << endl << "Ingrese una opción: ";
		getline(cin, opcion);
		while (!esNumero(opcion) || stoi(opcion) < 1 || stoi(opcion) > 11) {
			cout << "Opción no válida, intente de nuevo" << endl;
			cout << endl << menu() << endl;
			cout << endl << "Ingrese una opción: ";
			getline(cin, opcion);
		}
		opcionint = stoi(opcion);


		if (opcionint != 11) {
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
		}
	} while (opcion != "11");
	delete diccionario1;
	delete diccionario2;
}