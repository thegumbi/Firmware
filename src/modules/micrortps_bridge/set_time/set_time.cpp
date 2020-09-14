/****************************************************************************
 *
 *   Copyright (c) 2012-2019 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/



/**
 * @file px4_simple_app.c
 * Set time with uorb message for PX4 autopilot with companion computer
 *
 * @author James Kennedy <jken099@gmail.com>
 */

#include <px4_platform_common/log.h>
#include <ctime>

extern "C" __EXPORT int set_time_main(int argc, char *argv[]);

int set_time_main(int argc, char *argv[])
{
    PX4_INFO("Hello Sky!");
    timespec new_time, current_time;

    //Check the current time
    px4_clock_gettime(CLOCK_REALTIME, &current_time);
    PX4_INFO("Current time is: %lu:%lu", (unsigned long)current_time.tv_sec, (unsigned long)current_time.tv_nsec);

    //Chose the new time
    new_time.tv_sec = 0;
    new_time.tv_nsec = 0;
    //Set the time
    if(px4_clock_settime(CLOCK_REALTIME, &new_time))
    {
        //Check the current time again to see if it has changed
        px4_clock_gettime(CLOCK_REALTIME, &current_time);
        PX4_INFO("Current time is: %lu:%lu", (unsigned long)current_time.tv_sec, (unsigned long)current_time.tv_nsec);
    }
    else
    {
        //Set time failed
        PX4_WARN("Set time failed");

    }
    return OK;
}
