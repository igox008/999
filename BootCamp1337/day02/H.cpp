#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    unsigned long long n;
    cin >> n;
    unsigned long long k = sqrt(2 * n + 0.25) - 0.5;
    cout << k << '\n';
}
