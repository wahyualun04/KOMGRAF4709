#include <iostream>
#include <cmath>

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

void rotate(float points[3][1], float angle, float pivotX, float pivotY)
{
    float radian = angle * (M_PI / 180.0);

    float rotationMatrix[3][3] = {
        {static_cast<float>(cos(radian)), static_cast<float>(-sin(radian)), static_cast<float>(pivotX * (1 - cos(radian)) + pivotY * sin(radian))},
        {static_cast<float>(sin(radian)), static_cast<float>(cos(radian)), static_cast<float>(pivotY * (1 - cos(radian)) - pivotX * sin(radian))},
        {0.0f, 0.0f, 1.0f}};

    std::cout << "Matriks Rotasi:\n";
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << rotationMatrix[i][j] << " ";
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
                result[i][j] += rotationMatrix[i][k] * points[k][j];
            }
        }
    }

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

    float angle = 45.0f;
    float pivotX = 3.0f;
    float pivotY = 3.0f;

    rotate(points, angle, pivotX, pivotY);

    std::cout << "Koordinat setelah rotasi: (" << points[0][0] << ", " << points[1][0] << ")\n";

    return 0;
}
