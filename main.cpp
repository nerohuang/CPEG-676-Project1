#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>
#include <random>

using namespace std;

typedef std::multimap<string, string> dictionary;
dictionary m;

// random number generator
int rand_x(int x){
	std::random_device rd;
	return rd()%x;
}

int main() {
    string txt;  
    string line;
    std::vector<string> words;
    ifstream fin( "test.txt" );  
    string  s;  
    while ( fin >> s ){
        words.push_back(s);
    }
    for (int i=0; i < words.size() - 1; i++){
            m.insert(pair<string, string>(words[i], words[i + 1]));
    }
    dictionary::iterator iter = m.find("test");
//    cout << iter->first << " " << iter->second <<endl;
	
	
	std::string pick = "";
	int i = 0; 
	int num;
	cout << "please enter how may words you want to generate: ";
	cin >> num;

	while (i < num){
		//generate random number
		int rand_index = rand_x(m.count(iter->first));
		dictionary::iterator it = m.find(iter->first);
		for (int j=0; j<=rand_index; j++, it++){
			pick = it->second;
		}
		cout << pick << " ";
		iter = m.find(pick);
		if (iter == m.end()){
			pick = "test";
			iter = m.find(pick);
			cout << pick << " ";
		}
		i++;
	}
	cout << endl;
}
