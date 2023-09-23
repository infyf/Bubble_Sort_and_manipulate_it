#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int n; // кількість елементів масиву

// Функція для введення кількості елементів масиву
int control() {
    while (true) {
        cout << "Enter the number of elements of the array: ";
        cin >> n;
        if (cin.get() == '\n' && n > 0) break;
        else {
            cout << "An integer is expected!";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return n;
}

// Функція для обміну значень двох змінних
void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// Функція для сортування масиву бульбашковим методом
void bubbleSort(int* arr) {
    for (int j = n - 1; j >= 0; j--) {
        for (int i = 0; i < j; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}

// Функція для генерації масиву з випадковими числами
void genRandom(int* arr) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 2001 - 1000;
    }
}

// Функція для генерації масиву відсортованого за спаданням
void genSpad(int* arr) {
    for (int i = 0; i < n; i++) {
        arr[i] = 1000 - i;
    }
}

// Функція для генерації масиву з однаковими значеннями і розташовані в довільном порядку 
void duplicate_value(int* arr, int value) {
    for (int i = 0; i < n; i++) {
        arr[i] = value;
    }
}

// Функція для генерації масиву з двома однаковими значеннями
void genTheSameValue(int* arr) {
    duplicate_value(arr, rand() % 2001 - 1000);
    int index1 = rand() % n;
    int index2;
    do {
        index2 = rand() % n;
    } while (index2 == index1);

    arr[index2] = arr[index1];
}

int main() {
    n = control();

    int* randomArr = new int[n];
    genRandom(randomArr);

    int* descendArr = new int[n];
    genSpad(descendArr);

    int uniformValue = rand() % 2001 - 1000;
    int* uniformArr = new int[n];
    duplicate_value(uniformArr, uniformValue);

    int* duplicateArr = new int[n + 2];
    genTheSameValue(duplicateArr);

    clock_t start_time1 = clock();
    bubbleSort(randomArr);
    clock_t end_time1 = clock();

    clock_t start_time2 = clock();
    bubbleSort(descendArr);
    clock_t end_time2 = clock();

    clock_t start_time3 = clock();
    bubbleSort(uniformArr);
    clock_t end_time3 = clock();

    clock_t start_time4 = clock();
    bubbleSort(duplicateArr);
    clock_t end_time4 = clock();

    cout << "Bubble sort for random array: " << (end_time1 - start_time1) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
    cout << "Bubble sort for spad: " << (end_time2 - start_time2) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
    cout << "Bubble sort for 2 value: " << (end_time3 - start_time3) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
    cout << "Bubble sort for array with all: " << (end_time4 - start_time4) * 1000 / CLOCKS_PER_SEC << "ms" << endl;

    delete[] randomArr;
    delete[] descendArr;
    delete[] uniformArr;
    delete[] duplicateArr;

    system("pause");
    return 0;
} 
