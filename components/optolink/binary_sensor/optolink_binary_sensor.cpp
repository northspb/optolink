#ifdef USE_ARDUINO

#include "optolink_binary_sensor.h"
#include "../optolink.h"

namespace esphome
{
  namespace optolink
  {
    static const char *const TAG = "optolink.binary_sensor";

    void OptolinkBinarySensor::datapoint_value_changed(uint8_t value)
    {
      if (value != 5)
      {
        publish_state((int8_t)value);
      }
      else
      {
        ESP_LOGD(TAG, "ignoring value %s for binary sensor",
                 value().c_str());
      }
    };
  } // namespace optolink
} // namespace esphome

#endif
