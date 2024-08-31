#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    vector<int> v(n);
    vector<unsigned long long> prefixSum(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        prefixSum[i + 1] = prefixSum[i] + v[i];
    }
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << prefixSum[b] - prefixSum[a - 1] << '\n';
    }

    return 0;
}
