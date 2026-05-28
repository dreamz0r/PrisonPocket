# Prison Pocket

Adds a final player equipment slot named `Prison Pocket`.

By default, only `Zucchini` can be placed in the slot.

## Config

The mod creates this file during mission init:

```text
$profile:PrisonPocket/PrisonPocketConfig.json
```

Default config:

```json
{
    "ConfigVersion": 1,
    "AllowedItems": [
        "Zucchini"
    ],
    "BleedChance": 0.25
}
```

`BleedChance` is rolled every time an item is placed into or removed from the slot. Use `0.0` for no bleeding chance, `1.0` for guaranteed bleeding.

The slot declaration, slot icon, and base attach slot registration still live in `config.cpp` because DayZ needs those loaded before scripts run. Runtime options are read from the JSON config.

## Allowing More Items

Edit `AllowedItems` in `$profile:PrisonPocket/PrisonPocketConfig.json`:

```json
{
    "AllowedItems": [
        "Zucchini",
        "Apple"
    ],
    "BleedChance": 0.25
}
```

Any added item also needs the `PrisonPocket` inventory slot in its own `inventorySlot[]` config so DayZ can attach it to the player:

```cpp
class Apple: Edible_Base
{
	inventorySlot[] += {"PrisonPocket"};
};
```
