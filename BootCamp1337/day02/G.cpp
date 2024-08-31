#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++)cin >> arr[i];
    
    int q;cin >> q;

    for (int i = 0; i < q; i++)
    {
        int k;cin >> k;

        auto lwr = lower_bound(arr.begin(), arr.end(), k);
        auto upr = upper_bound(arr.begin(), arr.end(), k);
        
        int l = (lwr != arr.end()) ? (lwr - arr.begin()) : n;
        int u = (upr != arr.end()) ? (upr - arr.begin()) : n;

        cout << l << " " << u << '\n';
    }
}
