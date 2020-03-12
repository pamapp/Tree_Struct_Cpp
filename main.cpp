#include "binarySearchTree.hpp"
#include <iostream>

using namespace std;
int main()
{
    // создание пустого дерева
    BinarySearchTree <int> intTree;

    // добавление узлов
    intTree.insert(10);
    intTree.insert(3);
    intTree.insert(20);
    intTree.insert(15);
    intTree.insert(30);
    intTree.insert(2);
    intTree.insert(5);
    intTree.insert(32);
    intTree.insert(22);

    
//    Вывод узлов дерева в выходной поток
    cout << "Tree before modifications:" << endl;
    intTree.print(cout);
    cout << endl;

    cout << "------------------------------------" << endl << endl;
    
//    Oпределение высоты и количества узлов дерева
    cout << "Tree height: " << intTree.getHeight() << endl;
    cout << "Tree count : " << intTree.getCount () << endl;
    cout << endl;

    cout << "------------------------------------" << endl << endl;

//    Oбход узлов и вывод их в порядке возрастания
    cout << "Inorder walk result: " << endl;
    intTree.inorderWalkPrint();
    cout << '\n' << endl;

    cout << "------------------------------------" << endl << endl;
    
//    Поиск в дереве по ключу
    cout << "Search in tree:" << endl;
    
    int keyFound = 0;
    int testMass[6] = {10, 15, 22, 2, 23, 1};
    
    for (int i = 0; i < 6; ++i)
    {
        keyFound = intTree.iterativeSearch(testMass[i]);
        cout << "Key " << testMass[i] << (keyFound ? " found successfully" : " not found") << " in the tree" << endl;
    }
    cout << endl;
    
    cout << "------------------------------------" << endl << endl;
    
//   Удаление элементов
    cout << "Delete elements from tree:" << endl;
    
    int testMass1[3] = {2, 20, 50};
    
    for (int i = 0; i < 3; ++i)
    {
        intTree.deleteKey(testMass1[i]);
        cout << "Modified tree after key " << testMass1[i] << " delete: " << endl;
        intTree.print(cout);
        cout << endl;
    }
    
    cout << "------------------------------------" << endl << endl;
    
//  Количество элементов меньших чем ...
    cout << "Less keys:" << endl;
    
    int testMass2[5] = {-6, 1, 0, 32, 90};
    
    for (int i = 0; i < 5; ++i)
    {
        cout << "Number of keys that less than " << testMass2[i] << ": " << intTree.lessThen(testMass2[i]);
        cout << endl;
    }
    
    cout << endl << "------------------------------------" << endl;
    return 0;
}
