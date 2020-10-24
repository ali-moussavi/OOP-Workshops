#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip> 

#include "event.h"

using namespace std;

unsigned long int g_sysClock = 0;

namespace sdds {
	Event::Event()
	{
		setEmpty();
	}

	Event::Event(const Event& src) {
		setEmpty();
		if (src.description != nullptr)
		{
			if (src.description[0] != '\0')
			{
				description = new char[strlen(src.description) + 1];
				strcpy(description, src.description);
				startTime = src.startTime;
			}

		}
	}

	Event::~Event()
	{
		deleteDescription();
	}

	void Event::display() {
		
		static int counter = 0;
		counter++;
		int hours = startTime / 3600;
		int remainingTime = startTime - hours * 3600;
		int minutes = remainingTime / 60;
		int seconds = remainingTime - minutes * 60;


		if (this->description != nullptr)
		{
			if (this->description[0] != '\0'){
				cout << setfill(' ') << setw(3);
				cout << counter << ". " << setfill('0') << setw(2) << hours << ":"
					<< setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2) << seconds << " -> "
					<< this->description << endl;
			}
			else
			{
				cout << setfill(' ') << setw(3);
				cout << counter << ". [ No Event ]" << endl;
			}
		}
		else
		{
			cout << setfill(' ') << setw(3);
			cout << counter << ". [ No Event ]" << endl;
		}

	}

	void Event::setDescription(char* desc) {
		if (desc != nullptr)
		{
			if (desc[0] != '\0') {
				deleteDescription();
				description = new char[strlen(desc) + 1];
				strcpy(description, desc);
				this->startTime = g_sysClock;
			}
			else
			{
				deleteDescription();
				setEmpty();
			}
		}
		else
		{
			deleteDescription();
			setEmpty();
		}
			
	}

	void Event::setEmpty() {
		this->description = nullptr;
		this->startTime = 0;
	}

	void Event::deleteDescription() {
		if (this->description != nullptr)
		{
			delete[] description;
			description = nullptr;
		}
	}

	Event& Event::operator=(const Event& src) {
		if (this != &src)
		{
			if (description != nullptr || src.description == nullptr)
			{
				deleteDescription();
				setEmpty();
			}
			if (src.description != nullptr)
			{
				if (src.description[0] != '\0')
				{
					description = new char[strlen(src.description) + 1];
					strcpy(description, src.description);
					startTime = src.startTime;
				}
				else
				{
					deleteDescription();
					setEmpty();
				}

			}
		}
		
		

		return *this;
	}
}