// Obsoleted since 2025/04/14
#include "Utility.h"
#include <chrono>

static double lastSave = 0.0;

double GetSynchronizedTimestamp()
{
	using namespace std::chrono;
	auto now = system_clock::now();
	auto epoch = now.time_since_epoch();
	auto micros = duration_cast<microseconds>(epoch).count();

	double now_time = micros / 1e6;
	if (now_time - lastSave >= 0.2)     // µ•Œª£∫√Î
    {
        lastSave = now_time;
        return now_time;
    }
    return 0;
}

double PeekLastSyncedTimestamp()
{
    return lastSave;
}
