#include"Node.h"

template<typename T>
class RBT
{
public:
	virtual void insertValue(T value) = 0;
	virtual void deleteValue(T value) = 0;
	virtual void displayInorder(ostream& os) = 0;
	virtual void displayPreorder(ostream& os) = 0;
	virtual void displayPostorder(ostream& os) = 0;
	virtual void minValue() = 0;
	virtual void maxValue() = 0;
	virtual void searchValue(T value) = 0;
	virtual int calculateHeight(Node<T>* root) = 0;
	virtual void successor(T value) = 0;
	virtual void predecessor(T value) = 0;
};
