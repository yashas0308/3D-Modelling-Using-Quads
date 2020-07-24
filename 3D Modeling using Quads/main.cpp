#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
int vpX=0,vpY=0;
int FOV_v=70;
float gridAngleY=0;
int gridSize=20;
int cx=0,cy=0,cz=0;
int cn;
std::string vertex = "v";
std::string cline = "c";
std::string stat = "s";
std::string tot= "t";
std::string curFileName;
struct Quads
{
    int x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4;        //No of Coordinates required to draw a Quad is 4
    float r,g,b;                                       //Colors used between R,G,B
    int state;                                         //State = 4 will draw a Quad if greater it will allocate for next Quad
    int total;                                         //Counts Total No. of Quads Drawn in the Field
}; Quads Q[100];

void addQuad()
{
    Q[0].state++; if(Q[0].state>4) { Q[0].state=1;}
    int st=Q[0].state;

    if(st==1) { Q[0].total++; cn =Q[0].total;}
    if(st==1                      ){ Q[cn].x1=cx; Q[cn].y1=cy; Q[cn].z1=cz;}
    if(st==1||st==2               ){ Q[cn].x2=cx; Q[cn].y2=cy; Q[cn].z2=cz;}
    if(st==1||st==2||st==3        ){ Q[cn].x3=cx; Q[cn].y3=cy; Q[cn].z3=cz;}
    if(st==1||st==2||st==3||st==4 ){ Q[cn].x4=cx; Q[cn].y4=cy; Q[cn].z4=cz;}

}

void drawQuads()
{
    int i;
    for(i=1;i<Q[0].total+1;i++)
    {
        glBegin(GL_QUADS);
        glColor3f(Q[i].r,Q[i].g,Q[i].b);
        glVertex3f(Q[i].x1,Q[i].y1,Q[i].z1);
        glVertex3f(Q[i].x2,Q[i].y2,Q[i].z2);
        glVertex3f(Q[i].x3,Q[i].y3,Q[i].z3);
        glVertex3f(Q[i].x4,Q[i].y4,Q[i].z4);
        glEnd();
    }
}

void theCube()
{
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(cx,cy,cz);
    glutSolidCube(0.4);
    glPopMatrix();
}

void drawGrid()
{   int i;
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(vpX,vpY,0);
    glRotatef(gridAngleY,0.0,1.0,0.0);
    glFlush();
    for(i=0;i<gridSize;i++)
    {
     glPushMatrix();
     if(i< (gridSize/2)) {glTranslatef(0,0,i);}
     if(i>=(gridSize/2)) {glTranslatef(i-(gridSize/2),0,0); glRotatef(-90,0,1,0);}
     glBegin(GL_LINES);
     glColor3f(1.0,1.0,1.0);
     glLineWidth(1);
     glVertex3f(0.0,-0.1,0.0);
     glVertex3f((gridSize/2)-1,-0.1,0.0);
     glEnd();
     glPopMatrix();
    }
}


void display()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOV_v,1.0f,0.1f,1000);
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.2,0.2,0.2 ,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-13,0,-45);
    glRotatef(40,1,1,0);

    drawGrid();
    drawQuads();
    theCube();
   glutSwapBuffers();

}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOV_v,1.0f,0.1f,1000);
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.2,0.2,0.2,1);
}

std::string intToString(int a)
{
  std::ostringstream s;
  s << a;
  std::string ret(s.str());
  return ret;
}

std::string floatToString(float a)
{
  std::ostringstream s;
  s << a;
  std::string ret(s.str());
  return ret;
}

char* strTocharArray(std::string in_string)
{
   char *cstr = new char[in_string.length() + 1];
    strcpy(cstr, in_string.c_str());
    return cstr;

}

std::string eSI(int val)
{
    std::string zero="0";
    std::string retStr;
    if(val<10)
    {
        retStr=zero+" "+intToString(val);
    }else{
        retStr=intToString(val);
    }
    return retStr;
}
std::string eSF(float val)
{
    std::string zero="0";
    std::string retStr;
    if(val<10)
    {
        retStr=zero+" "+floatToString(val);
    }else{
        retStr=floatToString(val);
    }
    return retStr;
}

