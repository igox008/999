#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(unsigned long long X)
{
    if (X <= 1) return false;
    if (X <= 3) return true;
    if (X % 2 == 0 || X % 3 == 0) return false;
    
    for (unsigned long long i = 5; i * i <= X; i += 6)
        if (X % i == 0 || X % (i + 2) == 0) return false;
    return true;
}

int main() {
    unsigned long long X;
    cin >> X;

    cout << ((is_prime(X)) ? "\"Prime\"\n" : "\"Not Prime\"\n");

    return 0;
}
