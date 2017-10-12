# Bike helmet head and tail light with remote control

This project is a head light and tail light electronic and CAD design,
featuring a handlebar mounted remote control for on/off operation, high beam
and rear stop light.

![Helmet Front](https://fabiobaltieri.files.wordpress.com/2017/10/main-1.jpg)
![Helmet Rear](https://fabiobaltieri.files.wordpress.com/2017/10/main-2.jpg)

Contents
----------------

  - `cad`: FreeCAD source files for the various mechanical parts
  - `firmware-remote`: firmware for the remote control
  - `headlight`: hardware files for the head light LED carrier (Eagle)
  - `red-cluster`: hardware files for the rear light LED carrier (Eagle)
  - `remote`: hardware files for the remote controller (Eagle)

  TODO: add tail light pcb and firmware files.

Tail Light
----------

The tail light module contains the electronics and rechargeable battery.

Features:

  - Power drivers for front beam and rear lights (multiple channels).
  - Integrates a lithium battery charger via micro-USB (`MCP73831`).
  - Battery current and voltage monitoring (`INA219`).
  - Main microcontroller (`ATmega88PA`)
  - Low power radio for remote controlled operation (`nRF24L01+`).
  - Rear light uses an array of 4x3 red LEDs.

The module has a custom 3D printed case, and integrates a magnet to mount on
the rear helmet light slot found on many Giant helmets (meant to be used with
`Numen Link` lights). The magnet is glued to the case with epoxy.

Since the rear light module is removable, it includes two spring loaded
contacts (P/N: `Harwin P70-1020045R`) to drive the front headlight, which is
fixed on the helmet and wired to two matching copper tape pads on the rear
light slot.

![Tail Light 1](https://fabiobaltieri.files.wordpress.com/2017/10/taillight-1.jpg)
![Tail Light 2](https://fabiobaltieri.files.wordpress.com/2017/10/taillight-2.jpg)
![Tail Light 3](https://fabiobaltieri.files.wordpress.com/2017/10/taillight-3.jpg)

  NOTE: the tail light module controller board currently in the repository has
  been designed for a different application, which is why the LEDs are driven
  using a set of motor drivers (`DRV8830`) rather than LED drivers. The design is
  unnecessarily complicated and has some unused components. I may eventually
  redesign a dedicated board from scratch.

Head Light
----------

The head light is mounted on the front side of the helmet, and it's made of a
cylindrical carrier with a flat side to match the helmet curvature, a front
lens (biconvex lens reused from a first gen Cardboard), a conical spacer
covered in foil to act as a reflector and a LED carrier board with a 5x5mm CREE
high power LED (P/N: `XMLBWT`) and a lock ring to secure the whole assembly.

All support components are 3D printed, and the internal components are 25mm
diameter (driven by the lens).  The whole assembly is mounted on the helmet
using `3M VHB` adhesive foam type (I've used the 1.1 thick 4941P type, general
purpose).

The LED carrier board has power contacts and LED on the top layer (front) and a
filled plane on the bottom layer (rear), which is electrically neutral and
connected to the thermal pad of the LED.  This should give a minimum level of
water proofing and heat sinking.

The wiring to the tail light module is done with magnet wire through the foam
body of the helmet, and mostly hidden behind the internal padding.

![Head Light 1](https://fabiobaltieri.files.wordpress.com/2017/10/headlight-1.jpg)
![Head Light 2](https://fabiobaltieri.files.wordpress.com/2017/10/headlight-2.jpg)

Handlebar Remote
----------------

The remote uses a small custom board, meant to be mounted on the bike brake
lever assembly.

Features:

  - Operates from a single CR2032 non-rechargeable Lithium battery.
  - Main microcontroller (`ATmega88PA`), stays most of its life in power down
    state waiting for a button press, extremely low power consumption.
  - Three tactile buttons for on/off, position light and high beam.
  - One SMD low profile reed switch (`Coto CT05-1535-J1`) for brake operation
    detection.

The reed switch is activated through a small magnet mounted on the actual brake
lever using a 3D printed carrier and secured with VHB tape.

The remote control board is enclosed in a 3D printed case, with a set of
matching flexible domes to allow clicking on the contacts through the plastic,
covered with generic double sided tape to (hopefully) make it waterproof.

The remote mounts on the brake assembly on a support bracket fixed on the
brake itself, and locks in place with a set of matching magnets.

TODO: actually build this.

![Remote 1](https://fabiobaltieri.files.wordpress.com/2017/10/remote-1.jpg)
![Remote 2](https://fabiobaltieri.files.wordpress.com/2017/10/remote-2.jpg)
![Remote 3](https://fabiobaltieri.files.wordpress.com/2017/10/remote-3.jpg)

Demo
----

[Short video of the whole system operation](https://youtu.be/Jjlq_EyCdOQ).

I want one!
-----------

Good! This whole design though is custom fit to the helmet and bike that I own,
so you'll have to fork your own version, adapt and build the various parts.

If you are just looking for an off the shelf product with similar features,
there are many options available, including:

  - Garmin Varia
  - Trek Bontrager RT series
  - Gemini lights
  - CatEye Rapid X2 Kinetic
