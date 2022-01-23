#include <bits/types/clock_t.h>
#include <time.h>
#include "clock.h"

clock_t start, end;
int hz_per_second = 4190000;

void gb_delay(double sec)
{
    clock_t buffer = clock();
    while (clock() - buffer < sec * CLOCKS_PER_SEC)
    {}

}

void gb_define_clock_speed(int hz)
{
    hz_per_second = hz;
}


void gb_start_clock()
{
    start = clock();
}

void gb_stop_simulate_clock(int hz)
{
    end = clock();

    // There will be some delay because the calculations will take a second,
    // but it probably won't be noticeable
    int instruction_hertz = hz;
    double seconds = (double) (end - start) / CLOCKS_PER_SEC; // seconds is how long the instruction took, not the time needed to be simulated
    if (instruction_hertz / hz_per_second >= seconds)
    {
        gb_delay((1.0 / (hz_per_second / instruction_hertz)) - seconds);
    }
}