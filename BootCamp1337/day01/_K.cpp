#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for (int i = 0;i < n;i++)
	{
        int l; cin >> l;
        map <int,int> mp;
        for(int i = 0; i < l; i++)
		{
            int x; cin >> x;
            mp[x]++;
        }
        vector <int> vec;
        for(auto &iter : mp)
		{
			if(iter.second == 1)
				vec.push_back(iter.first);
		}
        sort(vec.begin(), vec.end());
        if(vec.size() >= 2)
            mp[vec[1]] = 0;
        int mex = 0;
        for (;mp[mex] > 0;++mex)
			;
        cout << mex << '\n';
    }
}