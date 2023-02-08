#include "RpcClient.h"
#include "../ApplicationConstants.h"

RpcClient::RpcClient(std::shared_ptr<grpc::Channel> channel)
	:client(Thesis::CommunicationService::NewStub(channel)) {}

void RpcClient::sendMessage()
{
	/*
	std::shared_ptr<Thesis::MessageReq> req = std::make_shared<Thesis::MessageReq>();
	req->set_request("Wow finally");

	std::shared_ptr<grpc::ClientContext> context = std::make_shared<grpc::ClientContext>();

	std::shared_ptr<Thesis::MessageResp> resp = std::make_shared<Thesis::MessageResp>();

	client->getMessage(context.get(), *req, resp.get());

	std::cout << resp->response() << std::endl;
	
	*/

	Thesis::MessageReq req;
	req.set_request("Wow finally");
	std::cout << req.stringlist().size() << std::endl;
	req.set_stringlist(0, "Was soll das?");
	req.add_stringlist("also nochmals");

	const google::protobuf::RepeatedPtrField<std::string> ptr = req.stringlist();
	std::cout << *ptr.begin() << std::endl;

	grpc::ClientContext context;
	Thesis::MessageResp resp;

	client->getMessage(&context, req, &resp);
	std::cout << "Trying to get response" << std::endl;
	std::cout << resp.response() << std::endl;
}

/*
int main() {
	std::unique_ptr<RpcClient> client =
		std::make_unique<RpcClient>(grpc::CreateChannel(RPC_HOST_AND_PORT, grpc::InsecureChannelCredentials()));

	client->sendMessage();
}

*/
