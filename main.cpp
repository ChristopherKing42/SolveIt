#include <iostream>
#include <math.h>

using namespace std;

void triangle_solver(float*,float*,float*,float*,float*,float*);//Prototype function for solving triangles, 6 floats for 3 sides and 3 angles

int main()
{
    float a1 = 0;
    float a2 = 0;
    float a3 = 0;
    float s1 = 2080.26370467;
    float s2 = 885.569781141;
    float s3 = 1327.17001098;
    triangle_solver(&a1,&a2,&a3,&s1,&s2,&s3);
    cout << "Done" << endl;
    return 0;
}

void triangle_solver(float *a1,float *a2,float *a3,float *s1,float *s2, float *s3)
{
  //BASIC SOLVING METHODS

  //SSS - 3 sides and no angles
  if(!*a1&&!*a2&&!*a3&&*s1&&*s2&&*s3)
  {
    cout << s2 << endl;
    *a1=acos((pow(*s2,2)+pow(*s3,2)-pow(*s1,2))/(2*(*s2)*(*s3)));
    *a2=acos((pow(*s1,2)+pow(*s3,2)-pow(*s2,2))/(2*(*s1)*(*s3)));
    *a3=180-*a1-*a2;
    //output results for debug porpoises:
    cout << "a1: " << *a1 << endl;
    cout << "a2: " << *a2 << endl;
    cout << "a3: " << *a3 << endl;
    cout << "s1: " << *s1 << endl;
    cout << "s2: " << *s2 << endl;
    cout << "s3: " << *s3 << endl;
    cout << "Done." << endl;
    return;
  }

    if((s1&&s2&&a3)||(s2&&s3&&a1)||(s1&&s3&&a2))
    {
      //SAS - 2 sides and an included angle
      float *a,*b,*c,*alpha,*beta,*gamma;
      if(s1&&s2&&a3)
      {
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
      //output results for debug porpoises:
      cout << "a1: " << *a1 << endl;
      cout << "a2: " << *a2 << endl;
      cout << "a3: " << *a3 << endl;
      cout << "s1: " << *s1 << endl;
      cout << "s2: " << *s2 << endl;
      cout << "s3: " << *s3 << endl;
      cout << "Done." << endl;
      return;
    }


    if((s1&&s2&&a1)||(s2&&s3&&a2)||(s3&&s1&&a3))
    {
      //SSA - 2 sides and a non-included angle
      float *a,*b,*c,*alpha,*beta,*gamma;
      if(s1&&s2&&a1)
      {
        if(s3)
        {
          a=s3;
        }
        b=s1;
        c=s2;
        if(a3)
        {
          alpha=a3;
        }
        beta=a1;
        if(a2)
        {
          gamma=a2;
        }
      }
      if(s2&&s3&&a2)
      {
        if(s1)
        {
          a=s1;
        }
        b=s2;
        c=s3;
        if(a1)
        {
          alpha=a1;
        }
        beta=a2;
        if(a3)
        {
          gamma=a3;
        }
      }
      if(s3&&s1&&a3)
      {
        if(s2)
        {
          a=s2;
        }
        b=s3;
        c=s1;
        if(a2)
        {
          alpha=a2;
        }
        beta=a3;
        if(a1)
        {
          gamma=a1;
        }
      }
      //Now solve
      float D;
      D=((*c)/(*b))*sin(*beta);
      if(D>1)
      {
        cout << "No triangle exists." << endl;
      }
      if(D==1)
      {
        *gamma=90;
      }
      if(D<1)
      {
        *gamma=asin(D);
        //we specifically chose gamma to be acute
      }
      *alpha=180-*beta-*gamma;
      *a = ((*b)*(sin(*alpha)/sin(*beta)));
      //output results for debug porpoises:
      cout << "a1: " << *a1 << endl;
      cout << "a2: " << *a2 << endl;
      cout << "a3: " << *a3 << endl;
      cout << "s1: " << *s1 << endl;
      cout << "s2: " << *s2 << endl;
      cout << "s3: " << *s3 << endl;
      cout << "Done." << endl;
      return;
    }


    if((a1&&s3&&a2)||(a2&&s1&&a3)||(a1&&s2&&a3))
    {
      //ASA - a side and 2 adjacent angles given
      float *a,*b,*c,*alpha,*beta,*gamma;
      if(a1&&s3&&a2)
      {
        if(s1)
        {
          a=s1;
        }
        if(s2)
        {
          b=s2;
        }
        c=s3;
        alpha=a1;
        beta=a2;
        if(a3)
        {
          gamma=a3;
        }
      }
      if(a2&&s1&&a3)
      {
        if(s2)
        {
          a=s2;
        }
        if(s3)
        {
          b=s3;
        }
        c=s1;
        alpha=a2;
        beta=a3;
        if(a1)
        {
          gamma=a1;
        }
      }
      if(a1&&s2&&a3)
      {
        if(s3)
        {
          a=s3;
        }
        if(s1)
        {
          b=s1;
        }
        c=s2;
        alpha=a3;
        beta=a1;
        if(a2)
        {
          gamma=a2;
        }
      }
    //Now solve:
    *gamma=180-*alpha-*beta;
    *a=(*c)*(sin(*alpha)/sin(*gamma));
    *b=(*c)*(sin(*beta)/sin(*gamma));
    //output results for debug porpoises:
    cout << "a1: " << *a1 << endl;
    cout << "a2: " << *a2 << endl;
    cout << "a3: " << *a3 << endl;
    cout << "s1: " << *s1 << endl;
    cout << "s2: " << *s2 << endl;
    cout << "s3: " << *s3 << endl;
    cout << "Done." << endl;
    return;
    }


    if((a1&&a2&&s1)||(a2&&a3&&s2)||(a3&&a1&&s3))
    {
      //AAS - 1 side, 1 adjacent angle and the opposite angle given
      float *a,*b,*c,*alpha,*beta,*gamma;
      if(a1&&a2&&s1)
      {
        alpha=a1;
        beta=a2;
        if(a3)
        {
          gamma=a3;
        }
        if(s2)
        {
          a=s2;
        }
        if(s3)
        {
          b=s3;
        }
        c=s1;
      }
      if(a2&&a3&&s2)
      {
        alpha=a2;
        beta=a3;
        if(a1)
        {
          gamma=a1;
        }
        if(s1)
        {
          a=s1;
        }
        if(s3)
        {
          b=s3;
        }
        c=s2;
      }
      if(a3&&a1&&s3)
      {
        alpha=a1;
        beta=a3;
        if(a2)
        {
          gamma=a2;
        }
        if(s1)
        {
          a=s1;
        }
        if(s2)
        {
          b=s2;
        }
        c=s3;
      }
      *gamma=180-(*alpha)-(*beta);
      *a=(*c)*(sin(*alpha)/sin(*gamma));
      *b=(*c)*(sin(*beta)/sin(*gamma));
      //output results for debug porpoises:
      cout << "a1: " << *a1 << endl;
      cout << "a2: " << *a2 << endl;
      cout << "a3: " << *a3 << endl;
      cout << "s1: " << *s1 << endl;
      cout << "s2: " << *s2 << endl;
      cout << "s3: " << *s3 << endl;
      cout << "Done." << endl;
      return;
    }


    if(a1&&a2&&a3&&!s1&&!s2&&!s3)
    {
      //AAA - impossible
      cout << "Not possible." << endl;
      //output results for debug porpoises:
      cout << "a1: " << *a1 << endl;
      cout << "a2: " << *a2 << endl;
      cout << "a3: " << *a3 << endl;
      cout << "s1: " << *s1 << endl;
      cout << "s2: " << *s2 << endl;
      cout << "s3: " << *s3 << endl;
      cout << "Done." << endl;
      return;
    }
    if(a1&&a2&&a3)
    {
      float atotal;
      atotal = (*a1)+(*a2)+(*a3);
      if(atotal!=180)
      {
        cout << "Error: Angles do not add up to 180 degrees!" << endl;
      }
    }

    //output results for debug porpoises:
    cout << "a1: " << *a1 << endl;
    cout << "a2: " << *a2 << endl;
    cout << "a3: " << *a3 << endl;
    cout << "s1: " << *s1 << endl;
    cout << "s2: " << *s2 << endl;
    cout << "s3: " << *s3 << endl;
    cout << "Done." << endl;
  }
