#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct.h"


int main(int argc, char *argv[]) 
{
	int i,j,k,l,x=0,count=0;
	float n;
	int fd = atoi(argv[1]);
	float *h = (float *)malloc(sizeof(float)*64);
	PPMImage *image;
	PPMPixel *imageData;

	if(read(fd,&n,sizeof(n))== -1){
		perror("error reading number of pixels\n");
		exit(1);
	}
	
	image = (PPMImage *)malloc(sizeof(PPMImage));
	imageData = (PPMPixel *)malloc(sizeof(PPMPixel)*n);

	if(read(fd,image,sizeof(PPMImage))==-1){
		perror("Error reading image.\n");
		exit(1);
	}

	if(read(fd,imageData,sizeof(PPMPixel)*n)==-1){
		perror("Error reading image pixels\n");
		exit(1);
	}
	
	for(j = 0; j <= 3; j++){
		for(k = 0; k <= 3; k++){
			for(l = 0; l <= 3; l++){
				for(i = 0; i < n; i++){
					if(imageData[i].red == j && imageData[i].green == k && imageData[i].blue == l){
						count++;
					}
				}
				h[x] = count / n;
				count = 0;
				x++;
			}
		}
	}

	for(i = 0; i < 64; i++){
		printf("%d = %0.3f ",i,h[i]);
	}
	printf("\n");
	
	return 0;
	
}
