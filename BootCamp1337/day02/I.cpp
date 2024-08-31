#include <iostream>
#include <vector>

using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long t;cin >>t ;

    while(t--){
        long long n, avail_water,l = 1;
        long long r = 0;
        cin >> n >> avail_water;
        vector < long long > coral_ht(n);
    
        for(long long i = 0 ; i < n ; i++)cin >> coral_ht[i];
        r = 1e10;
        while(l < r - 1)
        {
            long long total_water = 0;
            long long mid_ht = l + (r - l) / 2;
            for (long long i = 0 ; i < n ; i++)
                (coral_ht[i] < mid_ht) && (total_water += (mid_ht - coral_ht[i]));
            if (total_water > avail_water)
                r = mid_ht;
            else
                l = mid_ht;
        }
        cout << l <<endl;
    }  
}