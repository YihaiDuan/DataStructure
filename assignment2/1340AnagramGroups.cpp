#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>
#include <time.h>

using namespace std;
typedef map<string,int> wordCount;
struct word{
    char oris[30];
    char sorteds[30];
} wd[30005];
bool cmp (word w1,word w2){
    if(strcmp(w1.sorteds,w2.sorteds)!=0)
        return strcmp(w1.sorteds,w2.sorteds)<0;
    else
        return strcmp(w1.oris,w2.oris) < 0;
}
bool cmpMap (const pair<string,int> &p1,const pair<string,int> &p2){
    if(p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second > p2.second;
}
int main()
{
    wordCount wcnt;
    int n = 0;
    while(cin >> wd[n].oris){
        strcpy(wd[n].sorteds,wd[n].oris);
        sort(wd[n].sorteds,wd[n].sorteds+strlen(wd[n].sorteds));
        n++;
    }

//    clock_t start,ends;
//    start = clock();
    sort(wd,wd+n,cmp);
//    ends = clock();
//    cout << (double)(ends - start) << endl;
    for(int i=0; i<n;i++){
        wcnt.insert(pair<string,int>(wd[i].oris,1));
        string os = wd[i].oris;
        string ss = wd[i].sorteds;
        while(wd[i+1].sorteds == ss){
            i++;
            wcnt[os]++;
        }
    }
    vector<pair<string,int> > arr;
    for(wordCount ::iterator it = wcnt.begin();it != wcnt.end();it++){
        //cout << it->first << ": " << it->second << endl;
        arr.push_back(make_pair(it->first,it->second));
    }
    sort(arr.begin(),arr.end(),cmpMap);
    int cnt = 0;
    for(vector<pair<string,int> > :: iterator it = arr.begin(); cnt<5 && it != arr.end();it++){
        //cout << it->first << ": " << it->second << endl;
        string ss  = it->first;
        sort(&ss[0],&ss[ss.length()]);
        cout << "Group of size " << it->second << ": ";
        string ostr;
        for (int i=0; i<n;i++){
            if(wd[i].sorteds == ss && ostr != wd[i].oris)
                cout << wd[i].oris << " ";
            ostr = wd[i].oris;
        }
        cout << "." << endl;
        cnt++;
    }
//    ends = clock();
//    cout << (double)(ends - start) << endl;
    return 0;
}
