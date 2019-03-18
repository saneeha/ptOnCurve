#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string.h>
static int a =5, b=5;
bool IsPoint( int x, int y)
{
	int left= (y*y)%11 ;
	int right =((x*x*x)%11 +a*x%11 +b)%11;
	if (left==right)
		return true;
	else return false;
}
int slopePt (int x1, int y1, int x2, int y2)
{
	
		int slope=-20000; 
		if (x1==x2 && y1==y2)
	{
			int x=x1; int y=y1;
		if (y!=0)

		if ((3*x*x+ 1)%11 %(2*(y)%11)==0)
			{
				slope=(((3*x*x + a)%11 )/(2*(y)%11))%11;
	         printf("\n Slope was a whole number; Slope is %d",slope);
			}
		else 
		{
			int dev=(2*(y)%11); int i =1; dev<0?dev=dev+11:dev;
			while ((dev*i)%11 !=1)
				i++;
			printf("\n Inverse of %d is %d mod 11", dev,i);
			slope = ((3*x*x+1)*i)%11;
			printf("\n Slope was not a whole number, new slope is %d",slope);
		}
		     
		}

	else 
	{
		if (((y2-y1)%11) %((x2-x1)%11)==0){
		slope=((y2-y1)%11)/((x2-x1)%11)%11;
		printf("\n Slope is %d",slope);}
		else {
			int dev=((x2-x1)%11); int i =1; dev<0?dev=dev+11:dev;
			while ((dev*i)%11 !=1)
				i++;
			printf("\n Inverse of %d is %d mod 11", dev,i);
			slope = ((y2-y1)*i)%11;
			
		}

	}
		slope<0?slope=slope+11:slope;
		printf("\n Slope is %d",slope);
	return slope;	
}
int xDouble (int x, int y, int slope)
{
	
		
	int x2=( (slope*slope) %11 - (2*x)%11)%11; x2<0?x2=(11+x2):x2=x2; printf(" \n Square of slope modulo 11 is %d  - 2*%d mod 11 =%d ", slope*slope %11,x,slope*slope %11 -2*x);
	return x2;
}
int yDouble (int x, int y, int slope)
{
    int x2=( (slope*slope)%11 - (2*x)%11)%11; x2<0?x2=(11+x2):x2=x2; 
	
	printf("\n slope was %d, x=%d, x2=%d",slope,x,x2);
	int y2=(slope*(x- x2)%11 -y%11)%11;
	return y2;
}
int xAdd (int x1, int y1, int x2, int y2, int slope)
{
  
  int x3=(slope*slope - x1-x2)%11;
  return x3;
	
}
int yAdd (int x1, int y1, int x2, int y2, int slope) 
{
	int y3=(slope*(x1-xAdd(x1, y1, x2, y2,slope))-y1)%11;
	return y3;

}
void main()
{
	int x=4; int y=5;int slope; int n=1; int x1 =x; int y1=y; int tempx =-1 ;int tempy =-1;
	for (int i=1;/* i<7*/ tempx!=x && y!=11+(-1*y) ; i++)
	{
		//printf("\n Loop Entered");
		if(y1!=0)
		{
	slope= slopePt(x1,y1,x1,y1); //if (slope<0) slope=slope+11; 
	tempx=x1;
	x1=xDouble(x1,y1,slope);
	
	if (x1<0) x1=x1+11; //printf("\n passed x=%s",x1);
	
	y1=yDouble(tempx,y1,slope); if(y1<0) y1=y1+11;
	tempy=y1;
	printf("\n Point =%d*(%d,%d) = (%d,%d) \n", 2*i,x,y,x1,y1);
		}
		else
	{ n=i*2; 
	  
	printf("\n Order of curve =%d",n);break;
	}
	
		slope =slopePt(x,y,x1,y1); tempx=x1;
	    x1=xAdd(x,y,x1,y1,slope); if (x1<0) x1=x1+11;
		y1=yAdd(x,y,tempx,y1,slope); if(y1<0) y1=y1+11; tempy=y1;
		printf("\n Point =%d*(%d,%d) = (%d,%d) \n", i*2+1,x,y,x1,y1);
		
		if (x ==x1 && y==11-y1)
		{
			n=i*2+1; 
			printf("\n Order of curve =%d",n);
			break;
		}
	}
	
	    
	getch();
	
}
