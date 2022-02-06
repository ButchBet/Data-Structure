#ifndef AGRM_H
#define AHRM_H

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

typedef map<string, vector<string> > Graf;

vector<string> deepSearch(const Graf &graf, const string &origin="A") {
    vector<string> visit;

    stack<string> stk;
    
    vector<string> checked;

    visit.push_back(origin);

    stk.push(origin);

    while(!stk.empty()) {
        auto const vertex = stk.top();

        checked.push_back(vertex);

        stk.pop();

        auto const &adjacent = graf.at(vertex);

        for(size_t i = 0; i < adjacent.size(); i++) {
            auto const &adj = adjacent[i];

            if(find(visit.begin(), visit.end(), adj) == visit.end()) {
                visit.push_back(adj);

                stk.push(adj);
            }
        }
    }

    return checked;
}

vector<string> amplitudeSearch(const Graf &graf, const string &origin="A") {
    vector<string> visit;

    queue<string> que;
    
    vector<string> checked;

    visit.push_back(origin);

    que.push(origin);

    while(!que.empty()) {
        auto const vertex = que.front();

        checked.push_back(vertex);

        que.pop();

        auto const &adjacent = graf.at(vertex);

        for(size_t i = 0; i < adjacent.size(); i++) {
            auto const &adj = adjacent[i];

            if(find(visit.begin(), visit.end(), adj) == visit.end()) {
                visit.push_back(adj);

                que.push(adj);
            }
        }
    }

    return checked;
}


#endif