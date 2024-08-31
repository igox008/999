#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1000000007;

unsigned long long mod_exp(unsigned long long base, unsigned long long exp, unsigned long long mod)
{
    unsigned long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

void preprocess(const vector<int>& array, vector<unsigned long long>& prefix_product, int n)
{
    prefix_product[0] = array[0] % MOD;
    for (int i = 1; i < n; ++i)
        prefix_product[i] = (prefix_product[i - 1] * array[i]) % MOD;
}

int main()
{
    int N, Q;cin >> N >> Q;
    
    vector<int> array(N);
    for (int i = 0; i < N; ++i)cin >> array[i];
    
    vector<unsigned long long> prefix_product(N);
    preprocess(array, prefix_product, N);
    
    while (Q--)
    {
        int L, R;
        cin >> L >> R;
        L--;
        R--;
        
        unsigned long long result = prefix_product[R];
        if (L > 0)
        {
            unsigned long long inverse_prefix = mod_exp(prefix_product[L - 1], MOD - 2, MOD);
            result = (result * inverse_prefix) % MOD;
        }
        cout << result << '\n';
    }
}
