#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <iostream>

// Posisi jendela
int windowPosX = 100;
int windowPosY = 100;
int windowWidth = 800;
int windowHeight = 600;

// Posisi objek
float objectX = 0.0f;
float objectY = 0.0f;

// Fungsi untuk merender objek
void renderObject()
{
    glColor3f(1.0f, 0.0f, 0.0f); // Warna merah
    glBegin(GL_TRIANGLES);
    glVertex2f(objectX, objectY);
    glVertex2f(objectX + 0.1f, objectY);
    glVertex2f(objectX + 0.05f, objectY + 0.1f);
    glEnd();
}

// Fungsi untuk merender tampilan
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    renderObject();
    glutSwapBuffers();
}

// Fungsi untuk mengatur ukuran tampilan
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Menggunakan glOrtho sebagai pengganti gluOrtho2D
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Fungsi untuk mengatur input dari keyboard
void keyboard(unsigned char key, int x, int y)
{
    if (key == 'w')
        objectY += 0.1f;
    if (key == 's')
        objectY -= 0.1f;
    if (key == 'a')
        objectX -= 0.1f;
    if (key == 'd')
        objectX += 0.1f;

    glutPostRedisplay();
}

// Fungsi untuk mengatur input dari mouse
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        std::cout << "Mouse diklik pada posisi (" << x << ", " << y << ")" << std::endl;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(windowPosX, windowPosY);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Contoh OpenGL dengan GLUT");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 0;
}
