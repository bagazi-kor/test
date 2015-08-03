#include <stdio.h>
#include <errno.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/poll.h>
#include <stdint.h>
#include "HAL_motor_J.h"
#include "pwm_J.h"


int motor_init(){
pwm_open();
pwm_powerOn();
pwm_init();

pwm_SetWidth(0,0);
pwm_SetWidth(1,0);
pwm_SetWidth(2,0);
pwm_SetWidth(3,0);
return 0;
}


int motor_setDuty(unsigned int pwm,unsigned int width ){
	pwm_SetWidth(pwm,width);
return 0;
}


