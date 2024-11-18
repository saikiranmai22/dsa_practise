#include <iostream>
#include <cmath>
using namespace std;

int karatsuba(int x, int y) {
    // Base case for recursion
    if (x < 10 || y < 10)
        return x * y;

    int n = max(to_string(x).size(), to_string(y).size());
    int half = n / 2;

    int power = pow(10, half);

    int a = x / power;
    int b = x % power;
    int c = y / power;
    int d = y % power;

    // Recursively calculate the three products
    int ac = karatsuba(a, c);
    int bd = karatsuba(b, d);
    int ab_cd = karatsuba(a + b, c + d);

    // Combine the three products
    return ac * pow(10, 2 * half) + (ab_cd - ac - bd) * power + bd;
}

int main() {
    int x = 1234, y = 5678;
    cout << "Product of " << x << " and " << y << " is: " << karatsuba(x, y) << endl;
    return 0;
}
