/// @file FuelController.cpp
#include "JsonDeserializeAlp.h"
#include "FuelObject.h"
#include "FuelController.h"

FuelController::FuelController(FuelObject fuel, JsonDeserializeAlp jsonDeserialize) : _fuel(fuel), _jsonDeserialize(jsonDeserialize)
{
    pinMode(_fuel.getPin(), OUTPUT);
    analogWrite(_fuel.getPin(), _fuel.getCurrentStateFuel());
}

void FuelController::update(const String &json)
{
    bool shouldSendSignalToPin = canSendSignalToPin(json);

    if (shouldSendSignalToPin)
    {
        updateFuelState(json);
    }
    else
    {
        resetPinState();
    }
}

void FuelController::resetPinState()
{
    analogWrite(_fuel.getPin(), _fuel.getDefaultInitialValue());
    _fuel.setCurrentStateFuel(_fuel.getDefaultInitialValue());
}

bool FuelController::canSendSignalToPin(const String &json)
{
    bool electricOn = _jsonDeserialize.getBoolValue(json, "electricOn");
    bool engineOn = _jsonDeserialize.getBoolValue(json, "engineOn");

    return electricOn || engineOn;
}

void FuelController::updateFuelState(const String &json)
{
    float currentFuel = _jsonDeserialize.getFloatValue(json, "fuel");
    float fuelCapacity = _jsonDeserialize.getFloatValue(json, "fuelCapacity");

    if (currentFuel > 0 && fuelCapacity > 0)
    {
        if(currentFuel > fuelCapacity){
           fuelCapacity = currentFuel;
        }

        float percentValue = (currentFuel / fuelCapacity) * 100.0;
        int pwm = map(percentValue, 100, 0, _fuel.getMinPWM(), _fuel.getMaxPWM());

        if (_fuel.getCurrentStateFuel() != pwm)
        {
            analogWrite(_fuel.getPin(), pwm);
            _fuel.setCurrentStateFuel(pwm);
        }
    }
  
}
