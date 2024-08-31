#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> all(16);
    all[0] = 0;            
    all[1] = (1 * 60) + 10;
    all[2] = (10 * 60) + 1;
    all[3] = (2 * 60) + 20;
    all[4] = (20 * 60) + 2;
    all[5] = (3 * 60) + 30;
    all[6] = (4 * 60) + 40;
    all[7] = (5 * 60) + 50;
    all[8] = (11 * 60) + 11;
    all[9] = (12 * 60) + 21;
    all[10] = (13 * 60) + 31;
    all[11] = (14 * 60) + 41;
    all[12] = (15 * 60) + 51;
    all[13] = (21 * 60) + 12;
    all[14] = (22 * 60) + 22;
    all[15] = (23 * 60) + 32;

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        string t;
        int incr;
        cin >> t >> incr;

        int hrs = ((t[0] - '0') * 10) + (t[1] - '0');
        int mnt = ((t[3] - '0') * 10) + (t[4] - '0');
        int total_minutes = (hrs * 60) + mnt;
        int t0 = total_minutes;
        for (int j = 0;j < 16;j++)
        {
            if (total_minutes == all[j])
            {
                cnt++;
                break;
            }
        }
        total_minutes = (total_minutes + incr) % 1440;
        while(total_minutes != t0)
        {   
            for (int j = 0;j < 16;j++)
            {
                if (total_minutes == all[j])
                {
                    cnt++;
                    break;
                }
            }
            total_minutes = (total_minutes + incr) % 1440;
        }
        cout << cnt << '\n';
    }

    return 0;
}