void saveCurrentModel(std::string fname)
{

  int xa,ya,za, xb,yb,zb, xc,yc,zc, xd,yd,zd;
  float re,ge,be;
  int fstate;
  int ftotal;
  for(int i=0;i<=Q[0].total;i++)
  {
     xa=Q[i].x1;
     ya=Q[i].y1;
     za=Q[i].z1;
     xb=Q[i].x2;
     yb=Q[i].y2;
     zb=Q[i].z2;
     xc=Q[i].x3;
     yc=Q[i].y3;
     zc=Q[i].z3;
     xd=Q[i].x4;
     yd=Q[i].y4;
     zd=Q[i].z4;
     std::string vline= vertex+" "+eSI(xa)+" "+eSI(ya)+" "+eSI(za)+" "+eSI(xb)+" "+eSI(yb)+" "+eSI(zb)+" "+eSI(xc)+" "+eSI(yc)+" "+eSI(zc)+" "+eSI(xd)+" "+eSI(yd)+" "+eSI(zd);
     re=Q[i].r;
     ge=Q[i].g;
     be=Q[i].b;
     std::string rline= cline+" "+floatToString(re)+" "+floatToString(ge)+" "+floatToString(be);
     fstate = Q[i].state;
     std::string sline= stat+" "+intToString(fstate);
     ftotal = Q[i].total;
     std::string tline= tot+" "+intToString(ftotal);

char *v1=strTocharArray(vline);
char *v2=strTocharArray(rline);
char *v3=strTocharArray(sline);
char *v4=strTocharArray(tline);

char *fileName=strTocharArray(fname);

 FILE *fptr;

   fptr = fopen(fileName, "a");
   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }
   fprintf(fptr,"%s\n", v1);
   fprintf(fptr,"%s\n", v2);
   fprintf(fptr,"%s\n", v3);
   fprintf(fptr,"%s\n", v4);
   fclose(fptr);
   printf("Saved to file \n");

  }

}

void LoadModel(std::string fname)
{
    struct Quads F;

   int parseState=0;
   int tempxa,tempya, tempza;
   int tempxb,tempyb, tempzb;
   int tempxc,tempyc, tempzc;
   int tempxd,tempyd, tempzd;


   int vertsArray[24];
   int vac=0;
   float colsArray[10];
   int cac=0;
   int stateArray;
   int totalArray;

   int arraysize = 100000;
   char finalS[arraysize];
   //char current_char;
   int num_characters = 0;
   int i = 0;
  // char finalS[200];
     cin.getline(finalS, sizeof(finalS));
     char *fileName = strTocharArray(curFileName);
     fstream myfile (fileName);

     if (myfile.is_open())
        {
          while ( !myfile.eof())
          {
                myfile >> finalS[i];
                i++;
                num_characters++;
          }

        }else
        {
            cout<<"File doesn't exist"<<endl;
        }


   int se=0; struct Quads retS[100];

   for(int i=0; i<num_characters; i++)
    {

       const char cc=finalS[i];
       if(parseState==0){
           if(finalS[i]=='c')
           {

           parseState=1;
           }
           else if(finalS[i]=='v'){
                parseState=0;

            }
            else if(finalS[i]=='s'){
                parseState=2;
            }
            else if(finalS[i]=='t'){
                parseState=3;
            }

            else{
              int value = cc-'0';
               vertsArray[vac]=value;
               vac++;
           }
       }
       else if(parseState==1){

           if(finalS[i]=='v'){
           parseState=0;
           }
           else if(finalS[i]=='c'){
                parseState=1;
            }
            else if(finalS[i]=='s'){
                parseState=2;
            }
            else if(finalS[i]=='t'){
                parseState=3;
            }
            else{
               float value = (float) cc-'0';
               colsArray[cac]=value;
               cac++;
           }
       }

       else if(parseState==2){

           if(finalS[i]=='v'){
           parseState=0;
           }
           else if(finalS[i]=='c'){
                parseState=1;
            }
            else if(finalS[i]=='s'){
                parseState=2;
            }
            else if(finalS[i]=='t'){
                parseState=3;
            }
            else{
              int value = cc-'0';
               stateArray=value;
           }
       }

       else if(parseState==3){

                   if(finalS[i]=='v'){
           parseState=0;
           }
           else if(finalS[i]=='c'){
                parseState=1;
            }
            else if(finalS[i]=='s'){
                parseState=2;
            }
            else if(finalS[i]=='t'){
                parseState=3;
            }
            else{

              int value = cc-'0';
               totalArray=value;
               vac=0; cac=0;

              tempxa=vertsArray[0]*10+vertsArray[1];
              tempya=vertsArray[2]*10+vertsArray[3];
              tempza=vertsArray[4]*10+vertsArray[5];
              tempxb=vertsArray[6]*10+vertsArray[7];
              tempyb=vertsArray[8]*10+vertsArray[9];
              tempzb=vertsArray[10]*10+vertsArray[11];
              tempxc=vertsArray[12]*10+vertsArray[13];
              tempyc=vertsArray[14]*10+vertsArray[15];
              tempzc=vertsArray[16]*10+vertsArray[17];
              tempxd=vertsArray[18]*10+vertsArray[19];
              tempyd=vertsArray[20]*10+vertsArray[21];
              tempzd=vertsArray[22]*10+vertsArray[23];

              retS[se].x1= tempxa;
              retS[se].y1= tempya;
              retS[se].z1= tempza;
              retS[se].x2= tempxb;
              retS[se].y2= tempyb;
              retS[se].z2= tempzb;
              retS[se].x3= tempxc;
              retS[se].y3= tempyc;
              retS[se].z3= tempzc;
              retS[se].x4= tempxd;
              retS[se].y4= tempyd;
              retS[se].z4= tempzd;

              retS[se].r= F.r=colsArray[0];
              retS[se].g= F.g=colsArray[1];
              retS[se].b= F.b=colsArray[2];

               F.state=stateArray;
               F.total=totalArray;
             se++;
           }
       }
   }
  retS[0].total=Q[0].total=se-1;
for(int j=0; j<se; j++)
{
    Q[j]=retS[j];
    //printf("v %d %d %d %d %d %d %d %d %d %d %d %d c %f %f %f s %d t %d\n", Q[j].x1, Q[j].y1, Q[j].z1, Q[j].x2, Q[j].y2, Q[j].z2, Q[j].x3, Q[j].y3, Q[j].z3, Q[j].x4, Q[j].y4, Q[j].z4, Q[j].r, Q[j].g, Q[j].b, Q[j].state, Q[j].total);
}
glutPostRedisplay();
printf("Successfully Loaded");
}

