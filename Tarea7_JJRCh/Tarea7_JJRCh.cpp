#include <iostream>
#include <stdexcept>
#include <String>
#include "BSTDictionary.h"

using std::cout;
using std::endl;
using std::string;

void mostrarDiccionario(BSTDictionary<int, string>* D) {
	if (D->isEmpty()) {
		cout << "El diccionario está vacío" << endl;
		return;
	}
	D->print();
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
	} while (opcion != "");
}