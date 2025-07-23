# Video Morph & Reverse – C++

C++ image-processing project to perform smooth morphing between two images (frame by frame), and reverse an image-based video. Developed as part of the “Estructuras de Datos” (ED) course at the University of Granada.

## 🎬 Features

- **Morphing module**: generates intermediate frames between two images using linear blending
- **Reverse module**: inverts the order of images in a directory to reconstruct a reversed video
- Input and output are handled via image sequences (frames), not video files
- Supports common formats like PNG and JPEG (via libraries or raw PPM/PGM if simplified)

## 🛠️ Technologies

- C++
- Image file I/O
- Basic matrix operations
- File system navigation

## 📂 Structure

- `src/` – Core implementation
- `data/` – Folders containing input image sequences and result folders with generated morph or reversed images

## ▶️ How to Compile and Run

```bash
g++ -std=c++11 -o morph src/morphing.cpp
g++ -std=c++11 -o reverse src/rebobinar.cpp
./cmake-build-debug/morph data/imagenes/Azucena.pgm data/imagenes/Pedro.pgm data/videos/morph_az_pe 30
./cmake-build-debug/reverse data/videos/missa data/videos/reb_misssa
```

## 📌 Arguments:

`morph <img1> <img2> <output_folder> <frames>` – Creates a morph sequence

`reverse <input_folder> <output_folder>` – Creates reversed video (image sequence)

## 🎓 Academic Context
This project was developed in 2024/25 during the “Data Structures” course in the Double Degree in Computer Engineering and Mathematics (UGR).

## 🧪 Sample output
You can include examples of the morphing effect and reversed image sequences in the output/ folder.

## 📜 License
For academic purposes only.
Contact: javier.ortmol@gmail.com
