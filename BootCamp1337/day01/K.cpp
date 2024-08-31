#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin >> n;
    for (int i = 0;i < n;i++)
    {
        vector <int> alice;
        int l; cin >> l;
        vector <int> arr(l);
        for (int j = 0;j < l;j++) cin >> arr[j];
        int y = 0;
        for (;arr.size() > 0;)
        {
            auto min = min_element(arr.begin(), arr.end());
            if (find(alice.begin(), alice.begin(), *min) != alice.end())
                min = max_element(arr.begin(), arr.end());
            alice.push_back(*min);
            arr.erase(min);
            if (arr.size() > 0)
            {
                auto max = max_element(arr.begin(), arr.end());
                arr.erase(max);
            }
            else
                break;
        }
        unsigned long long outp = 0;
        for (;count(alice.begin(), alice.end(), outp);)
            outp++;
        cout << outp << '\n';
        // unordered_set<int> alice_set(alice.begin(), alice.end());
        // int mex = 0;
        // while (alice_set.count(mex))
        //     ++mex;
        // cout << mex << '\n';
    }
}