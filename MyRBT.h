#include "RBT.h"

template<typename T>
class MyRBT : public RBT<T>
{
private:
    void rotateLeft(Node<T>*& root, Node<T>*& ptr);
    void rotateRight(Node<T>*& root, Node<T>*& ptr);
    void fixInsertRBTree(Node<T>*& root, Node<T>*& ptr);
    void fixDeleteRBTree(Node<T>*& root, Node<T>*& node);
    Node<T>* insertBST(Node<T>*& root, Node<T>*& ptr);
    Node<T>* deleteBST(Node<T>*& root, T data);
    Node<T>* minValueNode(Node<T>*& node);
    Node<T>* maxValueNode(Node<T>*& node);
    int getColor(Node<T>*& node);
    void setColor(Node<T>*& node, char color);
    void inorderHelper(Node<T>* root, ostream& os);
    void preorderHelper(Node<T>* root, ostream& os);
    void postorderHelper(Node<T>* root, ostream& os);
    Node<T>* searchHelper(Node<T>* root, T value);
    //int max(int a, int b);
protected:
    Node<T>* root;
public:
    MyRBT();
    Node<T>* getRoot()const;
    void insertValue(T value) override;
    void deleteValue(T value) override;
    void displayInorder(ostream& os) override;
    void displayPreorder(ostream& os) override;
    void displayPostorder(ostream& os) override;
    void minValue()override;
    void maxValue()override;
    void searchValue(T value)override;
    int calculateHeight(Node<T>* root)override;
    void successor(T value)override;
    void predecessor(T value)override;
};
template<typename T>
MyRBT<T>::MyRBT() : root(nullptr) {}

template<typename T>
Node<T>* MyRBT<T>::getRoot() const
{
    return root;
}

template<typename T>
void MyRBT<T>::rotateLeft(Node<T>*& root, Node<T>*& ptr)
{
    Node<T>* right_child = ptr->right;
    ptr->right = right_child->left;

    if (ptr->right != nullptr)
    {
        ptr->right->parent = ptr;
    }

    right_child->parent = ptr->parent;

    if (ptr->parent == nullptr)
    {
        root = right_child;
    }
    else if (ptr == ptr->parent->left)
    {
        ptr->parent->left = right_child;
    }
    else
    {
        ptr->parent->right = right_child;
    }

    right_child->left = ptr;
    ptr->parent = right_child;
}

template<typename T>
void MyRBT<T>::rotateRight(Node<T>*& root, Node<T>*& ptr)
{
    Node<T>* left_child = ptr->left;
    ptr->left = left_child->right;

    if (ptr->left != nullptr)
    {
        ptr->left->parent = ptr;
    }

    left_child->parent = ptr->parent;

    if (ptr->parent == nullptr)
    {
        root = left_child;
    }
    else if (ptr == ptr->parent->left)
    {
        ptr->parent->left = left_child;
    }
    else
    {
        ptr->parent->right = left_child;
    }

    left_child->right = ptr;
    ptr->parent = left_child;
}

template<typename T>
void MyRBT<T>::fixInsertRBTree(Node<T>*& root, Node<T>*& ptr)
{
    Node<T>* parent_ptr = nullptr;
    Node<T>* grandparent_ptr = nullptr;

    while (ptr != root && getColor(ptr) == 'r' && getColor(ptr->parent) == 'r')
    {
        parent_ptr = ptr->parent;
        grandparent_ptr = parent_ptr->parent;

        if (parent_ptr == grandparent_ptr->left)
        {
            Node<T>* uncle_ptr = grandparent_ptr->right;

            if (getColor(uncle_ptr) == 'r')
            {
                setColor(uncle_ptr, 'b');
                setColor(parent_ptr, 'b');
                setColor(grandparent_ptr, 'r');
                ptr = grandparent_ptr;
            }
            else
            {
                if (ptr == parent_ptr->right)
                {
                    rotateLeft(root, parent_ptr);
                    ptr = parent_ptr;
                    parent_ptr = ptr->parent;
                }
                rotateRight(root, grandparent_ptr);
                std::swap(parent_ptr->color, grandparent_ptr->color);
                ptr = parent_ptr;
            }
        }
        else
        {
            Node<T>* uncle_ptr = grandparent_ptr->left;

            if (getColor(uncle_ptr) == 'r')
            {
                setColor(uncle_ptr, 'b');
                setColor(parent_ptr, 'b');
                setColor(grandparent_ptr, 'r');
                ptr = grandparent_ptr;
            }
            else
            {
                if (ptr == parent_ptr->left)
                {
                    rotateRight(root, parent_ptr);
                    ptr = parent_ptr;
                    parent_ptr = ptr->parent;
                }
                rotateLeft(root, grandparent_ptr);
                std::swap(parent_ptr->color, grandparent_ptr->color);
                ptr = parent_ptr;
            }
        }
    }
    setColor(root, 'b');
}

