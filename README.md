# Meinkraft

Meinkraft is a Minecraft-like rendering project made to experiment with the ~~Nvidia extensions that Vulkanize OpenGL~~ modern GL commands made to accelerate drawcalls.<br/>
This is a full C++ rewrite of my original C# Meinkraft project.

## Controls

* ZQSD : Movements
* Shift : Faster movements
* Ctrl : Slower movements

## Build

### Requirements:

- CMake 3.28+
- Ninja
- MSVC

### Steps:

```bash
# To build (required)
cmake --preset Release
cmake --build --preset Release --target Meinkraft

# To install (optional)
cmake --build --preset Release --target install
```

## License

This work by [Cyphall](https://github.com/Cyphall) is licensed under [CC BY-NC-SA 4.0](https://creativecommons.org/licenses/by-nc-sa/4.0).
