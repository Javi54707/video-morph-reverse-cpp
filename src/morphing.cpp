#include "image.h"
#include "video.h"
#include <iostream>
#include <cassert>
using namespace std;
Video morphing(const Image &I1,const Image &I2,int nf) {
    // Comprobamos que las imágenes tienen las mismas dimensiones
    assert(I1.get_rows() == I2.get_rows() && I1.get_cols() == I2.get_cols());

    int rows = I1.get_rows();
    int cols = I1.get_cols();

    // Creamos un objeto de la clase Video con nf fotogramas
    Video v(nf);

    // Para cada fotograma, calculamos la imagen interpolada
    for (int k = 0; k < nf; ++k) {
        // Creamos una nueva imagen para el fotograma k-ésimo
        Image img(rows, cols);

        // Calculamos los valores de los píxeles usando la fórmula del morphing
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // Fórmula de interpolación
                pixel p1 = I1.get_pixel(i, j);
                pixel p2 = I2.get_pixel(i, j);
                pixel new_pixel = (p1 - p1*k/nf) + ((p2 * k)/nf);

                // Establecemos el valor del nuevo píxel en la imagen resultante
                img.set_pixel(i, j, new_pixel);
            }
        }

        // Insertamos la imagen en el vídeo
        v[k] = img;
    }

    return v;
}

int main(int argc, char * argv[]) {
    // Comprobamos que el número de argumentos es correcto
    if (argc != 5) {
        cerr << "Uso: " << argv[0]
             << " <imagen_inicial.pgm> <imagen_final.pgm> <directorio_salida> <num_fotogramas>" << endl;
        return 1;
    }

    // Leemos los parámetros de entrada
    string fich_orig = argv[1];
    string fich_rdo = argv[2];
    string dir_salida = argv[3];
    int num_fotogramas = stoi(argv[4])+1;

    // Cargamos las dos imágenes
    Image I1, I2;
    if (!I1.Load(fich_orig.c_str())) {
        cerr << "Error: No se pudo cargar la imagen inicial " << fich_orig << endl;
        return 1;
    }

    if (!I2.Load(fich_rdo.c_str())) {
        cerr << "Error: No se pudo cargar la imagen final " << fich_rdo << endl;
        return 1;
    }

    // Comprobamos que las imágenes tienen las mismas dimensiones
    if (I1.get_rows() != I2.get_rows() || I1.get_cols() != I2.get_cols()) {
        cerr << "Error: Las imágenes no tienen las mismas dimensiones." << endl;
        return 1;
    }

    // Ejecutamos el morphing para generar el vídeo
    Video v = morphing(I1, I2, num_fotogramas);

    // Guardamos el vídeo en el directorio especificado
    string prefijo = "frame_";  // Prefijo para los nombres de los archivos de las imágenes del vídeo
    if (!v.EscribirVideo(dir_salida, prefijo)) {
        cerr << "Error: No se pudo guardar el vídeo en el directorio " << dir_salida << endl;
        return 1;
    }

    cout << "Morphing completado y guardado en el directorio " << dir_salida << endl;
    return 0;
}
