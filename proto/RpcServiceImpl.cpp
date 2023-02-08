#include "RpcServiceImpl.h"

RpcServiceImpl::~RpcServiceImpl() = default;
RpcServiceImpl::RpcServiceImpl() = default;

grpc::Status RpcServiceImpl::getMessage(grpc::ServerContext* context,
										const Thesis::MessageReq* request,
										Thesis::MessageResp* response)
{
	const std::string req = request->request();
	std::cout << req << " reached!" << std::endl;
	response->set_response("Got following message: " + req);
	return grpc::Status();
}
