#include <bits/stdc++.h>
using namespace std;

int d[100][100];
int MI[100][100];

/*
Input: Sequences: A, B, and character set Σ
Output: Edit distance table
1 u ← Σ.length
2 m ← A.length
3 n ← B.length
4 Let MI[0...u − 1, 0...n − 1] and ED[0...m, 0...n] be new tables
5 for i = 0 to u − 1 (Compute all iterations of i in parallel) do
6 for j = 0 to n − 1 do
7 Compute MIi,j according to Equation (2)
8 end
9 end
10 for i = 0 to m do
11 for j = 0 to n (Compute all iterations of j in parallel) do
12 Compute EDTi,j according to Equation (3)
13 end
14 end
*/

int getMinimumPenalty(string x, string y, int pxy, int pgap)
{
    int i, j; // intialising variables

    int m = x.length(); //Mangal length of gene1
    int n = y.length(); // length of gene2

    // table for storing optimal substructure answers
    int dp[m + 1][n + 1] = {0};

    // intialising the table
    for (int i = 0; i <= n; i++)
        dp[i][0] = i * pgap;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j * pgap;

    // calcuting the minimum penalty
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min({dp[i - 1][j - 1] + pxy,
                                dp[i - 1][j] + pgap,
                                dp[i][j - 1] + pgap});
            }
        }
    }
    cout << "Minimum Penalty in aligning the genes = ";
    cout << dp[m][n] << "\n";
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
    cout << "Lev t = ";
    cout << d[n][m] << "\n";
    return d[n][m];
}

vector<int> backtrack(string a, string b)
{
    vector<int> pos;
    int n = a.length(), m = b.length();
    for (int i = n; i > 0;)
    {
        for (int j = m; j > 0;)
        {
            if (d[i - 1][j] + 1 == d[i][j])
            {
                pos.push_back(i);
                i--;
            }
            else if (d[i - 1][j - 1] + ((a[i - 1] == b[j - 1]) ? 0 : 1) == d[i][j])
            {
                if (a[i - 1] != b[j - 1])
                    pos.push_back(i);
                i--;
                j--;
            }
            else
            {
                j--;
            }
        }
    }
    return pos;
}

int main()
{
    string a, b;
    //cin >> a >> b;
    a = "abccbaa";
    b = "aabcbaa";
    int n = a.length();
    int m = b.length();
    int dist = levenshtien(a, b);
    int pen = getMinimumPenalty(a, b, max(m, n), dist);
    vector<int> pos = backtrack(a, b);
    int sum = n * pos.size();
    for (int i = 0; i < pos.size(); i++)
    {
        sum -= (pos[i] - 1);
        cout << pos[i] << endl;
    }
    cout << "Percentage match : " << (1 - ((float)dist) / (float)max(m, n)) * 100 << endl;
    cout << "Percentage match : " << (1 - (float)sum / ((float)n * ((float)n + 1) / 2)) * 100 << endl;
    cout << "Percentage match : " << (1 - ((float)dist * (float)pen) / ((float)max(m, n) * (float)max(m, n) * 2)) * 100 << endl;
}