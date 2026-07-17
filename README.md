## TLE Satellite Parser

## Requirements: 
* C++ 20 compiler 
* GCC 13+ 
* CMake 3.15+ 
* Linux/WSL
## Build: 
* git clone https://github.com/mdiallo64/SatelliteParser.git
* cd SatelliteParser
* mkdir -p build
* cd build
* cmake .. 
* cmake --build . 

## Run:
* ./src/SatelliteParser src/data/data.txt 

## Data:
To change data input, visit https://celestrak.org/NORAD/elements/index.php?FORMAT=tle and download or copy and set as TLE data. If downloaded replace with current file in /data. If copied replace current contents with copied:

<img width="230" height="87" alt="image" src="https://github.com/user-attachments/assets/9702b20f-3980-4048-bfef-cea15c4d94c9" />



## Features
This program takes [TLE](https://en.wikipedia.org/wiki/Two-line_element_set)(Two line element) sets in as input from [CelesTrak](https://celestrak.org/NORAD/elements/) , then reads, classifies, and does calculations for relevant information. Users are then asked to choose from a list
of commands:


<img width="251" height="91" alt="image" src="https://github.com/user-attachments/assets/859f0016-91ab-4175-a591-86256a311998" />

Selecting "list" will display the stats for all current satellites in the dataset:

<img width="531" height="207" alt="image" src="https://github.com/user-attachments/assets/c31d4063-08dc-48be-87dd-ce260e2bdaf9" />



Selecting "filter" will enter a different state with new commands allowing the user to display satellites with a filter of their choice applied:


<img width="526" height="220" alt="image" src="https://github.com/user-attachments/assets/2f574f79-e4a8-442f-9d7f-4d3859c8f014" />

Selecting "back" takes the user to the previous menu:


<img width="527" height="209" alt="image" src="https://github.com/user-attachments/assets/a98d317c-a6fb-4c31-8e67-8cadedcd11a3" />


When "search" is selected, the user can enter the name of any satellite in the set to display its information:

<img width="528" height="83" alt="image" src="https://github.com/user-attachments/assets/1a450400-cc31-4195-af20-f556b2e8f8a7" />

As seen the user entered "iss" but since two satellites share this string in their name, the program displayed both. Exact or even partial names can be entered to display satellites.
If a name that is not included in the set is entered, the program will notify the user that no satellite was found.

Entering "quit" will exit the program

## Future work
* stats propagation
* live TLE fetch
