#include<bits/stdc++.h>
using namespace std;
#define int long long
struct point
{
    int x, y;
};

int n;
vector<point> v;
vector<point> hull;
 
int cross(point z, point a, point b)
{
    return (a.x - z.x) * (b.y - z.y) - (a.y - z.y) * (b.x - z.x);
}

bool cmp(point a, point b)
{
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
 
int32_t main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        point p;
        p.x = a; p.y = b;
        v.push_back(p);
    }
    sort(v.begin(), v.end(), cmp); //sortujemy po od lewej

    //algorytm otoczki
    for(int j = 0; j < 2; j++) //najpierw gorna potem dolna czesc otoczki
    {
        for(int i = 0; i < n; i++)
        {
            while(hull.size() >= 2 && cross(hull[hull.size() - 2], hull.back(), v[i]) > 0) //rozpatrujemy dwa ostatnie elementy i nasz ktory dodajemy i jak jest zle to wywalamy
                hull.pop_back();
            hull.push_back(v[i]);
        }
        reverse(v.begin(), v.end());
        hull.pop_back();
    }

    cout << hull.size() << "\n";
    for(int i = 0; i < hull.size(); i++) cout << hull[i].x << " " << hull[i].y << "\n";
}