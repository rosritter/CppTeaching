#include "stl.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

void taskRace(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < m; i++) {
        int count = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        cout << count << " ";
    }

};


void taskReg(){
    int n;
    cin >> n;
    set<string> used_names;
    
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        
        if (used_names.count(name) > 0) {
            int suffix = 1;
            string new_name = name;
            while (used_names.count(new_name) > 0) {
                new_name = name + to_string(suffix);
                suffix++;
            }
            used_names.insert(new_name);
            cout << new_name << " ";
        } else {
            used_names.insert(name);
            cout << "OK ";
        }
    }
};