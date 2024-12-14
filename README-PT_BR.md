# FuelController

## **Descrição**
Este projeto contém duas classes para controlar o comportamento de combustível usando PWM:
- **FuelObject**: Armazena informações sobre pino, valores PWM e estado atual.
- **FuelController**: Gerencia o estado do combustível com base em entradas JSON.

## **Como Usar**

### 1. Inicializar o `FuelObject`
```cpp
FuelObject fuel(pin, minPWM, maxPWM, estadoInicial);
```
- `pin`: Número do pino de saída.
- `minPWM`: Valor PWM mínimo.
- `maxPWM`: Valor PWM máximo.
- `estadoInicial`: Estado inicial do combustível.

### 2. Inicializar o `FuelController`
```cpp
FuelController controller(fuelObject);
```

### 3. Atualizar o estado do combustível
```cpp
controller.update(jsonString);
```
- `jsonString`: String JSON contendo informações como `fuel`, `fuelCapacity`, `electricOn`.

## **Exemplo**

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

[EN version](./README.md)