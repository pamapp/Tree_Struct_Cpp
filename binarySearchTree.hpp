#pragma once
#include <iostream>
using namespace std;

template <class T>
class BinarySearchTree
{
private:
    struct Node
    {
        T key_;
        Node* p_;
        Node* left_;
        Node* right_;
        Node(const T& key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) :
            key_(key), left_(left), right_(right), p_(p) {}
    };
    
    Node* root_;


public:
    BinarySearchTree() : root_(nullptr) {}
    
//    virtual ~BinarySearchTree()
//    {
//        deleteSubtree(root_);
//    }

    void print(ostream& out) const
    {
        printNode(out, root_);
        out << endl;
    }
    // Функция поиска по ключу в бинарном дереве поиска
//    bool iterativeSearch(const T& key)  const
//    {
//        return (iterativeSearchNode(key) != nullptr);
//    }

    // Вставка нового элемента в дерево, не нарушающая порядка элементов. Вставка производится в лист дерева
    void insert(const T& key)
    {
        Node* newNode = new Node(key);
        Node* ptr = nullptr;
        Node* ptr1 = nullptr;

        newNode->p_ = newNode->left_ = newNode->right_=0;
        ptr = root_;
        
        while (ptr != 0) //ищем родителя нашего нового узла
        {
            ptr1 = ptr;
            if (key < ptr->key_ )
                ptr = ptr->left_;
            else
                ptr = ptr->right_;
        }
        
        newNode->p_= ptr1; //родитель нашего нового узла
        
        if (ptr1 == 0) //дерево было пустое
                root_ = newNode;
        else
        {
            if(key < ptr1->key_ )
                    ptr1->left_ = newNode;
            else
                    ptr1->right_ = newNode;
        }
    }
    
    // Удаление элемента из дерева, не нарушающее порядка элементов
//    void deleteKey(const T& key)
//    {
//        Node* x = nullptr;
//        Node* y = nullptr;
//
//        if (key->left_ = nullptr || key->right_ = nullptr)
//        {
//            x = y;
//        }
//    }
//
//    // Определение количества узлов дерева
//    int getCount() const
//    {
//        return getCountSubTree(this->root_);
//    }
//
//    // Определение высоты дерева
    int getHeight() const
    {
        return getHeightSubTree(this->root_);
    }

private:
    // Функция поиска адреса узла по ключу в бинарном дереве поиска
//    Node* iterativeSearchNode(const T& key) const
//    {
//        Node* newNode = new Node(key);
//
//        if (key == 0 || key-> )
//    }

//    // Рекурсивные функции, представляющие рекурсивные тела основных интерфейсных методов
//    
//    // Рекурсивная функция для освобождения памяти
//    void deleteSubtree(Node* node)
//    {
//        while (node != nullptr)
//        {
//            deleteSubtree(node->left_);
//            deleteSubtree(node->right_);
//            delete node;
//        }
//    }
//    // Рекурсивная функция определения количества узлов дерева
    int getCountSubTree(Node* node) const
    {
        if (node == nullptr) return 0;
        return (1 + getCountSubTree(node->left_) + getCountSubTree(node->right_));
    }
    
//    // Рекурсивная функция определения высоты дерева
    int getHeightSubTree(Node* node) const
    {
        int x = 0;
        int y = 0;
        
        if (node == nullptr)
        {
            return 0;
        }
        if (node->left_ != nullptr)
        {
            x = getHeightSubTree(node->left_);
        }
        if (node->right_ != nullptr)
        {
            y = getHeightSubTree(node->right_);
        }
        
        if (x > y)
        {
            return x + 1;
        }
        else
        {
            return y + 1;
        }
    }
    
    // Рекурсивная функция для вывода изображения дерева в выходной поток
    void printNode(ostream& out, Node* root) const
    {
        // Изображение дерева заключается в круглые скобки.
        out << '(';
        if (root)
        {
           // Для узлов дерева должна быть определена (или переопределена) операция вывода в выходной поток <<
           out << root->key_;
           printNode(out, root->left_);
           printNode(out, root->right_);
        }
        out << ')';
    }
   
    // Рекурсивная функция для организации обхода узлов дерева.
//    void inorderWalk(Node* node) const
//    {
//    // . . .
//    }
}; // конец шаблона класса TreeBinarySearchTree

