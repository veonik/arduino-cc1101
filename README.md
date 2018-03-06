arduino-cc1101
==============

This is an Arduino library for interfacing with CC1101 transceivers.

This project is a fork of the [panStamp arduino_avr project][1], with
only the minimum requirements to interface with CC1101 transceivers.

[1]: https://github.com/panStamp/arduino_avr "panStamp arduino_avr"


Installation
------------

Download a zip of this repository, then include it from the Arduino IDE.


Usage
-----

See [examples/example.ino](examples/example/example.ino) for an example. This example can be used on both devices, and will periodically send `hello world` while printing out details of any received packets.
