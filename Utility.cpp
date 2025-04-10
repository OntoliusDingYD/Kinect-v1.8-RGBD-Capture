#include "Utility.h"

static ULONGLONG lastSave = 0;

ULONGLONG GetSynchronizedTimestamp()
{
    ULONGLONG now = GetTickCount64();

    if (now - lastSave >= 200)
    {
        lastSave = now;
        return now;
    }
    return 0;
}

ULONGLONG PeekLastSyncedTimestamp()
{
    return lastSave;
}
