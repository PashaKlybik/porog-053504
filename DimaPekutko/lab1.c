#include <stdio.h> 
#include <time.h>

// variant 23

int algorithm() {
	int i,j,k,l,m,count=0;
	for(i = 1; i <= 10; i++) {
		for(j = 1; j <= i; j++) {
			k = i*i-j*j;
			l = 2*i*j;
			m = i*i+j*j;
			if(k && l && m) {
				printf("%4d %4d %4d\n",k,l,m);
				count++;
				if(count == 10) 
					return 0;	
			}
		}
	}
	return 0; 
}  

int main() {
	//clock need for program time measure
	
	//clock_t begin = clock();
	algorithm();
	//clock_t end = clock();
	//double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	//printf("%f\n", time_spent);
	return 0;
}


