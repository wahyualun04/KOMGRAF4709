#include <GL/freeglut.h>
#include <iostream>
#include <cmath>

float Ax, Ay, Bx, By;
std::string nameA = "A", nameB = "B"; // Tetapkan nama A dan B

void drawAxisWithNumbers()
{
    glColor3f(0.0, 0.0, 0.0); // Warna hitam untuk sumbu dan teks
    glBegin(GL_LINES);

    // Sumbu X
    glVertex2f(-25.0, 0.0); // Titik awal
    glVertex2f(25.0, 0.0);  // Titik akhir

    // Sumbu Y
    glVertex2f(0.0, -25.0); // Titik awal
    glVertex2f(0.0, 25.0);  // Titik akhir

    glEnd();

    // Tambahkan nomor pada sumbu X
    for (int i = -25; i <= 25; i++)
    {
        char num[4];
        snprintf(num, 4, "%d", i);
        glRasterPos2f(i - 0.2, -0.5); // Atur posisi teks
        for (int j = 0; num[j] != '\0'; j++)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, num[j]); // Perbesar ukuran teks menjadi GLUT_BITMAP_HELVETICA_18
        }
    }

    // Tambahkan nomor pada sumbu Y
    for (int i = -25; i <= 25; i++)
    {
        char num[4];
        snprintf(num, 4, "%d", i);
        glRasterPos2f(-0.8, i - 0.2); // Atur posisi teks
        for (int j = 0; num[j] != '\0'; j++)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, num[j]); // Perbesar ukuran teks menjadi GLUT_BITMAP_HELVETICA_18
        }
    }
}

void drawText(const char *text, float x, float y)
{
    glRasterPos2f(x, y);
    for (int i = 0; text[i] != '\0'; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]); // Perbesar ukuran teks menjadi GLUT_BITMAP_HELVETICA_18
    }
}

void drawLine(float x1, float y1, float x2, float y2)
{
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void rotatePoint(float angle, float &x, float &y, float centerX, float centerY)
{
    float radians = angle * M_PI / 180; // Mengonversi sudut ke radian
    float newX = (x - centerX) * cos(radians) - (y - centerY) * sin(radians) + centerX;
    float newY = (x - centerX) * sin(radians) + (y - centerY) * cos(radians) + centerY;
    x = newX;
    y = newY;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Gambar sumbu x dan y dengan nomor
    drawAxisWithNumbers();

    // Gambar garis awal yang menghubungkan titik A dan B
    // glColor3f(0.0, 0.0, 0.0); // Warna hitam untuk garis
    // drawLine(Ax, Ay, Bx, By);

    // Lakukan rotasi terlebih dahulu
    float angle = 45.0; // Ubah sesuai sudut rotasi yang diinginkan
    rotatePoint(angle, Ax, Ay, 0, 0);
    rotatePoint(angle, Bx, By, 0, 0);

    // Gambar garis hasil rotasi yang menghubungkan titik A dan B
    glColor3f(0.0, 0.0, 1.0); // Warna biru untuk garis rotasi
    drawLine(Ax, Ay, Bx, By);

    // Gambar titik A
    glColor3f(1.0, 0.0, 0.0); // Warna merah
    glPointSize(8.0);         // Perbesar ukuran titik
    glBegin(GL_POINTS);
    glVertex2f(Ax, Ay);
    glEnd();

    // Tampilkan label titik A
    drawText(nameA.c_str(), Ax + 1.0, Ay + 1.0); // Sesuaikan posisi label

    // Gambar titik B
    glColor3f(0.0, 0.0, 1.0); // Warna biru
    glPointSize(8.0);         // Perbesar ukuran titik
    glBegin(GL_POINTS);
    glVertex2f(Bx, By);
    glEnd();

    // Tampilkan label titik B
    drawText(nameB.c_str(), Bx + 1.0, By + 1.0); // Sesuaikan posisi label

    glFlush();
}

void userInput(unsigned char key, int x, int y)
{
    if (key == 27)
    {            // 27 adalah kode ASCII untuk tombol Escape
        exit(0); // Keluar dari aplikasi jika Escape ditekan
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Transformasi Rotasi");

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-30.0, 30.0, -30.0, 30.0);

    std::cout << "Masukkan koordinat titik A (x y): ";
    std::cin >> Ax >> Ay;
    std::cout << "Masukkan koordinat titik B (x y): ";
    std::cin >> Bx >> By;

    glutDisplayFunc(display);
    glutKeyboardFunc(userInput);

    glutMainLoop();

    return 0;
}
