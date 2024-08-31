#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    map <int, int> arr_map;

    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 0; i < n; ++i)
    {
        int y = x - arr[i];
        if (arr_map.find(y) != arr_map.end())
            return (cout << arr_map[y] + 1 << " " << i + 1 << "\n", 0);
        arr_map[arr[i]] = i;
    }
    cout << "IMPOSSIBLE\n";
}
