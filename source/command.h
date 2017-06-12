#include <3ds.h>
#include <stdio.h>

void clear() {
	printf("\e[1;1H\e[2J");
}


void ver() {
	printf("0.0.1");
}

void reboot() { //i had to google all of this btw 
	APT_HardwareResetAsync();
}
