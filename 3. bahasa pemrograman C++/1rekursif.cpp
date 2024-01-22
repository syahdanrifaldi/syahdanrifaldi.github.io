#include <iostream>

int recursiveFactorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * recursiveFactorial(n - 1);
}

int main() {
    int result = recursiveFactorial(5);
    std::cout << "Factorial of 5: " << result << std::endl;
    return 0;
}

