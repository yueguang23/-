#include<stdio.h> 
void main() {
	long i;
	double t1, t2, t3, t4, t5, t6, t0;
	int t;
	
	t1 = 100000 * 0.1;
	t2 = 100000 * 0.075;
	t3 = 200000 * 0.050;
	t4 = 200000 * 0.030;
	t5 = 400000 * 0.015;
	
	printf("ÇëÊäÈëÀûÈó:\n");
	scanf("%ld",&i);
	
	t = i / 100000;
	if ( t > 10) {
		t = 10;
	}
	
	switch(t) {
		case 0:t0 = i * 0.10;break;
		case 1:t0 = t1 + (i - 100000) * 0.075;break;
		case 2:
		case 3:t0 = t1 + t2 + (i - 200000) * 0.05;break;
		case 4:
		case 5:t0 = t1 + t2 + t3 + (i - 400000) * 0.030;break;
		case 6:
		case 7:
		case 8:
		case 9:t0 = t1 + t2 + t3 + t4 + (i - 600000) * 0.015;break;
		case 10:t0 = t1 + t2 + t3 + t4 + t5 + (i - 1000000) * 0.01;break; 
	}
	printf("%5.3lf", t0);
} 
