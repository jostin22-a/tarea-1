#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Cliente {
    int numero;
};

vector<Cliente*> clientes;
map<int, int> historial;

void guardarHistorial() {
    ofstream archivo("historial.txt", ios::app);
    if (!archivo) {
        cerr << "Error al abrir el archivo de historial." << endl;
        return;
    }
    archivo << "--- Nuevo Sorteo ---\n";
    for (auto &par : historial) {
        archivo << "Numero " << par.first << " ha salido " << par.second << " veces.\n";
    }
    archivo.close();
}

void mostrarHistorial() {
    vector<pair<int, int>> numeros(historial.begin(), historial.end());
    sort(numeros.begin(), numeros.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });

    cout << "Historial de numeros sorteados: " << endl;
    for (auto &par : numeros) {
        cout << "Numero " << par.first << " ha salido " << par.second << " veces." << endl;
    }
}

void jugar() {
    Cliente* nuevo = new Cliente;
    cout << "Ingrese el numero con el que desea jugar: ";
    cin >> nuevo->numero;
    clientes.push_back(nuevo);
    cout << "Cliente agregado con exito!" << endl;
}

void tirarNumeros() {
    srand(time(0));
    int oro = rand() % 100 + 1;
    int plata = rand() % 100 + 1;
    int bronze = rand() % 100 + 1;

    historial[oro]++;
    historial[plata]++;
    historial[bronze]++;

    cout << "Numeros ganadores: \nORO: " << oro << "\nPLATA: " << plata << "\nBRONZE: " << bronze << endl;
    guardarHistorial();
}

void mostrarGanadores() {
    cout << "Ganadores del sorteo:" << endl;
    for (Cliente* cliente : clientes) {
        if (historial.find(cliente->numero) != historial.end()) {
            cout << "Cliente con numero " << cliente->numero << " ha ganado!" << endl;
        }
    }
}

void menu() {
    int opcion;
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Jugar" << endl;
        cout << "2. Lista de numeros salidos en la loteria" << endl;
        cout << "3. Tirar numeros" << endl;
        cout << "4. Mostrar ganadores" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                jugar();
                break;
            case 2:
                mostrarHistorial();
                break;
            case 3:
                tirarNumeros();
                break;
            case 4:
                mostrarGanadores();
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
    } while (opcion != 5);

    for (Cliente* cliente : clientes) {
        delete cliente;
    }
    clientes.clear();
}

int main() {
    menu();
    return 0;
}
