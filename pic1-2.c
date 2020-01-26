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
	/*	���W���̎n�_�C�I�_	*/
	/*----------------------*/
	//static	struct	{
	//	double	x,y,length;
	//}	axis[]	=	{	{-5,0,10},
	//							{0,-4,8},
	//						};

	/*----------------------*/
	/*	���W���̎n�_�C�I�_	*/
	/*----------------------*/
	int	x,y;

	/*--------------------*/
	/*tex�R�}���h���o��	*/
	/*--------------------*/
	printf("\\documentclass{jarticle}\n");
	printf("\\usepackage{epic,eepic} \n");
	printf("\\begin{document}\n");
	printf("\\begin{figure}[htbp]\n");
	printf("\\begin{center}\n");
	printf("\\setlength{\\unitlength}{10mm}\n");
	printf("\\begin{picture}(5,2)\n");

	/*----------------------*/
	/*���W���̏o�͎��s			*/
	/*----------------------*/
	//printf("\t	\\thicklines	\\put(	%4.2f,	%4.2f	)\{\\vector(1,0){	%4.2f	}}\n",axis[0].x,axis[0].y,axis[0].length);
	//printf("\t	\\thicklines	\\put(	%4.2f,	%4.2f	)\{$x$}\n",axis[0].x+axis[0].length+0.1,axis[0].y);
	//printf("\t	\\thicklines	\\put(	%4.2f,	%4.2f	)\{\\vector(0,1){	%4.2f	}}\n",axis[1].x,axis[1].y,axis[1].length);
	//printf("\t	\\thicklines	\\put(	%4.2f,	%4.2f	)\{$y$}\n",axis[1].x,axis[1].y+axis[1].length+0.1);

	//printf("\t	\\thicklines	\\put(	-0.5,	-0.5	)\{$O$}\n");

	/*----------------------*/
	/*�Ȑ��̏o�͎��s				*/
	/*----------------------*/
	printf("\t	\\thicklines\n");
	for(x=-4;x<5;x++){
		for(y=-4;y<5;y++){
			if(	x==0	&&	y==0){}
			else{
				if(	(y!=0	&&	x%y==0	)	||(x!=0	&&	y%x==0)){}
				else{
					printf("\t	\\put(\t	%d,\t%d\t	)\{\\vector(%d,	%d)\{	%f	\}\}\n"	,x
																																						,y
																																						,x
																																						,-y
																																						,sqrt(x*x+y*y));
				}
			}
		}
	}
	printf("\t	\\thinlines\n");

	/*--------------------*/
	/*tex�R�}���h���o��	*/
	/*--------------------*/
	printf("\\end{picture}\n");
	printf("\\end{center}\n");
	printf("\\end{figure}\n");
	printf("\\end{document}\n");
}
