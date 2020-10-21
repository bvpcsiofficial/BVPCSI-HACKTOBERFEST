#include<stdio.h>

#include<math.h>
float f(float x,float y);
int main()
{
    float x,y,m1,m2,m3,m4,h,xn,m;

    printf("Program for Solution of Ordinary Differential Equation\nRunge Kutta Method\n");
    printf("Enter value for x0,y0\n");
    scanf("%f%f",&x,&y);
    printf("Enter value for h and last of x\n");
    scanf("%f%f",&h,&xn);
    printf("\nm1\tm2\tm3\tm4\t\tX\t\tY\n");
    while(x<xn)
    {
 m1=f(x,y);
 m2=f((x+h/2.0),(y+m1*h/2.0));
 m3=f((x+h/2.0),(y+m2*h/2.0));
 m4=f((x+h),(y+m3*h));
 m=((m1+2*m2+2*m3+m4)/6);
 y=y+m*h;
 x=x+h;
 printf("%.4f\t%.4f\t%.4f\t%.4f\t\t%.4f\t\t%.4f\n",m1,m2,m3,m4,x,y);
    }
    return 0;
}
float f(float x,float y)
{
    float m;
    m=-(2*x*y*y);
    return m;
}
