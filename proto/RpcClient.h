#pragma once

#include <grpcpp/grpcpp.h>
#include <communicator.grpc.pb.h>

class RpcClient {
public:
	RpcClient(std::shared_ptr<grpc::Channel> channel);
	void sendMessage();

private:
	std::unique_ptr<Thesis::CommunicationService::Stub> client;
};