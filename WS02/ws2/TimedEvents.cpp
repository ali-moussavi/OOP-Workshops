#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <cstring>

#include "TimedEvents.h"

using namespace std;

namespace sdds {
	TimedEvents::TimedEvents()
	{

	}

	TimedEvents::~TimedEvents()
	{
	}

	void TimedEvents::startClock() {
		startTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock() {
		endTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::recordEvent(const char* name) {

		this->events[storedRecords].eventName = name;
		this->events[storedRecords].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
		this->events[storedRecords].unitsOfTime = "nanoseconds";
		storedRecords++;

	}

	ostream& operator<<(ostream& os, const TimedEvents& te)
	{
		os << "Execution Times:\n" << "--------------------------" << endl;
		for (int i = 0; i < te.storedRecords; i++)
		{
			os << setw(20) << left << te.events[i].eventName << setfill(' ') << setw(12) << right << te.events[i].duration.count() << " " << te.events[i].unitsOfTime << endl;

		}
		return os;
	}
}