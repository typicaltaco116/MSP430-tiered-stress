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

#define TOTAL_PE_CYCLES         1000000
#define STAT_INCREMENT_CYCLES   2000
#define STRESS_INDICATOR_CYCLES 500

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
  Serial0_write("- MSP Flash Tiered Stresser: 10k cycle increments" ENDL);
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
  int32_t totalIterations = TOTAL_PE_CYCLES;

  f_segment_t division1Start = (f_segment_t)bank + 1;
  f_segment_t division1End = (f_segment_t)bank + 50;

  while (totalIterations > 0) {
    // NOT REALLY NECESSARY
    snprintf(charBuffer, BUF_SIZE, "Division Starting Addresses: %p" ENDL, division1Start);
    Serial0_write(charBuffer);

    snprintf(charBuffer, BUF_SIZE, "%ld Cycles" ENDL, TOTAL_PE_CYCLES - totalIterations);
    Serial0_write(charBuffer);

    // Init Loading bar
    Serial0_write("............");
    Serial0_write("\x1B" "[0G"); // ANSI Escape code for return to zero column

    for (int32_t i = STAT_INCREMENT_CYCLES / STRESS_INDICATOR_CYCLES; i > 0; --i) {
      f_genStress(division1Start, division1End, 0x0000, STRESS_INDICATOR_CYCLES);
      Serial0_write("###"); // advance loading bar
    }
    Serial0_write(ENDL);

    totalIterations -= STAT_INCREMENT_CYCLES;

    division1Start++;
    
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
