#include "StringUtils.h"

namespace utils {

	bool isEmptyOrNull(const std::vector<std::string>& vec)
	{
		for each (const std::string & var in vec)
		{
			if (var.empty())
			{
				return false;
			}

		}
		return true;
	}

	bool isEmptyOrNull(const std::vector<std::wstring>& vec)
	{
		for each (const std::wstring & var in vec)
		{
			if (var.empty())
			{
				return false;
			}

		}
		return true;
	}

	std::string generateUUID()
	{
		return boost::lexical_cast<std::string>((*uuidGenPtr)());
	}
}
