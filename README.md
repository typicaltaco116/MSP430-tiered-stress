# MSP430F5529 NOR Flash Tiered Stressing Tool
This repo contains C code implementation for a tool to stress the MSP-EXP430F5529LP device in a tiered pattern. This tiered pattern is determined by the repository branch.

## master
The master branch creates three equally sized divisions through the last bank of flash memory.

| Segment |Address | Cycles |
|-------------- | ------------- | ------------ |
| 0 | 1C400 | 10k | 
| 1 | 1C600 | 20k | 
| 2 | 1C800 | 30k | 
| 3 | 1CA00 | 40k | 
| 4 | 1CC00 | 50k | 
| 5 | 1CE00 | 60k | 
| 6 | 1D000 | 70k | 
| 7 | 1D200 | 80k | 
| 8 | 1D400 | 90k | 
| 9 | 1D600 | 100k | 
| 10 | 1D800 | 110k | 
| 11 | 1DA00 | 120k | 
| 12 | 1DC00 | 130k | 
| 13 | 1DE00 | 140k | 
| 14 | 1E000 | 150k | 
| 15 | 1E200 | 160k | 
| 16 | 1E400 | 170k | 
| 17 | 1E600 | 180k | 
| 18 | 1E800 | 190k | 
| 19 | 1EA00 | 200k | 
| 20 | 1EC00 |      | 
| 21 | 1EE00 |      | 
| 22 | 1F000 | 10k  | 
| 23 | 1F200 | 20k  | 
| 24 | 1F400 | 30k  | 
| 25 | 1F600 | 40k  | 
| 26 | 1F800 | 50k  | 
| 27 | 1FA00 | 60k  | 
| 28 | 1FC00 | 70k  | 
| 29 | 1FE00 | 80k  | 
| 30 | 20000 | 90k  | 
| 31 | 20200 | 100k | 
| 32 | 20400 | 110k | 
| 33 | 20600 | 120k | 
| 34 | 20800 | 130k | 
| 35 | 20A00 | 140k | 
| 36 | 20C00 | 150k | 
| 37 | 20E00 | 160k | 
| 38 | 21000 | 170k | 
| 39 | 21200 | 180k | 
| 40 | 21400 | 190k | 
| 41 | 21600 | 200k | 
| 42 | 21800 |      | 
| 43 | 21A00 |      | 
| 44 | 21C00 | 10k  | 
| 45 | 21E00 | 20k  | 
| 46 | 22000 | 30k  | 
| 47 | 22200 | 40k  | 
| 48 | 22400 | 50k  | 
| 49 | 22600 | 60k  | 
| 50 | 22800 | 70k  | 
| 51 | 22A00 | 80k  | 
| 52 | 22C00 | 90k  | 
| 53 | 22E00 | 100k | 
| 54 | 23000 | 110k | 
| 55 | 23200 | 120k | 
| 56 | 23400 | 130k | 
| 57 | 23600 | 140k | 
| 58 | 23800 | 150k | 
| 59 | 23A00 | 160k | 
| 60 | 23C00 | 170k | 
| 61 | 23E00 | 180k | 
| 62 | 24000 | 190k | 
| 63 | 24200 | 200k | 
