# Custom Split Monoblock

A handwired split keyboard with a 3x5+3 layout in monoblock form factor.

## Features

- Split 3x5+3 layout (36 keys total)
- Elite-C controller
- Handwired matrix

## Layout

```
Q W E R T   Y U I O P
A S D F G   H J K L ;
Z X C V B   N M , . /
    ⌘ ␣ ⇧   ⇧ ⏎ ⌥
```

## Pin Configuration

- **Columns**: B3, B1, F7, F6, D4, C6, D7, E6, B4, B5 (10 pins)
- **Rows**: B2, B6, F0, F1 (4 pins)
- **Diode Direction**: COL2ROW

## Building

To build the firmware:

```bash
qmk compile -kb handwired/custom_split_monoblock -km default
```

## Flashing

Flash to Elite-C:

```bash
qmk flash -kb handwired/custom_split_monoblock -km default
```