#ifndef SINGTIME_H_
#define SINGTIME_H_
/* Monotonic time never goes backwards, and always goes forward at an even pace */
/* this returns the time as nanoseconds, counting forward from an unspecified epoch. */
uint64_t get_monotonic_time();

/* calendar time goes backwards, forwards, and stops
according to various historical and political decisions.
this returns the number of nanoseconds according to UTC, which is roughly,
the number of nanoseconds since midnight january 1st 1970 at the greenwich observatory.
(though there are nuances here in that it may in fact represent the number of days since then,
multiplied by 864000000000, plus the remainder nanoseconds. -- the key difference being that it may not
account for leap seconds or the exact length of a day which is not quite 864000000000
more research of the underlying apis are needed if this difference turns out to be important. )
*/
uint64_t get_utc_calendar_time ();

/* take into account local time zone information */
uint64_t get_local_calendar_time ();

/* monotonic time taking the process start as the epoch */
long since_start(void);


#endif /*SINGTIME_H_*/