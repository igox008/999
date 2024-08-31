#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int arr_count = 0;
    int sum = 0;
    int s_pos = 0;

    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        while (sum > x && s_pos <= i)
            (1) && (sum -= v[s_pos], s_pos++);
        if (sum == x)
        {
            arr_count++;
            sum -= v[s_pos];
            s_pos++;
        }
    }
    cout << arr_count << '\n';
}
