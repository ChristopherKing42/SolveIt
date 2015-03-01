#include <iostream>
#include <math.h>
#include <vector>
#include <tr1/array>

using namespace std;

typedef vector< tr1::array<float* , 2> > polygon;

void triangle_solver(float*,float*,float*,float*,float*,float*);//Prototype function for solving triangles, 6 floats for 3 sides and 3 angles
void polygon_solver(polygon poly);
void displayPoly(polygon);
int main()
{
    //polygon test(3, {1.0, 60.0});
    //polygon_solver(test);
    return 0;
}

void displayPoly(polygon poly)
{
        for (polygon::iterator it = poly.begin(); it != poly.end(); it++)
        {
            for (int c=0; c<2; c++)
            {
                if ((*it)[c]) cout << *(*it)[c] << endl;
                else cout << '?' << endl;
            }
        }
}

void polygon_solver(polygon poly)
{
    if (poly.size() > 3)
    {

        float *a1 = NULL;
        float *a3 = NULL;
        float *s2 = NULL;
        polygon sub(poly.begin()+2, poly.end()-1);
        float *A1 = NULL;
        float *A3 = NULL;
        float *S2 = NULL;
        sub.push_back({A1,S2});
        float *aA3 = poly[2][1];
        float *aA1 = poly[0][1];
        cout << "Sub Polygon: " << endl;
        displayPoly(sub); cout << endl;
        for (int c=0; c<1; c++)
        {
            triangle_solver(a1, poly[1][1], a3, poly[1][0], s2, poly[0][1]);
            polygon_solver(sub);
        }
        cout << "Polygon: " << endl;
        displayPoly(poly); cout << endl;
    }
}
void triangle_solver(float *a1,float *a2,float *a3,float *s1,float *s2, float *s3)
{

}
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
