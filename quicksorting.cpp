#include<iostream>

using namespace std;

int Partition(int vector1[], int start, int end) {
    int startb = start, pivot = vector1[start], index;

    for (index = start + 1; index <= end; index++) {
        if (pivot > vector1[index]) {
            vector1[startb] = vector1[index];
            vector1[index] = vector1[startb + 1];
            vector1[startb + 1] = pivot;
            startb = startb + 1;
        }
    }
    return startb;
}

void print(int vector1[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "[" << vector1[i] << "]";
    }
}

void QuickSort(int vector1[], int start, int end) {
    if (start < end) {
        int p = Partition(vector1, start, end);
        QuickSort(vector1, start, p - 1);
        QuickSort(vector1, p + 1, end);
    }

}

int main() {
    int vector1[] = {55, 44, 2, 1, 65};
    int start = 0, end = 4;

    QuickSort(vector1, start, end);

    print(vector1, end);

    return 0;
}
