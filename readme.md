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

### `int EscPos::read()`

Reads a single byte of data from the printer.

### `size_t EscPos::write(uint8_t c)`

Writes a single byte of data to the printer.

### `int EscPos::getStatus()`

Sends a query to the printer to check its status. Returns `0` if the printer is online.

### `void EscPos::feed(uint8_t n)`

Prints the data in the print buffer and feeds `n` lines of paper.

### `void EscPos::feed()`

Equivalent to calling `feed(1)`.

### `void EscPos::lineSpacing(uint8_t n)`

Sets the line spacing to `n/180` inch.

### `void EscPos::defaultLineSpacing()`

Sets the line spacing to `1/6` inch, which is equivalent to 30 dots.

### `void EscPos::set80mm()`

Sets the paper width to 80mm.

### `void EscPos::set58mm()`

Sets the paper width to 58mm.

### `void EscPos::characterSet(uint8_t n)`

Selects an international character set based on the value of `n`. See table below for more metails.

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
11 = Spain II
12 = Latin America
13 = Korea
14 = Slovenia / Croatia
15 = China
```

### `void EscPos::effectDoubleHeight()`

Enables double-height text printing. Can be combined with other effect.

### `void EscPos::effectDoubleWidth()`

Enables double-width text printing. Can be combined with other effect.

### `void EscPos::effectBold()`

Enables bold text printing. Can be combined with other effect.

### `void EscPos::effectUnderline()`

Enables underlined text printing. Can be combined with other effect.

### `void EscPos::effectOff()`

Disables all text printing effect.

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

### `void EscPos::barcodeHeight()`

Sets the height of barcodes to 162 dots.

### `void EscPos::barcodeWidth()`

Sets the width of barcodes to 3 dots.

### `void EscPos::barcodeTextPosition(uint8_t n)`

Sets the position of the barcode text. Range 0-3. 0=no 1=above 2=below 3=both

### `void EscPos::barcodeStartPrint()`

Prints a barcode. Use EscPos->print("barcode") to send the string of barcode.

### `void EscPos::barcodeEndPrint()`

End the barcode print.

### `void EscPos::qrcodeStartPrint(uint8_t len)`

Prints a qrcode. `len` value is lenght in char of the string. Use EscPos->print("qrcode") to send the string of barcode.

### `void EscPos::qrcodeEndPrint()`

End the qrcode print.

### `void EscPos::fullCut()`

Performs a full cut of the paper.

### `void EscPos::partialCut()`

Performs a partial cut of the paper.



## License

You may use this work under the terms of either the MIT License or the GNU General Public License (GPL) Version 3

## History

- 2023-05-08 - first public release

### Keywords

thermal, micro, receipt, printer, serial, tm-t88, tm88, tmt88, epson, arduino, tm20, tm-t20, tmt20
