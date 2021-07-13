#include <string>

namespace BinaryHelpers {
std::string uint8_to_hex_string(const uint8_t& value, bool with_prefix = true);
std::string uint32_to_hex_string(const uint32_t& value, bool with_prefix = true);
std::string uint8_to_binary_string(const uint8_t& value);
std::string uint16_to_binary_string(const uint16_t& value);
std::string uint32_to_binary_string(const uint32_t& value);
}  // namespace BinaryHelpers
