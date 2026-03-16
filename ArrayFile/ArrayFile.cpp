#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

int ConsoleInputSizeArray(const int sizeMax) {
    int size = 0;
    do {
        cout << " Enter array size (0 < n <= " << sizeMax << "): ";
        cin >> size;
    } while (size <= 0 || size > sizeMax);
    return size;
}

void Task1(int n, double* A) {
    cout << "\n--- Task 1 ---" << endl;
    double* B = new double[n];
    int countB = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] > 0) B[countB++] = A[i];
    }

    if (countB == 0) {
        cout << "No positive elements." << endl;
    }
    else {
        cout << "Result Array B: ";
        for (int i = 0; i < countB; i++) cout << B[i] << " ";

        ofstream fout("Task1_Output.txt");
        fout << countB << endl;
        for (int i = 0; i < countB; i++) fout << B[i] << " ";
        fout.close();
        cout << "\nSaved to Task1_Output.txt" << endl;
    }
    delete[] B;
}

void Task2(int n, double* A) {
    cout << "\n--- Task 2 ---" << endl;
    double T;
    cout << "Enter threshold T: ";
    cin >> T;

    double* pA = A;
    double* pEnd = A + n;
    double* pStart = nullptr;

    for (double* p = pA; p < pEnd; p++) {
        if (*p > T) {
            pStart = p;
            break;
        }
    }

    if (pStart == nullptr) {
        cout << "No elements > T found." << endl;
        return;
    }

    double maxVal = -1e9;
    double* pLastMax = nullptr;
    bool found = false;

    for (double* p = pStart; p < pEnd; p++) {
        if (*p > 0) {
            if (!found || *p >= maxVal) {
                maxVal = *p;
                pLastMax = p;
                found = true;
            }
        }
    }

    if (found) {
        int lastMaxIdx = pLastMax - A;
        cout << "Last max positive index: " << lastMaxIdx << " (Value: " << maxVal << ")" << endl;
    }
    else {
        cout << "No positive elements found after T." << endl;
    }
}

void Task3(int n, double* A) {
    cout << "\n--- Task 3 ---" << endl;
    double a, b;
    cout << "Enter a: "; cin >> a;
    cout << "Enter b: "; cin >> b;

    double sum_lt_a = 0.0;
    double prod_gt_b = 1.0;
    bool found_prod = false;

    double max_in = 0.0, min_in = 0.0;
    bool found_in = false;

    for (int i = 0; i < n; i++) {
        if (A[i] < a) {
            sum_lt_a += A[i];
        }
        if (A[i] > b) {
            prod_gt_b *= A[i];
            found_prod = true;
        }
        if (A[i] >= a && A[i] <= b) {
            if (!found_in) {
                max_in = A[i];
                min_in = A[i];
                found_in = true;
            }
            else {
                if (A[i] > max_in) max_in = A[i];
                if (A[i] < min_in) min_in = A[i];
            }
        }
    }

    cout << "Sum of elements < " << a << " = " << sum_lt_a << endl;

    if (found_prod) cout << "Product of elements > " << b << " = " << prod_gt_b << endl;
    else cout << "No elements > " << b << " found for product." << endl;

    if (found_in) {
        cout << "Max in range [" << a << ", " << b << "] = " << max_in << endl;
        cout << "Min in range [" << a << ", " << b << "] = " << min_in << endl;
    }
    else {
        cout << "No elements found in range [" << a << ", " << b << "]." << endl;
    }
}

int main() {
    int n = 0;
    double* A = nullptr;
    int choice;

    while (true) {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Input main array A (max 200)\n2. Run Task 1\n3. Run Task 2\n4. Run Task 3\n0. Exit\nChoice: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1:
            if (A) delete[] A;
            n = ConsoleInputSizeArray(200);
            A = new double[n];
            for (int i = 0; i < n; i++) {
                cout << "A[" << i << "] = "; cin >> A[i];
            }
            break;
        case 2:
            if (A) Task1(n, A);
            else cout << "Please input array A first!" << endl;
            break;
        case 3:
            if (A) Task2(n, A);
            else cout << "Please input array A first!" << endl;
            break;
        case 4:
            if (A) Task3(n, A);
            else cout << "Please input array A first!" << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    }
    if (A) delete[] A;
    return 0;
}