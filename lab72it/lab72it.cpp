#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>

void fillMatrix(int* matrix, int k, int n, int minVal, int maxVal) {
    srand(time(0));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            *(matrix + i * n + j) = minVal + rand() % (maxVal - minVal + 1);
        }
    }
}

void printMatrix(const int* matrix, int k, int n) {
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << *(matrix + i * n + j) << "\t";
        }
        std::cout << std::endl;
    }
}

int findMinOfMaxInEvenRows(const int* matrix, int k, int n) {
    int minOfMax = INT_MAX;

    for (int i = 0; i < k; i += 2) {
        int maxInRow = *(matrix + i * n); // Початкове значення максимуму — перший елемент парного рядка

        for (int j = 1; j < n; ++j) {
            if (*(matrix + i * n + j) > maxInRow) {
                maxInRow = *(matrix + i * n + j);
            }
        }

        if (maxInRow < minOfMax) {
            minOfMax = maxInRow;
        }
    }

    return minOfMax;
}

int main() {
    const int K = 4;
    const int N = 5;
    int matrix[K][N];

    fillMatrix(&matrix[0][0], K, N, -10, 50);
    std::cout << "Матриця:\n";
    printMatrix(&matrix[0][0], K, N);

    int result = findMinOfMaxInEvenRows(&matrix[0][0], K, N);
    std::cout << "Найменший серед максимальних елементів у парних рядках: " << result << std::endl;

    return 0;
}