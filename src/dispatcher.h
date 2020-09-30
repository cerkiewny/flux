#pragma once

#include <thread>

#include <boost/asio.hpp>

#include "messageTypes.h"
#include <type_traits>
#include "handlers.h"


class Dispatcher {
  public:
    Dispatcher();

    template<messageTypes Type, typename ...Args>
    void dispatch(Args&&... args) noexcept {
      io_.post([&args...](){
          handler<Type>(std::forward<Args>(args)...);
      });
    }
    
  private:
    boost::asio::io_context io_;
    boost::asio::io_service::work work_;
    std::thread worker_;
};
