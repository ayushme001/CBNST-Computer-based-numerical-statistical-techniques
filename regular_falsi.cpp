#include<iostream>
#include<math.h>
#define fcn(x) cos(x)-x // update the function here if not a polynomial
#include<stdlib.h>
int main()
{
	int n,i,itr=0,check=1;
	float *p;

	char pf,df;
	printf("Is function a polynomial function?(y/n):");
	scanf("%c",&pf);
	
	if (pf=='y')
	{
	printf("Enter degree of the polynomial function:");
	scanf("%d",&n);
	p = (float*) calloc(n, sizeof(float));
	
	printf("Enter the %d coefficients of x^0 to x^%d:",n+1,n);
	for (i=0;i<=n;i++)
    scanf("%f",p+i);
	// storing the coefficients such that index-i represesnts the power and data in adress p+i represents coefficients
    }else{	
    printf("Okay,have you defined it in the code?(y/n):");
	scanf(" %c",&df);
    if (df=='n')
    {printf("Pls define the function at line 3 of the code first, then re-run this software");return 0;}
	}
    
    
    
    float f,fp,fn,fm,xp,xn,mid,err,mido;
    
    
    printf("Enter a pair of values (xp and xn)such that f(xp)>0 and f(xn)<0:");
    scanf("%f%f",&xp,&xn);
    
    if (pf=='y')
    {
    f=0;
	for (i=0;i<=n;i++)
	f=f+*(p+i)*pow(xp,i);
    if (f<0)
	check=0;
    f=0;
	for (i=0;i<=n;i++)
	f=f+*(p+i)*pow(xn,i);
	if (f>0)
	check=0;
    }
    else
    {
    	f=fcn(xp);
    	if (f<0)
    	check=0;
    	f=fcn(xn);
    	if (f>0)
    	check=0;
	}
    // checking if inputs are right	
    
    
    
    if (check==1)
    {
    
    mido=(xp+xn)/2;   
    
    do
    {
    itr=itr+1;	
    if (pf=='y')
    {	
	fp=0;
	for (i=0;i<=n;i++)
	fp=fp+*(p+i)*pow(xp,i);
	}else
    {
    fp=fcn(xp);	
	}
	// 'fp' now contains f(xp) value
	if (pf=='y')
    {
	fn=0;
	for (i=0;i<=n;i++)
	fn=fn+*(p+i)*pow(xn,i);
	}else
    {
    fn=fcn(xn);	
	}
	// 'fn' now contains f(xn) value
    

	mid=xp-fp*(xp-xn)/(fp-fn); 
	// mid calculated by equating the slope between (xp,fp) and (mid,0) and (xp,fp) and (xn,fn); regular-falsi method.
	if (pf=='y')
    {
	fm=0;
	for (i=0;i<=n;i++)
	fm=fm+*(p+i)*pow(mid,i);
	}else
    {
    fm=fcn(mid);	
	}
	// 'fm' now contains f(mid) value
	
	if (fm>0)
	xp=mid;
	else if (fm<0)
	xn=mid;
	else
	break;
	// updating the pair or breaking if solution is already reached
	
	
	err=mido-mid;
	if (err<=0)
	err=-err;
	// calculate error between new mid and old mid (mido)
	
	
	mido=mid;
	// updating old mid value for next iteration
	}while(err>0.000001);// checking if tolerance level is reached
	
   printf("The root of this function is %f. It is achieved in %d iterations",mid,itr);
}else
{
	printf("Not possible to get the root with the given set of inputs");
}
    return 0;
}
