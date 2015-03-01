#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void triangle_solver(float,float,float,float,float,float);//Prototype function for solving triangles, 6 floats for 3 sides and 3 angles
void polygon_solver(const int length, const float arr[][2]);
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

void polygon_solver(const int length, const float arr[][2]){}

#if 0
void triangle_solver(float *a1,float *a2,float *a3,float *s1,float *s2, float *s3)
{
    //try other cases
    //(a2, a3, a1, s2, s3, s1) = triangle_solver(a2, a3, a1, s2, s3, s1)
    int method = 0;
    /*Method stores what method will be used to solve the triangle
    1 - SSS
    2 - SAS
    3 - sSA/ASs
    4 - SsA/AsS
    5 - AAS/SAA
    6 - ASA
    7 - Impossible*/
    for (int c = 0; c<3; c++)
    {
    //dan types here

    /*olda1=a1;
    a1=a2; a2=a3; a3=olda1;
    olds1=s1;
    s1=s2; s3=s2; s3=olds1;*/

  }
  //BASIC SOLVING METHODS

    if(!a1&&s1&&s2&&s3)//if a1 isnt already found, find it
    {
      a1=acos((pow(s2,2)+pow(s3,2)-pow(s1,2))/(2*s2*s3));
    }
    if(!a2&&s1&&s2&&s3)//if a2 isnt already found, find it
    {
      a2=acos((pow(s1,2)+pow(s3,2)-pow(s2,2))/(2*s1*s3));
    }
    if(!a3&&s1&&s2&&s3)//if a3 isnt found, find
    {
      a3=(180-a1-a2);
    }
    //if((s1&&s2&&a3)||(s2&&s3&&a1)||(s1&&s3&&a2))
    if(s1&&s2&&a3)
    {
      if(!s3)
      {
        s3=(sqrt(pow(s1,2)+pow(s2,2)-2*s1*s2*cos(a3)));
      }
      if(!a1)
      {
        a1=acos((pow(s2,2)+pow(s3,2)-pow(s1,2))/2*s2*s3);
      }
      if(!a2)
      {
        a2=180-a1-a3;
      }
    }



  }

}
#endif
