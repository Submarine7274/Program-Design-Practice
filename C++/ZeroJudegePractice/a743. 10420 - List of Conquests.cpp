#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int main(void) {
    int totalLines;     
    string firstLine;                
    getline(cin, firstLine);               
    totalLines = stoi(firstLine); 

    map<string, int> countryCount;      

    for (int lineIndex = 0; lineIndex < totalLines; lineIndex++) {
        string inputLine;               
        getline(cin, inputLine);

        stringstream ss(inputLine);    
        string countryName;            
        ss >> countryName;

        countryCount[countryName]++;    
    }

    for (auto& entry : countryCount) {   
        cout << entry.first << " " << entry.second << endl;
    }

    return 0;
}
