#include <bits/stdc++.h>
using namespace std;

int d[100][100] = {0};

int LevenshteinDistance(string a, string b)
{
    int n = a.length();
    int m = b.length();

    //Initilization
    d[0][0] = 0;
    for (int i = 1; i <= n; ++i) //first column
        d[i][0] = i;
    for (int j = 1; j <= m; ++j) //first row
        d[0][j] = j;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            d[i][j] = min(
                d[i - 1][j - 1] + (a[i] == b[j] ? 0 : 1), //Subistution cost
                min(d[i - 1][j] + 1,                      //deletion
                    d[i][j - 1] + 1                       //insertion
                    ));
        }
    }
    return d[n][m];
}
int main()
{
    string a, b;
    //cin >> a >> b;
    a = "rover";
    b = "river";

    int n = a.length(), m = b.length();
    cout << "Number of edits to convert " << a << " to " << b << " is " << LevenshteinDistance(a, b) << endl;

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
            cout << d[i][j] << " ";
        cout << endl;
    }
}