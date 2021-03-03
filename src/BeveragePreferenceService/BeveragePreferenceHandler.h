#ifndef VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>
#include <vector>

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
     std::cout << "Get beverage called!..." << std::endl;
     std::vector <std::string> hotlist {"cappuccino","latte","espresso"};
     std::vector <std::string> coldlist {"lemonade","ice tea","soda"};
 
   // randomly select a beverage
  if(btype == BeverageType::type::COLD){
        //int index = random.Next(coldlist.Count);
        // _return = coldlist[index];
   std::cout << "COLDDD" << std::endl
        _return = coldlist[0];

  }else{
        //int index = random.Next(hotlist.Count);
        //_return = hotlist[index];
   std::cout << "HOTTT" << std::endl
        _return = hotlist[1];
}
    _return = "blah";
    // randomly select a weather
    //return "beverage selection here";
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H

