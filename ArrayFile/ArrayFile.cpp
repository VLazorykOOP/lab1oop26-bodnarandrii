#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <float.h>

using namespace std;

void task1() {
    int n;
    cout << "Enter array size N: ";
    cin >> n;

    int* A = new int[n];
    cout << "Enter array elements: ";
    int positiveCount = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] > 0) positiveCount++;
    }

    if (positiveCount == 0) {
        cout << "No positive elements found.\n";
    }
    else {
        int* B = new int[positiveCount];
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] > 0) {
                B[j++] = A[i];
            }
        }

        cout << "Array B (positive elements): ";
        for (int i = 0; i < positiveCount; i++) {
            cout << B[i] << " ";
        }
        cout << endl;
        delete[] B;
    }
    delete[] A;
}

void task2() {
    int n, T;
    cout << "Enter size N and number T: ";
    cin >> n >> T;

    vector<int> A(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    int lastMaxIdx = -1;
    int maxValue = INT_MIN;
    bool foundT = false;

    int* ptr = A.data();

    for (int i = 0; i < n; i++) {
        if (!foundT) {
            if (*(ptr + i) > T) foundT = true;
        }

        if (foundT && *(ptr + i) > 0) {
            if (*(ptr + i) >= maxValue) {
                maxValue = *(ptr + i);
                lastMaxIdx = i;
            }
        }
    }

    if (lastMaxIdx != -1)
        cout << "Index of the last maximum positive element: " << lastMaxIdx << endl;
    else
        cout << "No elements matching the criteria were found.\n";
}

void task3() {
    double a, b, X[200];
    int n;
    cout << "Enter a and b: ";
    cin >> a >> b;
    cout << "Enter n (max 200): ";
    cin >> n;

    if (n > 200) n = 200;

    cout << "Enter array elements: ";
    double sumLessA = 0;
    double prodGreaterB = 1;
    bool hasGreaterB = false;
    double maxInRange = -DBL_MAX;
    double minInRange = DBL_MAX;
    bool hasInRange = false;

    for (int i = 0; i < n; i++) {
        cin >> X[i];

        if (X[i] < a) sumLessA += X[i];

        if (X[i] > b) {
            prodGreaterB *= X[i];
            hasGreaterB = true;
        }

        if (X[i] >= a && X[i] <= b) {
            if (X[i] > maxInRange) maxInRange = X[i];
            if (X[i] < minInRange) minInRange = X[i];
            hasInRange = true;
        }
    }

    cout << "Sum of X(i) < a: " << sumLessA << endl;
    cout << "Dobutok of X(i) > b: " << (hasGreaterB ? prodGreaterB : 0) << endl;

    if (hasInRange) {
        cout << "Max in range [a, b]: " << maxInRange << endl;
        cout << "Min in range [a, b]: " << minInRange << endl;
    }
    else {
        cout << "No elements found within the range [a, b].\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n========= MENU =========\n";
        cout << "1. Task 1\n";
        cout << "2. Task 2\n";
        cout << "3. Task 3\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 0: cout << "\n"; break;
        default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}