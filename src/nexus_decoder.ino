#include "Nexus_Decoder.h"

#define NEXUS_RX_PIN  14    // D5 - GPIO14: pin connected to the 433MHz receiver

NEXUS_DATA nexus_data_prev;

char * message = nullptr; // buffer for printing messages
size_t message_size = 128;



uint8_t print_nexus_data ()
{
  if (!message) {
    message = (char*)calloc(message_size, sizeof(char));
    return -1;
  }

  NEXUS_DATA nexus_data;

  nexus_data = decode_nexus_data();

  if ((nexus_data_prev.ID == nexus_data.ID) && ((nexus_data.Timestamp - nexus_data_prev.Timestamp) < 800) ) {

    return -1;

  } else {

    // Floating point are not formatted in sprintf/arduino
    char str_temp[6];
    /* 3 is mininum width, 1 is precision; float value is copied onto str_temp*/
    dtostrf(nexus_data.Temperature, 3, 1, str_temp);

    snprintf(message, 128, "*** NEXUS  *** House Code:%d  Channel:%d  Battery:%d  Temp:%sC  Hum:%d%%",
             nexus_data.ID,
             nexus_data.Channel,
             nexus_data.Battery,
             str_temp,
             nexus_data.Humidity
      );


  }

  nexus_data_prev = nexus_data;

  return 0;

}




void setup ()
{
	Serial.begin(115200);
	// Configure gpio pin number and mode
	config_receiver(NEXUS_RX_PIN);
}



void loop ()
{

	if (!int_enable) {


		if (print_nexus_data() == 0)
			Serial.printf("%s\n", message);


		int_enable = 1;

	}

}
