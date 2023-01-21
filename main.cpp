#include <stdlib.h> // standard definitions
#include <math.h> // math definitions
#include <stdio.h> // standard I/O

#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// escape key (for exit)
#define ESC 27

int sunce = 0;
// Camera position
float x = 15.0, y = -120.0, z = 22.0; // initially 5 units south of origin
float deltaMove = 0.0; // initially camera doesn't move

// Camera direction
float lx = 0.0, ly = 1.0; // camera points initially along y-axis
float angle = 0.0; // angle of rotation for the camera direction
float deltaAngle = 0.0; // additional angle change when dragging

// Mouse drag control
int isDragging = 0; // true when dragging
int xDragStart = 0; // records the x-coordinate when dragging starts

GLuint texture1;
GLuint texture2;
GLuint texture3;

//Funkcija za iscrtavanje texture
GLuint LoadTexture(const char* filename, int width, int height){
       GLuint texture;
       unsigned char* data;
       FILE* file;
       file=fopen(filename, "rb");
       if(file==NULL)return 0;
       data=(unsigned char*)malloc(width * height * 3);
       fread(data,width * height * 3,1,file);
       fclose(file);
       glGenTextures(1,&texture);
       glBindTexture(GL_TEXTURE_2D,texture);
       glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
       glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
       free(data);
       return texture;
}
void tepih()
{
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, texture1);
        glEnable(GL_TEXTURE_2D);
        glTranslatef(57.0,-2.0,0);
        glScalef(1.0,8,1.0);
        glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glTexCoord2d(1.0, 0.0); glVertex3f(5.55, 2, 1.2);
        glTexCoord2d(1.0, 1.0); glVertex3f(5.55, -2.2, 1.2);
        glTexCoord2d(0.0, 1.0); glVertex3f(1.2, -2.2, 1.2);
        glTexCoord2d(0.0, 0.0); glVertex3f(1.2, 2, 1.2);
        glEnd();

        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}
