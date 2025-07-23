
#ifndef PRACTICA2_VIDEO_H
#define PRACTICA2_VIDEO_H
#include "image.h"
#include <vector>
#include <algorithm>
#include <sys/types.h>
#include <dirent.h>
#include <cmath>
#include <string>
#include <filesystem>
#include <iostream>
using namespace std;

//Lee los ficheros de un directorio
//name es el nombre del directorio
//v el vector donde almacena los nombres

void read_directory(const std::string& name, vector<string>& v);
/**
  @brief T.D.A. Video

  Una instancia del tipo de dato abstracto Video nos permite almacenar objetos de la clase Imagen en un vector.

  Para poder usar el TDA Video se debe incluir el fichero

  \#include <video.h>

  @author Jorge Rodriguez
  @date Octubre 2024

**/

class Video {
    /**
     * @page repVideo Representación del TDA Video.

     * @section invVideo Invariante de la representación.

     * Un objeto válido 1 del TDA video representa un vector de objetos de la clase Imagen.

     **/
private:
    /**
     * @brief Vector de objetos de la clase imagen.
     */
    vector<Image> seq;
public:
    /**
     * @brief Constructor sin argumentos
     * @post Genera una instancia de la clase Video con un vector vacío.
     */
    Video();
    /**
     * @Constructor con parámetros.
     * @post Genera una instancia de la clase vídeo con un vector con n elementos de
     * la clase Image.
     * @param n Tamaño del vector.
     * @pre n>=0.
     */
    Video(int n);
    /**
     * @brief Constructor de copia.
     * @param V Referencia al objeto de la clase Video original que se quiere copiar.
     */
    Video(const Video &V);
    /**
     * @brief Destructor de la clase Video.
     * @return void.
     * @post El objeto Video destruido no puede usarse salvo que se haga sobre él una operacion Video().
     */
    ~Video();
    /**
     * @brief Operador de asignación.
     * @param V Referencia al video original que desea copiarse.
     * @return Una referencia al objeto video modificado.
     * @post Destruye cualquier información que contuviera previamente el objeto que llama
     * al operador de asignación.
     */
    Video &operator=(const Video &V);
    /**
     * @brief Número de imágenes que contiene el objeto de la clase video.
     * @return Entero que indica el número de imágenes que tiene la clase vídeo.
     * @post El entero devuelto tiene que ser mayor o igual que 0.
     */
    int size() const;
    /**
     * @brief Operador de indexación.
     * @param foto Entero que indica la posición en la que se encuentra el objeto de la
     * clase Imagen que se desea devolver del vector.
     * @return objeto de la clase Imagen por referencia.
     * @post Devuelve el objeto de la clase imagen correspondiente a la posición
     * que se le pasa como argumento.
     */
    Image &operator[](int foto);
    /**
     * @brief Operador de indexación constante
     * @param foto Entero que se usa para saber la posición del objeto de la clase
     * Imagen a devolver del vector.
     * @return Devuelve un objeto de la clase Imagen por referencia constante.
     * @post foto >= 0.
     */
    const Image &operator[](int foto)const;
    /**
     * @brief Se usa para insertar un objeto de la clase Imagen.
     * @param k Posición del vector en la que se inserta el objeto de la clase imagen.
     * @param I Objeto de la clase Imagen pasado por referencia constante que se desea
     * insertar en el vector.
     */
    void Insertar(int k, const Image &I);
    /**
     * @brief Borra un elemento del vector.
     * @param k Entero pasado por copia que contiene la posición del elemento a eliminar.
     */
    void Borrar(int k);
    /**
     * @brief Leer un video de disco.
     * @param path String pasado por referencia constante que contiene el directorio
     * donde almacenarse la secuencia temporal del fotograma.
     * @return Un booleano indicando si se ha leido el video o no.
     */
    bool LeerVideo(const string & path);
    /**
     * @brief Escribe un video de disco.
     * @param path String pasado por referencia constante que contiene el nombre del directorio donde se almacenará la
     * secuencia del fotograma.
     * @param prefijo String pasado por referencia constante que contiene el prefijo (parte común al nombre de todos
     * los ficheros).
     * @return Devuelve un booleano indicando si se ha podido escribir el video.
     */
    bool EscribirVideo(const string & path, const string &prefijo)const;
};

#endif //PRACTICA2_VIDEO_H
