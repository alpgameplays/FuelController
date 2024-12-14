# FuelController

## **Description**
This project includes two classes to control fuel behavior using PWM:
- **FuelObject**: Stores information about the pin, PWM values, and current state.
- **FuelController**: Manages the fuel state based on JSON inputs.

## **How to Use**

### 1. Initialize the `FuelObject`
```cpp
FuelObject fuel(pin, minPWM, maxPWM, initialState);
```
- `pin`: The output pin number.
- `minPWM`: The minimum PWM value.
- `maxPWM`: The maximum PWM value.
- `initialState`: The initial fuel state.

### 2. Initialize the `FuelController`
```cpp
FuelController controller(fuelObject);
```

### 3. Update the fuel state
```cpp
controller.update(jsonString);
```
- `jsonString`: JSON string containing keys like `fuel`, `fuelCapacity`, `electricOn`.

## **Example**

```cpp
#include "FuelObject.h"
#include "FuelController.h"

FuelObject fuel(9, 0, 255, 128);
FuelController fuelController(fuel);

void setup() {
    String json = R"({"fuel": 60.0, "fuelCapacity": 100.0, "electricOn": true})";
    fuelController.update(json);
}

```

[PT-BR version](./README-PT_BR.md)