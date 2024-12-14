/**
 * @file FuelObject.h
 * @brief Declaration of the FuelObject class, representing basic fuel system attributes.
 */
#ifndef FUEL_OBJECT_H
#define FUEL_OBJECT_H

#include <Arduino.h>

/**
 * @class FuelObject
 * @brief Represents a fuel control object with essential attributes.
 *
 * The FuelObject class encapsulates data related to a PWM output pin,
 * minimum and maximum PWM values, and the current fuel state.
 */
class FuelObject
{
public:
    /**
     * @brief Constructor to initialize the FuelObject.
     * @param pin The output pin number for PWM.
     * @param minPWM The minimum PWM value.
     * @param maxPWM The maximum PWM value.
     * @param currentStateFuel The initial fuel state.
     */
    FuelObject(int pin, int minPWM, int maxPWM, int currentStateFuel)
        : _pin(pin), _minPWM(minPWM), _maxPWM(maxPWM), _currentStateFuel(currentStateFuel), _defaultInitalValue(currentStateFuel) {}

    int getPin() const { return _pin; }
    int getMinPWM() const { return _minPWM; }
    int getMaxPWM() const { return _maxPWM; }
    int getCurrentStateFuel() const { return _currentStateFuel; }
    int getDefaultInitialValue() const { return _defaultInitalValue; }
    void setCurrentStateFuel(int value) { _currentStateFuel = value; }

private:
    int _pin;
    int _minPWM;
    int _maxPWM;
    int _currentStateFuel;
    int _defaultInitalValue;
};

#endif
