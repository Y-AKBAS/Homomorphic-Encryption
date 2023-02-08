#include "RpcServerManager.h"
#include "../ApplicationConstants.h"
#include "RpcServiceImpl.h"

void RpcServerManager::startServer()
{
	RpcServiceImpl service;
	std::unique_ptr<grpc::ServerBuilder> builder = std::make_unique<grpc::ServerBuilder>();
	builder->AddListeningPort(RPC_HOST_AND_PORT, grpc::InsecureServerCredentials());
	builder->RegisterService(&service);
	server = builder->BuildAndStart();
	std::cout << "started server" << std::endl;
	server->Wait();
}

bool RpcServerManager::isServerUp() {
	bool isNull = server == nullptr;
	std::cout << std::boolalpha << isNull << std::endl;
	return isNull;
}

void RpcServerManager::shutDownServer()
{
	if (server != nullptr)
	{
		server->Shutdown();
	}
}
