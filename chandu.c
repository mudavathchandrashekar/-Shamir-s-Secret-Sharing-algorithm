#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert a string with a given base to an integer
long long decodeValue(const char *value, int base) {
    return strtoll(value, NULL, base);
}

// Function to perform Lagrange interpolation to find the constant term 'c'
double lagrangeInterpolation(int n, int x[], long long y[]) {
    double c = 0.0;

    // Iterate over each point
    for (int i = 0; i < n; i++) {
        double term = y[i];

        // Calculate the product for the Lagrange basis polynomial L_i(x)
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term *= (0.0 - x[j]) / (x[i] - x[j]);  // Since we need to evaluate at x = 0
            }
        }

        // Add the term to the constant term
        c += term;
    }

    return c;
}

int main() {
    // First Test Case
    int n1 = 4;  // Number of points
    int k1 = 3;  // Minimum number of points required to solve the polynomial (k = m + 1)
    int x1[] = {1, 2, 3, 6};
    char *bases1[] = {"10", "2", "10", "4"};
    char *values1[] = {"4", "111", "12", "213"};
    long long y1[n1];

    // Decode y values for the first test case
    for (int i = 0; i < n1; i++) {
        y1[i] = decodeValue(values1[i], atoi(bases1[i]));
    }

    // Find the constant term 'c' using Lagrange interpolation for the first test case
    double secret1 = lagrangeInterpolation(k1, x1, y1);
    printf("Secret for first test case: %lld\n", (long long)round(secret1));

    // Second Test Case
    int n2 = 9;  // Number of points
    int k2 = 6;  // Minimum number of points required to solve the polynomial (k = m + 1)
    int x2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    char *bases2[] = {"10", "16", "12", "11", "16", "10", "14", "9", "8"};
    char *values2[] = {"28735619723837", "1A228867F0CA", "32811A4AA0B7B", "917978721331A", 
                       "1A22886782E1", "28735619654702", "71AB5070CC4B", "122662581541670", 
                       "642121030037605"};
    long long y2[n2];

    // Decode y values for the second test case
    for (int i = 0; i < n2; i++) {
        y2[i] = decodeValue(values2[i], atoi(bases2[i]));
    }

    // Find the constant term 'c' using Lagrange interpolation for the second test case
    double secret2 = lagrangeInterpolation(k2, x2, y2);
    printf("Secret for second test case: %lld\n", (long long)round(secret2));

    return 0;
}
