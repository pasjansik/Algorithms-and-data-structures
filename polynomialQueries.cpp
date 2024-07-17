#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int beg, qrs;
};
int n, q;
int base = 1;
int tr[1000005];
node lazy[1000005];

inline void push(int w, int lw, int pw)
{
    int l = w * 2, p = w * 2 + 1;
    if(lazy[w].qrs == 0) return;
    int dl = (pw - lw + 1) / 2;

    lazy[l].qrs += lazy[w].qrs;
    lazy[l].beg += lazy[w].beg;
    tr[l] += lazy[w].beg * dl + lazy[w].qrs * (((dl - 1) * dl) / 2);

    lazy[p].qrs += lazy[w].qrs;
    lazy[p].beg += lazy[w].beg + (lazy[w].qrs * dl);
    tr[p] += (lazy[w].beg + (lazy[w].qrs * dl)) * dl + lazy[w].qrs * (((dl - 1) * dl) / 2);

    lazy[w].beg = lazy[w].qrs = 0;
}

inline void merge(int w)
{
    int l = w * 2, p = w * 2 + 1;
    tr[w] = tr[l] + tr[p];
}

void update(int w, int lw, int pw, int lz, int pz, int val) //val -> wartosc poczatkowa tej calej sumy
{
    if(lw >= lz && pw <= pz) //mamy wierzcholek bazowy
    {
        int dl = pw - lw;
        tr[w] += (val * (dl + 1)) + ((dl * (dl + 1)) / 2);
        lazy[w].beg += val;
        lazy[w].qrs++;
        return;
    }
    if(pw < lz || lw > pz) //przedzial wierzcholka nie zawiera sie w zapytaniu
        return;

    push(w, lw, pw);
    int mid = (lw + pw) / 2;
    update(w * 2, lw, mid, lz, pz, val);
    update(w * 2 + 1, mid + 1, pw, lz, pz, val + max(0LL, mid - max(lz, lw) + 1)); //val + ilosc wierzcholkow zawierajcych sie w zapytaniu w lewym poddrzewie
    merge(w);
}

int query(int w, int lw, int pw, int lz, int pz)
{
    if(lw >= lz && pw <= pz) //mamy wierzcholek bazowy
        return tr[w];
    if(pw < lz || lw > pz) //przedzial wierzcholka nie zawiera sie w zapytaniu
        return 0;

    push(w, lw, pw);
    int mid = (lw + pw) / 2;
    return query(w * 2, lw, mid, lz, pz) + query(w * 2 + 1, mid + 1, pw, lz, pz);
}

int32_t main()
{
    cin >> n >> q;
    while(base < n) base *= 2;

    //making tree
    for(int i = 0; i < n; i++)
        cin >> tr[i + base];
    for(int i = base - 1; i > 0; i--)
        tr[i] = tr[i * 2] + tr[i * 2 + 1];

    for(int i = 0; i < q; i++)
    {
        char in; cin >> in;
        if(in == '2') //query
        {
            int a, b; cin >> a >> b;
            cout << query(1, 0, base - 1, a - 1, b - 1) << "\n";
        }
        else //update
        {
            int a, b; cin >> a >> b;
            update(1, 0, base - 1, a - 1, b - 1, 1);
        }
    }
}