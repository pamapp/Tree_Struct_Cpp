#pragma once
#include <iostream>
#include "math.h"
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
        Node* current = root_;
        Node* parent = nullptr;
        
        while (current != 0)
        {
            parent = current;
            if (key < current->key_ )
            {
                current = current->left_;
            }
            else
            {
                current = current->right_;
            }
        }
        
        newNode->p_= parent;
        
        if (parent == 0)
        {
            root_ = newNode;
        }
        else
        {
            if (key < parent->key_ )
            {
                parent->left_ = newNode;
            }
            else
            {
                parent->right_ = newNode;
            }
        }
    }
    
//  Удаление узла из дерева, не нарушающее порядка элементов
    void deleteNode (Node* node)
    {
        if (node == nullptr)
        {
            cout << "Empty tree";
        }

        Node* deleteNode = nullptr;
        Node* nodeChild = nullptr;
        
        if (node->left_ == nullptr || node->right_ == nullptr)
        {
            deleteNode = node;
        }
        else
        {
            deleteNode = find_next(node->key_);
        }
        
        if (deleteNode->left_ != nullptr)
        {
            nodeChild = deleteNode->left_;
        }
        else
        {
            nodeChild = deleteNode->right_;
        }
      
        if (nodeChild != nullptr)
        {
            nodeChild->p_ = deleteNode->p_;
        }
      
        if (deleteNode->p_ == nullptr)
        {
            root_ = nodeChild;
        }
        else
        {
            if (deleteNode == (deleteNode->p_)->left_)
            {
                (deleteNode->p_)->left_ = nodeChild;
            }
            else
            {
                (deleteNode->p_)->right_ = nodeChild;
            }
        }
        
        if (deleteNode != node)
        {
            node->key_ = deleteNode->key_;
        }
    }

//  Определение количества узлов дерева
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
  
    void deleteKey(const T& key) // удаление по ключу
    {
        if (iterativeSearch(key))
        {
            Node* toDelete = iterativeSearchNode(key);
            deleteNode(toDelete);
        }
        else
        {
            cout << "There is no such node in the tree!" << endl;
        }
    }
    
    int lessThen(const T& value) const
    {
        return lessThenSubtree(root_, value);
    }

private:
    // Функция поиска адреса узла по ключу в бинарном дереве поиска
    Node* iterativeSearchNode(const T& key) const
    {
        Node* current = nullptr;
        current = root_;
        bool find = false;

        while (current != nullptr && find == false)
        {
            if (key == current->key_)
            {
                find = true;
            }
            else if (key < current->key_ )
            {
                current = current->left_;
            }
            else
            {
                current = current->right_;
            }
        }
        
        if (find)
        {
            return current;
        }
        else
        {
            return nullptr;
        }
    }
    
    Node* find_next(const T& key) const
    {
        Node* current = iterativeSearchNode(key);
        Node* nextNode = nullptr;
        
        if (current == nullptr)
        {
            return nullptr;
        }

        if (current->right_ != nullptr)
        {
            return find_min(current->right_);
        }
        
        nextNode = current->p_;

        while (nextNode != nullptr && current == nextNode->right_)
        {
            current = nextNode;
            nextNode = nextNode->p_;
        }
        return nextNode;
    }
    
    Node* find_min(Node* node) const
    {
        if (root_ == nullptr)
        {
            return nullptr;
        }
        
        while (node->left_ != nullptr)
        {
            node = node->left_;
        }
        
        return node;
    }
    int lessThenSubtree(Node* node, const T& value) const
    {
        if (node == nullptr)
        {
            return 0;
        }
        
        if (node->key_ < value)
        {
            return (1 + lessThenSubtree(node->left_, value) + lessThenSubtree(node->right_, value));
        }
        else
        {
            return (lessThenSubtree(node->left_, value) + lessThenSubtree(node->right_, value));
        }
    }

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
   
    // Рекурсивная функция для организации вывода узлов дерева
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
