#include<bits/stdc++.h>
using namespace std;
int n, q, wiel[120005], par[120005], gl[120005], pre[120005], k, path[120005], tr[300005], tr2[300005];
int base = 1 << 17;
vector<int> G[120005];

void dfs(int w, int p)
{
    gl[w] = gl[p] + 1;
    par[w] = p;
    wiel[w] = 1;
    for(auto v : G[w])
    {
        if(v == p) continue;
        dfs(v, w);
        wiel[w] += wiel[v];
    }
}

void make_hld(int w, int p)
{
    pre[w] = ++k;
    int heavy = 0;
    for(auto v : G[w]) if(v != p && wiel[v] > wiel[heavy]) heavy = v;

    if(heavy)
    {
        path[heavy] = path[w];
        make_hld(heavy, w);
    }

    for(auto v : G[w])
    {
        if(v == p || v == heavy) continue;
        path[v] = v;
        make_hld(v, w); 
    }
}

void push(int w)
{
    tr[w * 2] += tr2[w];
    tr2[w * 2] += tr2[w];

    tr[w * 2 + 1] += tr2[w];
    tr2[w * 2 + 1] += tr2[w];

    tr2[w] = 0;
}

void update(int w, int l, int p, int a, int b, int val)
{
    if(p < a || l > b) return;
    if(l >= a && p <= b)
    {
        tr[w] += val;
        tr2[w] += val;
        return;
    }

    push(w);
    update(w * 2, l, (l + p) / 2, a, b, val);
    update(w * 2 + 1, (l + p) / 2 + 1, p, a, b, val);
    tr[w] = max(tr[w * 2], tr[w * 2 + 1]);
}

int query(int w, int l, int p, int a, int b)
{
    if(p < a || l > b) return 0;
    if(l >= a && p <= b) return tr[w];
    push(w);
    return max(query(w * 2, l, (l + p) / 2, a, b), query(w * 2 + 1, (l + p) / 2 + 1, p, a, b));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1, 0);
    make_hld(1, 0);

    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int a, b;
        char type; cin >> type >> a >> b;
        if(type == 'I') //update
        {   
            update(1, 0, base - 1, pre[a], pre[a], b);
        }
        else //query
        {
            int res = 0;
            while(path[a] != path[b])
            {
                if(gl[path[a]] < gl[path[b]]) swap(a, b);
                res = max(res, query(1, 0, base - 1, pre[path[a]], pre[a]));
                a = par[path[a]];
            }

            res = max(res, query(1, 0, base - 1, min(pre[a], pre[b]), max(pre[a], pre[b])));
            cout << res << "\n";
        }
    }
}