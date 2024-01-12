#include <iostream>
#include <array>

// Definisi matriks refleksi terhadap sumbu tegak lurus bidang XY
std::array<std::array<int, 3>, 3> reflectionMatrix = {{{-1, 0, 0}, {0, -1, 0}, {0, 0, 1}}};

// Fungsi untuk melakukan refleksi terhadap matriks refleksi
std::array<int, 3> reflectOverMatrix(std::array<int, 3> &point, std::array<std::array<int, 3>, 3> &matrix)
{
    int x = point[0];
    int y = point[1];
    int w = point[2];

    int result_x = x * matrix[0][0] + y * matrix[0][1] + w * matrix[0][2];
    int result_y = x * matrix[1][0] + y * matrix[1][1] + w * matrix[1][2];
    int result_w = x * matrix[2][0] + y * matrix[2][1] + w * matrix[2][2];

    return {result_x, result_y, result_w};
}

int main()
{
    // Titik awal P1 dan P2
    std::array<int, 3> P1 = {1, 2, 8}; // Koordinat homogen, dengan w=1
    std::array<int, 3> P2 = {3, 4, 1}; // Titik akhir dimodifikasi

    // Refleksi titik awal P1 terhadap sumbu tegak lurus bidang XY
    std::array<int, 3> reflected_P1 = reflectOverMatrix(P1, reflectionMatrix);

    // Refleksi titik awal P2 terhadap sumbu tegak lurus bidang XY
    std::array<int, 3> reflected_P2 = reflectOverMatrix(P2, reflectionMatrix);

    // Menampilkan hasil refleksi
    std::cout << "Titik awal P1: (" << P1[0] << ", " << P1[1] << ")\n";
    std::cout << "Titik setelah refleksi P1: (" << reflected_P1[0] << ", " << reflected_P1[1] << ")\n";
    std::cout << "Titik awal P2: (" << P2[0] << ", " << P2[1] << ")\n";
    std::cout << "Titik setelah refleksi P2: (" << reflected_P2[0] << ", " << reflected_P2[1] << ")\n";

    return 0;
}