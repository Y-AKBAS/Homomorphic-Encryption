#pragma comment(lib, "Ws2_32.lib")

#include <grpcpp/grpcpp.h>
#include <communication.grpc.pb.h>


class RpcServiceImpl final : public Thesis::CommunicationService::Service{
public:

    ~RpcServiceImpl();
    RpcServiceImpl();

    grpc::Status getMessage(
        grpc::ServerContext* context, 
        const Thesis::MessageReq* request,
        Thesis::MessageResp* response) override;


private:

};