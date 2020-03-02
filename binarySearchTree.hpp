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
    
    virtual ~BinarySearchTree()
    {
        deleteSubtree(root_);
    }

    void print(ostream& out) const
    {
        printNode(out, root_);
        out << endl;
    }
    // Функция поиска по ключу в бинарном дереве поиска
    bool iterativeSearch(const T& key)  const
    {
        return (iterativeSearchNode(key) != nullptr);
    }

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
            if (key < ptr1->key_ )
                    ptr1->left_ = newNode;
            else
                    ptr1->right_ = newNode;
        }
    }
    
    // Удаление элемента из дерева, не нарушающее порядка элементов
//    void deleteKey(const T& key)
//    {
//        Node* root1 = nullptr;
//        Node* deleteNode = nullptr;
//
//        root1 = root_;
//
//        //находим узел с таким значением
//        while (root1 != nullptr && deleteNode != root1)
//        {
//            if (key == root1->key_)
//                deleteNode = root1;
//            else if (key < root1->key_ )
//                root1 = root1->left_;
//            else
//                root1 = root1->right_;
//        }
//        //удаляем нужный ключ и переставляем элементы в нужном порядке
//        if (key == deleteNode->key_)
//        {
//            if (deleteNode->right_ == nullptr && deleteNode->left_ == nullptr)
//                deleteNode = nullptr;
//            else if (deleteNode->right_ == nullptr)
//
//        }
//        else
//            cout << "You haven't got this key";
//
//    }
//
    // Определение количества узлов дерева
    int getCount() const
    {
        return getCountSubTree(this->root_);
    }

    // Определение высоты дерева
    int getHeight() const
    {
        return getHeightSubTree(this->root_);
    }
    
    void inorderWalkPrint()
    {
        inorderWalk(this->root_);
    }

private:
    // Функция поиска адреса узла по ключу в бинарном дереве поиска
    Node* iterativeSearchNode(const T& key) const
    {
        Node* newNode = root_;
        bool find = false;

        while (newNode != nullptr && find == false)
        {
            if (key == newNode->key_)
                find = true;
            else if (key < newNode->key_ )
                newNode = newNode->left_;
            else
                newNode = newNode->right_;
        }
        
        if (find)
            return newNode;
        else
            return nullptr;
    }
    
//    Node* find_next(const T& key)
//    {
//        Node* x = iterativeSearch(key);
//        Node* y = nullptr;
//
//        if(x == 0)
//            return 0;
//        if(x->right_ != 0)
//        {
//            while(x->right_->left_!=0) // ищем минимальный
//                    x->right_ = x->right_->left_;
//            return x->right_;
//        }
//        y = x->p_;
//
//        while(y!=0 && x == y->right)
//        {
//            x = y;
//            y = y->p_;
//        }
//        return y;
//    }

    
    
    
//    Рекурсивные функции, представляющие рекурсивные тела основных интерфейсных методов

//    Рекурсивная функция для освобождения памяти
    void deleteSubtree(Node* node)
    {
        while (node != nullptr)
        {
            deleteSubtree(node->left_);
            deleteSubtree(node->right_);
            delete node;
            node = nullptr;
        }
        
    }
    
//    Рекурсивная функция определения количества узлов дерева
    int getCountSubTree(Node* node) const
    {
        if (node == nullptr) return 0;
        return (1 + getCountSubTree(node->left_) + getCountSubTree(node->right_));
    }
    
//    Рекурсивная функция определения высоты дерева
    int getHeightSubTree(Node* node) const
    {
        int leftNode = 0;
        int rightNode = 0;

        if (node == nullptr)
        {
            return 0;
        }
        if (node->left_ != nullptr)
        {
            leftNode = getHeightSubTree(node->left_);
        }
        if (node->right_ != nullptr)
        {
            rightNode = getHeightSubTree(node->right_);
        }
        if (leftNode > rightNode)
        {
            return leftNode + 1;
        }
        else
        {
            return rightNode + 1;
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
    void inorderWalk(Node* node) const
    {
        if (node != nullptr)
        {
            inorderWalk(node->left_);
            cout << node->key_ << " ";
            inorderWalk(node->right_);
        }
    }
}; // конец шаблона класса TreeBinarySearchTree

