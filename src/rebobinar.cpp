#include "image.h"
#include "video.h"
#include <iostream>
using namespace std;
Video Rebobinar(const Video &V){
    //Creo un objeto de la clase vídeo
    int n = V.size();
    Video devolver(n);

    //Hago la copia inversa
    for(int i = 0; i < V.size(); i++){
        devolver[i] = V[n - i - 1];
    }

    //Devuelvo el elemento
    return devolver;
}

int main(int argc, char * argv[]){
    // Comprobamos que el número de argumentos es correcto
    if (argc != 3) {
        cerr << "Uso: " << argv[0]
             << " <directorio_inicial> <directorio_final>" << endl;
        return 1;
    }

    string dir_origen = argv[1];
    string dir_salida = argv[2];

    //Cargar los datos
    Video o;
    if (!o.LeerVideo(dir_origen)) {
        cerr << "Error: No se pudo leer el video en el directorio " << dir_origen << endl;
        return 1;
    }

    //Rebobinar
    Video rebob = Rebobinar(o);

    if (!rebob.EscribirVideo(dir_salida,"rebobinada_")) {
        cerr << "Error: No se pudo guardar el vídeo en el directorio " << dir_salida << endl;
        return 1;
    }

    cout << "El video ha sido rebobinado correctamente y guardado en: " << dir_salida << endl;
    return(0);
}
