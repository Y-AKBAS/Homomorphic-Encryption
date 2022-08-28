
#include "Timer.h"

namespace utils {

	Timer::Timer() = default;
	Timer::~Timer() = default;

	void Timer::clear()
	{
		m_begin = m_end = clk::now();
	}

	void Timer::start()
	{
		m_begin = clk::now();
	}

	void Timer::stop()
	{
		m_end = clk::now();
	}

	double Timer::passedTimeInSeconds() const
	{
		if (m_end <= m_begin)
		{
			return 0.0;
		}

		const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(m_end - m_begin);
		return duration.count() / 1000000.0;
	}

	void Timer::extraction(std::ostream& os) const
	{
		os << passedTimeInSeconds();
	}

	std::shared_ptr<std::tm> Timer::getCurrentTm() {

		std::shared_ptr<std::tm> time_manager = std::make_shared<std::tm>();
		const clk::time_point now = clk::now();
		const std::time_t tt = clk::to_time_t(now);

		time_manager.reset(std::localtime(&tt));
		return time_manager;
	}

	std::shared_ptr<std::tm> getCustomTm(
		const std::optional<int>& year,
		const std::optional<int>& month,
		const std::optional<int>& day,
		const std::optional<int>& hour,
		const std::optional<int>& minute) {

		const bool have_values = year && month && day && hour && minute;
		if (have_values)
		{
			const std::shared_ptr<std::tm> time_manager = std::make_shared<std::tm>();

			time_manager->tm_year = year.value();
			time_manager->tm_mon = month.value();
			time_manager->tm_wday = day.value();
			time_manager->tm_hour = hour.value();
			time_manager->tm_min = minute.value();
			return time_manager;
		}

		return nullptr;
		//throw std::invalid_argument("One or more argument missing");
	}


	std::ostream& operator<<(std::ostream& os, const Timer& timer)
	{
		timer.extraction(os);
		return os;
	}

}