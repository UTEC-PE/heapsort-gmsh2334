#include <iostream>
#include <random>
#include <cassert>
#include <cstring>
#include <iterator>
#include <vector>

using namespace std;

#define MIN 100
#define MAX 500

mt19937 rng;

int generateRandomInt(int min, int max);
void printArray(int *array, size_t size);
void heapsort(int* array, size_t size);
bool validate(const int* array, size_t size);

int main(int argc, char *argv[]) {
    rng.seed(random_device()());
    cout << "===========================================================" << endl;
    cout << "\tHeapsort Practice" << endl;
    cout << "===========================================================" << endl << endl;

    const int numberOfElements = generateRandomInt(MIN, MAX);
    auto *numbers = new int[numberOfElements];
    for (int i = 0; i < numberOfElements; i++) {
        numbers[i] = generateRandomInt(0, 100);
    }

    printArray(numbers, (size_t) numberOfElements);
    heapsort(numbers, (size_t) numberOfElements);
    printArray(numbers, (size_t) numberOfElements);
    assert(validate(numbers, (size_t) numberOfElements) && "The sort is not ordering all the elements");
    cout<<"Presione una tecla...";
    cin.get();
    return EXIT_SUCCESS;
}

int generateRandomInt(int min, int max) {
    uniform_int_distribution<mt19937::result_type> distribution(static_cast<unsigned int>(min),
                                                                static_cast<unsigned int>(max));
    return distribution(rng);
}


void printArray(int *array, size_t size) {
    int a=size;
    for (int i = 0; i < a; i++)
        cout << array[i] << " ";
    cout << "\n\n";
}




void heap(int* array, size_t i, size_t delim)
{
    size_t left=2*i+1, right=2*i+2;

    if (right >= delim){
        return;}

    else if ((array[left] > array[right]) && (array[left] > array[i])) {
        swap(array[i], array[left]);
        heap(array, left, delim);
    }

    else if(array[right] > array[i]) {
        swap(array[i], array[right]);
        heap(array, right, delim);
    }
}

void heapsort(int* array, size_t size) {

    for (int i=(size/2)-1; i>=0; --i){
        heap(array, static_cast<size_t>(i), size - 1);
    }

    for (int i=size-1; i>0; --i) {
        swap(array[i], array[0]);
        heap(array, 0, static_cast<size_t>(i));
    }

    // TODO
}

bool validate(const int* array, size_t size) {
    int a=size;
    for (int i = 0; i < a - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}