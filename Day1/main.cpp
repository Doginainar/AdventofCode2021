#include <iostream>
#include <fstream>
#include <vector>

//Solution inspired by Pedro Lobo https://github.com/pedroclobo
using namespace std;
vector<int> numbers;
vector<int> sums;



void parse(){
    int value;
    ifstream file;
    file.open("input.txt");
    while(file >> value){
        numbers.push_back(value);
    }
    file.close();
}

vector<int> calculatesums(){
    int size = numbers.size();
    for(int i = 2; i < size; i++){
        sums.push_back(numbers[i-2] + numbers[i-1] + numbers[i]);

    }
    return sums;
}

int countincreases(vector<int> vec){
    int count = 0;
    int size = vec.size();
    for(int i = 1; i < size; i++){
        if(vec[i] > vec[i-1])
            count++;

    }
    return count;
}

int problem1(){
    return countincreases(numbers);
}

int problem2(){
    vector<int> vec = calculatesums();
    return countincreases(vec);
}

int main()
{
    parse();
    cout << problem1() << endl;
    cout << problem2() << endl;
}

