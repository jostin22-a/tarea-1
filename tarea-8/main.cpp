#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Vehiculo {
    string marca;
    string modelo;
    double consumo; // Galones por km
};

void guardarEnArchivo(const vector<Vehiculo>& vehiculos) {
    ofstream archivo("vehiculos.txt");
    if (!archivo) {
        cerr << "Error al abrir el archivo para escribir.\n";
        return;
    }
    for (const auto& veh : vehiculos) {
        archivo << veh.marca << " " << veh.modelo << " " << veh.consumo << endl;
    }
    archivo.close();
}

void leerYCalcular(double precioCombustible) {
    ifstream archivo("vehiculos.txt");
    if (!archivo) {
        cerr << "Error al abrir el archivo para leer.\n";
        return;
    }
    string marca, modelo;
    double consumo, km;
    cout << "Ingrese el kilometraje recorrido: ";
    cin >> km;
    cout << "Marca\tModelo\tKm\tCosto por galon\tCosto total\n";
    while (archivo >> marca >> modelo >> consumo) {
        double costoTotal = km * consumo * precioCombustible;
        cout << marca << "\t" << modelo << "\t" << km << "\t" << precioCombustible << "\t" << costoTotal << endl;
    }
    archivo.close();
}

int main() {
    vector<Vehiculo> vehiculos = {
        {"Toyota", "Corolla", 0.08},
        {"Honda", "Civic", 0.07},
        {"Ford", "Focus", 0.09}
    };
    guardarEnArchivo(vehiculos);

    double precioCombustible;
    cout << "Ingrese el precio del combustible por galon: ";
    cin >> precioCombustible;

    leerYCalcular(precioCombustible);

    return 0;
}

