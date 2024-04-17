#define _CRTDBG_MAP_ALLOC
typedef bool(*FunctionPointer)();

#include <iostream>
#include "BSTree.h"
#include <string>
#include <crtdbg.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;


int compared_int_arr[] = { 6,4,2,5,9,8,12 };
string compared_str_arr[] = { "F", "B", "A", "D", "G", "I" };

const int NUM_SIZE = 7;
const int NUM_NAMES = 6;

template <typename T>
void Display(T data) {
    cout << data << " ";
}

BSTree<int> ReturnIntTree()
{
    BSTree<int> temptree;
    
    temptree.Insert(6);
    temptree.Insert(4);
    temptree.Insert(9);
    temptree.Insert(5);
    temptree.Insert(2);
    temptree.Insert(8);
    temptree.Insert(12);
    return temptree;
}

BSTree<string> ReturnStrTree()
{
    BSTree<string> temptree;

    temptree.Insert("F");
    temptree.Insert("B");
    temptree.Insert("G");
    temptree.Insert("A");
    temptree.Insert("D");
    temptree.Insert("I");
    return temptree;
}

bool test_default_ctor();
bool test_default_ctor_complex();
bool test_copy_ctor();
bool test_copy_ctor_complex();
bool test_move_ctor();
bool test_move_ctor_complex();
bool test_op_equal();
bool test_op_equal_complex();
bool test_move_op_equal();
bool test_move_op_equal_complex();
bool test_tree_insert();
bool test_tree_insert_complex();
bool test_tree_size();
bool test_tree_size_complex();
bool test_tree_height();
bool test_tree_height_complex();
bool test_purge();
bool test_purge_complex();
bool test_delete();
bool test_delete_complex();
bool test_delete_exception();
bool test_delete_exception_complex();
bool test_tree_tranversal_display();
bool test_tree_tranversal_display_complex();

FunctionPointer test_functions[] = { test_default_ctor, test_default_ctor_complex, test_copy_ctor, test_copy_ctor_complex,
test_move_ctor, test_move_ctor_complex, test_op_equal, test_op_equal_complex, test_move_op_equal, test_move_op_equal_complex,
test_tree_insert, test_tree_insert_complex, test_tree_size, test_tree_size_complex, test_tree_height, test_tree_height_complex,
test_purge, test_purge_complex, test_delete, test_delete_complex, test_delete_exception, test_delete_exception_complex,
test_tree_tranversal_display, test_tree_tranversal_display_complex };

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // Run the test functions
    for (FunctionPointer func : test_functions)
    {
        if (func())
        {
            cout << "passed\n";
        }
        else
        {
            cout << "***** failed *****\n";
        }
    }

    cout << "\nPress Any Key to Exit";
    cin.get();
}

bool test_default_ctor()
{
    bool pass = true;
    BSTree<int> object;

    if (object.GetRoot() != nullptr || object.GetTreeSize() != 1 || object.GetArrIncr() != 0)
        pass = false;

    cout << "Default Ctor Test ";
    return pass;
}

bool test_default_ctor_complex()
{
    bool pass = true;
    BSTree<string> object;

    if (object.GetRoot() != nullptr || object.GetTreeSize() != 1 || object.GetArrIncr() != 0)
        pass = false;

    cout << "Default Ctor Test Complex ";
    return pass;
}

bool test_copy_ctor()
{
    bool pass = true;
    int arr[7];
    BSTree<int> object;
    
    object.Insert(6);
    object.Insert(4);
    object.Insert(9);
    object.Insert(5);
    object.Insert(2);
    object.Insert(8);
    object.Insert(12);

    BSTree<int> object2(object);
    object2.PreOrderTreeArray(arr);

    for (int i = 0; i < NUM_SIZE; i++) {
        if (arr[i] != compared_int_arr[i])
            pass = false;
    }

    cout << "Copy Ctor Test ";
    return pass;
}

