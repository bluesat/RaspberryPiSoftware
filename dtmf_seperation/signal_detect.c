#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main()
{
	char target[]="1111";
	char test = '5';
        int position = 0;

	int running = TRUE;
	int testLEDOn = FALSE;
	while ( running )
	{
		char in = getchar();

		// Validate the input chars -- only process numbers and letters
		int islegal = FALSE;
		if ( in >= 'a' && in <= 'z' ) islegal = TRUE;
		if ( in >= 'A' && in <= 'Z' ) islegal = TRUE;
		if ( in >= '0' && in <= '9' ) islegal = TRUE;
		
		if ( islegal )
		{
			printf("%c", in);
			if ( in == target[position] )
			{
				printf(" ###");
				position++;
				if ( position == strlen(target))
				{
					// We have a match
					position = 0;
					printf("\n\033[32mMATCH MADE\033[0m\n");
					system("./setPin.py 13 0"); // Turn pin 13 to low
				}
			} else {
				position = 0;
			}
			printf("\n");
			if (in == test){
				if (testLEDOn == FALSE){
					system("./setPin.py 26 1");
					printf("testpin ON\n");
					testLEDOn = TRUE;
				} else {
					system("./setPin.py 26 0");
					printf("testpin OFF\n");
					testLEDOn = FALSE;
				}
			}
		}
	}

	return 0;
}

