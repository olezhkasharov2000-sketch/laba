#include <stdio.h>
#include <math.h>

int main(void){

	float x, y, u;
	float min_u = 100000;
	float min_x = 0, min_y = 0;

	printf("X\tY\tU\n");

	for(x = 1; x<=3; x+=1.3){
		for(y = 2; y <= 4; y+=1.5){
			float u1 = (M_E*cos(M_PI*x*x)) - y;
			float u2 = tan(cbrtf(x*y*y) - 1/cbrtf(x));
			if(u1 > u2){
				u = u1;
			} else {
				u = u2;
			}
			
			printf("%f\t%f\t%f\n", x, y, u);
			
			if (u < min_u){
			min_u = u;
			min_x = x;
			min_y = y;
			}

		}
	}
	printf("Min U: %f\n", min_u);
	printf("Sootvetstvushie znacheniya X: %f, Y: %f\n", min_x, min_y);



return 0;
}
