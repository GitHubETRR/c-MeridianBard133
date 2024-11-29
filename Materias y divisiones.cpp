#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Materia {
protected:
    string nombre;
    vector<string> subdivisiones;

public:
    Materia(const string& nombre) : nombre(nombre) {}

    void agregarSubdivision(const string& subdivision) {
        subdivisiones.push_back(subdivision);
    }

    // Marked as const to allow calling on const objects
    void mostrarInformacion() const {
        cout << "Nombre de la materia: " << nombre << endl;
        if (!subdivisiones.empty()) {
            cout << "Subdivisiones:" << endl;
            for (const string& sub : subdivisiones) {
                cout << "- " << sub << endl;
            }
        }
    }
};

int main() {
    vector<Materia> materias;
    char opcion;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Agregar una nueva materia" << endl;
        cout << "2. Mostrar la lista de materias" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case '1': {
                string nombreMateria;
                cout << "Ingrese el nombre de la materia: ";
                cin >> nombreMateria;

                // Create a new materia variable inside the loop
                Materia materia(nombreMateria);
                materias.push_back(materia);

                char respuesta;
                cout << "¿La materia tiene subdivisiones? (s/n): ";
                cin >> respuesta;

                if (respuesta == 's' || respuesta == 'S') {
                    string subdivision;
                    cout << "Ingrese las subdivisiones (ingrese 'fin' para terminar):" << endl;
                    while (true) {
                        cin >> subdivision;
                        if (subdivision == "fin") {
                            break;
                        }
                        // Make sure to use the correct materia variable
                        materia.agregarSubdivision(subdivision);
                    }
                }
                break;
            }
            case '2': {
                if (materias.empty()) {
                    cout << "No hay materias ingresadas." << endl;
                } else {
                    for (const auto& materia : materias) { // Iterating with const reference
                        materia.mostrarInformacion();
                        cout << endl;
                    }
                }
                break;
            }
            case '3':
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != '3');

    return 0;
}