#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        int arr[20] = {0};
        for(int i=0; i<n; i++)
            cin >> arr[i];
        while(n>1){

            for(int i=0; i<n-1;i++)
                arr[i] = arr[i+1] - arr[i];
            n--;
        }
        cout << arr[0] << endl;
    }
    return 0;
}
