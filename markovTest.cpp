#include <map>
#include <iostream>
#include <string.h>
#include<stdlib.h>
#include<time.h>

using std::cout;
using std::endl;
using namespace std;

int rand_x(int x){
	return rand()%x;
}

int main(){
	typedef std::multimap <string, string> id_multi_map;
	id_multi_map m;
	m.insert(pair<string, string>("START", "i"));	
	m.insert(pair<string, string>("START", "you"));
	m.insert(pair<string, string>("i", "like"));
	m.insert(pair<string, string>("like", "to"));
	m.insert(pair<string, string>("to", "eat"));
	m.insert(pair<string, string>("you", "eat"));
	m.insert(pair<string, string>("eat", "oranges"));
	m.insert(pair<string, string>("eat", "apples"));
	m.insert(pair<string, string>("oranges", "END"));
	m.insert(pair<string, string>("apples", "END"));

	std::string pick = "";
	id_multi_map::iterator iter = m.find("START");
	while (iter->second != "END"){
//		std::pair<id_multi_map::iterator, id_multi_map::iterator> res = m.equal_range(iter->first);
		//set random index of value to the key	
		srand((unsigned)time(NULL));
		int rand_index = rand_x(m.count(iter->first));
		//pick random value
		id_multi_map::iterator it = m.find(iter->first);
		for (int i = 0; i<=rand_index; i++, it++){
			pick = it->second;
		}
		cout << pick << endl;
		iter = m.find(pick);
	}

	return 0;
}
