#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const char* key = "key";

void encrypt(char* data, int length, const char* key, int keyLength) {
    for (int i = 0; i < length; i++) {
        data[i] = data[i] ^ key[i % keyLength];
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }


    string filename = argv[1];


    ifstream input(filename);
    string content((istreambuf_iterator<char>(input)), (istreambuf_iterator<char>()));
    input.close();

  
    encrypt(&content[0], content.length(), key, strlen(key));

    
    ofstream output(filename + ".luac");
    output << content;
    output.close();

    return 0;
}
// created by digger man
