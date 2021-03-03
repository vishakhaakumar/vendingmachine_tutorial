#ifndef VENDING_MACHINE_MICROSERVICES_ORDERBEVERAGEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_ORDERBEVERAGEHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/OrderBeverageService.h"
#include "../../gen-cpp/WeatherService.h"
#include "../../gen-cpp/BeveragePreferenceService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine{

class OrderBeverageServiceHandler : public OrderBeverageServiceIf {
 public:
  OrderBeverageServiceHandler(
                  ClientPool<ThriftClient<WeatherServiceClient>> *,ClientPool<ThriftClient<BeveragePreferenceServiceClient>> *) ;
  ~OrderBeverageServiceHandler() override=default;

  void PlaceOrder(std::string& _return, const int64_t city) override;
 private:
  ClientPool<ThriftClient<WeatherServiceClient>> *_weather_client_pool;
  private:
  ClientPool<ThriftClient<BeveragePreferenceServiceClient>> *_beverage_client_pool;
};

// Constructor
OrderBeverageServiceHandler::OrderBeverageServiceHandler(
                ClientPool<ThriftClient<WeatherServiceClient>> *weather_client_pool,ClientPool<ThriftClient<BeveragePreferenceServiceClient>> *beverage_client_pool) {

     // Storing the clientpool
     _weather_client_pool = weather_client_pool;
         _beverage_client_pool = beverage_client_pool;
}

// Remote Procedure "PlaceOrder"
void OrderBeverageServiceHandler::PlaceOrder(std::string& _return, const int64_t city){
     // Your implementation goes here
     printf("PlaceOrder\n");

     //return BeverageType::type::COLD;
#if 1
    // 1. get the weather service client pool
    auto weather_client_wrapper = _weather_client_pool->Pop();
    if (!weather_client_wrapper) {
      ServiceException se;
      se.errorCode = ErrorCode::SE_THRIFT_CONN_ERROR;
      se.message = "Failed to connect to weather-service";
      throw se;
    }
    auto weather_client = weather_client_wrapper->GetClient();

    // by default get cold
    WeatherType::type weatherType = WeatherType::type::COLD;
    BeverageType::type beverageType = BeverageType::type::COLD;

    // 2. call the remote procedure : GetWeather
    try {
      weatherType = weather_client->GetWeather(city);
    } catch (...) {
      _weather_client_pool->Push(weather_client_wrapper);
      LOG(error) << "Failed to send call GetWeather to weather-client";
      throw;
    }
    _weather_client_pool->Push(weather_client_wrapper);

   // 3. business logic
   if(weatherType == WeatherType::type::WARM)
   {   beverageType = BeverageType::type::COLD;
        std::cout << "Weather is WARM" << std::endl;
        std::cout << "Beverage type is COLD" << std::endl;
   }  else{
           beverageType = BeverageType::type::HOT;
           std::cout << "Weather is COLD" << std::endl;
           std::cout << "Beverage type is HOT" << std::endl;
   }

   //// include new client here ////
   std::cout << "new code from heree!..." << std::endl;
        auto beverage_client_wrapper = _beverage_client_pool->Pop();
    if (!beverage_client_wrapper) {
      ServiceException se;
      se.errorCode = ErrorCode::SE_THRIFT_CONN_ERROR;
      se.message = "Failed to connect to beverage-service";
      throw se;
      std::cout << "Failed to connect to beverage-service!..." << std::endl;
    }
    auto beverage_client = beverage_client_wrapper->GetClient();
    std::cout << "before call!..." << std::endl;
        // 2. call the remote procedure : getBeverage

    std::string value = "";
    std::string& val = value;
   // std::string& value = &std::string&("");

     try {
//          
             beverage_client->getBeverage(val,beverageType);
       std::cout << "after call!..." << std::endl;
    } catch (...) {
      _beverage_client_pool->Push(beverage_client_wrapper);
      LOG(error) << "Failed to send call getBeverage to beverage-client";
      throw;
  //    std::cout << "Failed here!..." << std::endl;
    }
   _beverage_client_pool->Push(beverage_client_wrapper);
   _return =val;
#endif
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_ORDERBEVERAGEHANDLER_H

