#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <math.h>

double getDelta(double a, double b, double c){
	return b * b - 4 * a * c;
}

double* getXs(double a, double b, double c){
	double delta = getDelta(a,b,c);
	double xS[] = {0,0,0};
	xS[0] = delta;
	if(delta < 0){
		return xS;
	}else if(delta == 0){
		xS[1] = -b/(2*a);
		xS[2] = -b/(2*a);
		return xS;
	}else {
		xS[1] = (-b+sqrt(delta))/(2*a);
		xS[2] = (-b-sqrt(delta))/(2*a);
		return xS;
	}	
}


int main(int argc, char** argv) {
	
	printf("\n");
	
	if(argc < 4){
		printf("Sem argumentos");
	}else if(atoi(argv[1]) == 0){
		printf("O valor de A e 0");
	}else{
		double* xS = getXs(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
		
		if(xS[0] < 0){
			printf("delta negativo: %f", xS[0]);
		}else{
			printf("delta: %f", xS[0]);
			printf("\nx1: %f", xS[1]);
			printf("\nx2: %f", xS[2]);
		}
		
	}
	
	printf("\n");
	
	system("EXIT");
}
