#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <bits/stdc++.h> 
using namespace std;

typedef std::multimap<string, string> dictionary;
dictionary m;

int main() {
    string txt;  
    string line;
    std::vector<string> words;
    cout<<"逐词读取, 词之间用空格区分"<<endl;
    ifstream fin( "test.txt" );  
    string  s;  
    while ( fin >> s ){
        words.push_back(s);
    }
    for (int i=0; i < words.size() - 1; i++){
            m.insert(pair<string, string>(words[i], words[i + 1]));
    }
    dictionary::iterator iter = m.find("test");
    cout << iter->first << " " << iter->second <<endl;

}

    

