/*
htop - linux/Temperature.c
*/

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include "TemperatureMeter.h"
#include "StringUtils.h"

#define SYS_THERMAL_FILE "/sys/class/thermal/thermal_zone0/temp"

int readData() {
    FILE* file = fopen(SYS_THERMAL_FILE, "r");
    if (!file) {
        return -1;
    }
    char *line = String_readLine(file);
    if (!line) {
        return -2;
    }
    int temp = atoi(line);
    free(line);
    fclose(file);
    return temp;
}

void Temperature_getData(int* temperature) {
   *temperature = readData();
}
