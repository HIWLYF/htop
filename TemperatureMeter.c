/*
htop - TemperaterMeter.c
*/

#include "TemperatureMeter.h"

#include "Temperature.h"
#include "ProcessList.h"
#include "CRT.h"
#include "StringUtils.h"
#include "Platform.h"

#include <string.h>
#include <stdlib.h>

/*{
#include "Meter.h"
}*/

int TemperatureMeter_attributes[] = {
   TEMPERATURE
};

static void Temperature_updateValues(Meter * this, char *buffer, int len) {
    int temperature;

   Temperature_getData(&temperature);

   if (temperature < 0) {
      this->values[0] = 0;
      xSnprintf(buffer, len, "n/a");
      return;
   }

   this->values[0] = temperature;

   const char *temperatureText;

   temperatureText = "%2.2f°C";

   xSnprintf(buffer, len, temperatureText, temperature/1000.00);

   return;
}

MeterClass TemperatureMeter_class = {
   .super = {
      .extends = Class(Meter),
      .delete = Meter_delete
   },
   .updateValues = Temperature_updateValues,
   .defaultMode = TEXT_METERMODE,
   .maxItems = 1,
   .total = 100.0,
   .attributes = TemperatureMeter_attributes,
   .name = "Temperature",
   .uiName = "Temperature",
   .caption = "Temperature: "
};
