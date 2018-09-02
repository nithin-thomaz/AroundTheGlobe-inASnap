#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<Windows.h>
#include<mmsystem.h>
#include<string.h>

GLfloat c1=0,c2=0,c3=0,c4=0,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,x2=0,y2=0,x3=0,y3=0,x4=0,y4=0,x5=0,y5=0,x6=0,y6=0,x7=0,y7=0,x8=0,y8=0;
GLfloat x21=0,y21=0,x22=0,x31=0,y31=0,x32=0,x41=0,y41=0,x51=0,y51=0,x61=0,y61=0;

int dis1=0;
int dis2=0;
int window;
int circle_points = 100;
void road();
void blast();
void names();
void display1();
void display2();
void display3();
void display4();
void display5();
void display6();
void display8();
void circle1(GLfloat x,GLfloat y,GLfloat radius);
void intro();

void intro(unsigned char key, int x, int y)
{
    switch(key){
        case '1':   dis1=1;
                    dis2=0;
            break;
        case '0':   glutDestroyWindow(window);
            break;
    }
    glutPostRedisplay();

}
void display_string(float x, float y, char *string, int font)
{

    int len,i;
	glColor3f(1.000, 0.961, 0.933);
	glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++) {
    if(font==1)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
	if(font==2)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
	if(font==3)
	        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,string[i]);
	if(font==4)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,string[i]);
	}

}
void display_string1(float x, float y, char *string, int font)
{
    int len,i;
	glColor3f(0.545, 0.000, 0.000);
	glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++) {
    if(font==1)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
	if(font==2)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
	if(font==3)
	        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,string[i]);
	if(font==4)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,string[i]);
	}

}

