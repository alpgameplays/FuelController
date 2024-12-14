/**
 * @file FuelController.h
 * @brief Declaration of the FuelController class for managing fuel behavior.
 */
#ifndef FUEL_CONTROLLER_H
#define FUEL_CONTROLLER_H

#include <Arduino.h>
#include "FuelObject.h"
#include "JsonDeserializeAlp.h"

/**
 * @class FuelController
 * @brief Manages the fuel behavior based on input JSON data.
 *
 * The FuelController class interprets JSON inputs to update the fuel state
 * and adjust PWM outputs accordingly.
 */
class FuelController
{
public:
    /**
     * @brief Constructor to initialize the FuelController.
     * @param fuel The FuelObject to control.
     */
    FuelController(FuelObject fuel, JsonDeserializeAlp jsonDeserialize = JsonDeserializeAlp());

    /**
     * @brief Updates the fuel state, validating certain conditions (e.g., "electricOn" or "engineOn").
     * @param json The input JSON string with fuel-related data.
     */
    void update(const String &json);

    /**
     * @brief Directly updates the fuel state without additional validation.
     * @param json The input JSON string with fuel-related data.
     */
    void updateFuelState(const String &json); // Nome atualizado

    void resetPinState();

    bool canSendSignalToPin(const String &json);

private:
    FuelObject _fuel;
    JsonDeserializeAlp _jsonDeserialize;
};

#endif
