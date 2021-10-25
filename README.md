# textgrid

Single header library to print a grid to the console

## Build instructions

The project build system is based in `meson` and `ninja`. It supports Windows (tested with clang) and Linux (tested with gcc).

Simply, clone the repo and cd into it:
```
cd <repo>
```

Setup the build directory using `meson`:
```
meson setup <build_directory>
```

Now, you can build the project with:
```
# ninja -C <build_directory>
```
or
```
# cd <build_directory> && ninja
```

There's a demo executable that should be built along with the library.
```
# /<build_directory>/demo(.exe)
```

## Usage
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
5x5
```
+---------+
|x|x|x|x|x|
-----------
|x|x|x|x|x|
-----------
|x|x|x|x|x|
-----------
|x|x|x|x|x|
-----------
|x|x|x|x|x|
+---------+
```