template<typename T>
void MyRBT<T>::fixDeleteRBTree(Node<T>*& root, Node<T>*& node)
{
    if (node == nullptr)
    {
        return;
    }

    if (node == root)
    {
        root = nullptr;
        return;
    }

    if (getColor(node) == 'r' || getColor(node->left) == 'r' || getColor(node->right) == 'r')
    {
        Node<T>* child = node->left != nullptr ? node->left : node->right;

        if (node == node->parent->left)
        {
            node->parent->left = child;
            if (child != nullptr)
            {
                child->parent = node->parent;
            }
            setColor(child, 'b');
            delete node;
        }
        else
        {
            node->parent->right = child;
            if (child != nullptr)
            {
                child->parent = node->parent;
            }
            setColor(child, 'b');
            delete node;
        }
    }
    else
    {
        Node<T>* sibling = nullptr;
        Node<T>* parent = nullptr;
        Node<T>* temp = node;
        setColor(temp, 'b');

        while (temp != root && getColor(temp) == 'b')
        {
            parent = temp->parent;
            if (temp == parent->left)
            {
                sibling = parent->right;

                if (getColor(sibling) == 'r')
                {
                    setColor(sibling, 'b');
                    setColor(parent, 'r');
                    rotateLeft(root, parent);
                }
                else
                {
                    if (getColor(sibling->left) == 'b' && getColor(sibling->right) == 'b')
                    {
                        setColor(sibling, 'r');
                        if (getColor(parent) == 'b')
                        {
                            setColor(parent, 'b');
                        }
                        else
                        {
                            setColor(parent, 'b');
                        }
                        temp = parent;
                    }
                    else
                    {
                        if (getColor(sibling->right) == 'b')
                        {
                            setColor(sibling->left, 'b');
                            setColor(sibling, 'r');
                            rotateRight(root, sibling);
                            sibling = parent->right;
                        }
                        setColor(sibling, parent->color);
                        setColor(parent, 'b');
                        setColor(sibling->right, 'b');
                        rotateLeft(root, parent);
                        break;
                    }
                }
            }
            else
            {
                sibling = parent->left;

                if (getColor(sibling) == 'r')
                {
                    setColor(sibling, 'b');
                    setColor(parent, 'r');
                    rotateRight(root, parent);
                }
                else
                {
                    if (getColor(sibling->left) == 'b' && getColor(sibling->right) == 'b')
                    {
                        setColor(sibling, 'r');
                        if (getColor(parent) == 'b')
                        {
                            setColor(parent, 'b');
                        }
                        else
                        {
                            setColor(parent, 'b');
                        }
                        temp = parent;
                    }
                    else
                    {
                        if (getColor(sibling->left) == 'b')
                        {
                            setColor(sibling->right, 'b');
                            setColor(sibling, 'r');
                            rotateLeft(root, sibling);
                            sibling = parent->left;
                        }
                        setColor(sibling, parent->color);
                        setColor(parent, 'b');
                        setColor(sibling->left, 'b');
                        rotateRight(root, parent);
                        break;
                    }
                }
            }
        }
        if (temp == temp->parent->left)
        {
            temp->parent->left = nullptr;
        }
        else
        {
            temp->parent->right = nullptr;
        }
        delete temp;
        setColor(root, 'b');
    }
}

template<typename T>
Node<T>* MyRBT<T>::insertBST(Node<T>*& root, Node<T>*& ptr)
{
    if (root == nullptr)
    {
        return ptr;
    }

    if (ptr->data < root->data)
    {
        root->left = insertBST(root->left, ptr);
        root->left->parent = root;
    }
    if (ptr->data > root->data)
    {
        root->right = insertBST(root->right, ptr);
        root->right->parent = root;
    }
    return root;
}

template<typename T>
Node<T>* MyRBT<T>::deleteBST(Node<T>*& root, T data)
{
    if (root == nullptr)
    {
        return root;
    }

    if (data < root->data)
    {
        return deleteBST(root->left, data);
    }

    if (data > root->data)
    {
        return deleteBST(root->right, data);
    }

    if (root->left == nullptr || root->right == nullptr)
    {
        return root;
    }

    Node<T>* temp = minValueNode(root->right);
    root->data = temp->data;
    return deleteBST(root->right, temp->data);
}

template<typename T>
Node<T>* MyRBT<T>::minValueNode(Node<T>*& node)
{
    Node<T>* ptr = node;
    while (ptr->left != nullptr)
    {
        ptr = ptr->left;
    }
    return ptr;
}

template<typename T>
Node<T>* MyRBT<T>::maxValueNode(Node<T>*& node)
{
    Node<T>* ptr = node;
    while (ptr->right != nullptr)
    {
        ptr = ptr->right;
    }
    return ptr;
}

template<typename T>
int MyRBT<T>::getColor(Node<T>*& node)
{
    if (node == nullptr)
    {
        return 'b';
    }
    return node->color;
}

template<typename T>
void MyRBT<T>::setColor(Node<T>*& node, char color)
{
    if (node == nullptr)
    {
        return;
    }
    node->color = color;
}

