/* Do not edit this file. It was automatically generated. */

#ifndef HEADER_Temperature
#define HEADER_Temperature
/*
htop - linux/Temperature.h
*/

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#define SYS_THERMAL_FILE "/sys/class/thermal/thermal_zone0/temp"

int readData();

void Temperature_getData(int* temperature);

#endif
