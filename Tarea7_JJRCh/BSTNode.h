#pragma once

template <typename E>
class BSTNode {
public:
	E element;
	BSTNode<E>* left;
	BSTNode<E>* right;

	BSTNode(E element) {
		this->element = element;
		this->left = nullptr;
		this->right = nullptr;
	}
	int childenCount() {
		return (left != nullptr ? 1 : 0) + (right != nullptr ? 1 : 0);
	}
	BSTNode<E>* onlyChild() {
		return left != nullptr ? left : right;
	}
};

