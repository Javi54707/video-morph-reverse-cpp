
#include "video.h"

void read_directory(const std::string& name, vector<string>& v)
{
    DIR* dirp = opendir(name.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {

        v.push_back(dp->d_name);

    }
    closedir(dirp);
}


Video::Video(){
    seq.clear();
}
/**************************************************/
Video::Video(int n) {
    if (n >= 0) {
        seq.resize(n);
    }
}
/**************************************************/
//Constructor de copia
Video::Video(const Video &V) {
    if (this != &V) {
        seq.reserve(V.size());
        for (int i = 0; i < V.size(); i++) {
            seq[i] = V[i];
        }
    }
}
/**************************************************/
Video::~Video(){
    seq.clear();
}
/**************************************************/
Video &Video::operator=(const Video &V){
    if (this != &V) {
        seq.reserve(V.size());
        for (int i = 0; i < V.size(); i++) {
            seq[i] = V[i];
        }
    }

    return *this;
}
/**************************************************/
int Video::size() const{
    return seq.size();
}
/**************************************************/
Image &Video::operator[](int foto){
    return seq[foto];
}

const Image &Video::operator[](int foto)const{
    return seq[foto];
}

void Video::Insertar(int k, const Image &I) {
    seq.insert(seq.begin() + k, I);
}

void Video::Borrar(int k){
    if (k >= 0 && k <= size()) {
       seq.erase(seq.begin()+k);
    }
}

bool Video::LeerVideo(const string &path){
    vector<string> files;
    read_directory(path, files);

    if (!std::filesystem::is_directory(path)) {
        cout << path << " no es un directorio valido" << endl;
        return false;
    }

    if (files.empty()) {
        cout << "Error: No se encontraron archivos en el directorio " << path << endl;
        return false;
    }

    std::sort(files.begin(), files.end());
    int n_files = files.size();
    for (const auto& file : files) {
        if (file != "." && file != ".." && file.size() >= 4 && file.substr(file.size() - 4) == ".pgm") {
            // Leer la imagen y añadirla al video
            string full_path = path + "/" + file;
            Image img;
            if (img.Load(full_path.c_str())) {
                seq.push_back(img);
            } else {
                std::cerr << "Error al cargar la imagen: " << full_path << std::endl;
                return false;
            }
        }
    }

    return true;
}

bool Video::EscribirVideo(const string& path, const string& prefijo) const {
    bool exito = true;
    std::filesystem::path filepath = path;
    bool filepathExists = std::filesystem::is_directory(filepath);

    if (!filepathExists) {
        bool created_new_directory = std::filesystem::create_directory(filepath);
        if (!created_new_directory) {
            cout << "No se puede crear el directorio " << path << endl;
            exito = false;
        } else {
            cout << "Se ha creado el directorio " << path << endl;
        }
    }

    for (int i = 0; i < seq.size(); ++i) {
        string file_path = path + "/" + prefijo + to_string(i) + ".pgm";
        if (!seq[i].Save(file_path.c_str())) {
            cout << "Error al guardar la imagen " << file_path << endl;
            exito = false;
        }
    }

    return exito;
}