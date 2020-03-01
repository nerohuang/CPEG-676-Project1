#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

std::multimap<string, string> dictionary;


bool wordexist(string word){
    for (std::multimap<string,string>::iterator it=dictionary.begin(); it!=dictionary.end(); ++it){
        if ((*it).first == word)
            return true;
        else return false;
    };
}

int main() {
    string txt;  
    string line;
    ifstream myfile ("test.txt");
    if (myfile.is_open()){
        while ( myfile.good() ){
            getline (myfile,line);

            if (wordexist){
            }
            else{};
        myfile.close();
        }
    }
    else cout << "Unable to open file"; 
}
