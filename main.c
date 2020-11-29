
#import <stdio.h>
#import <stdlib.h>
#import <time.h>
#import <string.h>
#import "main.h"

// Declarations
char randomLetter();


// Main
int main(int argc, char *argv[]) {
	// Default password length
	long plen = 15;
	char* charset = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	// Get arguments
	for(int i = 0; i < argc; i++) {
		// T: Strings are char* pointers
		char* arg = argv[i];

		// T: String comparison. U: evaluates to true if NOT equal
		if (!strncmp(arg, "-c", 2)) {
			if (argc <= i+1) {
				printf("Error: Missing value for -c flag\n");
				return 1;
			} 
			char* cntstr = argv[i+1];
			int cntval = strtol(cntstr, NULL, 0);
			if (cntval <= 0) {
				printf("Error: -c argument demands a number higher than 0.\n");
				return 1;
			}
			plen = cntval;
		}
	}

	// Generate the password
	char* pass = generatePassword(plen, charset);

	// Print it
	printf("%s\n", pass);	

	return 0;
}

char * generatePassword(int len, char* charset) {
	char str[len + 1];

	// Seed the generator
	// T: NULL, random seeding and time()
	srandom(time(NULL));

	for (int i = 0; i < len; i++) {
		str[i] = randomLetter(charset);
	}
	str[len] = '\0';
	
	static char pass[100];
	memcpy(pass, str, len + 1);
	return pass;
}

char randomLetter(char* charset) {
	return charset[random() % strlen(charset)];
}

