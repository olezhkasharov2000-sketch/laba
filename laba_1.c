#include <stdio.h>
#include <math.h>

int main(){
	float sum_z = 0;
	int cnt_z = 0;

	printf("  z  |  x  |  y  \n");


	for (float x = 0.2; x <= 1; x += 0.5){
		for (float y = 1; y <= 3; y += 1.2){
			float z;
			if (x*x + y*y < 2){
				z = pow(1 - sin(x*x + y*y*y), 2);
			}
			else {
				z = sqrt(x*x*y+8);
			}

			printf("  %f  |  %f  |  %f\n", z, x, y);

			if (z >= 0.5){
				sum_z += z;
				cnt_z ++;
			}
		}
	}

	if (cnt_z > 0) {
	printf("Middle z: %f\n", sum_z / cnt_z);
	}	 
	return 0;
}

