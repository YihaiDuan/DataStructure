#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string m,n;
    while(1){
        int same = 0;
        cin >> m;
        if(m == "-1")
            break;
        cin >> n;
        int mLen = m.length();
        int nLen = n.length();
        for(int i=0;i<mLen;i++){
                //cout <<"i: " <<  i <<endl;
            int cnt = 0;
            for(int j=i;j<mLen;j++){

                if (m[j] == n[j-i]){
                    //cout << i << ": "<< cnt << endl;
                    cnt++;
                }
            }
            if(cnt>same)
                    same = cnt;
        }
        for(int i=0;i<nLen;i++){
            int cnt2 = 0;
            for(int j=i;j<nLen;j++){
                if(n[j] == m[j-i]){
                    cnt2++;
                }
            }
            if(cnt2>same)
                same = cnt2;
        }
        if(same == 0){
            cout << "appx(" << m << "," << n << ") = " << same << endl;
            continue;
        }
        same *= 2;
        int len = mLen+nLen;
        int divisor = same;
        while(1){
            if(len%divisor == 0 && same%divisor == 0)
                break;
            divisor--;
        }
        len /= divisor;
        same /= divisor;
        if(len == same)
            cout << "appx(" << m << "," << n << ") = " << 1 << endl;
        else
            cout << "appx(" << m << "," << n << ") = " << same << "/" << len << endl;

    }
    return 0;
}
