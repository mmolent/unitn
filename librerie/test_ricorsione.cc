#include <iostream>

// Function to print an array
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Test case 1: Empty tree
    Albero tree1 = nullptr;
    int dim1 = 0;
    int* result1 = alloca_dispari(tree1, dim1);
    std::cout << "Test case 1: ";
    printArray(result1, dim1);
    delete[] result1;

    // Test case 2: Tree with only even values
    Albero tree2 = new Nodo(2);
    tree2->left = new Nodo(4);
    tree2->right = new Nodo(6);
    int dim2 = 0;
    int* result2 = alloca_dispari(tree2, dim2);
    std::cout << "Test case 2: ";
    printArray(result2, dim2);
    delete[] result2;

    // Test case 3: Tree with only odd values
    Albero tree3 = new Nodo(1);
    tree3->left = new Nodo(3);
    tree3->right = new Nodo(5);
    int dim3 = 0;
    int* result3 = alloca_dispari(tree3, dim3);
    std::cout << "Test case 3: ";
    printArray(result3, dim3);
    delete[] result3;

    // Test case 4: Tree with both odd and even values
    Albero tree4 = new Nodo(1);
    tree4->left = new Nodo(2);
    tree4->right = new Nodo(3);
    tree4->left->left = new Nodo(4);
    tree4->left->right = new Nodo(5);
    tree4->right->left = new Nodo(6);
    tree4->right->right = new Nodo(7);
    int dim4 = 0;
    int* result4 = alloca_dispari(tree4, dim4);
    std::cout << "Test case 4: ";
    printArray(result4, dim4);
    delete[] result4;

    return 0;
}