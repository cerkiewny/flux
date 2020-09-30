#pragma once

#include "messageTypes.h"
#include <iostream>
      
template<messageTypes Type, class ...Args>
void handler(Args... args) noexcept;
