// Binary Search
// 1. A->B이므로 Binary Search를 하기 위해 B를 정렬해준다.
// 
#include <iostream>
using namespace std;

// function to Swap
void Swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int partition(int array[], int low, int high) {

    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            Swap(array[i], array[j]);
        }
    }

    // swap pivot with the greater element at i
    Swap(array[i + 1], array[high]);

    // return the partition point
    return (i + 1);
}

// function to Quick Sort
void QSort(int arr[], int left, int right) {




    if (left < right) {

        int pi_Pos = partition(arr, left, right); //pivot position

        QSort(arr, left, pi_Pos - 1);
        QSort(arr, pi_Pos + 1, right);
    }
}

int BSerching(int num) {
    return 1;
}

int main() {
    int Arr[] = { 7, 3, 1, 9, 11, 4, 15, 2 };
    int Brr[] = { 10, 6, 4, 7, 14, 1 };
    int ASize = sizeof(Arr) / sizeof(Arr[0]);
    int BSize = sizeof(Brr) / sizeof(Brr[0]);

    int Result = 0;

    // 퀵정렬
    QSort(Brr, 0, BSize - 1);

    for (int i = 0; i < ASize; i++) {
        Result += BSerching(Arr[i]);
    }

    printf("Result : %d", Result);

}