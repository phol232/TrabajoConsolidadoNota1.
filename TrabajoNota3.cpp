#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Registro {
    int id;
    string nombre;
    string apellido;
    string direccion;
    string telefono;
    string genero;
};
void agregarRegistro(vector<Registro>& registros) {
    Registro nuevoRegistro;
    nuevoRegistro.id = registros.size() + 1;
    cout << "\nIngrese el nombre: ";
    cin.ignore();
    getline(cin, nuevoRegistro.nombre);
    cout << "Ingrese el apellido: ";
    getline(cin, nuevoRegistro.apellido);
    cout << "Ingrese la dirección: ";
    getline(cin, nuevoRegistro.direccion);
    cout << "Ingrese el número de teléfono: ";
    getline(cin, nuevoRegistro.telefono);
    cout << "Ingrese el género: ";
    getline(cin, nuevoRegistro.genero);
    registros.push_back(nuevoRegistro);
    cout << "\nRegistro agregado correctamente." << endl;
}
void mostrarRegistros(const vector<Registro>& registros) {
    cout << "\nRegistros en la base de datos:" << endl;
    for (const Registro& registro : registros) {
        cout<<"\n";
        cout << "ID: " << registro.id << endl;
        cout << "Nombre: " << registro.nombre << endl;
        cout << "Apellido: " << registro.apellido << endl;
        cout << "Dirección: " << registro.direccion << endl;
        cout << "Número de teléfono: " << registro.telefono << endl;
        cout << "Género: " << registro.genero << endl;
        cout << endl;
    }
}
void buscarPorID(const vector<Registro>& registros, int idBuscar) {
    for (const Registro& registro : registros) {
        if (registro.id == idBuscar) {
            cout << "\nRegistro encontrado:" << endl;
            cout << "ID: " << registro.id << endl;
            cout << "Nombre: " << registro.nombre << endl;
            cout << "Apellido: " << registro.apellido << endl;
            cout << "Dirección: " << registro.direccion << endl;
            cout << "Número de teléfono: " << registro.telefono << endl;
            cout << "Género: " << registro.genero << endl;
            return;
        }
    }
    cout << "\nNo se encontró un registro con el ID especificado." << endl;
}
void eliminarRegistro(vector<Registro>& registros, int idEliminar) {
    auto it = registros.begin();
    while (it != registros.end()) {
        if (it->id == idEliminar) {
            it = registros.erase(it); 
            cout << "\nRegistro eliminado correctamente." << endl;
            return;
        } else {
            ++it;
        }
    }
    cout << "\nNo se encontró un registro con el ID especificado." << endl;
}
void liberarRegistros(vector<Registro>& registros) {
    registros.clear();
}
int main() {
    setlocale(LC_CTYPE, "Spanish");
    vector<Registro> baseDeDatos;
    char opcion;
    do {
        cout << "\nMenú de la base de datos:" << endl;
        cout << "1. Agregar registro" << endl;
        cout << "2. Mostrar registros" << endl;
        cout << "3. Buscar por ID" << endl;
        cout << "4. Eliminar registro" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;     
        switch (opcion) {
            case '1':
                agregarRegistro(baseDeDatos);
                break;
            case '2':
                mostrarRegistros(baseDeDatos);
                break;
            case '3':
                if (!baseDeDatos.empty()) {
                    int idBuscar;
                    cout << "Ingrese el ID del registro a buscar: ";
                    cin >> idBuscar;
                    buscarPorID(baseDeDatos, idBuscar);
                } else {
                    cout << "La base de datos está vacía." << endl;
                }
                break;
            case '4':
                if (!baseDeDatos.empty()) {
                    int idEliminar;
                    cout << "Ingrese el ID del registro a eliminar: ";
                    cin >> idEliminar;
                    eliminarRegistro(baseDeDatos, idEliminar);
                } else {
                    cout << "La base de datos está vacía." << endl;
                }
                break;
            case '5':
                liberarRegistros(baseDeDatos);
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != '5');  
    return 0;
}

