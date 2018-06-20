#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct.h"


int main(int argc, char *argv[]) 
{
	int arrLoopVar[5];
	int i,j,k,l,x=0,count=0;
	int iStart, jStart, kStart, lStart;
	int start = 1; //if this is the start of loop after parent process
	float n;
	int fd = atoi(argv[1]);
	float *h = (float *)malloc(sizeof(float)*64);
	PPMImage *image;
	PPMPixel *imageData;

	if(read(fd,&n,sizeof(n))== -1){
		perror("error reading number of pixels\n");
		exit(1);
	}
	
	if(read(fd,arrLoopVar,sizeof(arrLoopVar))== -1){
		perror("error reading x\n");
		exit(1);
	}
	
	image = (PPMImage *)malloc(sizeof(PPMImage));
	imageData = (PPMPixel *)malloc(sizeof(PPMPixel)*n);

	if(read(fd,h,(sizeof(float)*64))== -1){
		perror("error reading number of pixels\n");
		exit(1);
	}
	
	if(read(fd,image,sizeof(PPMImage))==-1){
		perror("Error reading image.\n");
		exit(1);
	}

	if(read(fd,imageData,sizeof(PPMPixel)*n)==-1){
		perror("Error reading image pixels\n");
		exit(1);
	}

	//printf("Hello Child\n");	

	x = arrLoopVar[0];
	jStart = arrLoopVar[1];
	kStart = arrLoopVar[2];
	lStart = arrLoopVar[3];
	iStart = arrLoopVar[4];

	for(j = jStart; j <= 3; j++){
		if(start != 1){kStart = 0; lStart = 0; iStart = 0;}
		for(k = kStart; k <= 3; k++){
			for(l = lStart; l <= 3; l++){
				for(i = iStart; i < n; i++){
					if(imageData[i].red == j && imageData[i].green == k && imageData[i].blue == l){
						count++;
					}
				}
				h[x] = count / n;
				count = 0;
				x++;
			}
		}
		start = 0;
	}

	for(i = 0; i < 64; i++){
		printf("%d = %0.3f ",i,h[i]);
	}
	printf("\n");
	
	return 0;
	
}
