// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "ThriftServiceBenchmark.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::thrift_code;

class ThriftServiceBenchmarkHandler : virtual public ThriftServiceBenchmarkIf {
 public:
  ThriftServiceBenchmarkHandler() {
    // Your initialization goes here
  }

  int32_t get_answer(const int32_t number) {
    // Your implementation goes here
    printf("get_answer\n");
  }

  void get_blob(std::string& _return) {
    // Your implementation goes here
    printf("get_blob\n");
  }

  void get_structs(std::vector<Student> & _return) {
    // Your implementation goes here
    printf("get_structs\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<ThriftServiceBenchmarkHandler> handler(new ThriftServiceBenchmarkHandler());
  shared_ptr<TProcessor> processor(new ThriftServiceBenchmarkProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

