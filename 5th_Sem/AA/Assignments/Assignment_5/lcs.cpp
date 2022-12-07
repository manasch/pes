#include <bits/stdc++.h>
using namespace std;

void LCS_len(string x, string y, int m, int n, vector<vector<string>> &b, vector<vector<int>> &c) {
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = "LU";
            }
            else if (c[i - 1][j] > c[i][j - 1]) {
                c[i][j] = c[i - 1][j] ;
                b[i][j] = "U";
            }
            else {
                c[i][j] = c[i][j - 1];
                b[i][j] = "L";
            }
        }
    }
}

void print_LCS(vector<vector<string>> &b, string &x, string &ans, int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }

    if (b[i][j] == "LU") {
        print_LCS(b, x, ans, i - 1, j - 1);
        ans += x[i - 1];
    }
    else if (b[i][j] == "U") {
        print_LCS(b, x, ans, i - 1, j);
    }
    else print_LCS(b, x, ans, i, j - 1);
}

int main() {
    string x, y, ans;
    cin >> y >> x;

    int m = x.size(), n = y.size();
    vector<vector<string>> b(m + 1, vector<string> (n + 1, "X"));
    vector<vector<int>> c(m + 1, vector<int> (n + 1, 0));

    LCS_len(x, y, m, n, b, c);
    print_LCS(b, x, ans, m, n);

    cout << c[m][n] << endl << ans << endl;
    return 0;
}
