#ifndef SDDS_EVENT_H__
#define SDDS_EVENT_H__


extern unsigned long int g_sysClock;


namespace sdds {
	class Event
	{
	public:
		unsigned long int startTime;
		Event();
		Event(const Event& src);
		~Event();
		void display();
		void setDescription(char* desc);
		Event& operator=(const Event& src);

	private:
		char* description;
		void setEmpty();
		void deleteDescription();
	};
}



#endif
