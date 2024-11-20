#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mod 1000000007

using namespace std;

int n,m,half;
ll k,board[22][22],res = 0;
map<ll,ll> path[21][21];

void back_lh(int x,int y, ll sum_xor, int move)
{
    sum_xor ^= board[x][y];
    if (move == half)
    {
        ++path[x][y][sum_xor];
        return;
    }
    if (x <= n) back_lh(x+1,y,sum_xor,move+1);
    if (y <= m) back_lh(x,y+1,sum_xor,move+1);
}
void back_rh (int x, int y,ll sum_xor, int move)
{
    sum_xor ^= board[x][y];
    if (move == n + m - 2 - half)
    {
        if (path[x][y].count(k ^ sum_xor ^ board[x][y]))
        {
            res += path[x][y][k ^ sum_xor ^ board[x][y]];
            return;
        }
    }

    if (x > 0) back_rh(x-1,y,sum_xor,move+1);
    if (y > 0) back_rh(x,y-1,sum_xor,move+1);
}
void solve()
{
    cin >> n >> m >> k;
    half = (n + m - 2) / 2;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            cin >> board[i][j];
    back_lh(1,1,0,0);
    back_rh(n,m,0,0);
    cout << res;
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