#include <stdint.h>
#ifdef __MACH__
#include <mach/mach_time.h>
#endif
#include <time.h>
#include "singtime.h"

/* Monotonic time never goes backwards, and always goes forward at an even pace */
/* this returns the time as nanoseconds, counting forward from an unspecified epoch. */
uint64_t get_monotonic_time()
{

#ifdef __MACH__
    mach_timebase_info_data_t info;
    if (mach_timebase_info(&info) != KERN_SUCCESS) return 0;
    uint64_t t = mach_absolute_time();
    return t * info.numer / info.denom;
#else
    struct timespec now;
    clock_gettime( CLOCK_MONOTONIC, &now );
    long nanos = now.tv_nsec;
    time_t seconds = now.tv_sec;
    uint64_t mus = (uint64_t)((( (uint64_t) seconds ) * 1000 * 1000 * 1000)+ (nanos ));
    return mus;
#endif
}
/* calendar time goes backwards, forwards, and stops
according to various historical and political decisions.
this returns the number of nanoseconds according to UTC, which is roughly,
the number of nanoseconds since midnight january 1st 1970 at the greenwich observatory.
(though there are nuances here in that it may in fact represent the number of days since then,
multiplied by 864000000000, plus the remainder nanoseconds. -- the key difference being that it may not
account for leap seconds or the exact length of a day which is not quite 864000000000
more research of the underlying apis are needed if this difference turns out to be important. )
*/
uint64_t get_utc_calendar_time ()
{
    struct timespec ts;
#ifdef __MACH__ // OS X does not have clock_gettime, use clock_get_time
    clock_serv_t cclock;
    mach_timespec_t mts;
    host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
    clock_get_time(cclock, &mts);
    mach_port_deallocate(mach_task_self(), cclock);
    ts.tv_sec = mts.tv_sec;
    ts.tv_nsec = mts.tv_nsec;
#else
    clock_gettime(CLOCK_REALTIME, &ts);
#endif
    time_t seconds = ts.tv_sec;
    long nanos = ts.tv_nsec;

    uint64_t mus = (uint64_t)((( (uint64_t)seconds ) * 1000 * 1000 )+ (nanos / 1000));
    return mus;
}

/* take into account local time zone information */
uint64_t get_local_calendar_time ()
{
    uint64_t nanoseconds = get_utc_calendar_time();
    struct tm lt;
    time_t mytime = (time_t)(nanoseconds / 1000000) ;

    //*get local tz offset */
    localtime_r( &mytime , &lt );
    uint64_t localnanoseconds = nanoseconds + ((uint64_t)lt.tm_gmtoff) * (uint64_t)1000000;
    return localnanoseconds;
}

static uint64_t startTime = 0;
long since_start(void)
{
    uint64_t curr = get_monotonic_time();
    if (startTime == 0) {
        startTime = curr;
        return 0;
    }
    uint64_t diff = curr-startTime;
    uint64_t diffdiv = diff/1000000;
    return (long)(diffdiv) ;
}

