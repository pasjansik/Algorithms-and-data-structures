#include<bits/stdc++.h>
using namespace std;
#define int long long
string w, s;
int wsh[3], ssh[1000015][3], res;
int pot[3] = {2, 3, 5}, mod[3] = {1000000007, 1000000207, 1000000009}, pp[3]; //pp[j] -> pot[j]^w.size()
int32_t main()
{
    cin >> s >> w;

    //liczymy hash wzorca
    for(int j = 0; j < 3; j++)
    {
        int p = 1;
        for(int i = w.size() - 1; i >= 0; i--)
        {
            wsh[j] = (wsh[j] + (w[i] - 'a' + 1) * p) % mod[j];
            p = p * pot[j] % mod[j];
        }
    }

    for(int j = 0; j < 3; j++)
    {
        pp[j] = 1;
        for(int i = 0; i < w.size(); i++)
            pp[j] = pp[j] * pot[j] % mod[j];
    }

    for(int i = 1; i <= s.size(); i++)
    {
        bool czy = true;
        for(int j = 0; j < 3; j++)
        {
            ssh[i][j] = (ssh[i - 1][j] * pot[j] + (s[i - 1] - 'a' + 1)) % mod[j];
            if(i < w.size()) 
            {
                czy = false;
                continue;
            }
            int frag = ((ssh[i][j] - (ssh[i - w.size()][j] * pp[j] % mod[j])) + mod[j]) % mod[j];
            if(frag != wsh[j])  
                czy = false;
        }

        if(czy) 
            res++;
    }

    cout << res;
}