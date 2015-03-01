#include <iostream>
#include <math.h>

using namespace std;

void triangle_solver(float*,float*,float*,float*,float*,float*);//Prototype function for solving triangles, 6 floats for 3 sides and 3 angles

int main()
{
    float a1,a2,a3,s1,s2,s3;
    int yn;//i dont care enough to test for valid inputs because this is just for debug purposes, so please don't crash this...
    cout << "Use 0 for no, 1 for yes for the following questions." << endl;
    cout << "Do you want to input a1?" << endl;
    cin>>yn;
    if(yn==1)
    {
      cin>>a1;
    }
    cout << "Do you want to input a2?" << endl;
    cin>>yn;
    if(yn==1)
    {
      cin>>a2;
    }
    cout << "Do you want to input a3?" << endl;
    cin>>yn;
    if(yn==1)
    {
      cin>>a3;
    }
    cout << "Do you want to input s1?" << endl;
    cin>>yn;
    if(yn==1)
    {
      cin>>s1;
    }
    cout << "Do you want to input s2?" << endl;
    cin>>yn;
    if(yn==1)
    {
      cin>>s2;
    }
    cout << "Do you want to input s3?" << endl;
    cin>>yn;
    if(yn==1)
    {
      cin>>s3;
    }
    cout << "Done! Now on to the solver." << endl;
    triangle_solver(&a1,&a2,&a3,&s1,&s2,&s3);
    cout << "End of program" << endl;
    return 0;
}

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
      *a1=acos((pow(*s2,2)+pow(*s3,2)-pow(*s1,2))/(2*(*s2)*(*s3)));
    }
    if(!a2&&s1&&s2&&s3)//if a2 isnt already found, find it
    {
      *a2=acos((pow(*s1,2)+pow(*s3,2)-pow(*s2,2))/(2*(*s1)*(*s3)));
    }
    if(!a3&&s1&&s2&&s3)//if a3 isnt found, find
    {
      *a3=180-*a1-*a2;
    }

    //SAS
    //if((s1&&s2&&a3)||(s2&&s3&&a1)||(s1&&s3&&a2))
    if(s1&&s2&&a3)
    {
      if(!s3)
      {
        *s3=(sqrt(pow(*s1,2)+pow(*s2,2)-2*(*s1)*(*s2)*cos(*a3)));
      }
      if(!a1)
      {
        *a1=acos((pow(*s2,2)+pow(*s3,2)-pow(*s1,2))/2*(*s2)*(*s3));
      }
      if(!a2)
      {
        *a2=180-*a1-*a3;
      }
    }
    if(s2&&s3&&a1)
    {
      //c is s1,a is s2,b is s3,alpha is a2,beta is a3,gamma is a1
      if(!s1)
      {
        *s1=(sqrt(pow(*s2,2)+pow(*s3,2)-2*(*s2)*(*s3)*cos(*a1)));
      }
      if(!a2)
      {
        *a2=acos((pow(*s3,2)+pow(*s1,2)-pow(*s2,2))/2*(*s3)*(*s1));
      }
      if(!a3)
      {
        *a3=180-*a1-*a2;
      }
    }
    if(s1&&s3&&a2)
    {
      //a is s3, b is s1,c is s2,alpha is a3,beta is a1, gamma is a2
      if(!s2)
      {
        *s2=(sqrt(pow(*s3,2)+pow(*s1,2)-2*(*s3)*(*s1)*cos(*a2)));
      }
      if(!a3)
      {
      *a3=acos((pow(*s1,2)+pow(*s2,2)-pow(*s3,2))/2*(*s1)*(*s2));
      }
      if(!a1)
      {
        *a1=180-*a2-*a3;
      }
    }

    //ALT METHOD:
    if((s1&&s2&&a3)||(s2&&s3&&a1)||(s1&&s3&&a2))
    {
      int returnmode;//keeps track of where to return values to
      //if we have SAS, assign general equation variables (a,b,c,alpha,beta,gamma) to the data, solve using general equations, then return values solved for.
      float *a,*b,*c,*alpha,*beta,*gamma;
      if(s1&&s2&&a3)
      {
        returnmode=1;
        a=s1;
        b=s2;
        if(s3)
        {
          c=s3;
        }
        if(a1)
        {
          alpha=a1;
        }
        if(a2)
        {
          beta=a2;
        }
        gamma=a3;
      }
      if(s2&&s3&&a1)
      {
        returnmode=2;
        a=s2;
        b=s3;
        if(s1)
        {
          c=s1;
        }
        if(a2)
        {
          alpha=a2;
        }
        if(a3)
        {
          beta=a3;
        }
        gamma=a1;
      }
      if(s1&&s3&&a2)
      {
        returnmode=3;
      a=s3;
      b=s1;
      if(s2)
      {
        c=s2;
      }
      if(a3)
      {
        alpha=a3;
      }
      if(a1)
      {
        beta=a1;
      }
      gamma=a2;
      }
      //Now that a,b,c,alpha,beta,gamma have been declared, we write general equations for those
      *c=sqrt(pow(*a,2)+pow(*b,2)-2*(*a)*(*b)*cos(*gamma));
      *alpha=acos((pow(*b,2)+pow(*c,2)-pow(*a,2))/2*(*b)*(*c));
      *beta=180-*alpha-*gamma;
      //Now we have solved generally, so we return c,alpha,and beta to their specific cases
      /*switch(returnmode)
      {
        case 1:
        s3=c;
        a1=alpha;
        a2=beta;
        break;
        case 2:
        s1=c;
        a2=alpha;
        a3=beta;
        break;
        case 3:
        s2=c;
        a3=alpha;
        a1=beta;
      }*/
    }//end of ALT METHOD


  }