void rotateGrid(float ra)
{
    gridAngleY += ra;
}

void increaseFOV(){
 FOV_v+=1;
}
void decreaseFOV(){
 FOV_v-=1;
}
void moveToSide(int dx)
{
    vpX+=dx;
}

void keyboard(unsigned char key, int x, int y)
{
    if(key=='w') {cz-=1;} if(key=='s') {cz+=1;} //forward / back
    if(key=='a') {cx-=1;} if(key=='d') {cx+=1;} //left    / right
    if(key=='z') {cy-=1;} if(key=='q') {cy+=1;} //up      / down

    if(key==32) {addQuad();}                    //Spacebar

    if(key=='r') {Q[cn].r=1; Q[cn].g=0; Q[cn].b=0;} //red
    if(key=='g') {Q[cn].r=0; Q[cn].g=1; Q[cn].b=0;} //green
    if(key=='b') {Q[cn].r=0; Q[cn].g=0; Q[cn].b=1;} //blue
    if(key=='y') {Q[cn].r=1; Q[cn].g=1; Q[cn].b=0;} //yellow
    if(key=='B') {Q[cn].r=0; Q[cn].g=1; Q[cn].b=1;} //Cyan
    if(key=='R') {Q[cn].r=1; Q[cn].g=0; Q[cn].b=1;} //Purple

    //rotate Grid
    if(key=='V') {rotateGrid(10);}
    if(key=='v') {rotateGrid(-10);}
    //Save file shortcut
    //if(key=='x') {saveCurrentModel(curFileName);}
    //if(key=='l') {LoadModel(curFileName);}
    if(key=='F') {increaseFOV();}
    if(key=='f') {decreaseFOV();}

    if(key=='p') {moveToSide(5);}
    if(key=='o') {moveToSide(-5);}

    glutPostRedisplay();

}

void menu(int id)
{
    switch(id)
    {
    case 1 :
        saveCurrentModel(curFileName);
        break;
    case 2:
        exit(0);
    }
}


int main(int argc, char**argv)
{
    int choice=1;
    glutInit(&argc, argv);
    printf("*************** WELCOME TO 3D MODELING USING QUADS *********************\n");
    printf("----- Select 1 To Create New Model and Press X key To Save Model -------\n");
    printf("----- Select 2 To Load Previous Model and Press L key To Load Model ----\n");
    printf("************************************************************************\n");
    printf("Enter the Choice:\n");
    printf("1.New\n2.Load\n");

    scanf("%d", &choice);
    printf("************************************************************************\n");
    printf("Enter the size of the grid \n");
    scanf("%d",&gridSize);
    printf("************************************************************************\n");

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    //glutInitWindowPosition(100,100);
    //glutHideWindow();
    glutCreateWindow("3D MODELING USING QUADS");
    //glutIconifyWindow();
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutCreateMenu(menu);
    glutAddMenuEntry("Save      ",1);
    glutAddMenuEntry("Exit      ",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    if(choice==1)
    {
     cout<<"Enter the name of the file "<<endl;
     cin>>curFileName;
     printf("************************************************************************\n");
    }
    if(choice==2)
    {
     cout<<"Enter the name of the file "<<endl;
     cin>>curFileName;
     LoadModel(curFileName);
     printf("\n************************************************************************\n");
    }
    //glutShowWindow();
    glutMainLoop();
    return 0;
}
