#include "noteshrink.h"
#include <stb/stb_image.h>
#include <string>
#include <vector>

int mainz(const char* fpath)
{
    std::string file(fpath);
    int width, height, bpp;
    stbi_uc* pixels = stbi_load(file.c_str(), &width, &height, &bpp, STBI_rgb_alpha);
    std::vector<NSHRgb> img(width * height);
    size_t i = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            size_t idx = (height - y - 1) * width * 4 + x * 4;
            NSHRgb p;
            p.R = pixels[idx];
            p.G = pixels[idx + 1];
            p.B = pixels[idx + 2];
            img[i++] = p;
        }
    }
    free(pixels);

    NSHOption o = NSHMakeDefaultOption();
    std::vector<NSHRgb> palette(8);
    NSHCreatePalette(img.data(), img.size(), o, palette.data(), palette.size());
    return 0;
}

int main() {

    #define DIR_ROOT "E:\\kpdf\\pdfreader_image\\fastpdf-turbo\\image\\imagetest\\testdata\\jpg\\"
    const char* fpath[] = {
        DIR_ROOT "01.jpg",
        DIR_ROOT "02.jpg",
        DIR_ROOT "03.jpg",
        DIR_ROOT "04.jpg",
        DIR_ROOT "05.jpg",
        DIR_ROOT "06.jpg",
        DIR_ROOT "07.jpg",
        DIR_ROOT "08.jpg",
        DIR_ROOT "09.jpg",
        DIR_ROOT "10.jpg",
        DIR_ROOT "16.jpg",
        DIR_ROOT "18.jpg",
        DIR_ROOT "19.png",
        DIR_ROOT "21.jpg",
        DIR_ROOT "22.jpg",
        DIR_ROOT "23.jpg",
        DIR_ROOT "24.jpg",
        DIR_ROOT "25.jpg",
        DIR_ROOT "26.jpg",
        DIR_ROOT "27.jpg",
        DIR_ROOT "28.jpg",
        DIR_ROOT "29.jpg",
        DIR_ROOT "30.jpg",
        DIR_ROOT "31.jpg",
        DIR_ROOT "32.jpg",
        DIR_ROOT "33.jpg",
        DIR_ROOT "34.jpg",
        DIR_ROOT "35.jpg",
        DIR_ROOT "36.png",
        DIR_ROOT "37.png",
        DIR_ROOT "38.png",
        DIR_ROOT "39.jpg",
        DIR_ROOT "40.jpg",
        DIR_ROOT "41.png",
        DIR_ROOT "42.jfif",
        DIR_ROOT "43.jpg",
        DIR_ROOT "44.jpg",
        DIR_ROOT "45.jpg",
    };

    int count = sizeof(fpath) / sizeof(fpath[0]);
    for (int i = 0; i < count; i++) {
        printf("%s\n", fpath[i]);
        mainz(fpath[i]);
    }

    getchar();
    return 0;
}