#include <iostream>
#include <cctype>
using namespace std;

string cambiarMayusMinus(string texto) {
    for (char &c : texto) {
        if (isupper(c)) {
            c = tolower(c);
        } else if (islower(c)) {
            c = toupper(c);
        }
    }
    return texto;
}

int main() {
    string entrada;

    cout << "Introduce un texto: ";
    getline(cin, entrada);

    string resultado = cambiarMayusMinus(entrada);

    cout << "Texto convertido: " << resultado << endl;

    return 0;
}
