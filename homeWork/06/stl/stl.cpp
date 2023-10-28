#include "stl.hpp"
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void taskRace(){
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> mono(n);
    vector<int> poli(m);
    for (int i = 0; i < n; i++) {
        cin >> mono[i];
    }
    sort(mono.begin(), mono.end());
    for (int i = 0; i < m; i++) {
        cin >> poli[i];
    }
    for (int i = 0; i < m; i++) {
        int t = poli[i] + 1;
        auto c = lower_bound(mono.begin(), mono.end(), t);
        cout << distance(mono.begin(), c) << " ";
    }
};


void taskReg(){
    int n = 0;
    map<string, unsigned> a;
    cin >> n;
    vector<string> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        if (a.count(b[i]) == 0) cout << "OK";
        else cout << b[i] + to_string(a[b[i]]);
        a[b[i]] += 1;
        if (i != n -1) cout << " ";
    }
};