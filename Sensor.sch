EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "3 dec 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L THERMISTOR TH?
U 1 1 547F0AF4
P 5350 3250
F 0 "TH?" V 5450 3300 50  0000 C CNN
F 1 "THERMISTOR 330" V 5250 3250 50  0000 C CNN
F 2 "~" H 5350 3250 60  0000 C CNN
F 3 "~" H 5350 3250 60  0000 C CNN
	1    5350 3250
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 547F0B31
P 6150 3250
F 0 "R?" V 6230 3250 40  0000 C CNN
F 1 "330 1%" V 6157 3251 40  0000 C CNN
F 2 "~" V 6080 3250 30  0000 C CNN
F 3 "~" H 6150 3250 30  0000 C CNN
	1    6150 3250
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 547F0B5C
P 4800 3500
F 0 "#PWR?" H 4800 3500 30  0001 C CNN
F 1 "GND" H 4800 3430 30  0001 C CNN
F 2 "" H 4800 3500 60  0000 C CNN
F 3 "" H 4800 3500 60  0000 C CNN
	1    4800 3500
	1    0    0    -1  
$EndComp
$Comp
L AGND #PWR?
U 1 1 547F0B77
P 5000 3500
F 0 "#PWR?" H 5000 3500 40  0001 C CNN
F 1 "AGND" H 5000 3430 50  0000 C CNN
F 2 "" H 5000 3500 60  0000 C CNN
F 3 "" H 5000 3500 60  0000 C CNN
	1    5000 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 3250 5100 3250
Wire Wire Line
	4800 3250 4800 3500
Wire Wire Line
	5000 3250 5000 3500
Wire Wire Line
	5600 3250 5900 3250
$Comp
L MOS_N Q?
U 1 1 547F0C01
P 6750 3450
F 0 "Q?" H 6760 3620 60  0000 R CNN
F 1 "MOS_N" H 6760 3300 60  0000 R CNN
F 2 "~" H 6750 3450 60  0000 C CNN
F 3 "~" H 6750 3450 60  0000 C CNN
	1    6750 3450
	-1   0    0    1   
$EndComp
Wire Wire Line
	6400 3250 6650 3250
$Comp
L +5V #PWR?
U 1 1 547F0C42
P 6650 4000
F 0 "#PWR?" H 6650 4090 20  0001 C CNN
F 1 "+5V" H 6650 4090 30  0000 C CNN
F 2 "" H 6650 4000 60  0000 C CNN
F 3 "" H 6650 4000 60  0000 C CNN
	1    6650 4000
	0    1    1    0   
$EndComp
Wire Wire Line
	6650 3650 6650 4000
$Comp
L C C?
U 1 1 547F0D97
P 5450 3900
F 0 "C?" H 5450 4000 40  0000 L CNN
F 1 "10uF" H 5456 3815 40  0000 L CNN
F 2 "~" H 5488 3750 30  0000 C CNN
F 3 "~" H 5450 3900 60  0000 C CNN
	1    5450 3900
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 547F0DBC
P 5750 3600
F 0 "R?" V 5830 3600 40  0000 C CNN
F 1 "1K" V 5757 3601 40  0000 C CNN
F 2 "~" V 5680 3600 30  0000 C CNN
F 3 "~" H 5750 3600 30  0000 C CNN
	1    5750 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 3900 5150 3900
Wire Wire Line
	5150 3900 5150 3450
Wire Wire Line
	5150 3450 5000 3450
Connection ~ 5000 3450
Wire Wire Line
	5650 3900 5750 3900
Wire Wire Line
	5750 3850 5750 4300
Wire Wire Line
	5750 3350 5750 3250
Connection ~ 5750 3250
Connection ~ 5750 3900
Text Notes 5800 4350 0    60   ~ 0
Output
Text Notes 7100 3500 0    60   ~ 0
uC Power Control
$EndSCHEMATC
