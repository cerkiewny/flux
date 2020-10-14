#include "handlers.h"

template <>
void handler<messageTypes::TEST_MESSAGE>(std::string message)  noexcept {
  std::cout << "message" << std::endl;
}

template <>
void handler<messageTypes::SILENT_MESSAGE>()  noexcept {

}
