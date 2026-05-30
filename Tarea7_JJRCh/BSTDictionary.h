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

	bool contains(K key) {
		return pairs->contains(Pair<K, V>(key));
	}

	void clear() {
		pairs->clear();
	}

	List<K>* getKeys() {
		List<K>* keys = new LinkedList<K>();
		List<Pair<K, V>>* elements = pairs->getElements();
		elements->goToStart();
		while (!elements->atEnd()) {
			keys->append(elements->getElement().key);
			elements->next();
		}
		delete elements;
		return keys;
	}

	List<V>* getValues() {
		List<V>* values = new LinkedList<V>();
		List<Pair<K, V>>* elements = pairs->getElements();
		elements->goToStart();
		while (!elements->atEnd()) {
			values->append(elements->getElement().value);
			elements->next();
		}
		delete elements;
		return values;
	}

	int getSize() {
		return pairs->getSize();
	}

	void update(Dictionary<K, V>* D) {
		List<K>* keys = D->getKeys();
		keys->goToStart;
		while (!keys->atEnd()) {
			K key = keys->getElement();
			V value = D->getValue(key);
			if (contains(key))
				setValue(key, value);
			else
				insert(key, value);
			keys->next();
		}
	}

	void zip(List<K>* keys, List<V> values) {
		BSTree<Pair<K, V>>* newPairs = new BSTree<Pair<K, V>>();
		if (keys->getSize() > values->getSize()) {
			keys->goToStart();
			values->goToStart;
			while (!values->atEnd()) {
				if (contains(keys->getElement()))
					setValue(keys->getElement(), values->getElement());
				else
					newPairs->insert(Pair<K, V>(keys->getElement, values->getElement()));
			}
		}
		keys->goToStart();
		values->goToStart;
		while (!keys->atEnd()) {
			newPairs->insert(Pair<K, V>(keys->getElement, values->getElement()));
		}
	}
};

