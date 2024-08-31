#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool is_prime(unsigned long long n)
{
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (unsigned long long i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

class PrimeGenerator {
private:
    unsigned long long current;
    vector<unsigned long long> primes;

public:
    PrimeGenerator() : current(1) {}

    unsigned long long next_prime() 
    {
        while (true)
        {
            ++current;
            if (is_prime(current))
            {
                primes.push_back(current);
                return current;
            }
        }
    }

    unsigned long long sum_primes_up_to(unsigned long long limit)
    {
        unsigned long long sum = 0;
        for (int i = 0;i < primes.size();i++)
        {
            if (primes[i] > limit)
                return (sum);
            sum += primes[i];
        }
        while (true)
        {
            unsigned long long p = next_prime();
            if (p > limit) break;
            sum += p;
        }
        return sum;
    }
};

int main() {
    int num_cases;
    cin >> num_cases;

    PrimeGenerator pg;

    while (num_cases--)
    {
        unsigned long long upper_limit;
        cin >> upper_limit;
        cout << pg.sum_primes_up_to(upper_limit) << '\n';
    }

    return 0;
}
