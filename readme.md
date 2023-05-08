# ESC/POS Printer Library

A Library to control an ESC/POS printer by an ARDUINO via serial connection.

## Requirements

To get Arduino work together with the thermal printer on RS232 (serial) you need a level shifter. From Maxim you can get MAX2XX chips for 5 Volt and MAX32XX for 3.3 volt powered arduinos. The library works with SoftSerial so you are still able to send Data to Arduino with the standard serial line. The SoftSerial works at 9600 baud.

## Tested

- Epson TM-T88II (Serial RS232) & Arduino Uno & Maxim MAX233CPP
- Epson TM-T20 (Serial RS232) & Arduino Uno & Maxim MAX233CPP

## Functions

The functions available in this class are:

### `EscPos::EscPos(int rxPin, int txPin)`

Constructor that initializes the `rxPin` and `txPin` used to communicate with the printer and calls the `start()` function.

### `void EscPos::start()`

Sets up the communication pins, initializes the `SoftwareSerial` object used for communication with the printer, and sets the baud rate to 9600.

### `int EscPos::getStatus()`

Sends a query to the printer to check its status. Returns `0` if the printer is online.

### `int EscPos::read()`

Reads a single byte of data from the printer.

### `void EscPos::feed(uint8_t n)`

Prints the data in the print buffer and feeds `n` lines of paper.

### `void EscPos::feed()`

Equivalent to calling `feed(1)`.

### `void EscPos::lineSpacing(uint8_t n)`

Sets the line spacing to `n/180` inch.

### `void EscPos::defaultLineSpacing()`

Sets the line spacing to `1/6` inch, which is equivalent to 30 dots.

### `void EscPos::characterSet(uint8_t n)`

Selects an international character set based on the value of `n`. See reference for more metails.

Example:

```
 0 = U.S.A.
 1 = France
 2 = Germany
 3 = U.K.
 4 = Denmark I
 5 = Sweden
 6 = Italy
 7 = Spain
 8 = Japan
 9 = Norway
10 = Denmark II
```

### `void EscPos::doubleHeightOn()`

Enables double-height text printing.

### `void EscPos::doubleHeightOff()`

Disables double-height text printing.

### `void EscPos::boldOn()`

Enables bold text printing.

### `void EscPos::boldOff()`

Disables bold text printing.

### `void EscPos::underlineOn()`

Enables underlined text printing.

### `void EscPos::underlineOff()`

Disables underlined text printing.

### `void EscPos::reverseOn()`

Enables white/black reverse printing mode.

### `void EscPos::reverseOff()`

Disables white/black reverse printing mode.

### `void EscPos::justifyLeft()`

Sets text justification to left.

### `void EscPos::justifyCenter()`

Sets text justification to center.

### `void EscPos::justifyRight()`

Sets text justification to right.

### `void EscPos::barcodeHeight(uint8_t n)`

Sets the height of barcodes to `n` dots. Range 1-255.

### `void EscPos::barcodeWidth(uint8_t n)`

Sets the width of barcodes to `n` dots. Range 2-6

### `void EscPos::barcodeNumberPosition(uint8_t n)`

Sets the position of the barcode number. Range 0-3

### `void EscPos::printBarcode(uint8_t m, uint8_t n)`

Prints a barcode of type `m` (range 65-73) with a digit length of `n`.

### `void EscPos::fullCut()`

Performs a full cut of the paper.

### `void EscPos::partialCut()`

Performs a partial cut of the paper.

### `size_t EscPos::write(uint8_t c)`
### `size_t EscPos::write(char c)`

Writes a single byte of data to the printer.


## License

You may use this work under the terms of either the MIT License or the GNU General Public License (GPL) Version 3

## History

- 2023-05-08 - first public release

### Keywords

thermal, micro, receipt, printer, serial, tm-t88, tm88, tmt88, epson, arduino, tm20, tm-t20, tmt20
