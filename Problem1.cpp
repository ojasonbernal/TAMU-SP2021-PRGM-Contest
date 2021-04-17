#include <string>
#include <iostream>
#include <sstream>
using namespace std;

void axiom(int n){
    if (n < 0 || n > 100){
        throw invalid_argument("error");
    }

    while (n != -1){
        string line;
        getline(cin,line);
        stringstream ss(line);
        int num = 0;
        string str; 
        while (!ss.eof()){
            ss >> str;
            ++num;
        }
        if (num >= 10){
            cout << line << endl;
        }
        --n;
    }
}

int main(){
    int number; 
    cin >> number;
    axiom(number);
    return 0;
}
