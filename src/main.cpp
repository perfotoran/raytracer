#include <iostream>

int main(){
    int image_width = 256;
    int image_height = 256;

    // outputing PPM format image

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for(int j = 0; j < image_height; j++){
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for(int i = 0; i < image_width; i++){
            double r = i / (image_width - 1.0);
            double g = j / (image_height - 1.0);
            double b = 0.0;

            // converting from double to int format

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    std::clog << "\rDone.                 \n";

    return 0;
}