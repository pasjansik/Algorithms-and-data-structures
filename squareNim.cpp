#include<bits/stdc++.h>
using namespace std;
int q, n, nim[1000015], czy[1000015];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 1; i <= 250000; i++)
    {
        int mex = 0;
        for(int j = 1; j * j <= i; j++)
        {
            //nim[i - j * j] <- nasza wartosc aktualna
            if(nim[i - j * j] == mex)
            {
                mex++;
                while(czy[mex])
                    mex++;
            }
            czy[nim[i - j * j]] = 1;
        }
        
        nim[i] = mex;

        for(int j = 1; j * j <= i; j++)
            czy[nim[i - j * j]] = 0;
    }

    cin >> q;
    for(int i = 0; i < q; i++)
    {
        cin >> n;
        long long res = 0;
        for(int j = 0; j < n; j++)
        {
            int a; cin >> a;
            res ^= nim[a]; 
        }
        if(res == 0) cout << "NIE\n";
        else cout << "TAK\n";
    }
}