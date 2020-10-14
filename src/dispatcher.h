#pragma once

#include <thread>

#include <boost/asio.hpp>

#include "messageTypes.h"
#include <type_traits>
#include "handlers.h"

#include <iostream>

template <typename Arg, typename... Args>
void print_args(Arg arg, Args... args) {
  std::cout << arg;
  ((std::cout << ", " << args), ..., (std::cout << std::endl));
}

class Dispatcher {
  public:
    Dispatcher();

    template<messageTypes Type, typename ...Args>
    void dispatch(Args&&... args) noexcept {
      io_.post([&args...](){
          print_args("Message received: ", args...);
          handler<Type>(args...);
      });
    }
    
  private:
    boost::asio::io_context io_;
    boost::asio::io_service::work work_;
    std::thread worker_;
};
