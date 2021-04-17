#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int value = 0 ;
    vector<int> values;
    cin >> n;
    cin >> b;
    // Check to see if in range
    if(n >= 1 && n <= 1000000) {
        if(b >= 1 && b <= 1000000) {
            // for loop to gather c inputs
            for(int i = 0; i < n; i++) {
                cin >> c;
                if(c >= 1 && c <= 1000) {
                    values.push_back(c);
                }
                // cout << values.at(i) <<  " ";
            }
            // cout << endl;
            // for loop to gather d inputs
            for(int i = 0; i < values.size(); i++) {
                cin >> d;
                if(d >= 0 && d <= 1000) {
                    // Applying discounts
                    values.at(i) -= d;
                    // cout << values.at(i) <<  " ";

                    // If discount is more than actual price, Gonzo ate for free
                    if(values.at(i) < 0) {
                        values.at(i) = 0;
                    }
                    // cout << values.at(i) << " ";

                    value += values.at(i);
                }
                // cout << endl;
            }
            b -= value;
            // Printing out remaining funds in Gonzo's account
            cout << b << endl;
        }
    }


    return 0;
}