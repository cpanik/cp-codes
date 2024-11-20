#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mod 1000000007

using namespace std;

int n,m;
bool visited[3001], notValid[3001];
vector<int> graph[3001];

void dfs(int u)
{
    visited[u] = true;
    for (auto x : graph[u])
    {
        if (visited[x] == false && notValid[x] == false) dfs(x);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int tmp1,tmp2;
    for (int i = 1;i <= m;i++)
    {
        cin >> tmp1 >> tmp2;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
    }
    int erasedNode = 0;
    for (int i = 1;i <= n;i++)
    {
        notValid[erasedNode] = true;
        bool check = true;
        for (int j = 1;j <= n;j++) visited[j] = false;
        for (int j = 1;j <= n;j++)
        {
            if (notValid[j] == false)
            {
                dfs(j);
                break;
            }
        }
        for (int j = 1;j <= n;j++)
        {
            if (notValid[j] == false && visited[j] == false)
            {
                check = false;
                break;
            }
        }
        if (check == true) cout << "YES";
        else cout << "NO";
        cout << "\n";
        cin >> erasedNode;
    }
    return 0;
}
