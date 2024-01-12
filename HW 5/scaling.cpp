#include <GL/freeglut.h>
#include <iostream>

float scaleX = 1.0f;
float scaleY = 1.0f;

void drawTriangle()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 1.0f); // Warna biru
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f * scaleX, -0.5f * scaleY);
    glVertex2f(0.5f * scaleX, -0.5f * scaleY);
    glVertex2f(0.0f, 0.5f * scaleY);
    glEnd();
    glFlush();
}

void handleKeypress(unsigned char key, int x, int y)
{
    if (key == 27) // 27 adalah kode ASCII untuk tombol Escape
        exit(0);   // Keluar dari aplikasi jika Escape ditekan
}

void handleSpecialKeypress(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        scaleY += 0.1f; // Perbesar objek ke atas
        break;
    case GLUT_KEY_DOWN:
        scaleY -= 0.1f; // Perkecil objek ke bawah
        break;
    case GLUT_KEY_RIGHT:
        scaleX += 0.1f; // Perbesar objek ke kanan
        break;
    case GLUT_KEY_LEFT:
        scaleX -= 0.1f; // Perkecil objek ke kiri
        break;
    }
    glutPostRedisplay(); // Menampilkan ulang jendela setelah scaling diubah
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Warna background putih
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Scaling Segitiga");

    init();
    glutDisplayFunc(drawTriangle);
    glutKeyboardFunc(handleKeypress);
    glutSpecialFunc(handleSpecialKeypress);

    glutMainLoop();
    return 0;
}
