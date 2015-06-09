#include <windows.h>


class Timer {
private:
	double pcFreq;
	__int64 counterStart;
	double time;

public:
	Timer(){
		pcFreq = 0.0;
		counterStart = 0.0;
		time = 0.0;
	}

	// Start timer
	void start_counter()
	{
		LARGE_INTEGER li;
		if(!QueryPerformanceFrequency(&li))
			throw "QueryPerformanceFrequency failed!";

		pcFreq = double(li.QuadPart)/1000.0;

		QueryPerformanceCounter(&li);
		counterStart = li.QuadPart;
	}

	// Stop measuring time
	void stop_counter()
	{
		LARGE_INTEGER li;
		QueryPerformanceCounter(&li);
		time = double(li.QuadPart-counterStart)/pcFreq;
	}

	// Reset timer
	void reset_counter(){
		time = 0.0;
	}

	// Return time in seconds
	double get_elapsed_time(){
		return time/1000.0;
	}

};