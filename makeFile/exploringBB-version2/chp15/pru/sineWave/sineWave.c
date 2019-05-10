 /*
 * Source Modified by Derek Molloy for Exploring BeagleBone Rev2
 * Based on the examples distributed by TI
 *
 * Copyright (C) 2015 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *	* Redistributions of source code must retain the above copyright
 *	  notice, this list of conditions and the following disclaimer.
 *
 *	* Redistributions in binary form must reproduce the above copyright
 *	  notice, this list of conditions and the following disclaimer in the
 *	  documentation and/or other materials provided with the
 *	  distribution.
 *
 *	* Neither the name of Texas Instruments Incorporated nor the names of
 *	  its contributors may be used to endorse or promote products derived
 *	  from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdint.h>
#include <pru_cfg.h>
#include "resource_table_empty.h"
#include <math.h>

// Delay factor which defines the PWM frequency
#define DELAYFACTOR 0
volatile register uint32_t __R30;
volatile register uint32_t __R31;

void main(void)
{
   volatile uint32_t gpio, button;
   uint32_t count, i;

   uint32_t waveform[100];
   float gain = 50.0f;                   // want the full range 0-99
   float phase = 0.0f;                   // phase can be changed
   float bias = 50.0f;                   // center on 1.65V, for full range
   float freq = 2.0f * 3.14159f / 100.0f;
   for (i=0; i<100; i++){                // general sine wave equation
      waveform[i] = (unsigned int)(bias + (gain * sin((i * freq) + phase)));
   }

   // Use pru0_pru_r30_5 as an output i.e., 100000 or 0x0020
   gpio = 0x0020;
   // Use pru0_pru_r31_3 as a button i.e., 1000 or 0x0008
   button = 0x0008;

   // Stop the loop when the button is pressed
   while (!(__R31 && button)) {
      for(i=0; i<100; i++){
         for(count=0; count<100; count++){
            // Use two comparisons to equalize the timing
            if(count<=waveform[i]) { __R30 |=  gpio;    }
            if(count> waveform[i]) { __R30 &= (~gpio); }
            __delay_cycles(DELAYFACTOR);
         }
      }
   }
   __halt();
}

