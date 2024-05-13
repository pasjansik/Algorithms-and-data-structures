#include<bits/stdc++.h>
using namespace std;
int n, m, wiel[1000005], off[1000005], cen, par[1000005], od[1000005], odl[1000005], K[100005][18], gl[100005];
vector<int> G[1000005], C[1000005];
 
int dfs(int w, int p)
{
    int res = 1;
    for(auto v : G[w])
    {
        if(v == p || off[v]) continue;
        res += dfs(v, w);
    }
    wiel[w] = res;
    return res;
}
 
int find_centroid(int w, int p, int sajz)
{
    for(auto v : G[w])
    {
        if(v == p || off[v]) continue;
        if(wiel[v] > sajz / 2) return find_centroid(v, w, sajz);
    }
    return w;
}
 
int centroid_decomposition(int w, bool flag)
{
    dfs(w, 0);
    int centr = find_centroid(w, 0, wiel[w]);
    if(flag) cen = centr;
 
    off[centr] = 1;
    for(auto v : G[centr])
    {
        if(off[v]) continue;
        int k = centroid_decomposition(v, false);
        C[k].push_back(centr);
        C[centr].push_back(k);
    }
    return centr;
}
 
void tatuski(int w, int p)
{
    par[w] = p;
    for(auto v : C[w])
    {
        if(v == p) continue;
        tatuski(v, w);
    }
}
 
void binLift(int w, int p)
{
    K[w][0] = p;
    gl[w] = gl[p] + 1;
    for(int i = 1; i < 18; i++)
    {
        if(K[w][i - 1] == 0) break;
        K[w][i] = K[K[w][i - 1]][i - 1];
    }
 
    for(auto v : G[w])
    {
        if(v == p) continue;
        binLift(v, w);
    }
}
 
int lca(int a, int b)
{
    if(gl[a] < gl[b]) swap(a, b);
 
    for(int i = 17; i >= 0; i--)
    {
        if(K[a][i] == 0) continue;
        if(gl[K[a][i]] >= gl[b]) a = K[a][i];
    }
 
    for(int i = 17; i >= 0; i--)
    {
        if(K[a][i] == 0 || K[b][i] == 0) continue;
        if(K[a][i] != K[b][i])
        {
            a = K[a][i];
            b = K[b][i];
        }
    }
    if(a == b) return a;
    return K[a][0];
}
 
int dist(int a, int b)
{
    return odl[a] + odl[b] - 2 * odl[lca(a, b)];
}
 
void update(int w, int org)
{
    od[w] = min(od[w], dist(w, org));
    if(w == cen) return;
    update(par[w], org);
}
 
int query(int w, int org)
{
    int res = 1e5 + 54;
    //cout << od[w] << " " << dist(org, w) << endl;
    res = min(res, od[w] + dist(org, w));
    if(w == cen) return res;
    return min(res, query(par[w], org));
}
 
void dfs2(int w, int p)
{
    for(auto v : G[w])
    {
        if(v == p) continue;
        odl[v] = odl[w] + 1;
        dfs2(v, w);
    }
}
 
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
 
    centroid_decomposition(1, true);
    tatuski(cen, 0);
    for(int i = 1; i <= n; i++) od[i] = 1e5 + 144;
    dfs2(1, 0);
    binLift(1, 0);
    update(1, 1);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a == 1) //update
        {
            update(b, b);
        }
        else //query
        {
            cout << query(b, b) << "\n";
        }
    }
}