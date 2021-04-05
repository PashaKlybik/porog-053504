#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h> 
#include <sys/ioctl.h>
#include <unistd.h>

#define MAX_TEXT_SIZE 512

// char 

void alignToWidth(char text[MAX_TEXT_SIZE]) {
	// get terimal length
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	int windowLength = w.ws_col;

	char tempText[MAX_TEXT_SIZE] = "\0";

	int lastSpaceIndex;

	for(int i = 0; i < MAX_TEXT_SIZE; i++) {
		if(text[i] == '\0') {
			if(i < windowLength) {
				printf("%s\n", text);
				return;
			}
		}
	}

	for(int i = 0; i < MAX_TEXT_SIZE; i++) {
		if(text[i] == ' ') {
			lastSpaceIndex = i;
		}
		// if(text[i] == '\0') {
		if(i >= windowLength) {
			// printf("!!!!\n");
			i = lastSpaceIndex;

			int textLength = i;
			int spaceCount = 0;
			int spacesToAdd = windowLength-i;
			int spacesBetweenChars;
			int spaceRemainder;

			for(int j = 0; j < i; j++) {
				if(text[j] == ' ') {
					spaceCount++;
				} 
			}

			if(!spaceCount)
				break;

			spacesToAdd += spaceCount;
			spacesBetweenChars = (spacesToAdd/spaceCount);
			spaceRemainder = spacesToAdd%spaceCount;

			for(int j = 0; j < i; j++) {
				if(text[j] == ' ') {
						// printf("space\n");
					for(int k = 0; k < MAX_TEXT_SIZE; k++) {
						if(tempText[k] == '\0') {
							// printf("%d\n", k);
							for(int l = 0; l < spacesBetweenChars; l++) {
								tempText[l+k] = ' ';
								if(spaceRemainder && l+1 == spacesBetweenChars) {
									tempText[l+k+1] = ' ';
									spaceRemainder--;
								}
							}	
							break;
						}
					}
				}
				else {
						// printf("letter\n");
					for(int k = 0; k < MAX_TEXT_SIZE; k++) {
						if(tempText[k] == '\0') {
							tempText[k] = text[j];
							break;
						} 
					}
				}
			}

			char newText[MAX_TEXT_SIZE];

			for(int j = 0; j < MAX_TEXT_SIZE; j++) {
				if(text[j] == '\0') {
					break;
				}
				newText[j] = text[j+lastSpaceIndex+1];
			}


			printf("%s\n", tempText);
			alignToWidth(newText);
			break;
		}
	}

}

int main() {

	char text[MAX_TEXT_SIZE];

	printf("Type your 6 strings:\n");
	fgets(text, MAX_TEXT_SIZE, stdin);
	for(int i = 0; i < 5; i++) {
		char string[MAX_TEXT_SIZE];
		fgets(string, MAX_TEXT_SIZE, stdin);
		for(int j = 0; j < MAX_TEXT_SIZE; j++) {
			if(text[j] == '\0') {
				for(int k = 0; k < MAX_TEXT_SIZE; k++) {
					text[j+k] = string[k];
					if(string[k] == '\0')
						break;
				}
				break;
			}
		}
	}

    //delete all \n
	for(int i = 0; i < MAX_TEXT_SIZE; i++) {
		if(text[i] == '\n') {
			text[i] = ' ';
		}
		if(text[i] == '\0') {
    		// delete space at the end of the text
			text[i-1] = '\0';
		}
	}

	printf("Result text:\n");
	alignToWidth(text);

	return 0;
}
