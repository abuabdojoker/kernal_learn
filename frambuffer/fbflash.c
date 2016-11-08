#include "frambuffer.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
	unsigned char *fbp = 0;
	int fd;

	char path[][15] = {"1.bmp", "2.bmp", "3.bmp", "4,bmp", "1234.bmp"};

	fd = fb_init(&fbp);
	wipe_screen(fbp);
	draw_BMP(fbp, path[0], 50, 50);
	printf("pic1\n");

	sleep(3);
	switch_vscreen(fd);
	draw_BMP(fbp, path[1], 50, 450);
	sleep(3);
	switch_vscreen(fd);
	sleep(3);
	switch_vscreen(fd);

	release_fb(fbp);

	return 0;
}