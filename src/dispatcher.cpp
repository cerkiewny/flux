#include "dispatcher.h"

#include <iostream>

Dispatcher::Dispatcher() : work_(io_), worker_{[this](){
      io_.run();
  }} {
}
