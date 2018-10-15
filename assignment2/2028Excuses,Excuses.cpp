#include <iostream>
using namespace std;

int main()
{
    int k,e;
    int num = 1;
    while(cin >> k >> e){
        string keys[k];
        string excuses[e];
        string oexcuses[e];
        int cnt[e];
        int maxCnt = 0;
        for(int i=0;i<k;i++)
            cin >> keys[i];
        cin.get();
        for(int i=0;i<e;i++){
            cnt[i] = 0;
            getline(cin,excuses[i]);
            oexcuses[i] = excuses[i];
            for(int j=0; j<excuses[i].length();j++){
                if(excuses[i][j] >= 'A' && excuses[i][j] <= 'Z')
                    excuses[i][j]+=32;
            }
            for(int j=0;j<k;j++){
                int index = 0;
                while(1){
                    index = excuses[i].find(keys[j],index);
                    if (index == -1)
                        break;
                    if((excuses[i][index-1]<'a' || excuses[i][index-1]>'z')&&(excuses[i][index+keys[j].length()]<'a' || excuses[i][index+keys[j].length()] > 'z'))
                        cnt[i]++;
                    index++;
                }

            }
            if(cnt[i] > maxCnt)
                maxCnt = cnt[i];
        }
        cout << "Excuse Set #" << num << endl;
        num++;
        for(int i=0;i<e;i++){
            if(cnt[i] == maxCnt)
                cout << oexcuses[i] << endl;
        }
        cout << endl;
    }
    return 0;
}
