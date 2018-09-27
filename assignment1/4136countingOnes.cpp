#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while (cases--){
        int n;
        int cnt = 0;
        cin >> n;
        for(int i=0; i<n; i++){
            int num;
            cin >> num;
            if(num == 1)
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
