#include <iostream>
#include <string>
#include "src/index.hpp"

using namespace std;

int main() {
    string inputFile;

    cout << "Enter the name of the text file: ";
    getline(cin, inputFile);

    try {
        Index index;

        index.readFile(inputFile);
        index.writeIndex("index.json");

        cout << "Inverted index saved to index.json\n";
    } catch (const std::exception& error) {
        cerr << "Error: " << error.what() << '\n';
        return 1;
    }

    return 0;
}
