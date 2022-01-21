# Magnetics


This document outlines the final designs for the Primary and Pick-up Coils for the 2021 Summer Workshop RC Car design.


The design specifications are outlined below:

## Authors:
- Ashley
- Tor

## Description:
This "Magnetics" folder contains all of the magnetics simulations done for the primary and pickup coils to be used for the RC car design. The primary coils, which will go on track while the pickup coils would go onboard the RC car. 

## Specifications considered when designing the coils:
### Track Details:
- Length > 1000mm
- Width  = 300mm
- Tolerance ± 50mm
 
### Car details:
- Link: https://www.rchobbies.co.nz/tamiya-1-10-tt-02-subaru-impreza-monte-carlo-99-rc-car/
- Length: 16.6" (421mm)
- Width: 7.5" (190mm)
- Height: 3.8" (98mm)

### Primary Coil:
-  Coil:
    - Width = 300mm
    - Length = 1000mm
    - Height = 5mm
    
- Ferrite
    - Height = 8mm

### Secondary Coil:
- Coil
    - Width =  20mm
    - Length = 18mm
    - Height = 11mm

- Ferrite
  - Width = 109mm
  - Length = 15mm
  - Height = 8mm
  - Secondary coil is 15mm above primary coil


### Ferrite Placement:
2.5mm between the primary coil and ferrite layer

### Finding K:
- Keep k between 50% when car is moving.

## Final Design Values:
### Min Offset:
  - Lpt: 30.93uH
  - Lst: 7.345uH
  - k: 0.14
  - Isc: 2.49
  - Voc: 1.39
### Max Offset:
  - Lpt: 30.59uH
  - Lst: 7.37uH
  - k: 0.066
  - Isc: 1.44
  - Voc: 0.7

### Additional
Here is a link to a google doc with additional information about how the design was developed: https://docs.google.com/document/d/1CYPLc7FcOTWijb-OdK_4NrKyWV1d8R1uPq-4dlyw1d0/edit?usp=sharing

### Authors:
- Ashley v.d. Merwe
- Tor Larsen
