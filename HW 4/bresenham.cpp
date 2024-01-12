#include <GL/freeglut.h>
#include <iostream>
#include <string>
#include <cmath>

float Ax, Ay, Bx, By;
std::string nameA = "A", nameB = "B";

void drawAxisWithNumbers()
{
    // Menggambar sumbu X dan Y, serta penomoran sumbu-sumbu tersebut
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);

    // Sumbu X
    glVertex2f(-25.0, 0.0);
    glVertex2f(25.0, 0.0);

    // Sumbu Y
    glVertex2f(0.0, -25.0);
    glVertex2f(0.0, 25.0);

    glEnd();

    for (int i = -25; i <= 25; i++)
    {
        char num[4];
        snprintf(num, 4, "%d", i);
        glRasterPos2f(i - 0.2, -0.5);
        for (int j = 0; num[j] != '\0'; j++)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, num[j]);
        }
    }

    for (int i = -25; i <= 25; i++)
    {
        char num[4];
        snprintf(num, 4, "%d", i);
        glRasterPos2f(-0.8, i - 0.2);
        for (int j = 0; num[j] != '\0'; j++)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, num[j]);
        }
    }
}

void drawText(const char *text, float x, float y)
{
    // Menggambar teks pada posisi tertentu pada jendela
    glRasterPos2f(x, y);
    for (int i = 0; text[i] != '\0'; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

void bresenhamLine(int x1, int y1, int x2, int y2)
{
    // Menggambar garis dengan algoritma Bresenham berdasarkan titik awal dan akhir yang diberikan
    bool steep = std::abs(y2 - y1) > std::abs(x2 - x1);
    if (steep)
    {
        std::swap(x1, y1);
        std::swap(x2, y2);
    }
    if (x1 > x2)
    {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    int dx = x2 - x1;
    int dy = std::abs(y2 - y1);
    int error = dx / 2;
    int ystep = (y1 < y2) ? 1 : -1;
    int y = y1;

    for (int x = x1; x <= x2; x++)
    {
        if (steep)
        {
            glBegin(GL_POINTS);
            glVertex2i(y, x);
            glEnd();
        }
        else
        {
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
        }
        error -= dy;
        if (error < 0)
        {
            y += ystep;
            error += dx;
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawAxisWithNumbers();

    // Menggambar garis dengan algoritma Bresenham
    glColor3f(0.0, 0.0, 0.0);
    bresenhamLine(static_cast<int>(Ax), static_cast<int>(Ay), static_cast<int>(Bx), static_cast<int>(By));

    // Menggambar titik A
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(8.0);
    glBegin(GL_POINTS);
    glVertex2f(Ax, Ay);
    glEnd();

    // Menambahkan teks "A" di sekitar titik A
    drawText(nameA.c_str(), Ax + 1.0, Ay + 1.0);

    // Menggambar titik B
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(8.0);
    glBegin(GL_POINTS);
    glVertex2f(Bx, By);
    glEnd();

    // Menambahkan teks "B" di sekitar titik B
    drawText(nameB.c_str(), Bx + 1.0, By + 1.0);

    glFlush();
}

void userInput(unsigned char key, int x, int y)
{
    if (key == 27)
    {
        // Menutup program jika tombol ESC ditekan
        exit(0);
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Algoritma Bresenham");

    // Konfigurasi tampilan awal
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-30.0, 30.0, -30.0, 30.0);

    // Meminta pengguna untuk memasukkan koordinat titik A dan B
    std::cout << "Masukkan koordinat titik A (x y): ";
    std::cin >> Ax >> Ay;
    std::cout << "Masukkan koordinat titik B (x y): ";
    std::cin >> Bx >> By;

    glutDisplayFunc(display);
    glutKeyboardFunc(userInput);

    // Memulai loop utama GLUT
    glutMainLoop();

    return 0;
}
