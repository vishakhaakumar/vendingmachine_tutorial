#ifndef VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/BeveragePreferenceService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine{

class BeveragePreferenceHandler : public BeveragePreferenceServiceIf {
 public:
  BeveragePreferenceHandler();
  ~BeveragePreferenceHandler() override=default;

  void getBeverage(std::string& _return, const BeverageType::type btype) override;
};

// Constructor
BeveragePreferenceHandler::BeveragePreferenceHandler() {

}

// Remote Procedure "get beverage"

void BeveragePreferenceHandler::getBeverage(std::string& _return, const BeverageType::type btype) {
     // Your implementation goes here
     printf("GetBeverage\n");

    // randomly select a weather
    return "beverage selection here";
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H

