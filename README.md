# MSP430F5529 NOR Flash Tiered Stressing Tool
This repo contains C code implementation for a tool to stress the MSP-EXP430F5529LP device in a tiered pattern. This tiered pattern is determined by the repository branch.

## single-division
The single division branch contains a stressing pattern with a single division.

| Segment |Address | Cycles |
|-------------- | ------------- | ------------ |
| 0 | 1C400  | 0k | 
| 1 | 1C600  | 2k | 
| 2 | 1C800  | 4k | 
| 3 | 1CA00  | 6k | 
| 4 | 1CC00  | 8k | 
| 5 | 1CE00  | 10k | 
| 6 | 1D000  | 12k | 
| 7 | 1D200  | 14k | 
| 8 | 1D400  | 16k | 
| 9 | 1D600  | 18k | 
| 10 | 1D800 | 20k | 
| 11 | 1DA00 | 22k | 
| 12 | 1DC00 | 24k | 
| 13 | 1DE00 | 26k | 
| 14 | 1E000 | 28k | 
| 15 | 1E200 | 30k | 
| 16 | 1E400 | 32k | 
| 17 | 1E600 | 34k | 
| 18 | 1E800 | 36k | 
| 19 | 1EA00 | 38k | 
| 20 | 1EC00 | 40k | 
| 21 | 1EE00 | 42k | 
| 22 | 1F000 | 44k | 
| 23 | 1F200 | 46k | 
| 24 | 1F400 | 48k | 
| 25 | 1F600 | 50k | 
| 26 | 1F800 | 52k | 
| 27 | 1FA00 | 54k | 
| 28 | 1FC00 | 56k | 
| 29 | 1FE00 | 58k | 
| 30 | 20000 | 60k | 
| 31 | 20200 | 62k | 
| 32 | 20400 | 64k | 
| 33 | 20600 | 66k | 
| 34 | 20800 | 68k | 
| 35 | 20A00 | 70k | 
| 36 | 20C00 | 72k | 
| 37 | 20E00 | 74k | 
| 38 | 21000 | 76k | 
| 39 | 21200 | 78k | 
| 40 | 21400 | 80k | 
| 41 | 21600 | 82k | 
| 42 | 21800 | 84k | 
| 43 | 21A00 | 86k | 
| 44 | 21C00 | 88k | 
| 45 | 21E00 | 90k | 
| 46 | 22000 | 92k | 
| 47 | 22200 | 94k | 
| 48 | 22400 | 96k | 
| 49 | 22600 | 98k | 
| 50 | 22800 | 100k | 
| 51 | 22A00 | 0 | 
| 52 | 22C00 | 0 | 
| 53 | 22E00 | 0 | 
| 54 | 23000 | 0 | 
| 55 | 23200 | 0 | 
| 56 | 23400 | 0 | 
| 57 | 23600 | 0 | 
| 58 | 23800 | 0 | 
| 59 | 23A00 | 0 | 
| 60 | 23C00 | 0 | 
| 61 | 23E00 | 0 | 
| 62 | 24000 | 0 | 
| 63 | 24200 | 0 | 
