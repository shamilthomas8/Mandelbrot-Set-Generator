#include <iostream>

void mandelbrotSet(int width, int height) {
    for (int py = 0; py < height; ++py) {
        for (int px = 0; px < width; ++px) {
            double x0 = (px - width / 2.0) * 4.0 / width;
            double y0 = (py - height / 2.0) * 4.0 / height;
            double x = 0.0, y = 0.0;
            int iteration = 0;
            int max_iteration = 1000;
            while (x * x + y * y <= 4 && iteration < max_iteration) {
                double xtemp = x * x - y * y + x0;
                y = 2 * x * y + y0;
                x = xtemp;
                iteration++;
            }

            if (iteration == max_iteration)
                std::cout << "#";  // inside Mandelbrot set
            else
                std::cout << " ";  // outside Mandelbrot set
        }
        std::cout << std::endl;
    }
}

int main() {
    int width = 80, height = 40;
    mandelbrotSet(width, height);
    return 0;
}
