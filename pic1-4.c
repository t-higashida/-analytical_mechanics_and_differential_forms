#include<stdio.h>
#include<math.h>
//#include<float.h>

#define DELTA_X	0.25
#define DELTA_Y	0.25
double	r_1(double	t){
	//return	1/sqrt(1+exp(-2*t));
	return	1/sqrt(1+exp(-0.4*t));
}
double	r_2(double	t){
	//return	1/sqrt(1-0.00000000206115362243856*exp(-0.5*t));
		return	1/sqrt(1-0.00000614421235332821*exp(-0.4*t));
}
void main(void){

	/*----------------------*/
	/*	座標軸の始点，終点	*/
	/*----------------------*/
	//static	struct	{
	//	double	x,y,length;
	//}	axis[]	=	{	{-5,0,10},
	//							{0,-4,8},
	//						};

	/*----------------------*/
	/*	座標軸の始点，終点	*/
	/*----------------------*/
	double	x,dx,dx_dx,c;

	/*--------------------*/
	/*texコマンド環境出力	*/
	/*--------------------*/
	printf("\\documentclass{jarticle}\n");
	printf("\\usepackage{epic,eepic} \n");
	printf("\\begin{document}\n");
	printf("\\begin{figure}[htbp]\n");
	printf("\\begin{center}\n");
	printf("\\setlength{\\unitlength}{6mm}\n");
	printf("\\begin{picture}(5,2)\n");

	/*----------------------*/
	/*座標軸の出力実行			*/
	/*----------------------*/

	/*----------------------*/
	/*曲線の出力実行				*/
	/*----------------------*/

	/*----------------------*/
	/*	C=1									*/
	/*----------------------*/
	printf("\t	\\thicklines\n");
	printf("%C	\n");
	dx=0.1;	c=1;
	for(x=-12;x<12;x=x+dx){
		printf("\\path(	%lf,%lf)(%lf,%lf)	\n",x,sqrt(2*(c+cos(x))),x+dx,sqrt(2*(c+cos(x+dx))));
		printf("\\path(	%lf,%lf)(%lf,%lf)	\n",x,-sqrt(2*(c+cos(x))),x+dx,-sqrt(2*(c+cos(x+dx))));
	}

	/*----------------------*/
	/*	C=1.5									*/
	/*----------------------*/
	printf("\t	\\thicklines\n");
	printf("%C	\n");
	dx=0.1;	c=1.5;
	for(x=-12;x<12;x=x+dx){
		printf("\\path(	%lf,%lf)(%lf,%lf)	\n",x,sqrt(2*(c+cos(x))),x+dx,sqrt(2*(c+cos(x+dx))));
		printf("\\path(	%lf,%lf)(%lf,%lf)	\n",x,-sqrt(2*(c+cos(x))),x+dx,-sqrt(2*(c+cos(x+dx))));
	}

	/*----------------------*/
	/*	C=1.5									*/
	/*----------------------*/
	printf("\t	\\thicklines\n");
	printf("%C	\n");
	dx=0.1;	c=2;
	for(x=-12;x<12;x=x+dx){
		printf("\\path(	%lf,%lf)(%lf,%lf)	\n",x,sqrt(2*(c+cos(x))),x+dx,sqrt(2*(c+cos(x+dx))));
		printf("\\path(	%lf,%lf)(%lf,%lf)	\n",x,-sqrt(2*(c+cos(x))),x+dx,-sqrt(2*(c+cos(x+dx))));
	}

	/*----------------------*/
	/*	C=0.5								*/
	/*----------------------*/
	printf("\t	\\thicklines\n");
	printf("%C	\n");
	dx=0.1;	c=0.5;
	for(x=-12;x<12;x=x+dx){
		if(	2*(c+cos(x))	>=0	&&	2*(c+cos(x+dx))>=	0){
			printf("\\path(	%lf,%lf)(%lf,%lf)	\n",x,sqrt(2*(c+cos(x))),x+dx,sqrt(2*(c+cos(x+dx))));
			printf("\\path(	%lf,%lf)(%lf,%lf)	\n",x,-sqrt(2*(c+cos(x))),x+dx,-sqrt(2*(c+cos(x+dx))));
		}	else	if(2*(c+cos(x))	>=0	&&	2*(c+cos(x+dx))	<	0){
				dx_dx=dx;
				while	(2*(c+cos(x))	>=0	&&	2*(c+cos(x+dx_dx))	<	0){
					dx_dx=dx_dx*0.999;
				}
				printf("\\path(	%lf,%lf)(%lf,%lf)	\n",x,	sqrt(2*(c+cos(x)))	,x+dx_dx,	sqrt(2*(c+cos(x+dx_dx))));
				printf("\\path(	%lf,%lf)(%lf,%lf)	\n",x,	-sqrt(2*(c+cos(x)))	,x+dx_dx,	-sqrt(2*(c+cos(x+dx_dx))));
		}	else	if(2*(c+cos(x))	<	0	&&	2*(c+cos(x+dx))	>=	0){
				dx_dx=dx;
				while	(2*(c+cos(x-dx_dx+dx))	<	0	&&	2*(c+cos(x+dx))	>=0){
					dx_dx=dx_dx*0.999;
				}
				printf("\\path(	%lf,%lf)(%lf,%lf)	\n",x-dx_dx+dx,	sqrt(2*(c+cos(x-dx_dx+dx)))		,x+dx,	sqrt(2*(c+cos(x+dx))));
				printf("\\path(	%lf,%lf)(%lf,%lf)	\n",x-dx_dx+dx,	-sqrt(2*(c+cos(x-dx_dx+dx)))		,x+dx,	-sqrt(2*(c+cos(x+dx))));
		}
	}

	/*----------------------*/
	/*	C=0.05							*/
	/*----------------------*/
	printf("\t	\\thicklines\n");
	printf("%C	\n");
	dx=0.1;	c=0.05;
	for(x=-12;x<12;x=x+dx){
		if(	2*(c+cos(x))	>=0	&&	2*(c+cos(x+dx))>=	0){
			printf("\\path(	%lf,%lf)(%lf,%lf)	\n",x,sqrt(2*(c+cos(x))),x+dx,sqrt(2*(c+cos(x+dx))));
			printf("\\path(	%lf,%lf)(%lf,%lf)	\n",x,-sqrt(2*(c+cos(x))),x+dx,-sqrt(2*(c+cos(x+dx))));
		}	else	if(2*(c+cos(x))	>=0	&&	2*(c+cos(x+dx))	<	0){
				dx_dx=dx;
				while	(2*(c+cos(x))	>=0	&&	2*(c+cos(x+dx_dx))	<	0){
					dx_dx=dx_dx*0.999;
				}
				printf("\\path(	%lf,%lf)(%lf,%lf)	\n",x,	sqrt(2*(c+cos(x)))	,x+dx_dx,	sqrt(2*(c+cos(x+dx_dx))));
				printf("\\path(	%lf,%lf)(%lf,%lf)	\n",x,	-sqrt(2*(c+cos(x)))	,x+dx_dx,	-sqrt(2*(c+cos(x+dx_dx))));
		}	else	if(2*(c+cos(x))	<	0	&&	2*(c+cos(x+dx))	>=	0){
				dx_dx=dx;
				while	(2*(c+cos(x-dx_dx+dx))	<	0	&&	2*(c+cos(x+dx))	>=0){
					dx_dx=dx_dx*0.999;
				}
				printf("\\path(	%lf,%lf)(%lf,%lf)	\n",x-dx_dx+dx,	sqrt(2*(c+cos(x-dx_dx+dx)))		,x+dx,	sqrt(2*(c+cos(x+dx))));
				printf("\\path(	%lf,%lf)(%lf,%lf)	\n",x-dx_dx+dx,	-sqrt(2*(c+cos(x-dx_dx+dx)))		,x+dx,	-sqrt(2*(c+cos(x+dx))));
		}
	}

	printf("\t	\\thinlines\n");

	/*--------------------*/
	/*texコマンド環境出力	*/
	/*--------------------*/
	printf("\\end{picture}\n");
	printf("\\end{center}\n");
	printf("\\end{figure}\n");
	printf("\\end{document}\n");
}
