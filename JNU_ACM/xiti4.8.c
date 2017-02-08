#include <stdio.h>
int main(int argc, char const *argv[])
{
	float r,h;
	float C1,Sa,Sb,Va,Vb;
	scanf("%f %f",&r,&h);
	C1 = 2*3.14*r;
	Sa = 3.14*r*r;
	Sb = 4*3.14*r*r;
	Va = (4.0/3.0)*3.14*r*r*r;
	Vb = Sa*h;
	printf("C1=%.2f\nSa=%.2f\nSb=%.2f\nVa=%.2f\nVb=%.2f\n",C1,Sa,Sb,Va,Vb);
	return 0;
}