/*
 * \file main.c
 *
 * \brief avr128db48-constant-current-driver-using-opamp
 *
 *  (c) 2020 Microchip Technology Inc. and its subsidiaries.
 *
 *  Subject to your compliance with these terms,you may use this software and
 *  any derivatives exclusively with Microchip products.It is your responsibility
 *  to comply with third party license terms applicable to your use of third party
 *  software (including open source software) that may accompany Microchip software.
 *
 *  THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
 *  EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
 *  WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
 *  PARTICULAR PURPOSE.
 *
 *  IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
 *  INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 *  WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
 *  BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
 *  FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
 *  ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 *  THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 */

#include <avr/io.h>

// To compile the fuse configuration, the FUSES macro is used. The fuse settings are set to the device production values.
FUSES = {
    .WDTCFG = FUSE_WDTCFG_DEFAULT,
    .BODCFG = FUSE_BODCFG_DEFAULT,
    .OSCCFG = FUSE_OSCCFG_DEFAULT,
    .SYSCFG0 = FUSE_SYSCFG0_DEFAULT,
    .SYSCFG1 = FUSE_SYSCFG1_DEFAULT,
    .CODESIZE = FUSE_CODESIZE_DEFAULT,
    .BOOTSIZE = FUSE_BOOTSIZE_DEFAULT,
};
// To compile the lockbits configuration, the LOCKBITS macro is used. The lockbits are set to unlocked.
LOCKBITS = {
    LOCKBITS_DEFAULT,
};

int main(void)
{
	// Set up the timebase of the OPAMP peripheral
	OPAMP.TIMEBASE = 3; // Number of CLK_PER cycles that equal one us, minus one (4-1=3)
	
	//Connect OP0 to wiper and pin connected to sense resistor
	OPAMP.OP0INMUX = OPAMP_OP0INMUX_MUXPOS_WIP_gc | OPAMP_OP0INMUX_MUXNEG_INN_gc;
	//Connect resistor ladder to VDD and ground so the wiper functions as a voltage divider
	OPAMP.OP0RESMUX = OPAMP_OP0RESMUX_MUXBOT_GND_gc | OPAMP_OP0RESMUX_MUXWIP_WIP7_gc | OPAMP_OP0RESMUX_MUXTOP_VDD_gc;
	// Configure OP0 Control A
	OPAMP.OP0CTRLA = OPAMP_OP0CTRLA_OUTMODE_NORMAL_gc | OPAMP_ALWAYSON_bm;
	
	// Enable the OPAMP peripheral
	OPAMP.CTRLA = OPAMP_ENABLE_bm;

	while (1);
}

