#include "dispatcher.h"

#include <iostream>

Dispatcher::Dispatcher() : work_(io_), worker_{[this](){
      io_.run();
  }} {
}

void Dispatcher::dispatch(std::string message){
  io_.post([message](){
    std::cout << message << std::endl;
  });
}
