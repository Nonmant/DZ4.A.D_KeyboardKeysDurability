//https://contest.yandex.ru/contest/27665/problems/D/

#include "funcs.h"
#include <bits/stdc++.h>

void parseFile(std::istream & input, std::ostream & output){

    int n;
    input >> n;
    std::vector<int> keysDurability(n);
    std::copy_n(std::istream_iterator<int>(input),n,keysDurability.begin());

    int k;
    input >> k;
    std::vector<unsigned int> keysPresses(k);
    std::copy_n(std::istream_iterator<int>(input),k,keysPresses.begin());
    for(auto & press : keysPresses){
        --keysDurability[press-1];
    }

    for(auto & key : keysDurability){
        output << (key >= 0 ? "NO\n" : "YES\n");
    }
}
