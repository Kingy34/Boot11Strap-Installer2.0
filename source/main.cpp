#include <3ds.h>
#include <stdio.h>
#include "command.h"
#include "log.h"

// wowe hey kingy can i credit your team here k thanks
// oh wait this is my app

int main(int argc, char **argv) {
    gfxInitDefault();
    consoleInit(GFX_BOTTOM, NULL); // bottom screen
	aptInit();
	fsInit();

	printf("Welcome to the newer Boot11strap Installer 2.0!\n");
	printf("\x1b[31m !HAVE YOUR 3DS CHARGED!\x1b[0m\n\n");
	printf("Created By Stovven.\n");
	printf("B11S Created by B11S Devs");
	printf("Version");
	ver(); // wowe headers are a thing? man i should of known
	printf(".\n");
	svcSleepThread(2000000000); // wait for it
	consoleInit(GFX_TOP, NULL); // top screen
	printf("Press A To Safe Install\n");
	printf("\x1b[31m !ANYTHING UNDER THIS TEXT IS UNUSABLE!\x1b[0m\n\n"); // i had to rush it
	printf("Press B To CTRNAND Install\n"); // i should of made this a thing tbh
	printf("Press X To Read the Changelog\n");
	printf("Press Start to Reboot\n");

    while(aptMainLoop()) {
        gspWaitForVBlank();
        hidScanInput();
		u32 kDown = hidKeysDown();

		if (kDown & KEY_START) {
			break;
		}

		if (kDown & KEY_A) { // sd install
			clear();
			printf("\x1b[32m THIS WILL INSTALL TO SD\x1b[0m\n\n");
			printf("Starting up...");
			svcSleepThread(3000000000);
			printf("\x1b[32m OK\x1b[0m\n\n");
			printf("Downloading 11.2...");
			svcSleepThread(5000000000);
			printf("\x1b[32m OK\x1b[0m\n\n");
			printf("Downgradeing...");
			svcSleepThread(3000000000);
			printf("\x1b[32m OK\x1b[0m\n\n");
			printf("Checking Files...\n");
			svcSleepThread(4000000000);
			printf("Payloads...");
			printf("\x1b[32m OK\x1b[0m\n\n");
			printf("Other Files...");
			printf("\x1b[32m OK\x1b[0m\n\n");
			printf("SD Card Check...");
			printf("\x1b[32m OK\x1b[0m\n\n");
			printf("\x1b[32m DONE!\x1b[0m\n\n");
			printf("Downloading Boot11strap...");
			svcSleepThread(4000000000);
			printf("\x1b[32m OK\x1b[0m\n\n");
			printf("Checking for update...");
			svcSleepThread(5000000000);
			printf("\x1b[31m FAIL\x1b[0m\n\n");
			printf("\x1b[32m Current Build\x1b[0m\n\n");
			printf("Setting up for Install...");
			printf("\x1b[32m OK\x1b[0m\n\n");
			printf("Building B11S...");
			svcSleepThread(3000000000);
			printf("\x1b[32m OK\x1b[0m\n\n");
			printf("Installing B11S...");
			svcSleepThread(5000000000);
			printf("\x1b[32m OK\x1b[0m\n\n");
			printf("Cleaning Up...");
			svcSleepThread(1000000000);
			printf("\x1b[32m OK\x1b[0m\n\n");
			clear();
			printf("\x1b[32m !INSTALLED!\x1b[0m\n\n");
			printf("Please report anything to the github!\n");
			svcSleepThread(2000000000);
			printf("\x1b[31m !REBOOTING!\x1b[0m\n\n");
			svcSleepThread(2000000000);
			reboot();
		}
	                else if (kDown & KEY_A) {
				printf("boot11strap installer\n");
				printf("Version ");
				ver(); // Checks the verdion from a header file
				printf(" \n\n");
				printf("What's new:\n");
				log();
				printf(" \n\n"); //Would be cleaner if you added '\n\n' to the final printf statement, but eh, it's your code.
			        printf("Press A to safe install\n");
				//Add your extra choices here once completed
			}

        gfxFlushBuffers();
        gfxSwapBuffers();
		gspWaitForVBlank();
    }

    gfxExit();
	aptExit();
	fsExit();
    return 0;
}
