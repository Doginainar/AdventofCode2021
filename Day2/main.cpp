#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<int> changes;
vector<string> instruction;

int hs = 0;
int depth = 0;
int aim = 0;


void parse(){
    int value;
    string direction ;
    ifstream file;
    file.open("input.txt");
    while(file >> direction >> value){
        changes.push_back(value);
        instruction.push_back(direction);

    }
    file.close();
}
int main() {
    parse();
    int size = changes.size();
    char keyword;

    for(int i= 0; i<size; i++){
        if(instruction[i] == "forward") {
            hs += changes[i];
            depth += changes[i] *  aim;


        }
        if(instruction[i] == "up") {
            aim -= changes[i];
        }
        if(instruction[i] == "down") {
            aim+=changes[i];
        }

    }
    cout << depth*hs << endl;
    return 0;
}
