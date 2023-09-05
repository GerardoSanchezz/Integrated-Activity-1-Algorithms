#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void showVector(const vector<char>& vec);



int main() {
    // Array of file names
    string fileNames[] = {"transmission1.txt", "transmission2.txt", "mcode1.txt", "mcode2.txt", "mcode3.txt"};

    vector<char> transmission1;
    vector<char> transmission2;
    vector<char> mcode1;
    vector<char> mcode2;
    vector<char> mcode3;

    for (int i = 0; i < 5; i++) {
        ifstream inputFile(fileNames[i]);

        if (!inputFile.is_open()) {
            cerr << "Error: Unable to open file " << fileNames[i] << endl;
            continue;
        }

        // Leer y procesar el contenido del archivo carácter por carácter
        char c;
        while (inputFile.get(c)) {
            // Almacenar el carácter en el vector correspondiente
            switch (i) {
                case 0:
                    transmission1.push_back(c);
                    break;
                case 1:
                    transmission2.push_back(c);
                    break;
                case 2:
                    mcode1.push_back(c);
                    break;
                case 3:
                    mcode2.push_back(c);
                    break;
                case 4:
                    mcode3.push_back(c);
                    break;
            }
        }

        // Close the file
        inputFile.close();
    }

    // Mostrar cada vector por separado
    showVector(transmission1);
    showVector(transmission2);
    showVector(mcode1);
    showVector(mcode2);
    showVector(mcode3);

    return 0;
}
