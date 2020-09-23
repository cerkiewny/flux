#pragma once

#include <thread>

#include <boost/asio.hpp>

class Dispatcher {

  public:
    void dispatch(std::string message);
    Dispatcher();
    
  private:
    boost::asio::io_context io_;
    boost::asio::io_service::work work_;
    std::thread worker_;
};
