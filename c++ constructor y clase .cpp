#include <iostream>
#include <string>

class Alumno {
public:
    std::string nombre;
    int edad;
    int añoNacimiento;
    
    Alumno() {} // Constructor por defecto

    Alumno(std::string nom, int ed, int año) {
        nombre = nom;
        edad = ed;
        añoNacimiento = año;
        
    }

    void clasificar() {
        if (añoNacimiento >= 2005 && añoNacimiento <= 2006) {
            std::cout << nombre << " está en 6° año secundario." << std::endl;
        } else if (añoNacimiento >= 2007 && añoNacimiento <= 2008) {
            std::cout << nombre << " está en 5° año secundario." << std::endl;
        } else if (añoNacimiento >= 2009 && añoNacimiento <= 2010) {
            std::cout << nombre << " está en 4° año secundario." << std::endl;
        } else if (añoNacimiento >= 2011 && añoNacimiento <= 2012) {
            std::cout << nombre << " está en 3° año secundario." << std::endl;
        } else if (añoNacimiento >= 2013 && añoNacimiento <= 2014) {
            std::cout << nombre << " está en 2° año secundario." << std::endl;
        } else if (añoNacimiento >= 2015 && añoNacimiento <= 2016) {
            std::cout << nombre << " está en 1° año secundario." << std::endl;
        } else {
            std::cout << "Año de nacimiento inválido." << std::endl;
        }
    }
};

int main() {
    Alumno alumno;
    char opcion;

    do {
        std::cout << "Desea cargar un nuevo alumno? (s/n): ";
        std::cin >> opcion;

        if (opcion == 's') {
            std::string nombre;
            int edad, añoNacimiento;

            std::cout << "Ingrese el nombre del alumno: ";
            std::cin.ignore(); // Limpiar el buffer de entrada
            std::getline(std::cin, nombre);

            std::cout << "Ingrese la edad del alumno: ";
            std::cin >> edad;
        
            std::cout << "Ingrese el año de nacimiento: ";
            std::cin >> añoNacimiento;

            alumno = Alumno(nombre, edad, añoNacimiento); // Inicializar el objeto Alumno con el constructor
            alumno.clasificar();
        } else if (opcion != 'n') {
            std::cout << "Opción inválida. Ingrese 's' para cargar un nuevo alumno o 'n' para salir." << std::endl;
        }
    } while (opcion != 'n');

    return 0;
}