/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef OrderBeverageService_H
#define OrderBeverageService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "vending_machine_types.h"

namespace vending_machine {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class OrderBeverageServiceIf {
 public:
  virtual ~OrderBeverageServiceIf() {}
  virtual BeverageType::type PlaceOrder(const location& l) = 0;
};

class OrderBeverageServiceIfFactory {
 public:
  typedef OrderBeverageServiceIf Handler;

  virtual ~OrderBeverageServiceIfFactory() {}

  virtual OrderBeverageServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(OrderBeverageServiceIf* /* handler */) = 0;
};

class OrderBeverageServiceIfSingletonFactory : virtual public OrderBeverageServiceIfFactory {
 public:
  OrderBeverageServiceIfSingletonFactory(const ::std::shared_ptr<OrderBeverageServiceIf>& iface) : iface_(iface) {}
  virtual ~OrderBeverageServiceIfSingletonFactory() {}

  virtual OrderBeverageServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(OrderBeverageServiceIf* /* handler */) {}

 protected:
  ::std::shared_ptr<OrderBeverageServiceIf> iface_;
};

class OrderBeverageServiceNull : virtual public OrderBeverageServiceIf {
 public:
  virtual ~OrderBeverageServiceNull() {}
  BeverageType::type PlaceOrder(const location& /* l */) {
    BeverageType::type _return = (BeverageType::type)0;
    return _return;
  }
};

typedef struct _OrderBeverageService_PlaceOrder_args__isset {
  _OrderBeverageService_PlaceOrder_args__isset() : l(false) {}
  bool l :1;
} _OrderBeverageService_PlaceOrder_args__isset;

class OrderBeverageService_PlaceOrder_args {
 public:

  OrderBeverageService_PlaceOrder_args(const OrderBeverageService_PlaceOrder_args&);
  OrderBeverageService_PlaceOrder_args& operator=(const OrderBeverageService_PlaceOrder_args&);
  OrderBeverageService_PlaceOrder_args() {
  }

  virtual ~OrderBeverageService_PlaceOrder_args() noexcept;
  location l;

  _OrderBeverageService_PlaceOrder_args__isset __isset;

  void __set_l(const location& val);

  bool operator == (const OrderBeverageService_PlaceOrder_args & rhs) const
  {
    if (!(l == rhs.l))
      return false;
    return true;
  }
  bool operator != (const OrderBeverageService_PlaceOrder_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const OrderBeverageService_PlaceOrder_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class OrderBeverageService_PlaceOrder_pargs {
 public:


  virtual ~OrderBeverageService_PlaceOrder_pargs() noexcept;
  const location* l;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _OrderBeverageService_PlaceOrder_result__isset {
  _OrderBeverageService_PlaceOrder_result__isset() : success(false), se(false) {}
  bool success :1;
  bool se :1;
} _OrderBeverageService_PlaceOrder_result__isset;

class OrderBeverageService_PlaceOrder_result {
 public:

  OrderBeverageService_PlaceOrder_result(const OrderBeverageService_PlaceOrder_result&);
  OrderBeverageService_PlaceOrder_result& operator=(const OrderBeverageService_PlaceOrder_result&);
  OrderBeverageService_PlaceOrder_result() : success((BeverageType::type)0) {
  }

  virtual ~OrderBeverageService_PlaceOrder_result() noexcept;
  BeverageType::type success;
  ServiceException se;

  _OrderBeverageService_PlaceOrder_result__isset __isset;

  void __set_success(const BeverageType::type val);

  void __set_se(const ServiceException& val);

  bool operator == (const OrderBeverageService_PlaceOrder_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(se == rhs.se))
      return false;
    return true;
  }
  bool operator != (const OrderBeverageService_PlaceOrder_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const OrderBeverageService_PlaceOrder_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _OrderBeverageService_PlaceOrder_presult__isset {
  _OrderBeverageService_PlaceOrder_presult__isset() : success(false), se(false) {}
  bool success :1;
  bool se :1;
} _OrderBeverageService_PlaceOrder_presult__isset;

class OrderBeverageService_PlaceOrder_presult {
 public:


  virtual ~OrderBeverageService_PlaceOrder_presult() noexcept;
  BeverageType::type* success;
  ServiceException se;

  _OrderBeverageService_PlaceOrder_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class OrderBeverageServiceClient : virtual public OrderBeverageServiceIf {
 public:
  OrderBeverageServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  OrderBeverageServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  BeverageType::type PlaceOrder(const location& l);
  void send_PlaceOrder(const location& l);
  BeverageType::type recv_PlaceOrder();
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class OrderBeverageServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<OrderBeverageServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (OrderBeverageServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_PlaceOrder(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  OrderBeverageServiceProcessor(::std::shared_ptr<OrderBeverageServiceIf> iface) :
    iface_(iface) {
    processMap_["PlaceOrder"] = &OrderBeverageServiceProcessor::process_PlaceOrder;
  }

  virtual ~OrderBeverageServiceProcessor() {}
};

class OrderBeverageServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  OrderBeverageServiceProcessorFactory(const ::std::shared_ptr< OrderBeverageServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< OrderBeverageServiceIfFactory > handlerFactory_;
};

class OrderBeverageServiceMultiface : virtual public OrderBeverageServiceIf {
 public:
  OrderBeverageServiceMultiface(std::vector<std::shared_ptr<OrderBeverageServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~OrderBeverageServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<OrderBeverageServiceIf> > ifaces_;
  OrderBeverageServiceMultiface() {}
  void add(::std::shared_ptr<OrderBeverageServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  BeverageType::type PlaceOrder(const location& l) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->PlaceOrder(l);
    }
    return ifaces_[i]->PlaceOrder(l);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class OrderBeverageServiceConcurrentClient : virtual public OrderBeverageServiceIf {
 public:
  OrderBeverageServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  OrderBeverageServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  BeverageType::type PlaceOrder(const location& l);
  int32_t send_PlaceOrder(const location& l);
  BeverageType::type recv_PlaceOrder(const int32_t seqid);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

} // namespace

#endif
