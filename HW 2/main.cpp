#include <iostream>
#include <vector>

// Fungsi untuk memasukkan matriks
std::vector<std::vector<int>> inputMatrix(int rows, int cols)
{
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    std::cout << "Masukkan elemen-elemen matriks:" << std::endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    return matrix;
}

// Fungsi untuk menampilkan matriks
void displayMatrix(const std::vector<std::vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            std::cout << val << ' ';
        }
        std::cout << std::endl;
    }
}

// Fungsi untuk menjumlahkan dua matriks
std::vector<std::vector<int>> addMatrices(const std::vector<std::vector<int>> &A, const std::vector<std::vector<int>> &B)
{
    int rows = A.size();
    int cols = A[0].size();
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

// Fungsi untuk mengurangkan dua matriks
std::vector<std::vector<int>> subtractMatrices(const std::vector<std::vector<int>> &A, const std::vector<std::vector<int>> &B)
{
    int rows = A.size();
    int cols = A[0].size();
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

// Fungsi untuk mengalikan matriks dengan skalar
std::vector<std::vector<int>> multiplyMatrixByScalar(const std::vector<std::vector<int>> &matrix, int scalar)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix[i][j] * scalar;
        }
    }

    return result;
}

int main()
{
    int rows, cols;
    std::cout << "Masukkan jumlah baris: ";
    std::cin >> rows;
    std::cout << "Masukkan jumlah kolom: ";
    std::cin >> cols;

    std::cout << "Masukkan matriks A:" << std::endl;
    std::vector<std::vector<int>> A = inputMatrix(rows, cols);

    std::cout << "Masukkan matriks B:" << std::endl;
    std::vector<std::vector<int>> B = inputMatrix(rows, cols);

    std::cout << "Pilih operasi (1: Penjumlahan, 2: Pengurangan, 3: Perkalian dengan Skalar): ";
    int choice;
    std::cin >> choice;

    std::vector<std::vector<int>> result;
    switch (choice)
    {
    case 1:
        result = addMatrices(A, B);
        break;
    case 2:
        result = subtractMatrices(A, B);
        break;
    case 3:
        int scalar;
        std::cout << "Masukkan skalar: ";
        std::cin >> scalar;
        result = multiplyMatrixByScalar(A, scalar);
        break;
    default:
        std::cout << "Pilihan tidak valid." << std::endl;
        return 1;
    }

    std::cout << "Hasil operasi:" << std::endl;
    displayMatrix(result);

    return 0;
}
