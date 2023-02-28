#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

float zBuffer[160 * 44];
char buffer[160 * 44];
int backgroundASCIICode = ' ';
int width = 160, height = 44;

int main(){
	printf("\x1b[2j");
	while(1){
		memset(buffer, backgroundASCIICode, width * height);
		memset(zBuffer, 0, width * height * 4);
		printf("\x1b[H");
		for(int k = 0; k < width * height; k++){
		      putchar( k % width ? buffer[k] : 10);
		}
	}
	return 0;
}
