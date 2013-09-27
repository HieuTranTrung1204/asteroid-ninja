/*
 Copyright (C) 2013 by Anton Gaenko
 Mail anton.gaenko@yahoo.com

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */


#include "Ship.h"
#include "Logger.h"
#include "Plasmoid.h"
#include "SpaceArchitect.h"

Ship::Ship(const Geometry<float, 3>& geometry, const ColorRGB& color, const Vector & initPos):
  SpaceObject(geometry, color, initPos) {
  debug("Spacecraft is ready, sir!");
}

// TODO Destroy laser object in this class user
Plasmoid Ship::piffPaff() {
  debug("Piff paff!");
  Plasmoid l(SpaceArchitect::LASER, kRED, _position);
  // apply rotation to laser
  l.setAngleInRadians(_angle);
  // then apply rotation to velocity vector
  Vector v = SpaceArchitect::PLASMOID_VELOCITY * RotateMatrix(_angle, Radians);
  l.setVelocity(v);
  return l;
}
