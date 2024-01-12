#include <GL/freeglut.h>
#include <iostream>
#include <string>
#include <cmath>

float Ax, Ay, Bx, By;
std::string nameA = "A", nameB = "B";

void drawAxisWithNumbers()
{
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
    glRasterPos2f(x, y);
    for (int i = 0; text[i] != '\0'; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

void ddaLine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = std::max(std::abs(dx), std::abs(dy));

    float X_inc = static_cast<float>(dx) / static_cast<float>(steps);
    float Y_inc = static_cast<float>(dy) / static_cast<float>(steps);

    float x = static_cast<float>(x1);
    float y = static_cast<float>(y1);

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++)
    {
        glVertex2f(round(x), round(y));
        x += X_inc;
        y += Y_inc;
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawAxisWithNumbers();

    glColor3f(0.0, 0.0, 0.0);
    ddaLine(static_cast<int>(Ax), static_cast<int>(Ay), static_cast<int>(Bx), static_cast<int>(By));

    glColor3f(1.0, 0.0, 0.0);
    glPointSize(8.0);
    glBegin(GL_POINTS);
    glVertex2f(Ax, Ay);
    glEnd();

    drawText(nameA.c_str(), Ax + 1.0, Ay + 1.0);

    glColor3f(0.0, 0.0, 1.0);
    glPointSize(8.0);
    glBegin(GL_POINTS);
    glVertex2f(Bx, By);
    glEnd();

    drawText(nameB.c_str(), Bx + 1.0, By + 1.0);

    glFlush();
}

void userInput(unsigned char key, int x, int y)
{
    if (key == 27) // Tombol ESC untuk keluar
    {
        exit(0);
    }
    else if (key == 13) // Tombol Enter untuk mengkonfirmasi input
    {
        std::cout << "Masukkan koordinat titik A (x y): ";
        std::cin >> Ax >> Ay;
        std::cout << "Masukkan koordinat titik B (x y): ";
        std::cin >> Bx >> By;
        glutPostRedisplay(); // Meminta agar fungsi display dijalankan ulang
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Algoritma DDA");

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
