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

// Fungsi untuk melakukan scaling menggunakan matriks 3x3
void scale(float points[3][1], float scaleX, float scaleY)
{
    float scalingMatrix[3][3] = {
        {scaleX, 0, 0},
        {0, scaleY, 0},
        {0, 0, 1}};

    // Menampilkan matriks scaling
    std::cout << "Matriks Scaling:\n";
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << scalingMatrix[i][j] << " ";
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
                result[i][j] += scalingMatrix[i][k] * points[k][j];
            }
        }
    }

    // Update koordinat titik setelah scaling
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

    float scaleX = 2.0f;
    float scaleY = 3.0f;

    scale(points, scaleX, scaleY);

    std::cout << "Koordinat setelah scaling: (" << points[0][0] << ", " << points[1][0] << ")\n";

    return 0;
}