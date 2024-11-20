#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mod 1000000007

using namespace std;

string path;
bool visited[9][9];
ll res = 0;
int i = 7, m_step = i * i - 1;

void visit(int x, int y, int step, char prev) 
{
    if (visited[x][y] == true) return;
    if (x == i && y == 1)
    {
        if (step == m_step) res++;
        return;
    }
    if (prev == 'U' || prev == 'D')
    {
        if (visited[x+1][y] == true && visited[x-1][y] == true)
            if (visited[x][y+1] == false && visited[x][y-1] == false)
                return;
    }
    if (prev == 'L' || prev == 'R')
    {
        if (visited[x][y+1] == true && visited[x][y-1] == true)
            if (visited[x+1][y] == false && visited[x-1][y] == false)
                return;
    }
    visited[x][y] = true;
    if (path[step] == '?')
    {
        visit(x+1,y,step+1,'D');
        visit(x,y+1,step+1,'R');
        visit(x-1,y,step+1,'U');
        visit(x,y-1,step+1,'L');
    }
    else
    {
        if (path[step] == 'L') visit(x,y-1,step+1,'L');
        if (path[step] == 'R') visit(x,y+1,step+1,'R');
        if (path[step] == 'U') visit(x-1,y,step+1,'U');
        if (path[step] == 'D') visit(x+1,y,step+1,'D');
    }
    visited[x][y] = false;
}

void solve()
{
    cin >> path;
    for (int k = 0;k <= i+1;k++)
    {
        visited[0][k] = true;
        visited[k][0] = true;
        visited[i+1][k] = true;
        visited[k][i+1] = true;
    }
    visit(1,1,0,'0');
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
    cerr << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5) << " sec " << endl;

    return 0;
}
