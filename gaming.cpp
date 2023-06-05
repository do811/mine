#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
	short vary,t,count=0;
	srand((unsigned int)time(NULL));
	printf("難易度0～10\n");
	scanf("%hd", &t);
	t = 12 - t;
	short num[40][40], already[40][40], x = -1, y = -1;
	x = 0;
	y = 40;
	for (int r = 0; r < 40; r++) {
		for (int e = 0; e < 40; e++) {
			already[r][e] = -1;
			vary = rand()%t;
			num[r][e] =vary;
		}
	}
	int bread = 1, counter = 0;
	int a,breaker=0,on=0;
	short bomcounter = 0;

	for (int q = 0; q < bread; q++) {
		printf("  0");
		for (int u = 0; u < 4; u++) {
			for (int r = 1; r < 10; r++) {
				printf("%d", r);
			}
			printf("0");
		}
		printf("\n");
		for (int i = 0; i < 20; i++) {
			if (i < 10) {
				printf("%d ", i);
			}else{
				printf("%d", i);
			}
			
			for (int j = 0; j < 40; j++) {

				if (on) {
					for (int b = 0; b <= 2; b++) {

						for (int h = 0; h <= 2; h++) {

							if (num[b + i - 1][j + h - 1] == 1 && b + i - 1 >= 0 && j + h - 1 >=
								0) {
								bomcounter++;
							}
						}
					}
					already[i][j] = bomcounter;
				}
				if (a == 0 && j == x && i == y || already[i+20][j] == -2) {
									 printf("C");
								 already[i+20][j] = -2;
				}
				else if (already[y][x] == 0 && x + 1 >= j && j >= x - 1 && y + 1 >= i && i >= y - 1 || (j == x && i == y || already[i + 20][j] == 0)) {
					 if (already[i][j]==0) {
						 printf("□");
						 already[i + 20][j] = 0;
					 }
					 else {
						 printf("%hd", already[i][j]);
						 already[i + 20][j] = 0;
					 }
				 } else if (already[i][j] == 0 && already[i+20][j]==0) {
						printf("□");
				}
				else {
						printf("■");
				}
				bomcounter = 0;
			}				printf("\n");
		}

		on = 1;
		printf("position(x,y)");
			scanf("%hd%hd", &x, &y);
			breaker = 2;
			for (int q = 1; q < breaker; q++) {
				if (x > 40 || y > 20) {
					printf("0<x<40,0<y<20でお願いします");
					scanf("%hd%hd", &x, &y);
					breaker++;
				}
				else {
					breaker = 0;
				}
			}
			if (a != 0) {
				already[y + 20][x] = 0;
			}
			breaker = 0;
		printf("type:");
	    	scanf("%d", &a);



			bread++;
			if (num[y][x] == 1&&!(a==0)) {
				bread = 1;
			}
		}
		printf("over\n");
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 40; j++) {
				if (i == y && j == x) {
					printf("L");
				}
				else if (num[i][j] == 1) {
					printf("■");
				}
				else
				{
					printf("□");
				}
			}
			printf("\n");
		}
		return 0;
	}
