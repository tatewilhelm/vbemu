#ifndef VBEMU_CLOCK_H
#define VBEMU_CLOCK_H

void gb_start_clock();

void gb_stop_simulate_clock(int hz);

void gb_delay(double sec);

#endif //VBEMU_CLOCK_H