void display(void)
{
    if ((dis1==0)&&(dis2==0)){
        display1();
    }
    else if(dis1==1){
        glClear(GL_COLOR_BUFFER_BIT);
         glColor3f(0.372549,0.623529,0.623529);
         glBegin(GL_POLYGON);
         glVertex2f(0,0);
         glVertex2f(499,0);
         glVertex2f(499,499);
         glVertex2f(0,499);
         glEnd();
        road();

        glPushMatrix();
        glTranslated(a,c,0.0);
        glColor3f(0.0,1.8,0.8);//head char
        circle1(108.0,60.0,8.0);

        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(108.0,62.0);
        glVertex2f(116.0,62.0);//helmet
        glVertex2f(116.0,56.0);
        glVertex2f(108.0,58.0);
        glEnd();
        glColor3f(1,0.4,0.7);
        glLineWidth(1);
        glBegin(GL_LINE_LOOP);//outline of upper triangle plane
        glVertex2f(108.0,62.0);
        glVertex2f(116.0,62.0);//helmet
        glVertex2f(116.0,56.0);
        glVertex2f(108.0,58.0);
        glEnd();
        glColor3f(1,0.4,0.7);
        glBegin(GL_POLYGON);//rectangular body
        glVertex2f(110.0,35.0);
        glVertex2f(135.0,40.0);
        glVertex2f(107.0,53.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(a,c,0.0);
        glColor3f(1.2,1.4,0.2);
        glBegin(GL_POLYGON);//rectangular body
        glVertex2f(35,25.0);
        glVertex2f(40,20.0);
        glVertex2f(135.0,27.0);
        glVertex2f(135.0,40.0);
        glVertex2f(37.0,32.0);
        glVertex2f(35.0,25.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(a,c,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);//upper triangle construction plane
        glVertex2f(130.0,58.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(a,c,0.0);
        glColor3f(0.5,0,2);
        glLineWidth(4);
        glBegin(GL_LINE_LOOP);//outline of upper triangle plane
        glVertex2f(130.0,58.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
        glEnd();
        glPopMatrix();


        glPushMatrix();
        glTranslated(a,c,0.0);
        glColor3f(0.5,0,2);
        glBegin(GL_POLYGON);//lower triangle
        glVertex2f(135.0,40.0);
        glVertex2f(160.0,40.0);
        glVertex2f(160.0,37.0);
        glVertex2f(145.0,27.0);
        glVertex2f(135.0,27.0);
        glEnd();
        glPopMatrix();


        glPushMatrix();
            glTranslated(a,c,0.0);
            glColor3f(1.2,1.4,0.2);
            glBegin(GL_POLYGON);//body
            glVertex2f(35.0,30.0);
            glVertex2f(115.0,36.0);
            glVertex2f(106.0,57.0);
            glVertex2f(100.0,63.0);
            glVertex2f(90.0,62.0);
            glVertex2f(80.0,60.0);
            glVertex2f(70.0,56.0);
            glVertex2f(50.0,42.0);
            glEnd();
            glPopMatrix();

            glPushMatrix();
            glTranslated(a,c,0.0);
            glColor3f(1,1,1);
            glBegin(GL_POLYGON);//inside body
            glVertex2f(67.0,37.0);
            glVertex2f(107.0,42.0);
            glVertex2f(95.0,58.0);
            glVertex2f(65.0,48.0);
            glEnd();
            glPopMatrix();

            glPushMatrix();
            glTranslated(a,c,0.0);
            glColor3f(0.0,0.0,0.0);
            glLineWidth(3);
            glBegin(GL_LINE_LOOP);//outline of upper triangle plane
            glVertex2f(67.0,37.0);
            glVertex2f(107.0,42.0);
            glVertex2f(95.0,58.0);
            glVertex2f(65.0,48.0);
            glEnd();
            glPopMatrix();

            glPushMatrix();
            glTranslated(a,c,0.0);


            glColor3f(0.5,0,2);
            glBegin(GL_POLYGON);//back wing
            glVertex2f(35,30.0);
            glVertex2f(58.0,45.0);
            glVertex2f(35.0,70.0);
            glVertex2f(22.0,75.0);
            glEnd();
            glPopMatrix();


            glPushMatrix();
            glTranslated(a,c,0.0);
            glColor3f(0.5,0,2);
            glBegin(GL_POLYGON);//right wing
            glVertex2f(85.0,10.0);
            glVertex2f(105.0,15.0);
            glVertex2f(127.0,38.0);
            glVertex2f(100.0,35.0);
            glEnd();
            glPopMatrix();

            glPushMatrix();
            glTranslated(c1,0,0.0);
            glColor3f(0.929412,0.929412,0.929412);
            circle1(560.0,380.0,25.0);
            circle1(620.0,400.0,30.0); //cloud
            circle1(580.0,390.0,25.0);
            circle1(600.0,380.0,30.0);
            glPopMatrix();
            glPushMatrix();
            glTranslated(c2,0,0.0);
            glColor3f(0.829412,0.929412,0.929412);
            circle1(160.0,340.0,25.0);
            circle1(220.0,345.0,30.0);
            circle1(180.0,340.0,25.0);
            circle1(200.0,330.0,30.0);
            circle1(220.0,320.0,20.0);
            glPopMatrix();

        if(c>360)
        {
         display2();
         d+=10;
         x2+=4;
         y2-=0;
         x21-=4;
         x22-=2;
        }

        if(c>750)
        {
         display3();
         e+=10;
          if(e>50)//timer to call blast function
         {
          blast();
          e+=0;
         }
         x3+=0;
         y3+=0.5;
         x31-=0;
         y31-=2;
         x32-=0.7;
        }
        if(c>1140)
        {
         display4();
         f+=10;
         x4+=0.6;
         y4+=0;
         x41-=3;
         y41+=0;
        }

        if(c>1530)
        {
         display5();
         g+=10;
         x5-=2;
         y5+=1;
         x51-=3;
         y51-=0.3;
        }

        if(c>1890)
        {
         display6();
         h+=10;
         x6+=0.1;
         y6-=2;
         x61+=0.5;
         y61-=0.01;
        }

        if(c>2260)
        {
         display8();
         c3-=2;
         c4-=1;
         j+=4;
         x8-=6;
         y8-=5;
        }

        if(c>3000)
        {
		glutDestroyWindow(window);
        }
        glFlush();
}
}

/////...
void display2()
{

glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0.941, 0.902, 0.549);
 glBegin(GL_POLYGON);
 glVertex2f(0,0);
 glVertex2f(499,0);
 glVertex2f(499,499);
 glVertex2f(0,499);
 glEnd();

 glColor3f(1.0,1.0,1.0);
    circle1(50.0,170.0,2.0);
	circle1(250.0,350.0,1.0);
	circle1(180.0,200.0,1.0);
	circle1(200.0,350.0,1.0);
	circle1(150.0,200.0,1.0);
	circle1(400.0,450.0,1.0);
	circle1(420.0,400.0,2.0);//stars
	circle1(330.0,300.0,1.0);
	circle1(350.0,250.0,1.0);
	circle1(400.0,300.0,1.0);
    circle1(220.0,100.0,1.0);
    circle1(450.0,200.0,1.0);

    glColor3f(0.9,0.978,1);
    glPushMatrix();
    glTranslated(x21,y2,0.0);
     circle1(140.0,325.0,15.0);
     circle1(260.0,325.0,15.0);
     glBegin(GL_POLYGON);
     glVertex2f(140,340);
     glVertex2f(140,310);
     glVertex2f(260,310);
     glVertex2f(260,340);
     glEnd();
    glPopMatrix();
    glColor3f(1,0.988,1);
    glPushMatrix();
    glTranslated(x21,y2,0.0);
     circle1(200.0,345.0,15.0);
     circle1(350.0,345.0,15.0);
     glBegin(GL_POLYGON);
     glVertex2f(200,360);
     glVertex2f(200,330);
     glVertex2f(350,330);
     glVertex2f(350,360);
     glEnd();
    glPopMatrix();

    glColor3f(0.137255,0.556863,0.419608);
    circle1(250.0,-180.0,280.0);//earth

    glColor3f(0.556863,0.137255,0.137255); //base1
    glBegin(GL_POLYGON);
        glVertex2f(80.0,48.0);
    glVertex2f(100.0,40.0);
    glVertex2f(120.0,20.0);
        glVertex2f(150.0,30.0);
    glVertex2f(170.0,20.0);
    glVertex2f(190.0,22.0);
        glVertex2f(200.0,30.0);
    glVertex2f(210.0,35.0);
    glVertex2f(220.0,30.0);
        glVertex2f(250.0,40.0);
    glVertex2f(270.0,40.0);
    glVertex2f(290.0,45.0);
        glVertex2f(305.0,40.0);
    glVertex2f(320.0,50.0);
    glVertex2f(340.0,52.0);
        glVertex2f(360.0,42.0);
    glVertex2f(380.0,60.0);
    glVertex2f(390.0,68.0);
        glVertex2f(400.0,62.0);
    glVertex2f(420.0,50.0);
    glVertex2f(425.0,40.0);
        glVertex2f(440.0,27.0);
    glVertex2f(420.0,35.0);
    glVertex2f(410.0,40.0);
        glVertex2f(390.0,15.0);
    glVertex2f(360.0,35.0);
    glVertex2f(340.0,30.0);
        glVertex2f(280.0,10.0);
    glVertex2f(220.0,25.0);
    glVertex2f(200.0,18.0);
        glVertex2f(160.0,15.0);
    glVertex2f(130.0,17.0);
    glEnd();

    glColor3f(0.65,0.50,0.39); //base2
    glBegin(GL_POLYGON);
        glVertex2f(80.0,45.0);
  //  glVertex2f(90.0,30.0);
    glVertex2f(120.0,25.0);
        glVertex2f(160.0,30.0);
    glVertex2f(170.0,20.0);
    glVertex2f(190.0,22.0);
        glVertex2f(200.0,30.0);
    glVertex2f(210.0,35.0);
    glVertex2f(220.0,30.0);
        glVertex2f(250.0,40.0);
    glVertex2f(270.0,40.0);
    glVertex2f(290.0,45.0);
        glVertex2f(305.0,40.0);
    glVertex2f(320.0,50.0);
    glVertex2f(340.0,52.0);
        glVertex2f(360.0,30.0);
    glVertex2f(390.0,60.0);
    glVertex2f(400.0,62.0);
        glVertex2f(368.0,80.0);
    glVertex2f(366.0,88.0);
    glVertex2f(363.0,90.0);
        glVertex2f(360.0,82.0);
    glVertex2f(330.0,95.0);
    glVertex2f(328.0,98.0);
        glVertex2f(325.0,100.0);
    glVertex2f(280.0,110.0);
    glVertex2f(220.0,115.0);
        glVertex2f(180.0,105.0);
    glVertex2f(175.0,110.0);
    glVertex2f(163.0,106.0);
        glVertex2f(160.0,75.0);
    glVertex2f(145.0,95.0);
    glVertex2f(138.0,98.0);
        glVertex2f(130.0,95.0);
    glVertex2f(130.0,85.0);
    glVertex2f(110.0,78.0);
        glVertex2f(105.0,80.0);
    glVertex2f(100.0,65.0);
    glVertex2f(90.0,68.0);
        glVertex2f(85.0,62.0);
    glEnd();

        glColor3f(0.81,0.71,0.23);
        circle1(151.0,82.0,10.0);//grass
        glColor3f(0.81,0.71,0.23);
        circle1(158.0,87.0,10.0);
        glPopMatrix();
        glColor3f(0.81,0.71,0.23); //structure
        glBegin(GL_POLYGON);
        glVertex2f(330.0,80.0);
        glVertex2f(360.0,80.0);
        glVertex2f(360.0,85.0);
        glVertex2f(355.0,85.0);
        glVertex2f(355.0,90.0);
        glVertex2f(350.0,90.0);
        glVertex2f(350.0,95.0);
        glVertex2f(345.0,95.0);
        glVertex2f(340.0,95.0);
        glVertex2f(340.0,90.0);
        glVertex2f(335.0,85.0);
        glVertex2f(330.0,85.0);
        glEnd();

        glColor3f(0.65,0.49,0.24);
        glBegin(GL_POLYGON);
        glVertex2f(340.0,95.0);
        glVertex2f(355.0,95.0);
        glVertex2f(360.0,100.0);
        glVertex2f(355.0,105.0);
        glVertex2f(350.0,105.0);
        glEnd();

        glColor3f(0.81,0.71,0.23); //pyramid
        glBegin(GL_POLYGON);
        glVertex2f(205.0,80.0);
        glVertex2f(280.0,80.0);
        glVertex2f(230.0,200.0);
        glEnd();
        glColor3f(0.65,0.49,0.24);
        glBegin(GL_POLYGON);
        glVertex2f(230.0,200.0);
        glVertex2f(190.0,90.0);
        glVertex2f(205.0,80.0);
        glEnd();

        glColor3f(0.81,0.71,0.23);//pyramid
        glBegin(GL_POLYGON);
        glVertex2f(183.0,120.0);
        glVertex2f(150.0,60.0);
        glVertex2f(215.0,60.0);
        glEnd();
        glColor3f(0.65,0.49,0.24);
        glBegin(GL_POLYGON);
        glVertex2f(183.0,120.0);
        glVertex2f(142.0,76.0);
        glVertex2f(150.0,60.0);
        glEnd();

        glColor3f(0.81,0.71,0.23); //pyramid
        glBegin(GL_POLYGON);
        glVertex2f(280.0,140.0);
        glVertex2f(260.0,70.0);
        glVertex2f(325.0,70.0);
        glEnd();
        glColor3f(0.65,0.49,0.24);
        glBegin(GL_POLYGON);
        glVertex2f(280.0,140.0);
        glVertex2f(230.0,70.0);
        glVertex2f(260.0,70.0);
        glEnd();


        glPushMatrix();
        glTranslated(d,300,0.0);
        glColor3f(0.0,1.8,0.8);//head char
        circle1(108.0,60.0,8.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(108.0,62.0);
        glVertex2f(116.0,62.0);//helmet
        glVertex2f(116.0,56.0);
        glVertex2f(108.0,58.0);
        glEnd();
        glColor3f(1,0.4,0.7);
        glLineWidth(1);
        glBegin(GL_LINE_LOOP);//outline of upper triangle plane
        glVertex2f(108.0,62.0);
        glVertex2f(116.0,62.0);//helmet
        glVertex2f(116.0,56.0);
        glVertex2f(108.0,58.0);
        glEnd();
        glColor3f(1,0.4,0.7);
        glBegin(GL_POLYGON);//rectangular body
        glVertex2f(110.0,35.0);
        glVertex2f(135.0,40.0);
        glVertex2f(107.0,53.0);
        glEnd();
        glColor3f(1.2,1.4,0.2);
        glBegin(GL_POLYGON);//rectangular body
        glVertex2f(35,25.0);
        glVertex2f(40,20.0);
        glVertex2f(135.0,27.0);
        glVertex2f(135.0,40.0);
        glVertex2f(37.0,32.0);
        glVertex2f(35.0,25.0);
        glEnd();
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);//upper triangle construction plane
        glVertex2f(130.0,58.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
        glEnd();
        glColor3f(0.5,0,2);
        glLineWidth(4);
        glBegin(GL_LINE_LOOP);//outline of upper triangle plane
        glVertex2f(130.0,58.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
        glEnd();
        glColor3f(0.5,0,2);
        glBegin(GL_POLYGON);//lower triangle
        glVertex2f(135.0,40.0);
        glVertex2f(160.0,40.0);
        glVertex2f(160.0,37.0);
        glVertex2f(145.0,27.0);
        glVertex2f(135.0,27.0);
        glEnd();
            glColor3f(1.2,1.4,0.2);
            glBegin(GL_POLYGON);//body
            glVertex2f(35.0,30.0);
            glVertex2f(115.0,36.0);
            glVertex2f(106.0,57.0);
            glVertex2f(100.0,63.0);
            glVertex2f(90.0,62.0);
            glVertex2f(80.0,60.0);
            glVertex2f(70.0,56.0);
            glVertex2f(50.0,42.0);
            glEnd();
            glColor3f(1,1,1);
            glBegin(GL_POLYGON);//inside body
            glVertex2f(67.0,37.0);
            glVertex2f(107.0,42.0);
            glVertex2f(95.0,58.0);
            glVertex2f(65.0,48.0);
            glEnd();
            glColor3f(0.0,0.0,0.0);
            glLineWidth(3);
            glBegin(GL_LINE_LOOP);//outline of upper triangle plane
            glVertex2f(67.0,37.0);
            glVertex2f(107.0,42.0);
            glVertex2f(95.0,58.0);
            glVertex2f(65.0,48.0);
            glEnd();
            glColor3f(0.5,0,2);
            glBegin(GL_POLYGON);//back wing
            glVertex2f(35,30.0);
            glVertex2f(58.0,45.0);
            glVertex2f(35.0,70.0);
            glVertex2f(22.0,75.0);
            glEnd();
            glColor3f(0.5,0,2);
            glBegin(GL_POLYGON);//right wing
            glVertex2f(85.0,10.0);
            glVertex2f(105.0,15.0);
            glVertex2f(127.0,38.0);
            glVertex2f(100.0,35.0);
            glEnd();

            glPopMatrix();

        glColor3f(0.9,0.988,1);
        glPushMatrix();
        glTranslated(x22,y2,0.0);
         circle1(390.0,340.0,20.0);
         circle1(470.0,340.0,20.0);
         glBegin(GL_POLYGON);
         glVertex2f(390,360);
         glVertex2f(390,320);
         glVertex2f(470,320);
         glVertex2f(470,360);
         glEnd();
        glPopMatrix();
        names();
        glPushMatrix();
        glRotatef(30,0,0,1);
        display_string(79,61,"Pyramids",2);
        display_string1(180,-100,"atlantic ocean",2);
        glPopMatrix();

}

/////...
void display3()
{
glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0.256863,0.137255,0.137255);
 glBegin(GL_POLYGON);
 glVertex2f(0,0);
 glVertex2f(499,0);
 glVertex2f(499,499);
 glVertex2f(0,499);
 glEnd();
 glColor3f(1.0,1.0,1.0);
    circle1(50.0,170.0,2.0);
	circle1(250.0,350.0,1.0);
	circle1(180.0,200.0,1.0);
	circle1(200.0,350.0,1.0);
	circle1(150.0,200.0,1.0);
	circle1(400.0,450.0,1.0);
	circle1(420.0,400.0,2.0);//stars
	circle1(330.0,300.0,1.0);
	circle1(350.0,250.0,1.0);
	circle1(400.0,300.0,1.0);
    circle1(220.0,100.0,1.0);
    circle1(450.0,200.0,1.0);
    //circle1(400.0,300.0,2.0);

    glColor3f(0.137255,0.556863,0.419608);
    circle1(250.0,-180.0,280.0);//earth

    glColor3f(0.333, 0.420, 0.184);//base1
    glBegin(GL_POLYGON);
        glVertex2f(80.0,48.0);
    glVertex2f(100.0,40.0);
    glVertex2f(120.0,20.0);
        glVertex2f(150.0,30.0);
    glVertex2f(170.0,20.0);
    glVertex2f(190.0,22.0);
        glVertex2f(200.0,30.0);
    glVertex2f(210.0,35.0);
    glVertex2f(220.0,30.0);
        glVertex2f(250.0,40.0);
    glVertex2f(270.0,40.0);
    glVertex2f(290.0,45.0);
        glVertex2f(305.0,40.0);
    glVertex2f(320.0,50.0);
    glVertex2f(340.0,52.0);
        glVertex2f(360.0,42.0);
    glVertex2f(380.0,60.0);
    glVertex2f(390.0,68.0);
        glVertex2f(400.0,62.0);
    glVertex2f(420.0,50.0);
    glVertex2f(425.0,40.0);
        glVertex2f(440.0,27.0);
    glVertex2f(420.0,35.0);
    glVertex2f(410.0,40.0);
        glVertex2f(390.0,15.0);
    glVertex2f(360.0,35.0);
    glVertex2f(340.0,30.0);
        glVertex2f(280.0,10.0);
    glVertex2f(220.0,25.0);
    glVertex2f(200.0,18.0);
        glVertex2f(160.0,15.0);
    glVertex2f(130.0,17.0);
    glEnd();

    glColor3f( 	0.000, 0.392, 0.000); //base2
    glBegin(GL_POLYGON);
        glVertex2f(80.0,45.0);
  //  glVertex2f(90.0,30.0);
    glVertex2f(120.0,25.0);
        glVertex2f(160.0,30.0);
    glVertex2f(170.0,20.0);
    glVertex2f(190.0,22.0);
        glVertex2f(200.0,30.0);
    glVertex2f(210.0,35.0);
    glVertex2f(220.0,30.0);
        glVertex2f(250.0,40.0);
    glVertex2f(270.0,40.0);
    glVertex2f(290.0,45.0);
        glVertex2f(305.0,40.0);
    glVertex2f(320.0,50.0);
    glVertex2f(340.0,52.0);
        glVertex2f(360.0,30.0);
    glVertex2f(390.0,60.0);
    glVertex2f(400.0,62.0);
        glVertex2f(368.0,80.0);
    glVertex2f(366.0,88.0);
    glVertex2f(363.0,90.0);
        glVertex2f(360.0,82.0);
    glVertex2f(330.0,95.0);
    glVertex2f(328.0,98.0);
        glVertex2f(325.0,100.0);
    glVertex2f(280.0,110.0);
    glVertex2f(220.0,115.0);
        glVertex2f(180.0,105.0);
    glVertex2f(175.0,110.0);
    glVertex2f(163.0,106.0);
        glVertex2f(160.0,75.0);
    glVertex2f(145.0,95.0);
    glVertex2f(138.0,98.0);
        glVertex2f(130.0,95.0);
    glVertex2f(130.0,85.0);
    glVertex2f(110.0,78.0);
        glVertex2f(105.0,80.0);
    glVertex2f(100.0,65.0);
    glVertex2f(90.0,68.0);
        glVertex2f(85.0,62.0);
    glEnd();

glColor3f(0.723529,0.723529,0.372549);//m3
glBegin(GL_POLYGON);
glVertex2f(170.0,70.0);
glVertex2f(210.0,160.0);
glVertex2f(250.0,120.0);
glVertex2f(310.0,170.0);
glVertex2f(350.0,70.0);
glEnd();

glColor3f(0.658824,0.635294,0.358824);//m1
glBegin(GL_POLYGON);
glVertex2f(140.0,70.0);
glVertex2f(165.0,140.0);
glVertex2f(175.0,150.0);
glVertex2f(185.0,145.0);
glVertex2f(240.0,70.0);
glEnd();
glColor3f(0.9,0.05,0);//volcano
glBegin(GL_POLYGON);
glVertex2f(200.0,70.0);
glVertex2f(198.0,90.0);
glVertex2f(205.0,110.0);
glVertex2f(215.0,130.0);
glVertex2f(210.0,140.0);
glVertex2f(225.0,160.0);
glVertex2f(239.0,200.0);
glVertex2f(240.0,200.0);
glVertex2f(240.0,70.0);
glEnd();
glColor3f(1,0.20,0);//volcano
glBegin(GL_POLYGON);
glVertex2f(210.0,70.0);
glVertex2f(208.0,90.0);
glVertex2f(215.0,110.0);
glVertex2f(225.0,130.0);
glVertex2f(220.0,140.0);
glVertex2f(235.0,160.0);
glVertex2f(240.0,200.0);
glVertex2f(250.0,200.0);
glVertex2f(250.0,70.0);
glEnd();
glColor3f(1,0.10,0);//volcano
glBegin(GL_POLYGON);
glVertex2f(250.0,70.0);
glVertex2f(250.0,200.0);
glVertex2f(260.0,200.0);
glVertex2f(270.0,160.0);
glVertex2f(280.0,140.0);
glVertex2f(280.0,120.0);
glVertex2f(310.0,70.0);
glEnd();


glColor3f(0.52,0,0);//fire
glBegin(GL_POLYGON);
glVertex2f(240.0,200.0);
glVertex2f(242.0,190.0);
glVertex2f(250.0,200.0);
glVertex2f(252.0,180.0);
glVertex2f(260.0,200.0);
glEnd();


glColor3f(0.72,0,0);
glBegin(GL_POLYGON);
glVertex2f(240.0,200.0);
glVertex2f(245.0,195.0);//fire
glVertex2f(255.0,195.0);
glVertex2f(260.0,200.0);
glVertex2f(255.0,203.0);
glVertex2f(245.0,203.0);
glEnd();
glColor3f(0.52,0,0);//fire
glBegin(GL_POLYGON);
glVertex2f(235.0,155.0);
glVertex2f(235.0,145.0);
glVertex2f(250.0,156.0);
glVertex2f(240.0,130.0);
glEnd();
glColor3f(0.62,0,0);//fire
glBegin(GL_POLYGON);
glVertex2f(252.0,160.0);
glVertex2f(260.0,157.0);
glVertex2f(265.0,140.0);
glVertex2f(260.0,120.0);
glEnd();
glColor3f(1.000, 0.271, 0.000);//fire
glBegin(GL_POLYGON);
glVertex2f(250.0,125.0);
glVertex2f(245.0,120.0);
glVertex2f(248.0,110.0);
glVertex2f(240.0,100.0);
glVertex2f(245.0,90.0);
glVertex2f(235.0,80.0);
glVertex2f(235.0,70.0);
glVertex2f(230.0,60.0);
glVertex2f(250.0,60.0);
glEnd();
//glColor3f(0.62,0,0);//fire
glBegin(GL_POLYGON);
glVertex2f(250.0,125.0);
glVertex2f(255.0,120.0);
glVertex2f(253.0,110.0);
glVertex2f(260.0,100.0);
glVertex2f(255.0,90.0);
glVertex2f(280.0,75.0);
glVertex2f(250.0,60.0);
glEnd();

glColor3f(0.558824,0.635294,0.258824);
glBegin(GL_POLYGON);
glVertex2f(90.0,60.0);//m2
glVertex2f(120.0,120.0);
glVertex2f(160.0,90.0);
glVertex2f(200.0,120.0);
glVertex2f(240.0,60.0);
glEnd();
glColor3f(0.658824,0.735294,0.258824);
glBegin(GL_POLYGON);
glVertex2f(270.0,70.0);//m4
glVertex2f(285.0,90.0);
glVertex2f(300.0,120.0);
glVertex2f(310.0,135.0);
glVertex2f(320.0,140.0);
glVertex2f(340.0,140.0);
glVertex2f(350.0,130.0);
glVertex2f(310.0,70.0);
glEnd();
glColor3f(0.558824,0.635294,0.258824);
glPushMatrix();

glScalef(1,1.1,1);
glBegin(GL_POLYGON);
glVertex2f(350.0,130.0);//m5
glVertex2f(310.0,70.0);
glVertex2f(370.0,70.0);
glVertex2f(360.0,120.0);
glEnd();
glPopMatrix();

glColor3f(0.558824,0.7000,0.258824);//m6
glBegin(GL_POLYGON);
glVertex2f(330.0,70.0);
glVertex2f(380.0,90.0);
glVertex2f(403.0,60.0);
glEnd();



        glPushMatrix();
        glTranslated(e,300,0.0);
        glColor3f(0.0,1.8,0.8);//head char
        circle1(108.0,60.0,8.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(108.0,62.0);
        glVertex2f(116.0,62.0);//helmet
        glVertex2f(116.0,56.0);
        glVertex2f(108.0,58.0);
        glEnd();
        glColor3f(1,0.4,0.7);
        glLineWidth(1);
        glBegin(GL_LINE_LOOP);//outline of upper triangle plane
        glVertex2f(108.0,62.0);
        glVertex2f(116.0,62.0);//helmet
        glVertex2f(116.0,56.0);
        glVertex2f(108.0,58.0);
        glEnd();
        glColor3f(1,0.4,0.7);
        glBegin(GL_POLYGON);//rectangular body
        glVertex2f(110.0,35.0);
        glVertex2f(135.0,40.0);
        glVertex2f(107.0,53.0);
        glEnd();
        glColor3f(1.2,1.4,0.2);
        glBegin(GL_POLYGON);//rectangular body
        glVertex2f(35,25.0);
        glVertex2f(40,20.0);
        glVertex2f(135.0,27.0);
        glVertex2f(135.0,40.0);
        glVertex2f(37.0,32.0);
        glVertex2f(35.0,25.0);
        glEnd();
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);//upper triangle construction plane
        glVertex2f(130.0,58.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
        glEnd();
        glColor3f(0.5,0,2);
        glLineWidth(4);
        glBegin(GL_LINE_LOOP);//outline of upper triangle plane
        glVertex2f(130.0,58.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
        glEnd();
        glColor3f(0.5,0,2);
        glBegin(GL_POLYGON);//lower triangle
        glVertex2f(135.0,40.0);
        glVertex2f(160.0,40.0);
        glVertex2f(160.0,37.0);
        glVertex2f(145.0,27.0);
        glVertex2f(135.0,27.0);
        glEnd();
            glColor3f(1.2,1.4,0.2);
            glBegin(GL_POLYGON);//body
            glVertex2f(35.0,30.0);
            glVertex2f(115.0,36.0);
            glVertex2f(106.0,57.0);
            glVertex2f(100.0,63.0);
            glVertex2f(90.0,62.0);
            glVertex2f(80.0,60.0);
            glVertex2f(70.0,56.0);
            glVertex2f(50.0,42.0);
            glEnd();
            glColor3f(1,1,1);
            glBegin(GL_POLYGON);//inside body
            glVertex2f(67.0,37.0);
            glVertex2f(107.0,42.0);
            glVertex2f(95.0,58.0);
            glVertex2f(65.0,48.0);
            glEnd();
            glColor3f(0.0,0.0,0.0);
            glLineWidth(3);
            glBegin(GL_LINE_LOOP);//outline of upper triangle plane
            glVertex2f(67.0,37.0);
            glVertex2f(107.0,42.0);
            glVertex2f(95.0,58.0);
            glVertex2f(65.0,48.0);
            glEnd();
            glColor3f(0.5,0,2);
            glBegin(GL_POLYGON);//back wing
            glVertex2f(35,30.0);
            glVertex2f(58.0,45.0);
            glVertex2f(35.0,70.0);
            glVertex2f(22.0,75.0);
            glEnd();
            glColor3f(0.5,0,2);
            glBegin(GL_POLYGON);//right wing
            glVertex2f(85.0,10.0);
            glVertex2f(105.0,15.0);
            glVertex2f(127.0,38.0);
            glVertex2f(100.0,35.0);
            glEnd();

            glPopMatrix();
names();
glPushMatrix();
glRotatef(30,0,0,1);
display_string(83,56,"Mt.Fuji",2);
display_string1(180,-100,"pacific ocean",2);
glPopMatrix();
}

/////...
void display4()
{

glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1.000, 0.627, 0.478);
 glBegin(GL_POLYGON);
 glVertex2f(0,0);
 glVertex2f(499,0);
 glVertex2f(499,499);
 glVertex2f(0,499);
 glEnd();

 glColor3f(1.0,1.0,1.0);
    circle1(50.0,170.0,2.0);
	circle1(250.0,350.0,1.0);
	circle1(180.0,200.0,1.0);
	circle1(200.0,350.0,1.0);
	circle1(150.0,200.0,1.0);
	circle1(400.0,450.0,1.0);
	circle1(420.0,400.0,2.0);//stars
	circle1(330.0,300.0,1.0);
	circle1(350.0,250.0,1.0);
	circle1(400.0,300.0,1.0);
    circle1(220.0,100.0,1.0);
    circle1(450.0,200.0,1.0);
    //circle1(400.0,300.0,2.0);

glPushMatrix();
glTranslated(x41,y41,0.0);
    glColor3f(0.5,0.5,0.5);
	circle1(140.0,295.0,25.0);
	circle1(200.0,300.0,30.0);
	circle1(160.0,295.0,25.0);//cloud
    circle1(180.0,285.0,30.0);
    circle1(200.0,275.0,20.0);
glPopMatrix();

    glColor3f(0.858,0.8,0.35);//layer4
    glBegin(GL_POLYGON);
        glVertex2f(120.0,80.0);
    glVertex2f(130.0,120.0);
        glVertex2f(180.0,125.0);
    glVertex2f(220.0,110.0);
    glVertex2f(250.0,140.0);
        glVertex2f(280.0,115.0);
    glVertex2f(320.0,130.0);
    glVertex2f(370.0,100.0);
        glVertex2f(390.0,110.0);
    glVertex2f(420.0,60.0);
    glVertex2f(430.0,30.0);
        glVertex2f(300.0,90.0);
    glVertex2f(260.0,110.0);
    glVertex2f(220.0,90.0);
        glVertex2f(150.0,100.0);
    glEnd();

    glColor3f(0.498, 1.000, 0.831);
    circle1(250.0,-180.0,280.0);//earth

    glColor3f(0.858824,0.858824,0.339216);//base1
    glBegin(GL_POLYGON);
    glVertex2f(62.0,30.0);
        glVertex2f(80.0,48.0);
    glVertex2f(100.0,40.0);
    glVertex2f(170.0,20.0);
    glVertex2f(190.0,22.0);
        glVertex2f(200.0,30.0);
    glVertex2f(220.0,30.0);
        glVertex2f(250.0,40.0);
    glVertex2f(270.0,40.0);
    glVertex2f(290.0,45.0);
        glVertex2f(305.0,40.0);
    glVertex2f(340.0,52.0);
        glVertex2f(360.0,82.0);
    glVertex2f(380.0,60.0);
    glVertex2f(390.0,40.0);
        glVertex2f(400.0,62.0);
    glVertex2f(420.0,50.0);
    glVertex2f(425.0,40.0);
        glVertex2f(440.0,27.0);
    glVertex2f(420.0,35.0);
    glVertex2f(410.0,40.0);
        glVertex2f(390.0,90.0);
    glVertex2f(360.0,100.0);
       glVertex2f(340.0,100.0);
        glVertex2f(280.0,100.0);
        glVertex2f(160.0,60.0);
    glVertex2f(90.0,80.0);
    glEnd();

        glColor3f(0.858,0.8,0.3); //base2
    glBegin(GL_POLYGON);
        glVertex2f(80.0,45.0);
    glVertex2f(120.0,25.0);
        glVertex2f(160.0,40.0);
    glVertex2f(170.0,20.0);
    glVertex2f(190.0,32.0);
        glVertex2f(200.0,40.0);
    glVertex2f(210.0,45.0);
    glVertex2f(220.0,40.0);
        glVertex2f(250.0,50.0);
    glVertex2f(270.0,50.0);
    glVertex2f(290.0,65.0);//
        glVertex2f(305.0,70.0);
    glVertex2f(320.0,60.0);
    glVertex2f(340.0,52.0);
        glVertex2f(360.0,50.0);
    glVertex2f(390.0,60.0);
    glVertex2f(400.0,62.0);
        glVertex2f(368.0,80.0);
    glVertex2f(366.0,88.0);
    glVertex2f(363.0,90.0);
        glVertex2f(360.0,82.0);
    glVertex2f(330.0,95.0);
    glVertex2f(328.0,98.0);
        glVertex2f(325.0,100.0);
    glVertex2f(280.0,110.0);
    glVertex2f(220.0,115.0);
    glEnd();



    glColor3f(0.858,0.7,0.1); //layer1
    glBegin(GL_POLYGON);
        glVertex2f(80.0,45.0);
    glVertex2f(120.0,92.0);
        glVertex2f(135.0,80.0);
    glVertex2f(180.0,115.0);
    glVertex2f(220.0,105.0);
        glVertex2f(270.0,125.0);
    glVertex2f(300.0,110.0);
    glVertex2f(340.0,120.0);
        glVertex2f(360.0,86.0);
    glVertex2f(300.0,66.0);
    glEnd();

    glColor3f(0.858,0.8555,0.3); //layer2
    glBegin(GL_POLYGON);
        glVertex2f(95.0,45.0);
    glVertex2f(120.0,45.0);
        glVertex2f(160.0,48.0);
    glVertex2f(170.0,67.0);
    glVertex2f(190.0,60);
        glVertex2f(200.0,60.0);
    glVertex2f(210.0,62.0);
    glVertex2f(220.0,63.0);
        glVertex2f(250.0,55.0);
    glVertex2f(270.0,62.0);
    glVertex2f(290.0,65.0);
        glVertex2f(300.0,80.0);
    glVertex2f(260.0,108.0);
    glVertex2f(220.0,87.0);
        glVertex2f(150.0,96.0);
    glEnd();

glColor3f(0.196078,0.8,0.196078);
glBegin(GL_POLYGON);
glVertex2f(170.0,50.0);
glVertex2f(180.0,60.0);//grass
glVertex2f(175.0,57.0);
glVertex2f(170.0,65.0);
glVertex2f(165.0,57.0);
glVertex2f(160.0,60.0);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(175.0,50.0);
glVertex2f(185.0,60.0);//grass
glVertex2f(180.0,57.0);
glVertex2f(175.0,65.0);
glVertex2f(170.0,57.0);
glVertex2f(165.0,60.0);
glEnd();

    glColor3f(0.196078,0.8,0.196078);
glBegin(GL_POLYGON);
glVertex2f(360.0,80.0);
glVertex2f(370.0,90.0);//grass
glVertex2f(365.0,87.0);
glVertex2f(360.0,95.0);
glVertex2f(355.0,87.0);
glVertex2f(350.0,90.0);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(365.0,80.0);
glVertex2f(375.0,90.0);//grass
glVertex2f(370.0,87.0);
glVertex2f(365.0,95.0);
glVertex2f(360.0,87.0);
glVertex2f(355.0,90.0);
glEnd();

glColor3f(0.196078,0.79,0.596078);
    circle1(270.0,45.0,13.0);//water
	circle1(283.0,40.0,10.0);
	circle1(290.0,48.0,15.0);
	circle1(300.0,45.0,15.0);
glColor3f(0.36,0.25,0.20);
glBegin(GL_POLYGON);
glVertex2f(330.0,40.0);
glVertex2f(320.0,40.0);//coco tree
glVertex2f(315.0,90.0);
glVertex2f(308.0,90.0);
glEnd();
glColor3f(0.196078,0.8,0.196078);
glBegin(GL_POLYGON);
glVertex2f(280.0,70.0);
glVertex2f(300.0,80.0);//coco tree
glVertex2f(310.0,90.0);
glVertex2f(290.0,95.0);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(300.0,120.0);
glVertex2f(300.0,95.0);//coco tree
glVertex2f(310.0,90.0);
glVertex2f(315.0,100.0);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(340.0,80.0);
glVertex2f(320.0,95.0);//coco tree
glVertex2f(310.0,90.0);
glVertex2f(320.0,80.0);
glEnd();
glColor3f(0.85,0.85,0.10);
    circle1(306.0,87.0,5.0);//coco
	circle1(313.0,86.0,5.0);

glColor3f(0.196078,0.69,0.196078);
	glBegin(GL_POLYGON);

glVertex2f(197.0,85.0);//orchid
glVertex2f(197.0,100.0);
glVertex2f(203.0,100.0);
glVertex2f(203.0,110.0);
glVertex2f(199.0,110.0);
glVertex2f(199.0,105.0);
glVertex2f(193.0,105.0);
glVertex2f(193.0,95.0);
glVertex2f(189.0,95.0);
glVertex2f(189.0,110.0);
glVertex2f(185.0,110.0);
glVertex2f(185.0,95.0);
glVertex2f(193.0,85.0);
glEnd();
glColor3f(0.196078,0.79,0.296078);
	glBegin(GL_POLYGON);
glVertex2f(247.0,115.0);//orchid
glVertex2f(247.0,130.0);
glVertex2f(253.0,130.0);
glVertex2f(253.0,140.0);
glVertex2f(249.0,140.0);
glVertex2f(249.0,135.0);
glVertex2f(243.0,135.0);
glVertex2f(243.0,125.0);
glVertex2f(239.0,125.0);
glVertex2f(239.0,140.0);
glVertex2f(235.0,140.0);
glVertex2f(235.0,125.0);
glVertex2f(243.0,115.0);
glEnd();

        glPushMatrix();
        glTranslated(f,300,0.0);
        glColor3f(0.0,1.8,0.8);//head char
        circle1(108.0,60.0,8.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(108.0,62.0);
        glVertex2f(116.0,62.0);//helmet
        glVertex2f(116.0,56.0);
        glVertex2f(108.0,58.0);
        glEnd();
        glColor3f(1,0.4,0.7);
        glLineWidth(1);
        glBegin(GL_LINE_LOOP);//outline of upper triangle plane
        glVertex2f(108.0,62.0);
        glVertex2f(116.0,62.0);//helmet
        glVertex2f(116.0,56.0);
        glVertex2f(108.0,58.0);
        glEnd();
        glColor3f(1,0.4,0.7);
        glBegin(GL_POLYGON);//rectangular body
        glVertex2f(110.0,35.0);
        glVertex2f(135.0,40.0);
        glVertex2f(107.0,53.0);
        glEnd();
        glColor3f(1.2,1.4,0.2);
        glBegin(GL_POLYGON);//rectangular body
        glVertex2f(35,25.0);
        glVertex2f(40,20.0);
        glVertex2f(135.0,27.0);
        glVertex2f(135.0,40.0);
        glVertex2f(37.0,32.0);
        glVertex2f(35.0,25.0);
        glEnd();
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);//upper triangle construction plane
        glVertex2f(130.0,58.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
        glEnd();
        glColor3f(0.5,0,2);
        glLineWidth(4);
        glBegin(GL_LINE_LOOP);//outline of upper triangle plane
        glVertex2f(130.0,58.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
        glEnd();
        glColor3f(0.5,0,2);
        glBegin(GL_POLYGON);//lower triangle
        glVertex2f(135.0,40.0);
        glVertex2f(160.0,40.0);
        glVertex2f(160.0,37.0);
        glVertex2f(145.0,27.0);
        glVertex2f(135.0,27.0);
        glEnd();
            glColor3f(1.2,1.4,0.2);
            glBegin(GL_POLYGON);//body
            glVertex2f(35.0,30.0);
            glVertex2f(115.0,36.0);
            glVertex2f(106.0,57.0);
            glVertex2f(100.0,63.0);
            glVertex2f(90.0,62.0);
            glVertex2f(80.0,60.0);
            glVertex2f(70.0,56.0);
            glVertex2f(50.0,42.0);
            glEnd();
            glColor3f(1,1,1);
            glBegin(GL_POLYGON);//inside body
            glVertex2f(67.0,37.0);
            glVertex2f(107.0,42.0);
            glVertex2f(95.0,58.0);
            glVertex2f(65.0,48.0);
            glEnd();
            glColor3f(0.0,0.0,0.0);
            glLineWidth(3);
            glBegin(GL_LINE_LOOP);//outline of upper triangle plane
            glVertex2f(67.0,37.0);
            glVertex2f(107.0,42.0);
            glVertex2f(95.0,58.0);
            glVertex2f(65.0,48.0);
            glEnd();
            glColor3f(0.5,0,2);
            glBegin(GL_POLYGON);//back wing
            glVertex2f(35,30.0);
            glVertex2f(58.0,45.0);
            glVertex2f(35.0,70.0);
            glVertex2f(22.0,75.0);
            glEnd();
            glColor3f(0.5,0,2);
            glBegin(GL_POLYGON);//right wing
            glVertex2f(85.0,10.0);
            glVertex2f(105.0,15.0);
            glVertex2f(127.0,38.0);
            glVertex2f(100.0,35.0);
            glEnd();

            glPopMatrix();
glPushMatrix();
glTranslated(x41,y41,0.0);
    glColor3f(0.5,0.5,0.5);
	circle1(380.0,320.0,25.0);
	circle1(440.0,340.0,30.0); //cloud
	circle1(400.0,340.0,25.0);
    circle1(420.0,320.0,30.0);
glPopMatrix();

names();
glPushMatrix();
glRotatef(30,0,0,1);
display_string(85,61,"Sahara",2);
display_string1(180,-100,"arctic ocean",2);
glPopMatrix();
glLineWidth(6);
glPushMatrix();
glTranslated(x4,y4,0.0);
glColor3f(1,0,0);
glBegin(GL_LINES);
glVertex2f(170.0,45.0);
glVertex2f(180.0,49.0);
glEnd();
glBegin(GL_LINES);
glVertex2f(180.0,49.0);
glVertex2f(190.0,47.0);
glEnd();
glBegin(GL_LINES);
glVertex2f(190.0,47.0);
glVertex2f(200.0,49.0);
glEnd();
glColor3f(0.1,0,0);
circle1(200.0,49.0,5.0);
glPopMatrix();
}

void display5()
{

glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0.282, 0.820, 0.800);
 glBegin(GL_POLYGON);
 glVertex2f(0,0);
 glVertex2f(499,0);
 glVertex2f(499,499);
 glVertex2f(0,499);
 glEnd();
 glColor3f(1.0,1.0,1.0);
    circle1(50.0,170.0,2.0);
	circle1(250.0,350.0,1.0);
	circle1(180.0,200.0,1.0);
	circle1(200.0,350.0,1.0);
	circle1(150.0,200.0,1.0);
	circle1(400.0,450.0,1.0);
	circle1(420.0,400.0,2.0);//stars
	circle1(330.0,300.0,1.0);
	circle1(350.0,250.0,1.0);
	circle1(400.0,300.0,1.0);
    circle1(220.0,100.0,1.0);
    circle1(450.0,200.0,1.0);
    //circle1(400.0,300.0,2.0);
glPushMatrix();
glTranslated(x51,y51,0.0);
    glColor3f(0.5,0.5,0.5);
	circle1(140.0,295.0,25.0);
	circle1(200.0,300.0,30.0);
	circle1(160.0,295.0,25.0);//cloud
    circle1(180.0,285.0,30.0);
    circle1(200.0,275.0,20.0);
    glColor3f(0.5,0.5,0.5);
	circle1(340.0,295.0,25.0);
	circle1(300.0,300.0,30.0);
	circle1(360.0,295.0,25.0);//cloud
    circle1(380.0,285.0,30.0);
    circle1(300.0,275.0,20.0);
glPopMatrix();
    glColor3f(0,0,0);
	circle1(370.0,80.0,10.0);//stone
	circle1(360.0,85.0,15.0);

    glColor3f(0.137255,0.556863,0.419608);
    circle1(250.0,-180.0,280.0);//earth

    glColor3f(0.13,0.37,0.31); //base1
    glBegin(GL_POLYGON);
        glVertex2f(80.0,48.0);
    glVertex2f(100.0,40.0);
    glVertex2f(120.0,20.0);
        glVertex2f(150.0,30.0);
    glVertex2f(170.0,20.0);
    glVertex2f(190.0,22.0);
        glVertex2f(200.0,30.0);
    glVertex2f(210.0,35.0);
    glVertex2f(220.0,30.0);
        glVertex2f(250.0,40.0);
    glVertex2f(270.0,40.0);
    glVertex2f(290.0,45.0);
        glVertex2f(305.0,40.0);
    glVertex2f(320.0,50.0);
    glVertex2f(340.0,52.0);
        glVertex2f(360.0,42.0);
    glVertex2f(380.0,60.0);
    glVertex2f(390.0,68.0);
        glVertex2f(400.0,62.0);
    glVertex2f(420.0,50.0);
    glVertex2f(425.0,40.0);
        glVertex2f(440.0,27.0);
    glVertex2f(420.0,35.0);
    glVertex2f(410.0,40.0);
        glVertex2f(390.0,15.0);
    glVertex2f(360.0,35.0);
    glVertex2f(340.0,30.0);
        glVertex2f(280.0,10.0);
    glVertex2f(220.0,25.0);
    glVertex2f(200.0,18.0);
        glVertex2f(160.0,15.0);
    glVertex2f(130.0,17.0);
    glEnd();

    glColor3f(0.137255,0.556863,0.137255); //base2
    glBegin(GL_POLYGON);
        glVertex2f(80.0,45.0);
    glVertex2f(120.0,25.0);
        glVertex2f(160.0,30.0);
    glVertex2f(170.0,20.0);
    glVertex2f(190.0,22.0);
        glVertex2f(200.0,30.0);
    glVertex2f(210.0,35.0);
    glVertex2f(220.0,30.0);
        glVertex2f(250.0,40.0);
    glVertex2f(270.0,40.0);
    glVertex2f(290.0,45.0);
        glVertex2f(305.0,40.0);
    glVertex2f(320.0,50.0);
    glVertex2f(340.0,52.0);
        glVertex2f(360.0,30.0);
    glVertex2f(390.0,60.0);
    glVertex2f(400.0,62.0);
        glVertex2f(368.0,80.0);
    glVertex2f(366.0,88.0);
    glVertex2f(363.0,90.0);
        glVertex2f(360.0,82.0);
    glVertex2f(330.0,95.0);
    glVertex2f(328.0,98.0);
        glVertex2f(325.0,100.0);
    glVertex2f(280.0,110.0);
    glVertex2f(220.0,115.0);
        glVertex2f(180.0,105.0);
    glVertex2f(175.0,110.0);
    glVertex2f(163.0,106.0);
        glVertex2f(160.0,75.0);
    glVertex2f(145.0,95.0);
    glVertex2f(138.0,98.0);
        glVertex2f(130.0,95.0);
    glVertex2f(130.0,85.0);
    glVertex2f(110.0,78.0);
        glVertex2f(105.0,80.0);
    glVertex2f(100.0,65.0);
    glVertex2f(90.0,68.0);
        glVertex2f(85.0,62.0);
    glEnd();

glColor3f(0.647059,0.164706,0.164706);
glBegin(GL_POLYGON);
glVertex2f(138.0,40.0);
glVertex2f(138.0,60.0);
glVertex2f(145.0,80.0);
glVertex2f(120.0,110.0);
glVertex2f(118.0,112.0);
glVertex2f(118.0,138.0);
glVertex2f(121.0,138.0);
glVertex2f(121.0,115.0);
glVertex2f(142.0,112.0);
glVertex2f(145.0,123.0);
glVertex2f(140.0,130.0);
glVertex2f(140.0,150.0);
glVertex2f(125.0,200.0);
glVertex2f(130.0,200.0);
glVertex2f(130.0,153.0);
glVertex2f(140.0,155.0);
glVertex2f(140.0,160.0);
glVertex2f(143.0,160.0);
glVertex2f(143.0,142.0);
glVertex2f(150.0,130.0);
glVertex2f(162.0,135.0);//
glVertex2f(152.0,120.0);
glVertex2f(150.0,80.0);
glVertex2f(142.0,70.0);
glVertex2f(142.0,57.0);
glVertex2f(148.0,55.0);
glVertex2f(143.0,40.0);
glEnd();

glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(162.0,40.0);
glVertex2f(160.0,60.0);
glVertex2f(163.0,80.0);
glVertex2f(160.0,120.0);
glVertex2f(170.0,130.0);
glVertex2f(170.0,160.0);
glVertex2f(167.0,160.0);
glVertex2f(167.0,150.0);
glVertex2f(162.0,135.0);
glVertex2f(152.0,120.0);
glVertex2f(150.0,80.0);
glVertex2f(142.0,70.0);
glVertex2f(142.0,57.0);
glVertex2f(148.0,55.0);
glVertex2f(143.0,40.0);
glEnd();

    glColor3f(0,1,0);
	circle1(165.0,160.0,9.0);
    circle1(123.0,138.0,8.0);
    circle1(127.0,210.0,20.0);
    glColor3f(0.137255,0.556863,0.137255);
	circle1(139.0,160.0,8.0);//
    circle1(171.0,160.0,11.0);//
	circle1(133.0,200.0,15.0);//
	circle1(116.0,138.0,7.0);//
    glColor3f(0,1,0);
	circle1(121.0,200.0,15.0);
	circle1(145.0,160.0,8.0);

glColor3f(0.36,0.25,0.20);
glBegin(GL_POLYGON);
glVertex2f(190.0,60.0);
glVertex2f(200.0,60.0);
glVertex2f(200.0,140.0);
glVertex2f(190.0,140.0);
glEnd();
    glColor3f(0,1,0);
	circle1(185.0,140.0,15.0);
	circle1(195.0,145.0,20.0);
    circle1(205.0,140.0,15.0);
    glColor3f(0.137255,0.556863,0.137255);
    circle1(195.0,135.0,12.0);

glColor3f(0.59,0.41,0.31);
glBegin(GL_POLYGON);
glVertex2f(220.0,50.0);
glVertex2f(230.0,50.0);
glVertex2f(230.0,130.0);
glVertex2f(220.0,130.0);
glEnd();
    glColor3f(0,1,0);
	circle1(215.0,130.0,15.0);
	circle1(225.0,135.0,20.0);
	circle1(225.0,125.0,12.0);
	glColor3f(0.137255,0.556863,0.137255);
    circle1(235.0,130.0,15.0);

glColor3f(0.52,0.37,0.26);
glBegin(GL_POLYGON);
glVertex2f(250.0,50.0);
glVertex2f(260.0,50.0);
glVertex2f(260.0,130.0);
glVertex2f(250.0,130.0);
glEnd();
    glColor3f(0,1,0);
	circle1(245.0,120.0,15.0);
	circle1(255.0,125.0,20.0);
	glColor3f(0.137255,0.556863,0.137255);
	circle1(255.0,115.0,12.0);
    circle1(265.0,120.0,15.0);

glColor3f(0.59,0.41,0.31);
glBegin(GL_POLYGON);
glVertex2f(280.0,50.0);
glVertex2f(290.0,50.0);
glVertex2f(290.0,130.0);
glVertex2f(280.0,130.0);
glEnd();
    glColor3f(0,1,0);
	circle1(275.0,130.0,15.0);
	circle1(285.0,135.0,20.0);
	circle1(285.0,125.0,12.0);
	glColor3f(0.137255,0.556863,0.137255);
    circle1(295.0,130.0,15.0);

glColor3f(0.36,0.25,0.20);
glBegin(GL_POLYGON);
glVertex2f(310.0,60.0);
glVertex2f(320.0,60.0);
glVertex2f(320.0,140.0);
glVertex2f(310.0,140.0);
glEnd();
    glColor3f(0,1,0);
	circle1(305.0,140.0,15.0);
	circle1(315.0,145.0,20.0);
	glColor3f(0.137255,0.556863,0.137255);
	circle1(315.0,135.0,12.0);
    circle1(325.0,140.0,15.0);

glColor3f(0.59,0.41,0.31);
glBegin(GL_POLYGON);
glVertex2f(340.0,70.0);
glVertex2f(350.0,70.0);
glVertex2f(350.0,150.0);
glVertex2f(340.0,150.0);
glEnd();
    glColor3f(0.0,1.0,0.0);
	circle1(335.0,150.0,15.0);
	circle1(345.0,155.0,20.0);
	circle1(345.0,145.0,12.0);
    circle1(355.0,150.0,15.0);

glColor3f(0.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(138.0,40.0);
glVertex2f(160.0,50.0);
glVertex2f(200.0,35.0);
glVertex2f(320.0,32.0);
glVertex2f(330.0,50.0);
glVertex2f(340.0,35.0);
glVertex2f(370.0,40.0);
glVertex2f(360.0,30.0);
glVertex2f(260.0,40.0);
glVertex2f(130.0,30.0);
glEnd();

glColor3f(0.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(370.0,50.0);
glVertex2f(380.0,60.0);//grass
glVertex2f(375.0,57.0);
glVertex2f(370.0,65.0);
glVertex2f(365.0,57.0);
glVertex2f(360.0,60.0);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(320.0,50.0);
glVertex2f(330.0,60.0);//grass
glVertex2f(325.0,57.0);
glVertex2f(320.0,65.0);
glVertex2f(315.0,57.0);
glVertex2f(310.0,60.0);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(120.0,50.0);
glVertex2f(130.0,60.0);//grass
glVertex2f(125.0,57.0);
glVertex2f(120.0,65.0);
glVertex2f(115.0,57.0);
glVertex2f(110.0,60.0);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(210.0,70.0);
glVertex2f(220.0,80.0);//grass
glVertex2f(215.0,77.0);
glVertex2f(210.0,85.0);
glVertex2f(205.0,77.0);
glVertex2f(200.0,80.0);
glEnd();

        glPushMatrix();
        glTranslated(g,300,0.0);
        glColor3f(0.0,1.8,0.8);//head char
        circle1(108.0,60.0,8.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(108.0,62.0);
        glVertex2f(116.0,62.0);//helmet
        glVertex2f(116.0,56.0);
        glVertex2f(108.0,58.0);
        glEnd();
        glColor3f(1,0.4,0.7);
        glLineWidth(1);
        glBegin(GL_LINE_LOOP);//outline of upper triangle plane
        glVertex2f(108.0,62.0);
        glVertex2f(116.0,62.0);//helmet
        glVertex2f(116.0,56.0);
        glVertex2f(108.0,58.0);
        glEnd();
        glColor3f(1,0.4,0.7);
        glBegin(GL_POLYGON);//rectangular body
        glVertex2f(110.0,35.0);
        glVertex2f(135.0,40.0);
        glVertex2f(107.0,53.0);
        glEnd();
        glColor3f(1.2,1.4,0.2);
        glBegin(GL_POLYGON);//rectangular body
        glVertex2f(35,25.0);
        glVertex2f(40,20.0);
        glVertex2f(135.0,27.0);
        glVertex2f(135.0,40.0);
        glVertex2f(37.0,32.0);
        glVertex2f(35.0,25.0);
        glEnd();
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);//upper triangle construction plane
        glVertex2f(130.0,58.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
        glEnd();
        glColor3f(0.5,0,2);
        glLineWidth(4);
        glBegin(GL_LINE_LOOP);//outline of upper triangle plane
        glVertex2f(130.0,58.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
        glEnd();
        glColor3f(0.5,0,2);
        glBegin(GL_POLYGON);//lower triangle
        glVertex2f(135.0,40.0);
        glVertex2f(160.0,40.0);
        glVertex2f(160.0,37.0);
        glVertex2f(145.0,27.0);
        glVertex2f(135.0,27.0);
        glEnd();
            glColor3f(1.2,1.4,0.2);
            glBegin(GL_POLYGON);//body
            glVertex2f(35.0,30.0);
            glVertex2f(115.0,36.0);
            glVertex2f(106.0,57.0);
            glVertex2f(100.0,63.0);
            glVertex2f(90.0,62.0);
            glVertex2f(80.0,60.0);
            glVertex2f(70.0,56.0);
            glVertex2f(50.0,42.0);
            glEnd();
            glColor3f(1,1,1);
            glBegin(GL_POLYGON);//inside body
            glVertex2f(67.0,37.0);
            glVertex2f(107.0,42.0);
            glVertex2f(95.0,58.0);
            glVertex2f(65.0,48.0);
            glEnd();
            glColor3f(0.0,0.0,0.0);
            glLineWidth(3);
            glBegin(GL_LINE_LOOP);//outline of upper triangle plane
            glVertex2f(67.0,37.0);
            glVertex2f(107.0,42.0);
            glVertex2f(95.0,58.0);
            glVertex2f(65.0,48.0);
            glEnd();
            glColor3f(0.5,0,2);
            glBegin(GL_POLYGON);//back wing
            glVertex2f(35,30.0);
            glVertex2f(58.0,45.0);
            glVertex2f(35.0,70.0);
            glVertex2f(22.0,75.0);
            glEnd();
            glColor3f(0.5,0,2);
            glBegin(GL_POLYGON);//right wing
            glVertex2f(85.0,10.0);
            glVertex2f(105.0,15.0);
            glVertex2f(127.0,38.0);
            glVertex2f(100.0,35.0);
            glEnd();

            glPopMatrix();

        glPushMatrix();
        glTranslated(x5,y5,0.0);
        glColor3f(0,0,0);
        glBegin(GL_POLYGON);
        glVertex2f(270.0,150.0);
        glVertex2f(280.0,160.0);//bird
        glVertex2f(265.0,157.0);
        glVertex2f(260.0,160.0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(262.0,157.0);
        glVertex2f(262.0,161.0);//bird
        glVertex2f(257.0,158.0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(290.0,160.0);
        glVertex2f(300.0,170.0);//bird
        glVertex2f(285.0,167.0);
        glVertex2f(280.0,170.0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(282.0,167.0);
        glVertex2f(282.0,171.0);//bird
        glVertex2f(277.0,168.0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(290.0,140.0);
        glVertex2f(300.0,150.0);//bird
        glVertex2f(285.0,147.0);
        glVertex2f(280.0,150.0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(282.0,147.0);
        glVertex2f(282.0,151.0);//bird
        glVertex2f(277.0,148.0);
        glEnd();
        glPopMatrix();

        names();
        glPushMatrix();
        glRotatef(30,0,0,1);
        display_string(82,61,"Amazon",2);
        display_string1(180,-100,"atlantic ocean",2);
        glPopMatrix();

}

void display6()
{
        glClear(GL_COLOR_BUFFER_BIT);
         glColor3f(0.847, 0.749, 0.847);
         glBegin(GL_POLYGON);
         glVertex2f(0,0);
         glVertex2f(499,0);
         glVertex2f(499,499);
         glVertex2f(0,499);
         glEnd();

    glColor3f(1.0,1.0,1.0);
    circle1(50.0,170.0,2.0);
	circle1(250.0,350.0,1.0);
	circle1(180.0,200.0,1.0);
	circle1(200.0,350.0,1.0);
	circle1(150.0,200.0,1.0);
	circle1(400.0,450.0,1.0);
	circle1(420.0,400.0,2.0);//exxtra
	circle1(330.0,300.0,1.0);
	circle1(350.0,250.0,1.0);
	circle1(400.0,300.0,1.0);
    circle1(220.0,100.0,1.0);
    circle1(450.0,200.0,1.0);
    //circle1(400.0,300.0,2.0);

    glColor3f(0.373, 0.620, 0.627);
    circle1(250.0,-200.0,300.0);//earth

       glColor3f( 	1.000, 0.980, 0.941);//layer4
    glBegin(GL_POLYGON);
        glVertex2f(120.0,80.0);
    glVertex2f(130.0,120.0);
        glVertex2f(180.0,125.0);
    glVertex2f(220.0,110.0);
    glVertex2f(250.0,140.0);
        glVertex2f(280.0,115.0);
    glVertex2f(320.0,130.0);
    glVertex2f(370.0,100.0);
        glVertex2f(390.0,110.0);
    glVertex2f(420.0,60.0);
    glVertex2f(430.0,30.0);
        glVertex2f(300.0,90.0);
    glVertex2f(260.0,110.0);
    glVertex2f(220.0,90.0);
        glVertex2f(150.0,100.0);
    glEnd();

        glColor3f(1.000, 0.980, 0.980); //base2
    glBegin(GL_POLYGON);
        glVertex2f(80.0,45.0);
    glVertex2f(120.0,25.0);
        glVertex2f(160.0,40.0);
    glVertex2f(170.0,20.0);
    glVertex2f(190.0,32.0);
        glVertex2f(200.0,40.0);
    glVertex2f(210.0,45.0);
    glVertex2f(220.0,40.0);
        glVertex2f(250.0,50.0);
    glVertex2f(270.0,50.0);
    glVertex2f(290.0,65.0);//
        glVertex2f(305.0,70.0);
    glVertex2f(320.0,60.0);
    glVertex2f(340.0,52.0);
        glVertex2f(360.0,50.0);
    glVertex2f(390.0,60.0);
    glVertex2f(400.0,62.0);
        glVertex2f(368.0,80.0);
    glVertex2f(366.0,88.0);
    glVertex2f(363.0,90.0);
        glVertex2f(360.0,82.0);
    glVertex2f(330.0,95.0);
    glVertex2f(328.0,98.0);
        glVertex2f(325.0,100.0);
    glVertex2f(280.0,110.0);
    glVertex2f(220.0,115.0);
    glEnd();

    glColor3f(0.941, 1.000, 1.000); //layer1
    glBegin(GL_POLYGON);
        glVertex2f(80.0,45.0);
    glVertex2f(120.0,92.0);
        glVertex2f(135.0,80.0);
    glVertex2f(180.0,115.0);
    glVertex2f(220.0,105.0);
        glVertex2f(270.0,125.0);
    glVertex2f(300.0,110.0);
    glVertex2f(340.0,120.0);
        glVertex2f(360.0,86.0);
    glVertex2f(300.0,66.0);
    glEnd();

    glColor3f(0.941, 0.973, 1.000); //layer2
    glBegin(GL_POLYGON);
        glVertex2f(95.0,45.0);
    glVertex2f(120.0,45.0);
        glVertex2f(160.0,48.0);
    glVertex2f(170.0,67.0);
    glVertex2f(190.0,60);
        glVertex2f(200.0,60.0);
    glVertex2f(210.0,62.0);
    glVertex2f(220.0,63.0);
        glVertex2f(250.0,55.0);
    glVertex2f(270.0,62.0);
    glVertex2f(290.0,65.0);
        glVertex2f(300.0,80.0);
    glVertex2f(260.0,108.0);
    glVertex2f(220.0,87.0);
        glVertex2f(150.0,96.0);
    glEnd();

    glColor3f(1,1,0.8);//m1
    glBegin(GL_POLYGON);
    glVertex2f(140.0,70.0);
    glVertex2f(165.0,140.0);
    glVertex2f(175.0,150.0);
    glVertex2f(185.0,145.0);
    glVertex2f(240.0,70.0);
    glEnd();

        glColor3f(1,1,0.9);//m3
        glBegin(GL_POLYGON);
        glVertex2f(170.0,70.0);
        glVertex2f(210.0,160.0);
        glVertex2f(250.0,120.0);
        glVertex2f(310.0,170.0);
        glVertex2f(350.0,70.0);
        glEnd();

        glColor3f(1,1,0.8);
        glBegin(GL_POLYGON);
        glVertex2f(270.0,70.0);//m4
        glVertex2f(285.0,90.0);
        glVertex2f(300.0,120.0);
        glVertex2f(310.0,135.0);
        glVertex2f(320.0,140.0);
        glVertex2f(340.0,140.0);
        glVertex2f(350.0,130.0);
        glVertex2f(310.0,70.0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(350.0,130.0);//m5
        glVertex2f(310.0,70.0);
        glVertex2f(370.0,70.0);
        glVertex2f(360.0,120.0);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(330.0,70.0);//3mountains
        glVertex2f(380.0,90.0);
        glVertex2f(403.0,60.0);
        glEnd();

        glColor3f(1.0,1.0,0.3);
        glBegin(GL_POLYGON);
        glVertex2f(160.0,80.0);
        glVertex2f(220.0,80.0);
        glVertex2f(197.0,170.0);
        glVertex2f(178.0,150.0);
        glEnd();

        glColor3f(0.9,1.9,1.1);
        glBegin(GL_POLYGON);
        glVertex2f(190.0,200.0);
        glVertex2f(197.0,170.0);
        glVertex2f(178.0,150.0);
        glEnd();

        glColor3f(1.0,1.0,0.5);
        glBegin(GL_POLYGON);
        glVertex2f(240.0,70.0);
        glVertex2f(300.0,70.0);
        glVertex2f(300.0,250.0);
        glEnd();

        glColor3f(1.0,1.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(300.0,250.0);
        glVertex2f(300.0,70.0);
        glVertex2f(340.0,70.0);
        glEnd();


        glColor3f(0.9,1.9,1.1);
        glBegin(GL_POLYGON);
        glVertex2f(300.0,260.0);
        glVertex2f(280.0,190.0);
        glVertex2f(290.0,180.0);
        glVertex2f(300.0,195.0);
        glEnd();

        glColor3f(0.9,1.9,1.1);
        glBegin(GL_POLYGON);
        glVertex2f(300.0,260.0);
        glVertex2f(300.0,190.0);
        glVertex2f(310.0,180.0);
        glVertex2f(315.0,185.0);
        glEnd();
        //


        glColor3f(1.0,1.0,0.5);
        glBegin(GL_POLYGON);
        glVertex2f(200.0,70.0);
        glVertex2f(250.0,70.0);
        glVertex2f(250.0,180.0);
        glEnd();

        glColor3f(1.0,1.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(250.0,180.0);
        glVertex2f(250.0,70.0);
        glVertex2f(300.0,70.0);
        glEnd();


        glColor3f(0.9,1.9,1.1);
        glBegin(GL_POLYGON);
        glVertex2f(250.0,180.0);
        glVertex2f(250.0,140.0);
        glVertex2f(260.0,120.0);
        glVertex2f(270.0,140.0);
        glEnd();

        glColor3f(0.9,1.9,1.1);
        glBegin(GL_POLYGON);
        glVertex2f(250.0,180.0);
        glVertex2f(235.0,150.0);
        glVertex2f(240.0,130.0);
        glVertex2f(250.0,140.0);
        glEnd();

        glColor3f(1,1,0.9);
        glBegin(GL_POLYGON);
        glVertex2f(90.0,60.0);//m2
        glVertex2f(120.0,120.0);
        glVertex2f(160.0,90.0);
        glVertex2f(200.0,120.0);
        glVertex2f(240.0,60.0);
        glEnd();

        glColor3f(0.902, 0.902, 0.980);
        glBegin(GL_POLYGON);
        glVertex2f(170.0,50.0);
        glVertex2f(180.0,60.0);//grass
        glVertex2f(175.0,57.0);
        glVertex2f(170.0,65.0);
        glVertex2f(165.0,57.0);
        glVertex2f(160.0,60.0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(175.0,50.0);
        glVertex2f(185.0,60.0);//grass
        glVertex2f(180.0,57.0);
        glVertex2f(175.0,65.0);
        glVertex2f(170.0,57.0);
        glVertex2f(165.0,60.0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(320.0,50.0);
        glVertex2f(330.0,60.0);//grass
        glVertex2f(325.0,57.0);
        glVertex2f(320.0,65.0);
        glVertex2f(315.0,57.0);
        glVertex2f(310.0,60.0);
        glEnd();

        glColor3f(0.902, 0.902, 0.980);
        glBegin(GL_POLYGON);
        glVertex2f(360.0,80.0);
        glVertex2f(370.0,90.0);//grass
        glVertex2f(365.0,87.0);
        glVertex2f(360.0,95.0);
        glVertex2f(355.0,87.0);
        glVertex2f(350.0,90.0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(365.0,80.0);
        glVertex2f(375.0,90.0);//grass
        glVertex2f(370.0,87.0);
        glVertex2f(365.0,95.0);
        glVertex2f(360.0,87.0);
        glVertex2f(355.0,90.0);
        glEnd();

glColor3f(1,1,1);
        glPushMatrix();
        glTranslated(x61,y61,0.0);
         circle1(140.0,325.0,15.0);
         circle1(260.0,325.0,15.0);
         glBegin(GL_POLYGON);
         glVertex2f(140,340);
         glVertex2f(140,310);
         glVertex2f(260,310);
         glVertex2f(260,340);
         glEnd();
         glColor3f(1,1,1);
            circle1(260.0,340.0,25.0);
            circle1(320.0,345.0,30.0);
            circle1(280.0,340.0,25.0);
            circle1(300.0,330.0,30.0);
            circle1(320.0,320.0,20.0);
        glPopMatrix();

        glPushMatrix();
        glTranslated(x6,y6,0.0);
        glColor3f(1,1,1);
        glBegin(GL_POLYGON);
        glVertex2f(270.0,300.0);
        glVertex2f(275.0,310.0);//bird
        glVertex2f(265.0,307.0);
        glVertex2f(260.0,310.0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(170.0,350.0);
        glVertex2f(175.0,360.0);//bird
        glVertex2f(165.0,357.0);
        glVertex2f(160.0,360.0);
        glEnd();
        glPushMatrix();
        glRotatef(h,1,0,0);
        glBegin(GL_POLYGON);
        glVertex2f(370.0,350.0);
        glVertex2f(375.0,360.0);//bird
        glVertex2f(365.0,357.0);
        glVertex2f(360.0,360.0);
        glEnd();
        glPopMatrix();
        glPopMatrix();

//

        glPushMatrix();
        glTranslated(h,300,0.0);
        glColor3f(0.0,1.8,0.8);//head char
        circle1(108.0,60.0,8.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(108.0,62.0);
        glVertex2f(116.0,62.0);//helmet
        glVertex2f(116.0,56.0);
        glVertex2f(108.0,58.0);
        glEnd();
        glColor3f(1,0.4,0.7);
        glLineWidth(1);
        glBegin(GL_LINE_LOOP);//outline of upper triangle plane
        glVertex2f(108.0,62.0);
        glVertex2f(116.0,62.0);//helmet
        glVertex2f(116.0,56.0);
        glVertex2f(108.0,58.0);
        glEnd();
        glColor3f(1,0.4,0.7);
        glBegin(GL_POLYGON);//rectangular body
        glVertex2f(110.0,35.0);
        glVertex2f(135.0,40.0);
        glVertex2f(107.0,53.0);
        glEnd();
        glColor3f(1.2,1.4,0.2);
        glBegin(GL_POLYGON);//rectangular body
        glVertex2f(35,25.0);
        glVertex2f(40,20.0);
        glVertex2f(135.0,27.0);
        glVertex2f(135.0,40.0);
        glVertex2f(37.0,32.0);
        glVertex2f(35.0,25.0);
        glEnd();
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);//upper triangle construction plane
        glVertex2f(130.0,58.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
        glEnd();
        glColor3f(0.5,0,2);
        glLineWidth(4);
        glBegin(GL_LINE_LOOP);//outline of upper triangle plane
        glVertex2f(130.0,58.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
        glEnd();
        glColor3f(0.5,0,2);
        glBegin(GL_POLYGON);//lower triangle
        glVertex2f(135.0,40.0);
        glVertex2f(160.0,40.0);
        glVertex2f(160.0,37.0);
        glVertex2f(145.0,27.0);
        glVertex2f(135.0,27.0);
        glEnd();
            glColor3f(1.2,1.4,0.2);
            glBegin(GL_POLYGON);//body
            glVertex2f(35.0,30.0);
            glVertex2f(115.0,36.0);
            glVertex2f(106.0,57.0);
            glVertex2f(100.0,63.0);
            glVertex2f(90.0,62.0);
            glVertex2f(80.0,60.0);
            glVertex2f(70.0,56.0);
            glVertex2f(50.0,42.0);
            glEnd();
            glColor3f(1,1,1);
            glBegin(GL_POLYGON);//inside body
            glVertex2f(67.0,37.0);
            glVertex2f(107.0,42.0);
            glVertex2f(95.0,58.0);
            glVertex2f(65.0,48.0);
            glEnd();
            glColor3f(0.0,0.0,0.0);
            glLineWidth(3);
            glBegin(GL_LINE_LOOP);//outline of upper triangle plane
            glVertex2f(67.0,37.0);
            glVertex2f(107.0,42.0);
            glVertex2f(95.0,58.0);
            glVertex2f(65.0,48.0);
            glEnd();
            glColor3f(0.5,0,2);
            glBegin(GL_POLYGON);//back wing
            glVertex2f(35,30.0);
            glVertex2f(58.0,45.0);
            glVertex2f(35.0,70.0);
            glVertex2f(22.0,75.0);
            glEnd();
            glColor3f(0.5,0,2);
            glBegin(GL_POLYGON);//right wing
            glVertex2f(85.0,10.0);
            glVertex2f(105.0,15.0);
            glVertex2f(127.0,38.0);
            glVertex2f(100.0,35.0);
            glEnd();

            glPopMatrix();
        names();
        glPushMatrix();
        glRotatef(30,0,0,1);
        display_string(75,61,"Antarctica",2);
        display_string1(180,-100,"indian ocean",2);
        glPopMatrix();

}

void display8()
{

        glClear(GL_COLOR_BUFFER_BIT);
         glColor3f(0.372549,0.623529,0.623529);
         glBegin(GL_POLYGON);
         glVertex2f(0,0);
         glVertex2f(499,0);
         glVertex2f(499,499);
         glVertex2f(0,499);
         glEnd();
        road();
        glPushMatrix();
        glTranslated(j,300,0.0);
        glPushMatrix();
        glTranslated(j,y8,0.0);
        glColor3f(0.0,1.8,0.8);//head char
        circle1(108.0,60.0,8.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(108.0,62.0);
        glVertex2f(116.0,62.0);//helmet
        glVertex2f(116.0,56.0);
        glVertex2f(108.0,58.0);
        glEnd();
        glColor3f(1,0.4,0.7);
        glLineWidth(1);
        glBegin(GL_LINE_LOOP);//outline of upper triangle plane
        glVertex2f(108.0,62.0);
        glVertex2f(116.0,62.0);//helmet
        glVertex2f(116.0,56.0);
        glVertex2f(108.0,58.0);
        glEnd();
        glColor3f(1,0.4,0.7);
        glBegin(GL_POLYGON);//rectangular body
        glVertex2f(110.0,35.0);
        glVertex2f(135.0,40.0);
        glVertex2f(107.0,53.0);
        glEnd();
        glColor3f(1.2,1.4,0.2);
        glBegin(GL_POLYGON);//rectangular body
        glVertex2f(35,25.0);
        glVertex2f(40,20.0);
        glVertex2f(135.0,27.0);
        glVertex2f(135.0,40.0);
        glVertex2f(37.0,32.0);
        glVertex2f(35.0,25.0);
        glEnd();
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);//upper triangle construction plane
        glVertex2f(130.0,58.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
        glEnd();
        glColor3f(0.5,0,2);
        glLineWidth(4);
        glBegin(GL_LINE_LOOP);//outline of upper triangle plane
        glVertex2f(130.0,58.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
        glEnd();
        glColor3f(0.5,0,2);
        glBegin(GL_POLYGON);//lower triangle
        glVertex2f(135.0,40.0);
        glVertex2f(160.0,40.0);
        glVertex2f(160.0,37.0);
        glVertex2f(145.0,27.0);
        glVertex2f(135.0,27.0);
        glEnd();
            glColor3f(1.2,1.4,0.2);
            glBegin(GL_POLYGON);//body
            glVertex2f(35.0,30.0);
            glVertex2f(115.0,36.0);
            glVertex2f(106.0,57.0);
            glVertex2f(100.0,63.0);
            glVertex2f(90.0,62.0);
            glVertex2f(80.0,60.0);
            glVertex2f(70.0,56.0);
            glVertex2f(50.0,42.0);
            glEnd();
            glColor3f(1,1,1);
            glBegin(GL_POLYGON);//inside body
            glVertex2f(67.0,37.0);
            glVertex2f(107.0,42.0);
            glVertex2f(95.0,58.0);
            glVertex2f(65.0,48.0);
            glEnd();
            glColor3f(0.0,0.0,0.0);
            glLineWidth(3);
            glBegin(GL_LINE_LOOP);//outline of upper triangle plane
            glVertex2f(67.0,37.0);
            glVertex2f(107.0,42.0);
            glVertex2f(95.0,58.0);
            glVertex2f(65.0,48.0);
            glEnd();
            glColor3f(0.5,0,2);
            glBegin(GL_POLYGON);//back wing
            glVertex2f(35,30.0);
            glVertex2f(58.0,45.0);
            glVertex2f(35.0,70.0);
            glVertex2f(22.0,75.0);
            glEnd();
            glColor3f(0.5,0,2);
            glBegin(GL_POLYGON);//right wing
            glVertex2f(85.0,10.0);
            glVertex2f(105.0,15.0);
            glVertex2f(127.0,38.0);
            glVertex2f(100.0,35.0);
            glEnd();
            glPopMatrix();
            glPopMatrix();
            glPushMatrix();
            glTranslated(c3,0,0.0);
            glColor3f(0.863, 0.863, 0.863);
            circle1(560.0,380.0,25.0);
            circle1(620.0,400.0,30.0); //cloud
            circle1(580.0,390.0,25.0);
            circle1(600.0,380.0,30.0);
            glPopMatrix();
            glPushMatrix();
            glTranslated(c4,0,0.0);
            glColor3f(0.663, 0.663, 0.663);
            circle1(160.0,340.0,25.0);
            circle1(220.0,345.0,30.0);
            circle1(180.0,340.0,25.0);
            circle1(200.0,330.0,30.0);
            circle1(220.0,320.0,20.0);
            glPopMatrix();

            glPushMatrix();
            display_string(100,330,"YOU CAN ALWAYS MAKE MONEY",1);
            display_string(100,280,"YOU CAN'T ALWAYS MAKE MEMORIES",1);
            display_string1(150,180,"TAKE VACATIONS | TRAVEL",1);
            glPopMatrix();
}

void display1(void)
{
        glClear(GL_COLOR_BUFFER_BIT);
         glColor3f(0.804, 0.522, 0.247);
         glBegin(GL_POLYGON);
         glVertex2f(0,0);
         glVertex2f(499,0);
         glVertex2f(499,499);
         glVertex2f(0,499);
         glEnd();
        glClearColor(1.0,1.0,0.0,1.0);
        display_string1(160,395,"Sahyadri College of engineering",1);
        display_string(130,295,"*AROUND THE WORLD IN A SNAP*",1);
        display_string1(90,195,"COMPUTER GRAPHICS LABORATORY WITH MINI PROJECT",2);
        display_string(250,130,"BY",3);
        display_string(300,120,"NITHIN THOMAS",2);
        display_string(305,105,"4SF15CS100",3);
        display_string(300,80,"RAHUL N",2);
        display_string(305,65,"4SF15CS117",3);
        display_string(35,60,"ESCAPE 0 EXIT",4);
        display_string(35,40,"PRESS 1 TO ENTER",4);
        glutPostRedisplay();
        glutSwapBuffers();

        glutPostRedisplay();
        glutSwapBuffers();

}

/////...
void update(int value)
{
     a+=11.0; //Plane position takeoff on x axis
     b-=10.0;
     c1-=4;
     c2-=2; //Road Strip backward movement
     c+=8; //take off at certain angle on y axis
     if(b<=-78.0)// moving of run way
      b=0.0;
     glutPostRedisplay();
     glutTimerFunc(200,update,0);//delay
}

void blast(void)//blast polygon construction
{
        glPushMatrix();
        glTranslated(x3,y3,0.0);
        glColor3f(1.000, 0.271, 0.000);
                circle1(270.0,270.0,4.0);
                circle1(190.0,280.0,5.0);
        glBegin(GL_POLYGON);//smoke
        glVertex2f(240.0,195.0);
        glVertex2f(220.0,220.0);
        glVertex2f(222.0,230.0);
        glVertex2f(210.0,230.0);
        glVertex2f(220.0,250.0);
        glVertex2f(240.0,245.0);
        glVertex2f(260.0,250.0);
        glVertex2f(260.0,195.0);
        glEnd();
        glColor3f(1.000, 0.371, 0.000);
        glBegin(GL_POLYGON);
        glVertex2f(290.0,225.0);
        glVertex2f(280.0,220.0);
        glVertex2f(260.0,195.0);
        glVertex2f(260.0,195.0);
        glVertex2f(260.0,245.0);
        glVertex2f(280.0,235.0);
        glVertex2f(290.0,230.0);
        glVertex2f(290.0,240.0);
        glEnd();
        glColor3f(0.7,0,0);
        glBegin(GL_POLYGON);//smoke
        glVertex2f(230.0,240.0);
        glVertex2f(265.0,230.0);
        glVertex2f(260.0,220.0);
        glVertex2f(240.0,220.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(x31,y31,0.0);
        glColor3f(1.000, 0.371, 0.000);//fire
        circle1(300.0,220.0,5.0);
        circle1(302.0,215.0,3.0);
           // glColor3f(0.7,0,0);
            circle1(190.0,220.0,5.0);
            circle1(187.0,215.0,3.0);
                    //glColor3f(1,0,0);
                    circle1(210.0,180.0,4.0);
                    circle1(280.0,180.0,4.0);
                           // glColor3f(0.7,0,0);
                            circle1(170.0,160.0,3.0);
                            circle1(330.0,150.0,3.0);
                    //glColor3f(1.000, 0.571, 0.000);
                    circle1(220.0,200.0,3.0);
                    circle1(280.0,210.0,3.0);
               // glColor3f(0.7,0,0);
                circle1(270.0,270.0,4.0);
                circle1(190.0,280.0,5.0);
        glPopMatrix();

        glPushMatrix();
        glTranslated(x31,x32,0.0);
        glColor3f(0.52,0,0);//fire
        glBegin(GL_POLYGON);
        glVertex2f(235.0,200.0);
        glVertex2f(235.0,185.0);
        glVertex2f(250.0,166.0);
        glVertex2f(240.0,146.0);
        glEnd();
        glColor3f(0.62,0,0);//fire
        glBegin(GL_POLYGON);
        glVertex2f(252.0,190.0);
        glVertex2f(260.0,157.0);
        glVertex2f(265.0,146.0);
        glVertex2f(260.0,140.0);
        glEnd();
        glPopMatrix();
}

void circle1(GLfloat x, GLfloat y, GLfloat radius)
{
        float angle;
        glBegin(GL_POLYGON);
        for(int i=0;i<100;i++)
        {
            angle = i*2*(M_PI/100);
            glVertex2f(x+(cos(angle)*radius),y+(sin(angle)*radius));
        }
        glEnd();
}

void names()
{

        glColor3f(0.35,0.16,0.14);//pluck card
         glBegin(GL_POLYGON);
         glVertex2f(60,100);
         glVertex2f(70,100);
         glVertex2f(70,20);
         glVertex2f(60,20);
         glEnd();

        glColor3f(0.52,0.37,0.26);
         glBegin(GL_POLYGON);
         glVertex2f(40,70);
         glVertex2f(90,90);
         glVertex2f(100,110);
         glVertex2f(80,120);
         glVertex2f(30,100);
         glEnd();
        glColor3f(0.35,0.16,0.14);
        glLineWidth(4);
        glBegin(GL_LINE_LOOP);
         glVertex2f(40,70);
         glVertex2f(90,90);
         glVertex2f(100,110);
         glVertex2f(80,120);
         glVertex2f(30,100);
        glEnd();

}

void road()
{

        glColor3f(0.352941,0.352941,0.352941);
        glBegin(GL_POLYGON);//black road
        glVertex2f(0.0,0.0);
        glVertex2f(0.0,100.0);
        glVertex2f(500.0,100.0);
        glVertex2f(500.0,0.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);//white strips on road



        glVertex2f(0.0,40.0);
        glVertex2f(8.0,60.0);
        glVertex2f(58.0,60.0);
        glVertex2f(50.0,40.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(100.0,40.0);
        glVertex2f(108.0,60.0);
        glVertex2f(158.0,60.0);
        glVertex2f(150.0,40.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(200.0,40.0);
        glVertex2f(208.0,60.0);
        glVertex2f(258.0,60.0);
        glVertex2f(250.0,40.0);



        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(300.0,40.0);
        glVertex2f(308.0,60.0);
        glVertex2f(358.0,60.0);
        glVertex2f(350.0,40.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(400.0,40.0);
        glVertex2f(408.0,60.0);
        glVertex2f(458.0,60.0);
        glVertex2f(450.0,40.0);
        glEnd();
        glPopMatrix();
}

void myinit()
{
        glClearColor(0.0f,0.0f,0.0f,0.0f);
        glColor3f(1.0,0.0,0.0);
        glPointSize(1.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0,499.0,0.0,499.0);

}

void colorMenu(int id)
{
		if (id==6)
	{

        c1=0,c2=0,c3=0,c4=0,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,x2=0,y2=0,x3=0,y3=0,x4=0,y4=0,x5=0,y5=0,x6=0,y6=0,x7=0,y7=0,x8=0,y8=0;
        x21=0,y21=0,x22=0,x31=0,y31=0,x32=0,x41=0,y41=0,x51=0,y51=0,x61=0,y61=0;

		display2();
		glutPostRedisplay();


	}
	if(id ==7)
	{

		glutDestroyWindow(window);
	}

}

/////...
int main(int argc, char* argv[])
{

        PlaySound(TEXT("F:\\2.IMP FOLDER\\MINI PROJECTS\\Around the world -CG\\song2.wav"),NULL,SND_ASYNC|SND_LOOP);
      //  PlaySound(TEXT("C:\\Users\\Brodie\\Documents\\nthn\\audio.wav"),NULL,SND_ASYNC|SND_LOOP);
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(800.0,680.0);
        glutInitWindowPosition(250,0);
        window=glutCreateWindow("Around the world in a snap");
        glutCreateMenu(colorMenu);
        glutAddMenuEntry("Restart", 6);
        glutAddMenuEntry("Exit", 7);
            glutAttachMenu(GLUT_RIGHT_BUTTON);
            glutKeyboardFunc(&intro);
        glutDisplayFunc(display);
        myinit();
        glutTimerFunc(100,update,0);
        glutMainLoop();
}
