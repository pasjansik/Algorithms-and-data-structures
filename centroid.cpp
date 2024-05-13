#include<bits/stdc++.h>
using namespace std;
int n, k, off[200005], wiel[200005], dlu[200005], maksik;
long long res;
vector<int> G[200005];
 
void dfs(int w, int p)
{
    wiel[w] = 1;
    for(auto v : G[w])
    {
        if(v == p || off[v]) continue;
        dfs(v, w);
        wiel[w] += wiel[v];
    }
}
 
int find_centroid(int w, int p, int sajz)
{
    for(auto v : G[w])
        if(v != p && !off[v] && wiel[v] > sajz / 2) return find_centroid(v, w, sajz);
    return w;
}
 
void query(int w, int p, int dl)
{
    if(dl > k) return;
    res += dlu[k - dl];
    for(auto v : G[w])
    {
        if(v == p || off[v]) continue;
        query(v, w, dl + 1);
    }
}
 
void update(int w, int p, int dl)
{
    if(dl > k) return;
    dlu[dl]++;
    for(auto v : G[w])
    {
        if(v == p || off[v]) continue;
        update(v, w, dl + 1);
    }
}
 
void centroid_decomposition(int w)
{
    dfs(w, 0);
    int cent = find_centroid(w, 0, wiel[w]);
    dlu[0] = 1;
    for(auto v : G[cent])
    {
        if(off[v]) continue;
        query(v, cent, 1);
        update(v, cent, 1);
    }
 
    off[cent] = 1;
    for(int i = 0; i <= wiel[w]; i++) dlu[i] = 0;
    for(auto v : G[cent])
    {
        if(off[v]) continue;
        centroid_decomposition(v);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
 
    centroid_decomposition(1);
 
    cout << res;
}
