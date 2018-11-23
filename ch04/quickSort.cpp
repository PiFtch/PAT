#include <iostream>
using namespace std;

int Partition(int A[], int left, int right) {
    int mid = A[left];
    while (left < right) {
        while (left < right && A[right] >= mid)
            right--;
        A[left] = A[right];
        while (left < right && A[left] < mid)
            left++;
        A[right] = A[left];
    }
    A[left] = mid;
    return left;
}

void QuickSort(int A[], int left, int right) {
    if (left < right) {
        int pos = Partition(A, left, right);
        QuickSort(A, left, pos-1);
        QuickSort(A, pos+1, right);
    }
}

int main() {
    int array[] = {3,6,23,4,6,1,3,2,2,90};
    // mergeSort(array, 0, sizeof(array)/sizeof(int));
    // mergeSort2(array, sizeof(array)/sizeof(int));
    QuickSort(array, 0, sizeof(array)/sizeof(int)-1);
    for (int i = 0; i < sizeof(array)/sizeof(int); i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
}

