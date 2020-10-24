#pragma once

#include <chrono>

using namespace std;

namespace sdds {
	class TimedEvents
	{
	public:
		TimedEvents();
		~TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char* name);
		friend ostream& operator<<(ostream& os, const TimedEvents& te);



	private:
		int storedRecords{ 0 };
		chrono::steady_clock::time_point startTime;
		chrono::steady_clock::time_point endTime;
		struct {
			string eventName;
			string unitsOfTime;
			std::chrono::steady_clock::duration duration;
		} events[7];
	};

	
}