void prilaz()
{
    //staza
    glColor3f(0.9, 0.9, 0.9);
    glPushMatrix();
         glTranslatef(60.5,-28.0,1.1);
         glScalef(8.0, 17.8, 0.05);
         glutSolidCube(0.9);
    glPopMatrix();
}
void crtajKupatila()
{
    ///////////////////////////////////// MUSKO KUPATILO //////////////////////////////////
    //pregrade
    glColor3f(0.6, 0.8, 1.7);
    glPushMatrix();
         glTranslatef(44.8,8.0,1.1);
         glScalef(5.5, 0.2, 18.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(44.8,12.0,1.1);
         glScalef(5.5, 0.2, 18.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(44.8,16.0,1.1);
         glScalef(5.5, 0.2, 18.2);
         glutSolidCube(0.9);
    glPopMatrix();

    //granisna
    glColor3f(0.1, 0.0, 0.0);
    glPushMatrix();
         glTranslatef(46.8,12.2,7.1);
         glScalef(0.1, 17.5, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    //zakacke za zavesu
    glColor3f(0.9, 0.0, 0.0);
    glPushMatrix();
         glTranslatef(46.7,16.8,7.1);
         glScalef(0.4, 0.1, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(46.7,12.8,7.1);
         glScalef(0.4, 0.1, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(46.7,8.8,7.1);
         glScalef(0.4, 0.1, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(46.7,4.8,7.1);
         glScalef(0.4, 0.1, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    //zavese
    glColor3f(1.0, 0.9, 1.0);
    glPushMatrix();
         glTranslatef(46.6,4.8,1.4);
         glScalef(0.2, 0.4, 12.7);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(46.6,8.8,1.4);
         glScalef(0.2, 0.4, 12.7);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(46.6,12.8,1.4);
         glScalef(0.2, 0.4, 12.7);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(46.6,16.8,1.4);
         glScalef(0.2, 0.4, 12.7);
         glutSolidCube(0.9);
    glPopMatrix();

    //tusevi
    glColor3f(0.6, 0.6, 0.6);
    glPushMatrix();
         glTranslatef(45.7,7.0,6.5);
         glScalef(0.4, 2.0, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(45.7,11.0,6.5);
         glScalef(0.4, 2.0, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(45.7,15.0,6.5);
         glScalef(0.4, 2.0, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(45.7,19.0,6.5);
         glScalef(0.4, 2.0, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    //cesma
    glPushMatrix();
         glTranslatef(45.7,7.9,3.5);
         glScalef(1.0, 0.2, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(45.7,11.9,3.5);
         glScalef(1.0, 0.2, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(45.7,15.9,3.5);
         glScalef(1.0, 0.2, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(45.7,19.9,3.5);
         glScalef(1.0, 0.2, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    //lavaboi
    glColor3f(0.6, 0.8, 1.7);
    glPushMatrix();
         glTranslatef(55.0,10.2,3.1);
         glScalef(1.6, 9.5, 1.1);
         glutSolidCube(0.9);
    glPopMatrix();

    glColor3f(0.8, 0.8, 0.8);
    glPushMatrix();
         glTranslatef(55.0,8.2,3.8);
         glScalef(1.6, 2.5, 0.6);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(55.0,12.2,3.8);
         glScalef(1.6, 2.5, 0.4);
         glutSolidCube(0.9);
    glPopMatrix();

    //cesma na lavabou
    glColor3f(0.2, 0.1, 0.9);
    glPushMatrix();
         glTranslatef(55.2,8.2,4.3);
         glScalef(1.1, 0.5, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(55.2,12.2,4.3);
         glScalef(1.1, 0.5, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();

    //WC
    glColor3f(0.8, 0.8, 0.8);
    glPushMatrix();
         glTranslatef(54.7,17.6,2.0);
         glScalef(2.6, 2.5, 0.4);
         glutSolidCube(0.9);
    glPopMatrix();
    //zidovi wc-a
    glColor3f(0.9, 0.9, 0.9);
    glPushMatrix();
         glTranslatef(54.3,15.8,1.1);
         glScalef(3.5, 0.2, 18.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(49.8,18.2,1.1);
         glScalef(0.5, 5.2, 18.2);
         glutSolidCube(0.9);
    glPopMatrix();

    /////////////////////////////// ZENSKO KUPATILO ////////////////////////////////////////////
    //pregrade
    glColor3f(1,0.8,0.8);
    glPushMatrix();
         glTranslatef(76.2,8.0,5.1);
         glScalef(5.5, 0.2, 9.5);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(76.2,12.0,5.1);
         glScalef(5.5, 0.2, 9.5);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(76.2,16.0,5.1);
         glScalef(5.5, 0.2, 9.5);
         glutSolidCube(0.9);
    glPopMatrix();

    //granisna
    glColor3f(0.1, 0.0, 0.0);
    glPushMatrix();
         glTranslatef(74.3,12.2,7.1);
         glScalef(0.1, 17.5, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    //zakacke za zavesu
    glColor3f(0.9, 0.0, 0.0);
    glPushMatrix();
         glTranslatef(74.3,16.8,7.1);
         glScalef(0.4, 0.1, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(74.3,12.8,7.1);
         glScalef(0.4, 0.1, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(74.3,8.8,7.1);
         glScalef(0.4, 0.1, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(74.3,4.8,7.1);
         glScalef(0.4, 0.1, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    //zavese u zenskom kupatilu
    glColor3f(1.0, 0.9, 1.0);
    glPushMatrix();
         glTranslatef(74.4,4.8,1.4);
         glScalef(0.2, 0.4, 12.7);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(74.4,8.8,1.4);
         glScalef(0.2, 0.4, 12.7);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(74.4,12.8,1.4);
         glScalef(0.2, 0.4, 12.7);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(74.4,16.8,1.4);
         glScalef(0.2, 0.4, 12.7);
         glutSolidCube(0.9);
    glPopMatrix();

    //tusevi
    glColor3f(0.6, 0.6, 0.6);
    glPushMatrix();
         glTranslatef(76.7,7.0,6.5);
         glScalef(0.4, 2.0, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(76.7,11.0,6.5);
         glScalef(0.4, 2.0, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(76.7,15.0,6.5);
         glScalef(0.4, 2.0, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(76.7,19.0,6.5);
         glScalef(0.4, 2.0, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    //cesma
    glPushMatrix();
         glTranslatef(76.7,7.9,3.5);
         glScalef(1.0, 0.2, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(76.7,11.9,3.5);
         glScalef(1.0, 0.2, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(76.7,15.9,3.5);
         glScalef(1.0, 0.2, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(76.7,19.9,3.5);
         glScalef(1.0, 0.2, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    //lavaboi
    glColor3f(1,0.8,0.8);
    glPushMatrix();
         glTranslatef(65.6,10.2,3.1);
         glScalef(1.6, 9.5, 1.1);
         glutSolidCube(0.9);
    glPopMatrix();

    glColor3f(0.8, 0.8, 0.8);
    glPushMatrix();
         glTranslatef(65.6,8.2,3.8);
         glScalef(1.6, 2.5, 0.6);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(65.6,12.2,3.8);
         glScalef(1.6, 2.5, 0.4);
         glutSolidCube(0.9);
    glPopMatrix();

    //cesma na lavabou
    glColor3f(0.8, 0.0, 0.2);
    glPushMatrix();
         glTranslatef(65.4,8.2,4.3);
         glScalef(1.1, 0.5, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(65.4,12.2,4.3);
         glScalef(1.1, 0.5, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();

    //WC
    glColor3f(0.8, 0.8, 0.8);
    glPushMatrix();
         glTranslatef(66.1,17.6,2.0);
         glScalef(2.6, 2.5, 0.4);
         glutSolidCube(0.9);
    glPopMatrix();

    //zidovi wc-a
    glColor3f(0.9, 0.9, 0.9);
    glPushMatrix();
         glTranslatef(66.4,15.8,1.1);
         glScalef(3.5, 0.2, 18.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(70.8,18.2,1.1);
         glScalef(0.5, 5.2, 18.2);
         glutSolidCube(0.9);
    glPopMatrix();
}
void crtajRecepciju()
{
    //pult
    glColor3f(0.3, 0.4, 0.2);
    glPushMatrix();
         glTranslatef(47.9,-12.1,2.7);
         glScalef(2.0, 11.0, 2.8);
         glutSolidCube(0.9);
    glPopMatrix();
    glColor3f(0.7, 0.0, 0.7);
    glPushMatrix();
         glTranslatef(48.75,-12.1,4.3);
         glScalef(0.1, 11.0, 0.9);
         glutSolidCube(0.9);
    glPopMatrix();

    //kauc
    glColor3f(0.7, 0.0, 0.7);
    glPushMatrix();
         glTranslatef(52.9,-8.6,1.7);
         glScalef(6.5, 2.5, 1.6);
         glutSolidCube(0.9);
    glPopMatrix();

    glColor3f(0.7, 0.3, 0.7);
    glPushMatrix();
         glTranslatef(52.9,-7.7,3.3);
         glScalef(6.5, 0.5, 2.0);
         glutSolidCube(0.9);
    glPopMatrix();
    //naslon za ruke 1
    glPushMatrix();
         glTranslatef(56.0,-8.6,2.2);
         glScalef(0.5, 2.6, 2.3);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(49.9,-8.6,2.2);
         glScalef(0.5, 2.6, 2.3);
         glutSolidCube(0.9);
    glPopMatrix();

    //fotelja 1
    glColor3f(0.7, 0.0, 0.7);
    glPushMatrix();
         glTranslatef(66.4,-15.0,1.7);
         glScalef(2.5, 4.0, 1.6);
         glutSolidCube(0.9);
    glPopMatrix();
    glColor3f(0.7, 0.3, 0.7);
    glPushMatrix();
         glTranslatef(67.28,-15.0,3.3);
         glScalef(0.5, 4.0, 2.0);
         glutSolidCube(0.9);
    glPopMatrix();
    //naslon za ruke 2
    glPushMatrix();
         glTranslatef(66.4,-13.0,2.2);
         glScalef(2.5, 0.5, 2.3);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(66.4,-17.0,2.2);
         glScalef(2.5, 0.5, 2.3);
         glutSolidCube(0.9);
    glPopMatrix();

    //lampa 1
    glColor3f(0.647059, 0.4, 0.0);
    glPushMatrix();
         glTranslatef(66.4,-18.5,1.2);
         glScalef(1.0, 1.0, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glColor3f(0.647059, 0.4, 0.0);
    glPushMatrix();
         glTranslatef(66.4,-18.5,3.5);
         glScalef(0.1, 0.2, 6.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glColor3f(0.3, 0.4, 0.2);
    glPushMatrix();
         glTranslatef(66.4,-18.5,5.8);
         glScalef(0.3, 0.3, 4.0);
         glutSolidCone(3,0.2,8,8);
    glPopMatrix();

    //lampa 2
    glColor3f(0.647059, 0.4, 0.0);
    glPushMatrix();
         glTranslatef(69.7,-18.5,1.2);
         glScalef(1.0, 1.0, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glColor3f(0.647059, 0.4, 0.0);
    glPushMatrix();
         glTranslatef(69.7,-18.5,3.5);
         glScalef(0.1, 0.2, 6.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glColor3f(0.3, 0.4, 0.2);
    glPushMatrix();
         glTranslatef(69.7,-18.5,5.8);
         glScalef(0.3, 0.3, 4.0);
         glutSolidCone(3,0.2,8,8);
    glPopMatrix();

    //fotelja 2
    glColor3f(0.7, 0.0, 0.7);
    glPushMatrix();
         glTranslatef(69.9,-15.0,1.7);
         glScalef(2.5, 4.0, 1.6);
         glutSolidCube(0.9);
    glPopMatrix();
    glColor3f(0.7, 0.3, 0.7);
    glPushMatrix();
         glTranslatef(69.0,-15.0,3.3);
         glScalef(0.5, 4.0, 2.0);
         glutSolidCube(0.9);
    glPopMatrix();
    //naslon za ruke 2
    glPushMatrix();
         glTranslatef(69.9,-13.0,2.2);
         glScalef(2.5, 0.5, 2.3);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(69.9,-17.0,2.2);
         glScalef(2.5, 0.5, 2.3);
         glutSolidCube(0.9);
    glPopMatrix();

    //radni sto u kancelariji
    glColor3f(0.3, 0.3, 0.3);
    //nogare
    glPushMatrix();
         glTranslatef(73.9,-13.0,2.4);
         glScalef(0.2, 0.2, 2.3);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(73.9,-18.0,2.4);
         glScalef(0.2, 0.2, 2.3);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(75.5,-13.0,2.4);
         glScalef(0.2, 0.2, 2.3);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(75.5,-18.0,2.4);
         glScalef(0.2, 0.2, 2.3);
         glutSolidCube(0.9);
    glPopMatrix();
    //daska
    glPushMatrix();
         glTranslatef(74.8,-15.5,3.5);
         glScalef(2.5, 6.0, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    //stolica za radni sto u kancelariji
    //nogare
    glPushMatrix();
         glTranslatef(75.9,-15.0,2.0);
         glScalef(0.2, 0.2, 1.5);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(75.9,-16.8,2.0);
         glScalef(0.2, 0.2, 1.5);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(76.9,-15.0,2.0);
         glScalef(0.2, 0.2, 1.5);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(76.9,-16.8,2.0);
         glScalef(0.2, 0.2, 1.5);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(76.4,-15.9,2.65);
         glScalef(1.3, 2.0, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();

    //naslon za ledja
    glPushMatrix();
         glTranslatef(76.9,-15.9,3.65);
         glScalef(0.3, 2.0, 2.2);
         glutSolidCube(0.9);
    glPopMatrix();

    //papiri na stolu
    glColor3f(0.9,0.9,0.9);
    glPushMatrix();
         glTranslatef(74.9,-15.9,3.65);
         glScalef(1.2, 1.8, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    //komoda u kancelariji
    glColor3f(0.7,0.8,0.8);
    glPushMatrix();
         glTranslatef(77.4,-9.4,2.6);
         glScalef(1.2, 4.1, 4.1);
         glutSolidCube(0.9);
    glPopMatrix();


}
void changeSize(int w, int h)
{
	float ratio =  ((float) w) / ((float) h); // window aspect ratio
	glMatrixMode(GL_PROJECTION); // projection matrix is active
	glLoadIdentity(); // reset the projection
	gluPerspective(45.0, ratio, 0.1, 1000.0); // perspective transformation
	glMatrixMode(GL_MODELVIEW); // return to modelview mode
	glViewport(0, 0, w, h); // set viewport (drawing area) to entire window
}
void crtajKlupeZaPubliku()
{
    //daske
    glColor3f(0.4, 0.2, 0.2);
    glPushMatrix();
         glTranslatef(-50.5,32,2.4);
         glScalef(9.0, 2.8, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-50.5,34.8,4.0);
         glScalef(9.0, 2.8, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();


    //nogare
    glColor3f(0.1, 0.2, 0.2);
    glPushMatrix();
         glTranslatef(-54.5,33.5,1.1);
         glScalef(0.3, 5.6, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-46.5,33.5,1.1);
         glScalef(0.3, 5.6, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(-54.5,31.0,1.8);
         glScalef(0.1, 0.2, 1.5);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-54.5,33.0,1.8);
         glScalef(0.1, 0.2, 1.5);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-54.5,33.8,2.5);
         glScalef(0.1, 0.2, 3.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-54.5,35.6,2.5);
         glScalef(0.1, 0.2, 3.2);
         glutSolidCube(0.9);
    glPopMatrix();
    //////////////////////////////////
    glPushMatrix();
         glTranslatef(-46.5,31.0,1.8);
         glScalef(0.1, 0.2, 1.5);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-46.5,33.0,1.8);
         glScalef(0.1, 0.2, 1.5);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-46.5,33.8,2.5);
         glScalef(0.1, 0.2, 3.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-46.5,35.6,2.5);
         glScalef(0.1, 0.2, 3.2);
         glutSolidCube(0.9);
    glPopMatrix();
}

void update(void)
{
	if (deltaMove) { // update camera position
		x += deltaMove * lx * 0.1;
		y += deltaMove * ly * 0.1;
	}
	glutPostRedisplay(); // redisplay everything
}
void crtajCentar()
{

    //pod
    glColor3f(0.8, 0.9, 0.8);
    glPushMatrix();
         glTranslatef(60.5,0,1.1);
         glScalef(40.6, 45.8, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();

    //zidovi
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
         glTranslatef(78.6,0,5.1);
         glScalef(0.5, 45.8, 9.5);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(42.5,0,5.1);
         glScalef(0.5, 45.8, 9.5);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(49.5,-20,5.1);
         glScalef(15.5, 0.8, 9.5);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(71.5,-20,5.1);
         glScalef(15.5, 0.8, 9.5);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(49.5,20,5.1);
         glScalef(15.5, 0.3, 9.5);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(71.3,20,5.1);
         glScalef(15.5, 0.3, 9.5);
         glutSolidCube(0.9);
    glPopMatrix();

    //svlacionica i kupaonica za muskarce
    glColor3f(0.0, 0.5, 0.9);
    glPushMatrix();
         glTranslatef(46.0,4,5.1);
         glScalef(8.0, 0.3, 9.5);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(54.9,4,5.1);
         glScalef(1.9, 0.3, 9.5);
         glutSolidCube(0.9);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
         glTranslatef(55.8,9.2,5.1);
         glScalef(0.3, 24.0, 9.5);
         glutSolidCube(0.9);
    glPopMatrix();
    glColor3f(1.0, 1.0, 1.0);
    //svlacionica i kupaonica za zene
    glPushMatrix();
         glTranslatef(64.9,9.2,5.1);
         glScalef(0.3, 24.0, 9.5);
         glutSolidCube(0.9);
    glPopMatrix();
    glColor3f(0.8, 0.0, 0.2);
    glPushMatrix();
         glTranslatef(65.9,4,5.1);
         glScalef(1.9, 0.3, 9.5);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(75.0,4,5.1);
         glScalef(8.0, 0.3, 9.5);
         glutSolidCube(0.9);
    glPopMatrix();
    ///////////////////////////////////
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
         glTranslatef(49.8,-7,5.1);
         glScalef(16.5, 0.3, 9.5);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(71.3,-7,5.1);
         glScalef(16.5, 0.3, 9.5);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(68.3,-15.9,5.1);
         glScalef(0.5, 9.0, 9.5);
         glutSolidCube(0.9);
    glPopMatrix();

}
void crtajKomodu()
{
    //muska komoda
    glColor3f(0.6, 0.8, 1.7);
    glPushMatrix();
         glTranslatef(43.9,1.8,4.2);
         glScalef(1.5, 4.0, 7);
         glutSolidCube(0.9);
    glPopMatrix();

    //rucke
    glColor3f(0.3, 0.3, 0.3);
    glPushMatrix();
         glTranslatef(44.6,0.3,4.0);
         glScalef(0.1, 0.4, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(44.6,0.3,4.3);
         glScalef(0.1, 0.4, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(44.6,2.1,4.0);
         glScalef(0.1, 0.4, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(44.6,2.1,4.3);
         glScalef(0.1, 0.4, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();


    //zenska komoda
    glColor3f(1,0.8,0.8);
    glPushMatrix();
         glTranslatef(76.9,1.8,4.2);
         glScalef(1.5, 4.0, 7);
         glutSolidCube(0.9);
    glPopMatrix();

    //rucke
    glColor3f(0.3, 0.3, 0.3);
    glPushMatrix();
         glTranslatef(76.2,0.3,4.0);
         glScalef(0.1, 0.4, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(76.2,0.3,4.3);
         glScalef(0.1, 0.4, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(76.2,2.1,4.0);
         glScalef(0.1, 0.4, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(76.2,2.1,4.3);
         glScalef(0.1, 0.4, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

}
void crtajKlupu()
{
    glColor3f(0.4, 0.2, 0.2);
    //dusek
    glPushMatrix();
         glTranslatef(-8,8,2.2);
         glScalef(1.6, 6.8, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();

    //nogare
    glColor3f(0.1, 0.2, 0.2);
    glPushMatrix();
         glTranslatef(-7.4,5.05,1.6);
         glScalef(0.2, 0.2, 1.52);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-8.6,5.05,1.6);
         glScalef(0.2, 0.2, 1.5);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-8.6,10.95,1.6);
         glScalef(0.2, 0.2, 1.52);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-7.4,10.95,1.6);
         glScalef(0.2, 0.2, 1.52);
         glutSolidCube(0.9);
    glPopMatrix();
}
void crtajPod()
{
    //beton

    glColor3f(0.7, 0.7, 0.7);

    glPushMatrix();
         glTranslatef(0,0,0);
         glScalef(180.5, 0.1, 80);
         glutSolidCube(0.9);
    glPopMatrix();


}
void crtajKrov()
{
    //krov
    glColor3f(0.4, 0.5, 0.5);
    glPushMatrix();
         glTranslatef(60.5,0,9.4);
         glScalef(40.6, 45.8, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glColor3f(0.2, 0.5, 0.0);
    glPushMatrix();
         glTranslatef(60.5,0,10.5);
         glScalef(40.6, 45.8, 2.2);
         glutSolidCube(0.9);
    glPopMatrix();

    glColor3f(0.2, 0.3, 0.0);
    glPushMatrix();
         glTranslatef(60.5,0,12.5);
         glScalef(35.0, 10.0, 2.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(60.5,13,12.5);
         glScalef(35.0, 10.0, 2.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(60.5,-13,12.5);
         glScalef(35.0, 10.0, 2.2);
         glutSolidCube(0.9);
    glPopMatrix();
}
void crtajStolice()
{

    glColor3f(0.4, 0.2, 0.2);
    //dusek
    glPushMatrix();
         glTranslatef(-7,0,7.2);
         glScalef(1.9, 1.8, 1);
         glutSolidCube(0.9);
    glPopMatrix();

    //naslanjac za ledja
    glColor3f(0.1, 0.2, 0.2);
    glPushMatrix();
         glTranslatef(-8,0,8.7);
         glScalef(0.9, 1.9, 2.5);
         glutSolidCube(0.9);
    glPopMatrix();
    //stepenice
    glColor3f(0.4, 0.2, 0.2);
    glPushMatrix();
         glTranslatef(-6,0,2);
         glScalef(0.2, 1.9, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-6,0,3);
         glScalef(0.2, 1.9, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-6,0,4);
         glScalef(0.2, 1.9, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-6,0,5);
         glScalef(0.2, 1.9, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-6,0,6);
         glScalef(0.2, 1.9, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();
    //naslon za ruke
    glColor3f(0.1, 0.2, 0.2);
    glPushMatrix();
         glTranslatef(-7,-1,8.7);
         glScalef(2.8, 0.2, 0.5);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-7,1,8.7);
         glScalef(2.8, 0.2, 0.5);
         glutSolidCube(0.9);
    glPopMatrix();
    //nogare
    glColor3f(0.1, 0.2, 0.2);
    glPushMatrix();
         glTranslatef(-8,1,0);
         glScalef(0.4, 0.4, 19);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-8,-1,0);
         glScalef(0.4, 0.4, 19);
         glutSolidCube(0.9);
    glPopMatrix();


    glPushMatrix();
         glTranslatef(-6,1,0);
         glScalef(0.4, 0.4, 19);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(-6,-1,0);
         glScalef(0.4, 0.4, 19);
         glutSolidCube(0.9);
    glPopMatrix();
}
void crtajDrvo()
{
    //stablo
    glColor3f(0.647059, 0.4, 0.2);
    glPushMatrix();
         glTranslatef(0,0,6.2);
         glScalef(1.4, 1.4, 10);
         glutSolidCube(0.9);
    glPopMatrix();

    //zimzeleno
    glColor3f(0.2, 0.4, 0.0);
    glPushMatrix();
         glTranslatef(0.0, 0.0, 5.6);
        glutSolidCone(6,5,15,21);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(0.0, 0.0, 7.6);
        glutSolidCone(5,4,15,21);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(0.0, 0.0, 9.6);
        glutSolidCone(4,3,15,21);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(0.0, 0.0, 11.6);
        glutSolidCone(3,2,15,21);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(0.0, 0.0, 13.1);
        glutSolidCone(2,2,15,21);
    glPopMatrix();

}

void crtajTerene()
{
    //////////////////////////////////////// TEREN 1 /////////////////////////////////////////////////

    glColor3f(0.7, 0.0, 0.7);

    glPushMatrix();
         glTranslatef(-30,0.0,0.6);
         glScalef(30, 50.1, 1);
         glutSolidCube(0.9);
    glPopMatrix();

    //bijele linije
    glColor3f(1, 1, 1);

    ///////////////////////////////////////// MREZA 1 ///////////////////////////////////////////////
    //vertikalna mreza
    glPushMatrix();
         glTranslatef(-43.0,0.0,1.1);
         glScalef(0.5, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(-42.5,0.0,1.1);
         glScalef(0.5, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-42.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-41.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-41.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-40.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-40.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-39.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-39.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-38.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-38.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-37.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-37.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-36.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-36.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-35.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-35.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-34.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-34.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-33.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-33.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-32.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-32.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-31.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-31.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-30.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-30.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-29.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-29.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-28.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-28.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-27.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-27.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-26.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-26.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-25.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-25.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-24.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-24.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-23.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-23.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-22.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-22,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
glPushMatrix();
         glTranslatef(-21.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-21.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-20.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-20.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-19.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-19,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-18.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-18.0,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-17.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-17,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-16.5,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();


    //stub
    glPushMatrix();
         glTranslatef(-16.0,0.0,1.1);
         glScalef(0.5, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();

    //horizontalna mreza
    glPushMatrix();
         glTranslatef(-29.7,0.0,4.1);
         glScalef(30, 0.1, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-29.7,0.0,4.1);
         glScalef(30, 0.1, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-29.7,0.0,3.6);
         glScalef(30, 0.01, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-29.7,0.0,3.1);
         glScalef(30, 0.01, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-29.7,0.0,2.7);
         glScalef(30, 0.01, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-29.7,0.0,2.3);
         glScalef(30, 0.01, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-29.7,0.0,1.9);
         glScalef(30, 0.01, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-29.7,0.0,1.6);
         glScalef(30, 0.01, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    //horizontalne linije
    glPushMatrix();
         glTranslatef(-29.7,0.0,1.1);
         glScalef(30, 0.1, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(-29.8,9.0,1.1);
         glScalef(22, 0.1, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-29.8,-9.0,1.1);
         glScalef(22, 0.1, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    //vertikalne linije
    glPushMatrix();
         glTranslatef(-30,0.0,1.1);
         glScalef(0.1, 20, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(-40,0.0,1.1);
         glScalef(0.1, 50, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(-20,0.0,1.1);
         glScalef(0.1, 49.8, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();


    //////////////////////////////////////// TEREN 2 ///////////////////////////////////////////////
    glColor3f(0.7, 0.0, 0.7);
    glPushMatrix();
         glTranslatef(10,0.0,0.6);
         glScalef(30, 49.8, 1);
         glutSolidCube(0.9);
    glPopMatrix();

    //bijele linije
    glColor3f(1, 1, 1);

        //vertikalna mreza

    glPushMatrix();
         glTranslatef(-3.35,0.0,1.1);
         glScalef(0.5, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-2.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-2.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-1.8,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-1.3,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-0.8,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-0.3,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(0.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(0.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(1.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(1.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(2.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(2.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(3.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(3.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(4.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(4.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(5.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(5.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(6.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(6.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(7.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(7.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(8.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(8.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(9.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(9.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(10.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(10.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(11.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(11.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(12.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(12.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(12.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(12.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(13.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(13.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(14.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(14.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(15.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(15.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(15.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(15.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(16.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(16.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(17.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(17.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(18.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(18.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(19.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(19.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(20.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(20.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(21.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(21.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(22.2,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(22.7,0.0,1.0);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();


    //stub
    glPushMatrix();
         glTranslatef(23.5,0.0,1.1);
         glScalef(0.5, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();

    //horizontalna mreza
    glPushMatrix();
         glTranslatef(9.9,0.0,4.1);
         glScalef(30, 0.1, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(9.9,0.0,4.1);
         glScalef(30, 0.1, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(9.9,0.0,3.6);
         glScalef(30, 0.01, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(9.9,0.0,3.1);
         glScalef(30, 0.01, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(9.9,0.0,2.7);
         glScalef(30, 0.01, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(9.9,0.0,2.3);
         glScalef(30, 0.01, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(9.9,0.0,1.9);
         glScalef(30, 0.01, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(9.9,0.0,1.6);
         glScalef(30, 0.01, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    //horizontalne linije
    glPushMatrix();
         glTranslatef(10,0.0,1.1);
         glScalef(30, 0.1, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(10,9.0,1.1);
         glScalef(22.0, 0.1, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(10,-9.0,1.1);
         glScalef(22.0, 0.1, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();


    //vertikalne linije
    glPushMatrix();
         glTranslatef(10,0.0,1.1);
         glScalef(0.1, 20, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(0,0.0,1.1);
         glScalef(0.1, 49.7, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(20,0.0,1.1);
         glScalef(0.1, 49.7, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();

}

void prozori()
{
    glColor3f(0.0, 0.7, 1.0);
    glPushMatrix();
         glTranslatef(48.9,-20.0,5.3);
         glScalef(6.5, 1.5, 4.6);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(71.9,-20.0,5.3);
         glScalef(6.5, 1.5, 4.6);
         glutSolidCube(0.9);
    glPopMatrix();
}
void lightoff(unsigned char key, int x, int y) {

    key = tolower(key);
    if (key == 'a') {
        glDisable(GL_LIGHT0);
    }
    if (key == 's') {
        glEnable(GL_LIGHT0);
    }
    if (key == 'o') {
        glDisable(GL_LIGHT1);
    }
    if (key == 'p') {
        glEnable(GL_LIGHT1);
    }

    if (key == 'n') {
        glDisable(GL_LIGHT2);
    }
    if (key == 'm') {
        glEnable(GL_LIGHT2);
    }

    glutPostRedisplay();
}
void renderScene(void)
{
    glShadeModel(GL_SMOOTH);
     glEnable(GL_DEPTH_TEST);
     glDepthFunc(GL_LESS);
     glEnable(GL_LIGHTING);
     glEnable(GL_NORMALIZE);
     glEnable(GL_COLOR_MATERIAL);

     GLfloat lmodel_ambient[] = { 0.0, 0.0, 0.0, 1.9 };
     GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
     GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 0.0 };
     GLfloat light_positionSunce[] = { 55.0, 55.0, 50.0, 0.0 };

     GLfloat mat_amb_diff[] = { 0.7, 0.7, 0.7, 1.0 };
     GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
     GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
     GLfloat low_shininess[] = { 10.0 };

     glLightfv(GL_LIGHT0,GL_AMBIENT,lmodel_ambient);
     glLightfv(GL_LIGHT0,GL_DIFFUSE,light1_diffuse);
     glLightfv(GL_LIGHT0,GL_SPECULAR,light1_specular);
     glLightfv(GL_LIGHT0, GL_POSITION, light_positionSunce);
     glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, low_shininess);
	int i, j;

	// Clear color and depth buffers
	glClearColor(0.0, 0.7, 1.0, 0.4); // sky color is light blue
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	// Set the camera centered at (x,y,1) and looking along directional
	// vector (lx, ly, 0), with the z-axis pointing up
	gluLookAt(
            x,      y,      z,
			x + lx, y + ly, z,
			0.0,    0.0,    1.0);

	// Draw ground - 200x200 square colored green
	glColor3f(0.0, 0.7, 0.0);
	glBegin(GL_QUADS);
		glVertex3f(-1000.0, -1000.0, 0.0);
		glVertex3f(-1000.0,  1000.0, 0.0);
		glVertex3f( 1000.0,  1000.0, 0.0);
		glVertex3f( 1000.0, -1000.0, 0.0);
	glEnd();


	glPushMatrix();
   glTranslatef(0, 0, 1);
   glRotatef(90, 1, 0,0);
   //glColor3f(1.0, 0.7, 0.0);

   crtajPod();
   crtajTerene();
   crtajStolice();
   crtajCentar();
   crtajKomodu();
   crtajRecepciju();
   crtajKupatila();
   crtajKrov();
   crtajKlupeZaPubliku();
   prilaz();
   prozori();
   tepih();


   //  DRVECE
    glTranslatef(12,41,0);
    crtajDrvo();
    glTranslatef(15,0,0);
    crtajDrvo();
    glTranslatef(15,0,0);
    crtajDrvo();
    glTranslatef(15,0,0);
    crtajDrvo();
    glTranslatef(15,0,0);
    crtajDrvo();
    glTranslatef(-75,0,0);
    crtajDrvo();
    glTranslatef(-15,0,0);
    crtajDrvo();
    glTranslatef(-15,0,0);
    crtajDrvo();
    glTranslatef(-15,0,0);
    crtajDrvo();
    glTranslatef(-15,0,0);
    crtajDrvo();
    glTranslatef(0,-15,0);
    crtajDrvo();
    glTranslatef(0,-15,0);
    crtajDrvo();
    glTranslatef(0,-15,0);
    crtajDrvo();
    glTranslatef(0,-15,0);
    crtajDrvo();
    glTranslatef(0,-15,0);
    crtajDrvo();
    glTranslatef(0,-15,0);
    crtajDrvo();
    glTranslatef(15,0,0);
    crtajDrvo();
    glTranslatef(15,0,0);
    crtajDrvo();
    glTranslatef(15,0,0);
    crtajDrvo();
    glTranslatef(15,0,0);
    crtajDrvo();
    glTranslatef(15,0,0);
    crtajDrvo();
    glTranslatef(15,0,0);
    crtajDrvo();

    glTranslatef(-67,48,0);
    crtajStolice();

    glTranslatef(1,0,0);
    crtajKlupu();
    glTranslatef(0,-16,0);
    crtajKlupu();
    glTranslatef(40,0,0);
    crtajKlupu();
    glTranslatef(0,17,0);
    crtajKlupu();

    glTranslatef(51,-11.2,0);
    crtajKlupu();
    glRotatef(90,0,0,1);
    glTranslatef(13.5,-2.3,0);
    crtajKlupu();

    glTranslatef(0,-28.3,0);
    crtajKlupu();

    glRotatef(-90,0,0,1);
    glTranslatef(2.5,-13.5,0);
    crtajKlupu();

    glTranslatef(-75.5,11.0,0);
    crtajKlupeZaPubliku();
    glTranslatef(9.5,0.0,0);
    crtajKlupeZaPubliku();
    glTranslatef(9.5,0.0,0);
    crtajKlupeZaPubliku();
    glTranslatef(9.5,0.0,0);
    crtajKlupeZaPubliku();
    glTranslatef(9.5,0.0,0);
    crtajKlupeZaPubliku();
    glTranslatef(9.5,0.0,0);
    crtajKlupeZaPubliku();
    glTranslatef(9.5,0.0,0);
    crtajKlupeZaPubliku();
    glTranslatef(9.5,0.0,0);
    crtajKlupeZaPubliku();


    //rotacija klupe
    glRotatef(-90,0,0,1);
    glTranslatef(35,-75.0,0);
    crtajKlupeZaPubliku();
    glTranslatef(10,0.0,0);
    crtajKlupeZaPubliku();
    glTranslatef(10,0.0,0);
    crtajKlupeZaPubliku();
    glTranslatef(10,0.0,0);
    crtajKlupeZaPubliku();

    //rotacija klupe
    glRotatef(-90,0,0,1);
    glTranslatef(30,-65.0,0);
    crtajKlupeZaPubliku();
    glTranslatef(10,0.0,0);
    crtajKlupeZaPubliku();
    glTranslatef(10,0.0,0);
    crtajKlupeZaPubliku();
    glTranslatef(10,0.0,0);
    crtajKlupeZaPubliku();
    glTranslatef(10,0.0,0);
    crtajKlupeZaPubliku();
    glTranslatef(10,0.0,0);
    crtajKlupeZaPubliku();
    glTranslatef(10,0.0,0);
    crtajKlupeZaPubliku();
    glTranslatef(10,0.0,0);
    crtajKlupeZaPubliku();

	glutSwapBuffers(); // Make it all visible
}
void processNormalKeys(unsigned char key, int xx, int yy)
{
	if (key == ESC || key == 'q' || key == 'Q') exit(0);
}

void pressSpecialKey(int key, int xx, int yy)
{
	switch (key) {
		case GLUT_KEY_UP : deltaMove = 0.8; break;
		case GLUT_KEY_DOWN : deltaMove = -0.8; break;
	}
}

void releaseSpecialKey(int key, int x, int y)
{
	switch (key) {
		case GLUT_KEY_UP : deltaMove = 0.0; break;
		case GLUT_KEY_DOWN : deltaMove = 0.0; break;
	}
}

void mouseMove(int x, int y)
{
	if (isDragging) { // only when dragging
		// update the change in angle
		deltaAngle = (x - xDragStart) * 0.005;

		// camera's direction is set to angle + deltaAngle
		lx = -sin(angle + deltaAngle);
		ly = cos(angle + deltaAngle);
	}
}

void mouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) { // left mouse button pressed
			isDragging = 1; // start dragging
			xDragStart = x; // save x where button first pressed
		}
		else  { /* (state = GLUT_UP) */
			angle += deltaAngle; // update camera turning angle
			isDragging = 0; // no longer dragging
		}
	}
}

//----------------------------------------------------------------------
// Main program  - standard GLUT initializations and callbacks
//----------------------------------------------------------------------
void menu (int b)
{
     if(b==1)
     {
            x=15.0;
            y=-120.0;
            z=22.0;
     }
     if(b==2)
     {
			x=50.0;
            y=-60.0;
            z=5.5;
     }
     if(b==3)
     {
			x=60.0;
            y=-18.0;
            z=5.0;
     }
     if(b==4)
     {
			x=60.0;
            y=-7.0;
            z=5.0;
     }
     if(b==5)
     {
			x=-10.0;
            y=-40.0;
            z=7.0;
     }
     if(b==6)
     {
			if(sunce == 0)
            {
                glEnable(GL_LIGHT0);
                sunce = 1;
            }
            else
            {
                glDisable(GL_LIGHT0);
                sunce = 0;
            }
     }
     glutPostRedisplay();
}
void kreirajMeni()
{
     glutCreateMenu(menu);
     glutAddMenuEntry("Wimbledon centar",1);
     glutAddMenuEntry("Ulaz",2);
     glutAddMenuEntry("Recepcija",3);
     glutAddMenuEntry("Hodnik za takmicare",4);
     glutAddMenuEntry("Tereni za igru",5);
     glutAddMenuEntry("Sunce ON/OFF",6);
     glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc, char **argv)
{
	printf("\n\
-----------------------------------------------------------------------\n\
  OpenGL Sample Program:\n\
  - Drag mouse left-right to rotate camera\n\
  - Hold up-arrow/down-arrow to move camera forward/backward\n\
  - q or ESC to quit\n\
-----------------------------------------------------------------------\n");

	// general initializations
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1000, 500);
	glutCreateWindow("OpenGL/GLUT Sampe Program");
	kreirajMeni();
	// register callbacks
	glutReshapeFunc(changeSize); // window reshape callback
	glutDisplayFunc(renderScene); // (re)display callback
	glutIdleFunc(update); // incremental update
	glutIgnoreKeyRepeat(1); // ignore key repeat when holding key down
	glutMouseFunc(mouseButton); // process mouse button push/release
	glutMotionFunc(mouseMove); // process mouse dragging motion
	glutKeyboardFunc(processNormalKeys); // process standard key clicks
	glutSpecialFunc(pressSpecialKey); // process special key pressed
						// Warning: Nonstandard function! Delete if desired.
	glutSpecialUpFunc(releaseSpecialKey); // process special key release

	texture1=LoadTexture("04.bmp", 316, 316);


	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 0; // this is just to keep the compiler happy
}
