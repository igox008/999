#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> sieve_up_to(unsigned long long limit)
{
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (unsigned long long p = 2; p * p <= limit; ++p)
    {
        if (is_prime[p])
        {
            for (unsigned long long multiple = p * p; multiple <= limit; multiple += p)
                is_prime[multiple] = false;
        }
    }

    return (is_prime);
}

void print_primes_in_range(unsigned long long m, unsigned long long n)
{
    if (m < 2) m = 2;

    unsigned long long limit = sqrt(n);
    vector<bool> small_primes_sieve = sieve_up_to(limit);
    vector<unsigned long long> small_primes;

    for (unsigned long long p = 2; p <= limit; ++p)
    {
        if (small_primes_sieve[p])
            small_primes.push_back(p);
    }

    vector<bool> range_sieve(n - m + 1, true);

    for (unsigned long long p : small_primes)
    {
        unsigned long long start = max(p * p, (m + p - 1) / p * p);
        for (unsigned long long j = start; j <= n; j += p)
            range_sieve[j - m] = false;
    }

    bool found_prime = false;
    for (unsigned long long i = 0; i <= n - m; ++i)
    {
        if (range_sieve[i])
        {
            cout << (m + i) << '\n';
            found_prime = true;
        }
    }

    if (!found_prime)
        cout << "Absent" << '\n';
}

int main()
{
    unsigned long long m, n;
    cin >> m >> n;

    print_primes_in_range(m, n);

}
