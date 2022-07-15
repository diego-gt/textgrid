# textgrid

Simple library to print a grid / table to the console

## Build instructions

The project is being developed using `meson` and `ninja` as the build system.  
CMake support has been added, but may updated to it may lag behind the ones for `meson`.  

> A compiler with support for C++20 is required.

Current build workflow:
Setup the build directory using `meson`:
```
project_src_dir $ meson setup <build_directory>
```

For CMake, to achieve the same:
```
project_src_dir $ cmake -B <build_directory> -G Ninja
```

> You are free to use other backends but will need to adapt the project.

Now, you can build the project with:
```
# ninja -C <build_directory>
```

This will build the library as well as a demo that's meant to showcase the main abilities of the library.


## Usage
> Keep in mind that this is a beginner project and under heavy development at the moment. (2022-07-15)
Include `TextGrid.hpp` in your source code:
```cpp
#include "TextGrid.hpp"

int main() {
  TextGrid grid(2, 2);
  grid.InitializeCells('o');
  grid.Draw();

  return 0;
}
```

You can also look at the demo source code `src/main.cpp`.

## Example output
Depending on the parameters, you should see an output like this: 
2x5
```
+---------+
|x|x|x|x|x|
-----------
|x|x|x|x|x|
+---------+
```
