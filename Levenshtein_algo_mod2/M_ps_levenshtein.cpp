#include <bits/stdc++.h>
using namespace std;

int d[100][100] = {0};

double CalculateSimilarity(int stepsToSame, int length_a, int length_b)
{
    return (1.0 - ((double)stepsToSame / (double)max(length_a, length_b)));
}

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
    int stepsCount = LevenshteinDistance(a, b);
    cout << "Number of edits to convert " << a << " to " << b << " is " << stepsCount << endl;

    cout << "The percent similarity between two strings is " << CalculateSimilarity(stepsCount, n, m) << endl;
}
