/*
  Copyright (c) 2016 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#pragma once
#define TwoWire_h
#include <inttypes.h>
#include "Stream.h"

namespace arduino {

class HardwareI2C : public Stream
{
  public:
    virtual void begin() = 0;
    virtual void begin(uint8_t address) = 0;
    virtual void end() = 0;

    virtual void setClock(uint32_t freq) = 0;
  
    virtual void beginTransmission(uint8_t address) = 0;
    virtual uint8_t endTransmission(bool stopBit) = 0;
    virtual uint8_t endTransmission(void) = 0;

    virtual uint8_t requestFrom(uint8_t address, size_t len, bool stopBit) = 0;
    virtual uint8_t requestFrom(uint8_t address, size_t len) = 0;

    virtual void onReceive(void(*)(int)) = 0;
    virtual void onRequest(void(*)(void)) = 0;

    virtual int writeQuick(uint8_t toWrite) = 0;
};

}

