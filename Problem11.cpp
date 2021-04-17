#include <iostream>
#include <vector>
using namespace std;

int main () {
    // small b to big a and vise versa
    int n = 0;
    int a = 0;
    int b = 0;
    vector<int> aValues;
    vector<int> aValuesCopy;
    vector<int> bValues;
    double aceValue = 0.0;
    cin >> n;
    // Check to see if in range
    if(n >= 2 && n <= 100000) {
            vector<int> ACEValues(n);
            // for loop to gather a inputs
            for(int i = 0; i < n; i++) {
                cin >> a;
                if(a >= 1 && a <= 10000) {
                    aValues.push_back(a);
                }
            }
            aValuesCopy = aValues;
            // cout << endl;
            // for loop to gather b inputs
            for(int i = 0; i < aValues.size(); i++) {
                cin >> b;
                if(b >= 0 && b <= 1000) {
                    bValues.push_back(b);
                }
            }

        // while loop to continue until vector size is not 0
        while(aValues.size() != 0) {
            int max = aValues[0];
            int min = bValues[0];
            int max_index = 0;
            int min_index = 0;

            // FIND MAX/MIN
            //Find maximum and minimum in all array elements.
            for(int i = 1; i < bValues.size(); i++)
            {
                // If current element is greater than max
                if(aValues[i] >= max) {
                    max = aValues[i];
                    max_index = i;
                }
                // If current element is smaller than min
                if(bValues[i] <= min) {
                    min = bValues[i];
                    min_index = i;
                }
            }
            // cout << "a Values max: "<< max << " i: " << max_index << endl;
            // cout << "b Values min: "<< min << " i: " << min_index << endl;
            
            if(max_index == 0 && min_index > 0) {
                aValues.erase(aValues.begin());
                bValues.erase(bValues.begin()+(min_index));
            }
            else if (min_index == 0 && max_index > 0) {
                aValues.erase(aValues.begin()+(max_index));
                bValues.erase(bValues.begin());
            }
            else if (min_index == 0 && max_index == 0) {
                aValues.erase(aValues.begin());
                bValues.erase(bValues.begin());
            }
            else {
                aValues.erase(aValues.begin()+(max_index));
                bValues.erase(bValues.begin()+(min_index));
            }
            // for(int i = 0; i < aValues.size(); i++) {
            //     cout << aValues.at(i) << " ";
            // }
            // cout << endl;
            // for(int i = 0; i < bValues.size(); i++) {
            //     cout << bValues.at(i) << " ";
            // }
            // cout << endl;

            // Match large A value to small B value and keep respective order
            // cout <<"MI: " <<max_index << endl;
            // cout <<"min: " <<min << endl;
            for(int j = 0; j < aValuesCopy.size(); ++j) {
                // if(aValuesCopy.at(j) == max)
                if(aValuesCopy.at(j) == max) {
                    ACEValues.at(j) = min;
                    break;
                }
            }



        }
        for(int j = 0; j < aValuesCopy.size(); ++j) {
            // if(aValuesCopy.at(j) == max)
            if(ACEValues.at(j) == 0) {
                ACEValues.at(j) = aValuesCopy.at(j);
            }
        }
        // Calculate ACE values
        for(int i = 0; i < ACEValues.size(); i++) {
            aceValue += ACEValues.at(i) / (aValuesCopy.at(i) * 1.0);
        }
        cout << aceValue << endl;

        for(int i = 0; i < ACEValues.size(); i++) {
            cout << ACEValues.at(i) << " ";
        }
        cout << endl;



    }


    return 0;
}