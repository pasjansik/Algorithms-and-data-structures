#include<bits/stdc++.h>
using namespace std;
#define int long long
struct point
{
    int x, y;
};
int n, res;
vector<point> v;
point p0;

long long cross(point z, point a, point b)
{
    return (a.x - z.x) * (b.y - z.y) - (b.x - z.x) * (a.y - z.y);
}

bool cmp(point a, point b)
{
    return cross(p0, a, b) > 0;
}


int32_t main()
{
    cin >> n;
    int nin = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        point c; c.x = a; c.y = b;
        if(b < nin)
        {
            nin = b;
            p0 = c;
        }
        v.push_back(c);
    }

    sort(v.begin(), v.end(), cmp);
    p0 = v[0];
 
    for(int i = 2; i < v.size(); i++)
    {
        point a = v[i], b = v[i - 1];
 
        int pole = cross(p0, a, b);
        res += pole;
    }

    res = abs(res);
    cout << res; //we are printing 2*area
}