bool test_copy_ctor_complex()
{
    bool pass = true;
    string arr[6];
    BSTree<string> object;

    object.Insert("F");
    object.Insert("B");
    object.Insert("G");
    object.Insert("A");
    object.Insert("D");
    object.Insert("I");

    BSTree<string> object2(object);
    object2.PreOrderTreeArray(arr);

    for (int i = 0; i < NUM_NAMES; i++) {
        if (arr[i] != compared_str_arr[i])
            pass = false;
    }

    cout << "Copy Ctor Test Complex ";
    return pass;
}

bool test_move_ctor()
{
    bool pass = true;
    int arr[7];
    BSTree<int> object(ReturnIntTree());

    object.PreOrderTreeArray(arr);

    for (int i = 0; i < NUM_SIZE; i++) {
        if (arr[i] != compared_int_arr[i])
            pass = false;
    }

    cout << "Move Ctor Test ";
    return pass;
}

bool test_move_ctor_complex()
{
    bool pass = true;
    string arr[7];
    BSTree<string> object(ReturnStrTree());

    object.PreOrderTreeArray(arr);

    for (int i = 0; i < NUM_SIZE; i++) {
        if (arr[i] != compared_str_arr[i])
            pass = false;
    }

    cout << "Move Ctor Test Complex ";
    return pass;
}

bool test_op_equal()
{
    bool pass = true;
    int arr[7];
    BSTree<int> object;

    object.Insert(6);
    object.Insert(4);
    object.Insert(9);
    object.Insert(5);
    object.Insert(2);
    object.Insert(8);
    object.Insert(12);

    BSTree<int> object2;
    object2 = object;
    object2.PreOrderTreeArray(arr);

    for (int i = 0; i < NUM_SIZE; i++) {
        if (arr[i] != compared_int_arr[i])
            pass = false;
    }

    cout << "Op Equals Test ";
    return pass;
}

bool test_op_equal_complex()
{
    bool pass = true;
    string arr[6];
    BSTree<string> object;

    object.Insert("F");
    object.Insert("B");
    object.Insert("G");
    object.Insert("A");
    object.Insert("D");
    object.Insert("I");

    BSTree<string> object2;
    object2 = object;
    object2.PreOrderTreeArray(arr);

    for (int i = 0; i < NUM_NAMES; i++) {
        if (arr[i] != compared_str_arr[i])
            pass = false;
    }

    cout << "Op Equals Test Complex ";
    return pass;
}

bool test_move_op_equal()
{
    bool pass = true;
    int arr[7];
    BSTree<int> object;
    object = ReturnIntTree();

    object.PreOrderTreeArray(arr);

    for (int i = 0; i < NUM_SIZE; i++) {
        if (arr[i] != compared_int_arr[i])
            pass = false;
    }

    cout << "Move Op Equal Test ";
    return pass;
}

bool test_move_op_equal_complex()
{
    bool pass = true;
    string arr[7];
    BSTree<string> object;
    object = ReturnStrTree();

    object.PreOrderTreeArray(arr);

    for (int i = 0; i < NUM_SIZE; i++) {
        if (arr[i] != compared_str_arr[i])
            pass = false;
    }

    cout << "Move Op Equal Test Complex ";
    return pass;
}

bool test_tree_insert()
{
    bool pass = true;
    int arr[7];
    BSTree<int> object;

    object.Insert(6);
    object.Insert(4);
    object.Insert(9);
    object.Insert(5);
    object.Insert(2);
    object.Insert(8);
    object.Insert(12);

    object.PreOrderTreeArray(arr);

    for (int i = 0; i < NUM_SIZE; i++) {
        if (arr[i] != compared_int_arr[i])
            pass = false;
    }

    cout << "Tree Insert Test ";
    return pass;
}

bool test_tree_insert_complex()
{
    bool pass = true;
    string arr[6];
    BSTree<string> object;

    object.Insert("F");
    object.Insert("B");
    object.Insert("G");
    object.Insert("A");
    object.Insert("D");
    object.Insert("I");

    object.PreOrderTreeArray(arr);

    for (int i = 0; i < NUM_NAMES; i++) {
        if (arr[i] != compared_str_arr[i])
            pass = false;
    }

    cout << "Tree Insert Test Complex ";
    return pass;
}

