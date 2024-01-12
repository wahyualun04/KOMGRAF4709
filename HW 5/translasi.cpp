#include <GL/freeglut.h>
#include <iostream>

float Ax, Ay, Bx, By;
std::string nameA = "A", nameB = "B"; // Tetapkan nama A dan B
float AxTrans, AyTrans, BxTrans, ByTrans;
std::string nameATrans = "A'", nameBTrans = "B'"; // Tetapkan nama A' dan B'

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

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Gambar sumbu x dan y dengan nomor
    drawAxisWithNumbers();

    // Gambar garis awal yang menghubungkan titik A dan B
    glColor3f(0.0, 0.0, 0.0); // Warna hitam untuk garis
    drawLine(Ax, Ay, Bx, By);

    // Gambar garis hasil translasi yang menghubungkan titik A' dan B'
    glColor3f(0.0, 0.0, 1.0); // Warna biru untuk garis translasi
    drawLine(AxTrans, AyTrans, BxTrans, ByTrans);

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

    // Gambar titik A' (hasil translasi)
    glColor3f(0.0, 1.0, 0.0); // Warna hijau
    glPointSize(8.0);         // Perbesar ukuran titik
    glBegin(GL_POINTS);
    glVertex2f(AxTrans, AyTrans);
    glEnd();

    // Tampilkan label titik A' (hasil translasi)
    drawText(nameATrans.c_str(), AxTrans + 1.0, AyTrans + 1.0); // Sesuaikan posisi label

    // Gambar titik B' (hasil translasi)
    glColor3f(1.0, 0.0, 1.0); // Warna ungu
    glPointSize(8.0);         // Perbesar ukuran titik
    glBegin(GL_POINTS);
    glVertex2f(BxTrans, ByTrans);
    glEnd();

    // Tampilkan label titik B' (hasil translasi)
    drawText(nameBTrans.c_str(), BxTrans + 1.0, ByTrans + 1.0); // Sesuaikan posisi label

    // Menggambar garis potong-potong dari titik A ke sumbu X
    glColor3f(0.0, 0.0, 0.0); // Warna hitam untuk garis
    glLineStipple(1, 0x00FF); // Mengatur pola garis putus-putus
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex2f(Ax, Ay);
    glVertex2f(Ax, 0);
    glEnd();
    glDisable(GL_LINE_STIPPLE);

    // Menggambar garis potong-potong dari titik A ke sumbu Y
    glColor3f(0.0, 0.0, 0.0); // Warna hitam untuk garis
    glLineStipple(1, 0x00FF); // Mengatur pola garis putus-putus
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex2f(Ax, Ay);
    glVertex2f(0, Ay);
    glEnd();
    glDisable(GL_LINE_STIPPLE);

    // Menggambar garis potong-potong dari titik B ke sumbu X
    glColor3f(0.0, 0.0, 0.0); // Warna hitam untuk garis
    glLineStipple(1, 0x00FF); // Mengatur pola garis putus-putus
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex2f(Bx, By);
    glVertex2f(Bx, 0);
    glEnd();
    glDisable(GL_LINE_STIPPLE);

    // Menggambar garis potong-potong dari titik B ke sumbu Y
    glColor3f(0.0, 0.0, 0.0); // Warna hitam untuk garis
    glLineStipple(1, 0x00FF); // Mengatur pola garis putus-putus
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex2f(Bx, By);
    glVertex2f(0, By);
    glEnd();
    glDisable(GL_LINE_STIPPLE);

    // Menggambar garis potong-potong dari titik A' ke sumbu X
    glColor3f(0.0, 0.0, 0.0); // Warna hitam untuk garis
    glLineStipple(1, 0x00FF); // Mengatur pola garis putus-putus
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex2f(AxTrans, AyTrans);
    glVertex2f(AxTrans, 0);
    glEnd();
    glDisable(GL_LINE_STIPPLE);

    // Menggambar garis potong-potong dari titik A' ke sumbu Y
    glColor3f(0.0, 0.0, 0.0); // Warna hitam untuk garis
    glLineStipple(1, 0x00FF); // Mengatur pola garis putus-putus
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex2f(AxTrans, AyTrans);
    glVertex2f(0, AyTrans);
    glEnd();
    glDisable(GL_LINE_STIPPLE);

    // Menggambar garis potong-potong dari titik B' ke sumbu X
    glColor3f(0.0, 0.0, 0.0); // Warna hitam untuk garis
    glLineStipple(1, 0x00FF); // Mengatur pola garis putus-putus
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex2f(BxTrans, ByTrans);
    glVertex2f(BxTrans, 0);
    glEnd();
    glDisable(GL_LINE_STIPPLE);

    // Menggambar garis potong-potong dari titik B' ke sumbu Y
    glColor3f(0.0, 0.0, 0.0); // Warna hitam untuk garis
    glLineStipple(1, 0x00FF); // Mengatur pola garis putus-putus
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex2f(BxTrans, ByTrans);
    glVertex2f(0, ByTrans);
    glEnd();
    glDisable(GL_LINE_STIPPLE);

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
    glutCreateWindow("Translasi");

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-30.0, 30.0, -30.0, 30.0);

    std::cout << "Masukkan koordinat titik A (x y): ";
    std::cin >> Ax >> Ay;
    std::cout << "Masukkan koordinat titik B (x y): ";
    std::cin >> Bx >> By;

    std::cout << "Masukkan translasi (dx dy): ";
    float dx, dy;
    std::cin >> dx >> dy;

    AxTrans = Ax + dx;
    AyTrans = Ay + dy;
    BxTrans = Bx + dx;
    ByTrans = By + dy;

    glutDisplayFunc(display);
    glutKeyboardFunc(userInput);

    glutMainLoop();

    return 0;
}
