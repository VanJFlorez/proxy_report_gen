#include<iostream>
#include<vector>
#include<map>
#include<fstream>
#include"utilities.h"

using namespace std;

int main(int argc, char** argv) {
    ifstream infile;
    for(int i = 0; i < argc; i++) {
        infile.open(argv[i]);
        string line;
        getline(infile, line);
        vector<string> tokens(split(line));
        cout << tokens[0] << endl;
        infile.close();
    }
}
