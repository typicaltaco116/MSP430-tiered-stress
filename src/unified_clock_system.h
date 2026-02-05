#pragma once
#include <msp430.h>

typedef enum{
  UCS_1MHZ,
  UCS_8MHZ,
  UCS_16MHZ,
  UCS_20MHZ,
} UCS_freq_e;

void UCS_setMCLKFreq(UCS_freq_e freq);

UCS_freq_e UCS_getMCLKFreq(void);
