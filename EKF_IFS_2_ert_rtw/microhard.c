#include <stdlib.h> 
#include <string.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <errno.h>
#include <termios.h>
#include <assert.h>
int tty_fd;

#define BUF_SIZE 80
int g_debug_level = 1;
#define PDEBUG(lvl, fmt, ...)						\
	do { if (g_debug_level > lvl) fprintf(stderr, fmt, __VA_ARGS__); } while (0)

#define ARDUINO_COM "/dev/ttyS0"
#define AR_BAUDRATE B115200  /*rate for usb serial*/
void InitSerial()
{
        int i;
	struct termios tio;

	if((tty_fd = open(ARDUINO_COM , O_RDWR | O_NOCTTY)) < 0 ) { 
		perror("Error while opening serial port\n"); 
		exit(-11);
	}

	memset(&tio, 0, sizeof(tio));

	tio.c_iflag = IGNPAR | ICRNL;
	tio.c_cflag = AR_BAUDRATE | CS8 | CREAD | CLOCAL;
	tio.c_oflag = 0; 
	tio.c_lflag = ICANON; 
	tio.c_cc[VMIN] = 1; 
	tio.c_cc[VTIME] = 0; 

	tcflush(tty_fd, TCIFLUSH);
	tcsetattr(tty_fd, TCSANOW, &tio); 
	tcsetattr(tty_fd,TCSAFLUSH,&tio);  

	/* handshake */

         
}

int WriteLine(int fd, char *buf)
{
	int len  = strlen(buf);
	int tmp;
	tmp = write(tty_fd, buf, len);
	PDEBUG(0, "Send %s", buf);
  	assert(tmp == len);
        return tmp;
}
void CloseSerial()
{
	close(tty_fd); 
}
main()
{
InitSerial();
while(1)
WriteLine(tty_fd, "\r microhard is working\n");
CloseSerial();
}

