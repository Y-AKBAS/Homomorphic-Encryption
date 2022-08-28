#pragma once

#include <optional>
#include <chrono>
#include <iostream>
#include <memory>

namespace utils {

	class Timer {
	public:
		Timer();
		~Timer();
		void clear();
		void start();
		void stop();
		double passedTimeInSeconds() const;
		void extraction(std::ostream& os) const;
		static std::shared_ptr<std::tm> getCurrentTm();
		static std::shared_ptr<std::tm> getCustomTm(
			const std::optional<int>& year,
			const std::optional<int>& month,
			const std::optional<int>& day,
			const std::optional<int>& hour,
			const std::optional<int>& minute);

	private:
		using clk = std::chrono::system_clock;

		clk::time_point m_begin;
		clk::time_point m_end;
	};

	std::ostream& operator<<(std::ostream& os, const Timer& timer);

}