template<typename T>
void MyRBT<T>::inorderHelper(Node<T>* root, ostream& os)
{
    if (root == nullptr)
    {
        return;
    }

    inorderHelper(root->left, os);
    os << root->data << (root->color == 'r' ? "(r) " : "(b) ");
    inorderHelper(root->right, os);
}

template<typename T>
void MyRBT<T>::preorderHelper(Node<T>* root, ostream& os)
{
    if (root == nullptr)
    {
        return;
    }

    os << root->data << (root->color == 'r' ? "(r) " : "(b) ");
    preorderHelper(root->left, os);
    preorderHelper(root->right, os);
}

template<typename T>
void MyRBT<T>::postorderHelper(Node<T>* root, ostream& os)
{
    if (root == nullptr)
    {
        return;
    }

    postorderHelper(root->left, os);
    postorderHelper(root->right, os);
    os << root->data << (root->color == 'r' ? "(r) " : "(b) ");
}

template<typename T>
Node<T>* MyRBT<T>::searchHelper(Node<T>* root, T value)
{
    Node<T>* temp = root;
    if (temp == nullptr /* || root == temp->data*/)
    {
        //return root;
        return nullptr;
    }
    else if (value == temp->data)
    {
        return root;
    }
    else if (value < temp->data)
    {
        return searchHelper(temp->left, value);
    }
    else //for right
    {
        return searchHelper(temp->right, value);
    }
}

/*template<typename T>
int MyRBT<T>::max(int a, int b)
{
    return (a > b) ? a : b;
}*/

template<typename T>
void MyRBT<T>::insertValue(T value)
{
    Node<T>* newNode = new Node<T>(value);
    root = insertBST(root, newNode);
    fixInsertRBTree(root, newNode);
}

template<typename T>
void MyRBT<T>::deleteValue(T value)
{
    Node<T>* node = deleteBST(root, value);
    fixDeleteRBTree(root, node);
}

template<typename T>
void MyRBT<T>::displayInorder(ostream& os)
{
    inorderHelper(root, os);
}

template<typename T>
void MyRBT<T>::displayPreorder(ostream& os)
{
    preorderHelper(root, os);
}

template<typename T>
void MyRBT<T>::displayPostorder(ostream& os)
{
    postorderHelper(root, os);
}

template<typename T>
void MyRBT<T>::minValue()
{
    Node<T>* temp = minValueNode(root);
    cout << "Max Value in Tree: " << temp->data << "(" << temp->color << ")" << endl;
}

template<typename T>
void MyRBT<T>::maxValue()
{
    Node<T>* temp = maxValueNode(root);
    cout << "Max Value in Tree: " << temp->data << "(" << temp->color << ")" << endl;
}

template<typename T>
void MyRBT<T>::searchValue(T value)
{
    Node<T>* search = searchHelper(root, value);
    if (search == nullptr)
    {
        cout << "Value not Found!" << endl;
    }
    else
    {
        cout << "Value " << search->data << " Found!" << endl;
    }
}

template<typename T>
int MyRBT<T>::calculateHeight(Node<T>* root)
{
    if (root == nullptr)
    {
        return -1;  //counts
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    //return max(leftHeight, rightHeight) + 1;
    if (leftHeight > rightHeight)
    {
        return (leftHeight + 1);
    }
    else
    {
        return (rightHeight + 1);
    }
}

template<typename T>
void MyRBT<T>::successor(T value)
{
    Node<T>* current = searchHelper(root, value);

    if (current == nullptr)
    {
        cout << "Value not found in the tree!" << endl;
        return;
    }
    if (current->right != nullptr)
    {
        Node<T>* successorNode = minValueNode(current->right);
        cout << "Successor of " << value << " is " << successorNode->data << endl;
        return;
    }
    Node<T>* successorNode = nullptr;
    Node<T>* ancestor = root;
    while (ancestor != current)
    {
        if (current->data < ancestor->data)
        {
            successorNode = ancestor;
            ancestor = ancestor->left;
        }
        else
        {
            ancestor = ancestor->right;
        }
    }
    if (successorNode != nullptr)
    {
        cout << "Successor of " << value << " is " << successorNode->data << endl;
    }
    else
    {
        cout << "No successor exists for the value " << value << endl;
    }
}

template<typename T>
void MyRBT<T>::predecessor(T value)
{
    Node<T>* current = searchHelper(root, value);
    if (current == nullptr)
    {
        cout << "Value not found in the tree!" << endl;
        return;
    }
    if (current->left != nullptr)
    {
        Node<T>* predecessorNode = maxValueNode(current->left);
        cout << "Predecessor of " << value << " is " << predecessorNode->data << endl;
        return;
    }
    Node<T>* predecessorNode = nullptr;
    Node<T>* ancestor = root;
    while (ancestor != current)
    {
        if (current->data > ancestor->data)
        {
            predecessorNode = ancestor;
            ancestor = ancestor->right;
        }
        else
        {
            ancestor = ancestor->left;
        }
    }
    if (predecessorNode != nullptr)
    {
        cout << "Predecessor of " << value << " is " << predecessorNode->data << endl;
    }
    else
    {
        cout << "No predecessor exists for the value " << value << endl;
    }
}