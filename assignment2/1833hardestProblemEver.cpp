#include <iostream>

using namespace std;

int main()
{
    while(1){
        string start,ends;
        cin >> start;
        if (start == "ENDOFINPUT")
            break;
        cin.get();
        string clipher;
        getline(cin,clipher);
        for(int i=0; i<clipher.length();i++){
            clipher[i] -= 'A';
            if (clipher[i]>=0 && clipher[i] < 26)
                clipher[i] = (clipher[i]+26-5) % 26;
            clipher[i] += 'A';
        }
        cout << clipher << endl;
        cin >> ends;
    }
    return 0;
}
