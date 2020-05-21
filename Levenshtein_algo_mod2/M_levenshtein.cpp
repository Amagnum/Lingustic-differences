#include <bits/stdc++.h>
using namespace std;

int d[100][100];
int MI[100][100];

int getMinimumPenalty(string x, string y, int pxy, int pgap)
{
    int m = x.length(); //length of 1
    int n = y.length(); // length of 2

    //storing optimal substructure answers
    int dp[m + 1][n + 1] = {0};

    // intialising the table
    for (int i = 0; i <= n; i++)
        dp[i][0] = i * pgap;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j * pgap;

    // calcuting the minimum penalty
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1]) // when equal no penelty
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min({dp[i - 1][j - 1] + pxy, //Replace penelty
                                dp[i - 1][j] + pgap,    //Gap penelty
                                dp[i][j - 1] + pgap});  //gap penelty
            }
        }
    }

    return dp[m][n];
}

int levenshtien(string a, string b)
{
    int n = a.length(), m = b.length();
    for (int i = 1; i <= n; i++)
        d[i][0] = i;
    for (int j = 1; j <= m; j++)
        d[0][j] = j;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            d[i][j] =
                min(d[i - 1][j - 1] + ((a[i - 1] == b[j - 1]) ? 0 : 1), min(d[i - 1][j], d[i][j - 1]) + 1);
        }
    }
    return d[n][m];
}

void CompareString(string *s1, string *s2)
{
    string a;
    string b;
    int n = s1->length();
    int m = s2->length();
    if (m > n)
    {
        a = *s2;
        b = *s1;
    }
    else
    {
        a = *s1;
        b = *s2;
    }

    int dist = levenshtien(a, b);
    int penT = getMinimumPenalty(a, b, 2, 1);
    cout << "\n"
         << a << " "
         << b << " (";
    cout << (1 - ((float)dist) / (float)max(m, n)) * 100 << " lev,";
    cout << (1 - ((float)penT / ((float)max(m, n) * 2))) * 100 << " mod)";
}

int main()
{
    int nLanguages, nCompare;
    cin >> nLanguages >> nCompare;
    string lang[nLanguages];
    for (size_t i = 0; i < nLanguages; i++)
    {
        cin >> lang[i];
    }

    for (size_t i = 0; i < nCompare; i++)
    {
        string string1;
        cin >> string1;
        for (size_t i = 1; i < nLanguages; i++)
        {
            string compareWith;
            cin >> compareWith;
            CompareString(&string1, &compareWith);
        }
    }
}