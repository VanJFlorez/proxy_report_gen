#include<iostream>
#include<vector>
#include<map>
#include<fstream>
#include"utilities.h"

using namespace std;

int main(int argc, char** argv) {
    ifstream infile;
    vector<map<string, size_t>> total(10);
    for(int i = 0; i < argc; i++) {
        infile.open(argv[i]);
        vector<string> tokens(split(line));
        cout << tokens[0] << endl;
        infile.close();
    }
}
