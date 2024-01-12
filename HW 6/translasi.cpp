#include <iostream>
#include <cmath>

// Fungsi untuk mengalikan dua matriks 3x3
void multiplyMatrices(float a[3][3], float b[3][3], float result[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            result[i][j] = 0;
            for (int k = 0; k < 3; ++k)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Fungsi untuk melakukan translasi menggunakan matriks 3x3
void translate(float points[3][1], float tx, float ty)
{
    float translationMatrix[3][3] = {
        {1, 0, tx},
        {0, 1, ty},
        {0, 0, 1}};

    // Menampilkan matriks translasi
    std::cout << "Matriks Translasi:\n";
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << translationMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    float result[3][1] = {{0}, {0}, {0}};

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 1; ++j)
        {
            result[i][j] = 0;
            for (int k = 0; k < 3; ++k)
            {
                result[i][j] += translationMatrix[i][k] * points[k][j];
            }
        }
    }

    // Update koordinat titik setelah translasi
    for (int i = 0; i < 3; ++i)
    {
        points[i][0] = result[i][0];
    }
}

int main()
{
    float points[3][1] = {
        {3},
        {6},
        {1}};

    std::cout << "Koordinat awal: (" << points[0][0] << ", " << points[1][0] << ")\n";

    float tx = 3.0f;
    float ty = 3.0f;

    translate(points, tx, ty);

    std::cout << "Koordinat setelah translasi: (" << points[0][0] << ", " << points[1][0] << ")\n";

    return 0;
}