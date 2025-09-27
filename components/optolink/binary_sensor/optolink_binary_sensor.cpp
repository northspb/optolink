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
        lastvalue_ = (int8_t)value;
        publish_state((int8_t)value);
      }
      else
      {
        ESP_LOGI(TAG, "ignoring value %u (0x%02X) for binary sensor", value, value);
        publish_state(lastvalue_);
      }
    };
  } // namespace optolink
} // namespace esphome

#endif
