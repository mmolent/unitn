#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    fstream input, output;

    if (argc != 3) {
        cout << "Usage: ./a.out <inputFile> <outputFile>" << endl;
    }
    else {
        char carattereCorrente;
        bool rendiMaiuscola = true;

        input.open(argv[1], ios::in);
        output.open(argv[2], ios::out);

        if (input.fail()) {
            cout << "Il file non esiste!" << endl;
        }
        else {
            input >> noskipws;

            while (input >> carattereCorrente) {
                if ((carattereCorrente >= 'A') && (carattereCorrente <= 'Z')) {
                    rendiMaiuscola = false;
                }
                else if (rendiMaiuscola &&
                         (carattereCorrente >= 'a') &&
                         (carattereCorrente <= 'z')) {
                    carattereCorrente += ('A' - 'a');
                    rendiMaiuscola     = false;
                }
                else if ((carattereCorrente == '.') ||
                         (carattereCorrente == '!') ||
                         (carattereCorrente == '?')) {
                    rendiMaiuscola = true;
                }

                output << carattereCorrente;
            }

            input.close();
            output.close();
        }
    }

    return 0;
}
