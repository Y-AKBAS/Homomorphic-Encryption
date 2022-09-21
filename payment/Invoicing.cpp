#include "Invoicing.h"
#include "utils/Timer.h"

Invoicing::Invoicing(
	const std::shared_ptr<User>& user,
	const double& price
) : user{ user }, price{ price }
{
	invoicing_time = utils::Timer::getCurrentTm();
}