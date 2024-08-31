#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

const unsigned long long MAX_VALUE = 1000000000000ULL;
const unsigned long long MAX_SQRT = sqrt(MAX_VALUE) + 1;

vector<bool> sieve(MAX_SQRT + 1, true);
vector<unsigned long long> primes;

void compute_primes()
{
    sieve[0] = sieve[1] = false;
    for (unsigned long long i = 2; i * i <= MAX_SQRT; ++i)
    {
        if (sieve[i])
        {
            for (unsigned long long j = i * i; j <= MAX_SQRT; j += i)
                sieve[j] = false;
        }
    }
    for (unsigned long long i = 2; i <= MAX_SQRT; ++i)
    {
        if (sieve[i])
            primes.push_back(i);
    }
}

bool is_t_prime(unsigned long long n)
{
    if (n < 4) return false;

    unsigned long long root = sqrt(n);
    if (root * root != n) return false;
    return sieve[root];
}

int main()
{
    compute_primes();

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        unsigned long long tmp;
        cin >> tmp;
        cout << (is_t_prime(tmp) ? "YES\n" : "NO\n");
    }
}
