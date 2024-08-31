#include <iostream>

using namespace std;

int main()
{
    string s;cin >> s;
    int scoreA = 0;
    int scoreB = 0;
    bool    win2 = false;
    for (int i = 0;s[i]; i += 2)
    {
        if (scoreA == 10 && scoreB == 10)
            win2 = true;
        (s[i] == 'A') && (scoreA += s[i + 1] - 48);
        (s[i] == 'B') && (scoreB += s[i + 1] - 48);
        if (!win2 && (scoreA >= 11 || scoreB >= 11))
            return (cout << ((scoreA >= 11) ? 'A' : 'B') << '\n', 0);
        else if (win2 && (scoreA >= scoreB + 2 || scoreB >= scoreA + 2))
            return (cout << ((scoreB >= scoreA + 2) ? 'B' : 'A') << '\n', 0);
    }
}