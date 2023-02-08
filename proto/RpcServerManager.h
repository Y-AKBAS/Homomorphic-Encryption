#pragma once

#include <grpc++/server_builder.h>
#include <grpc++/server.h>

class RpcServerManager {
public:

	void startServer();
	bool isServerUp();
	void shutDownServer();

private:
	std::unique_ptr<grpc::Server> server;
};