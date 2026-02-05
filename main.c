/***************************************************************
* FILENAME: main.c
* AUTHOR: Jack Pyburn
* DATE: 01/13/2026
* STATUS: 
*        
* DESCRIPTION:
* Stresses flash memory segments in a tiered structure
****************************************************************/
#include <msp430.h> 
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "src/flash_operations.h"
#include "src/flash_partial_operations.h"
#include "src/flash_statistics.h"
#include "src/Serial.h"
#include "src/unified_clock_system.h"
#include "src/event_timer.h"


/* FLASH BANK D starts at 0x1_C400 and ends at 0x2_43FF */
#define F5529_FLASH_BANK_D      0x1C400
#define CHIP_ID_ADR             0x1A0A

#define TOTAL_PE_CYCLES         200000
#define STAT_INCREMENT_CYCLES   10000
#define STRESS_INDICATOR_CYCLES 1000

#define ENDL "\r\n"
#define BUF_SIZE                64

void haltUntilInput(void);
uint64_t get_chipID(void);

void equivalentTieredStress(f_bank_t, char*);

int main(void)
{
  char outputBuffer[BUF_SIZE];
  f_bank_t bank_D = (f_bank_t)F5529_FLASH_BANK_D;

  WDTCTL = WDTPW + WDTHOLD;	// stop watchdog timer

  haltUntilInput();

  UCS_setMCLKFreq(UCS_8MHZ);

  Serial0_setup(UCS_8MHZ);
  /* PRINT HEADER */
  Serial0_write("----------------------------------------------------------------------------------------------------" ENDL);
  Serial0_write("- MSP Flash Tiered Stresser: 0xAAAA Stressing Pattern" ENDL);
  snprintf(outputBuffer, BUF_SIZE, "- Subject Chip ID: 0x%08llX" ENDL, get_chipID());
  Serial0_write(outputBuffer);
  Serial0_write("----------------------------------------------------------------------------------------------------" ENDL);

  equivalentTieredStress(bank_D, outputBuffer);

  Serial0_write("----------------------------------------------------------------------------------------------------" ENDL);

  Serial0_write(" DONE..." ENDL ENDL);

  while (1) {
    P1OUT ^= BIT0;
    __delay_cycles(4E6);
  }

}

void equivalentTieredStress(f_bank_t bank, char* charBuffer)
{
  f_segment_t division1Start, division2Start, division3Start;
  f_segment_t division1End, division2End, division3End;

  int32_t totalIterations = TOTAL_PE_CYCLES;

  division1Start = (f_segment_t)bank + 0;
  division2Start = (f_segment_t)bank + 22;
  division3Start = (f_segment_t)bank + 44;

  division1End = (f_segment_t)bank + 19;
  division2End = (f_segment_t)bank + 41;
  division3End = (f_segment_t)bank + 63;

  while (totalIterations > 0) {
    // NOT REALLY NECESSARY
    snprintf(charBuffer, BUF_SIZE, "Division Starting Addresses: %p , %p, %p"
             ENDL, division1Start, division2Start, division3Start);
    Serial0_write(charBuffer);

    snprintf(charBuffer, BUF_SIZE, "%ld Cycles" ENDL, TOTAL_PE_CYCLES - totalIterations);
    Serial0_write(charBuffer);

    // Init Loading bar
    Serial0_write("....................");
    Serial0_write("\x1B" "[0G"); // ANSI Escape code for return to zero column

    for (int32_t i = STAT_INCREMENT_CYCLES / STRESS_INDICATOR_CYCLES; i > 0; --i) {
      f_genStress(division1Start, division1End, 0xAAAA, STRESS_INDICATOR_CYCLES);
      f_genStress(division2Start, division2End, 0xAAAA, STRESS_INDICATOR_CYCLES);
      f_genStress(division3Start, division3End, 0xAAAA, STRESS_INDICATOR_CYCLES);
      Serial0_write("##"); // advance loading bar
    }
    Serial0_write(ENDL);

    totalIterations -= STAT_INCREMENT_CYCLES;

    division1Start++;
    division2Start++;
    division3Start++;
    
  }

  snprintf(charBuffer, BUF_SIZE, "%ld Cycles" ENDL, TOTAL_PE_CYCLES);
  Serial0_write(charBuffer);
}

void haltUntilInput(void)
{
  P1REN |= BIT1;
  P1DIR |= BIT0;
  P1OUT |= BIT1 + BIT0;
  while(P1IN & BIT1);// wait till button press to start
  P1OUT &= ~BIT0;
}

uint64_t get_chipID(void)
{
  return *(uint64_t*)CHIP_ID_ADR;
}
