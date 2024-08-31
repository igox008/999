#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    string s;
    string vo = "AOYEUIaoyeui";
    cin >> s;
    for (char c : s)
    {
        if (vo.find(c) == string::npos)
            cout << "." << (char)tolower(c);
    }
    cout << endl;
}