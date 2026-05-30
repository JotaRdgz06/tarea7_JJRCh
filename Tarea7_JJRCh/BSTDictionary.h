#pragma once

#include "Dictionary.h"
#include "Pair.h"
#include "BSTree.h"
#include "List.h"

template <typename K, typename V>
class BSTDictionary: public Dictionary<K, V>{
private:
	BSTree<Pair<K, V>>* pairs;

public:
	BSTDictionary() {
		pairs = new BSTree<Pair<K, V>>();
	}

	~BSTDictionary() {
		delete pairs;
	}

	void insert(K key, V value) {
		pairs->insert(Pair<K, V>(key, value));
	}

	V remove(K key) {
		return pairs->remove(Pair<K, V>(key)).value;
	}

	V getValue(K key) {
		return pairs->find(Pair<K, V>(key)).value;
	}

	void setValue(K key, V value) {
		if (!contains(key))
			throw runtime_error("La llave no se encontró");
		pairs->setElement(Pair<K, V>(key, value));
	}
};

