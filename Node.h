#include<iostream>
using namespace std;

template<typename T>
class Node
{
public:
	T data;
	Node<T>* parent;
	Node<T>* left;
	Node<T>* right;
	char color;

	Node(T d) : data(d), parent(nullptr), left(nullptr), right(nullptr), color('r') {}
};
