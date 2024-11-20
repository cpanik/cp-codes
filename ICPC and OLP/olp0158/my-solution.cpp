#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mod 1000000007
#define matrix vector<vector<ll>>

using namespace std;

ll k;
matrix coe_matrix =
{
    {3, 2, 1, 1},
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 1}
}, base_matrix =
{
    {3},
    {2},
    {1},
    {3}
};

matrix matrix_mul(matrix a, matrix b)
{
    int a_row = a.size(), a_col = a[0].size(), b_col = b[0].size();
    matrix res;
    vector<ll> empt;

    for (int i = 0;i < a_row;i++)
    {
        res.push_back(empt);
        for (int j = 0;j < b_col;j++)
        {
            res[i].push_back(0);
            for (int k = 0;k < a_col;k++)
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
        }
    }

    return res;
}

matrix matrix_pow(matrix a, ll n)
{
    if (n == 1) return a;
    matrix doubled = matrix_pow(a, n/2);
    matrix doubled_n = matrix_mul(doubled, doubled);
    if (n % 2 == 0) return doubled_n;
    else return matrix_mul(doubled_n, a);
}

void solve()
{
    cin >> k;
    if (k == 1) cout << 2;
    else if (k == 2) cout << 3;
    else
    {
        matrix tmp = matrix_mul(matrix_pow(coe_matrix,k-2),base_matrix);
        cout << tmp[0][0];
    }
}

int main()
{
    clock_t start, end;
    start = clock();

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cerr << "Time taken by program is : " << fixed << setprecision(3)
         << time_taken << " sec " << endl;

    return 0;
}
