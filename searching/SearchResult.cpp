
#include "SearchResult.h"

SearchResult::SearchResult(
	const std::shared_ptr<BaseTransporter>& transporter,
	const std::shared_ptr<BaseProvider>& provider,
	const std::shared_ptr<std::tm>& when,
	const std::string& from,
	const std::string& to,
	const double& price,
	const std::optional<std::vector<std::shared_ptr<SearchResult>>>& change
) : transporter{ transporter },
provider{ provider },
when{ when },
from{ from },
to{ to },
price{ price },
change{ change }
{}