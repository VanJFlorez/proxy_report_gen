#include<vector>
#include<map>
#include<fstream>

using namespace std; 

vector<string> split(string);

ostream& serialize(ostream& , const map<string, long>&);