bool test_tree_size()
{
    bool pass = true;
    BSTree<int> object(ReturnIntTree());

    if (object.GetTreeSize() != 7)
        pass = false;

    cout << "Tree Size Test ";
    return pass;
}

bool test_tree_size_complex()
{
    bool pass = true;
    BSTree<string> object(ReturnStrTree());

    if (object.GetTreeSize() != 6)
        pass = false;

    cout << "Tree Size Test Complex ";
    return pass;
}

bool test_tree_height()
{
    bool pass = true;
    BSTree<int> object(ReturnIntTree());

    if (object.Height(object.GetRoot()) != 3)
        pass = false;

    cout << "Tree Height Test ";
    return pass;
}

bool test_tree_height_complex()
{
    bool pass = true;
    BSTree<string> object(ReturnStrTree());

    if (object.Height(object.GetRoot()) != 3)
        pass = false;

    cout << "Tree Height Test Complex ";
    return pass;
}

bool test_purge()
{
    bool pass = true;
    BSTree<int> object(ReturnIntTree());

    object.Purge(object.GetRoot());

    if (object.GetRoot() != nullptr)
        pass = false;

    cout << "Purge Test ";
    return pass;
}

bool test_purge_complex()
{
    bool pass = true;
    BSTree<string> object(ReturnStrTree());

    object.Purge(object.GetRoot());

    if (object.GetRoot() != nullptr)
        pass = false;

    cout << "Purge Test Complex ";
    return pass;
}

bool test_delete()
{
    bool pass = true;
    int arr[6];
    BSTree<int> object(ReturnIntTree());

    object.Delete(6);
    object.PreOrderTreeArray(arr);


    for (int i = 0; i < 6; i++) {
        if (arr[i] == 6)
            pass = false;
    }

    cout << "Tree Delete Test ";
    return pass;
}

bool test_delete_complex()
{
    bool pass = true;
    string arr[6];
    BSTree<string> object(ReturnStrTree());

    object.Delete("A");
    object.PreOrderTreeArray(arr);


    for (int i = 0; i < 6; i++) {
        if (arr[i] == "A")
            pass = false;
    }

    cout << "Tree Delete Test Complex ";
    return pass;
}

bool test_delete_exception()
{
    bool pass = false;
    BSTree<int> object;

    try
    {
        object.Delete(7);
    }
    catch (Exception& except)
    {
        pass = true;
    }

    cout << "Test Delete Exception ";
    return pass;
}

bool test_delete_exception_complex()
{
    bool pass = false;
    BSTree<string> object;

    try
    {
        object.Delete("A");
    }
    catch (Exception& except)
    {
        pass = true;
    }

    cout << "Test Delete Exception Complex ";
    return pass;
}

bool test_tree_tranversal_display()
{
    bool pass = true;
    BSTree<int> object(ReturnIntTree());

    cout << "InOrder Tranversal Display: ";
    object.InOrder(Display);
    cout << endl;
    cout << "PreOrder Tranversal Display: ";
    object.PreOrder(Display);
    cout << endl;
    cout << "PostOrder Tranversal Display: ";
    object.PostOrder(Display);
    cout << endl;
    cout << "BreadthFirst Tranversal Display: ";
    object.BreadthFirst(Display);
    cout << endl;

    cout << "Tree Transversal Function Pointer Test ";
    return pass;
}

bool test_tree_tranversal_display_complex()
{
    bool pass = true;
    BSTree<string> object(ReturnStrTree());

    cout << "InOrder Tranversal Display: ";
    object.InOrder(Display);
    cout << endl;
    cout << "PreOrder Tranversal Display: ";
    object.PreOrder(Display);
    cout << endl;
    cout << "PostOrder Tranversal Display: ";
    object.PostOrder(Display);
    cout << endl;
    cout << "BreadthFirst Tranversal Display: ";
    object.BreadthFirst(Display);
    cout << endl;

    cout << "Tree Transversal Function Pointer Test Complex ";
    return pass;
}
