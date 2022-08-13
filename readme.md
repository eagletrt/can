# CAN-bus Definitions for E-Agle TRT

This repository contains the **CAN-bus** message definition for the E-Agle TRT team.
The definitions are used to **automatically generate** a C/C++/Python library which
contains serialization / deserialization and util functions.

## How can I add new messages?

Just open a PR in this repository. Once your change gets merged the library will automatically
regenerate and you can update your code accordingly.

## Ho can I include these libraries in my project?

The generated files are located in the [`build`](https://github.com/eagletrt/can/tree/build) branch.
You can just download the branch or add it as a submodule to your existing repository:

```
git submodule add -b build git@github.com:eagletrt/can.git <path>
git submodule update --remote
```

## How do I use these libraries?

The idea behind single-header file libraries is that they're easy to distribute and deploy
because all the code is contained in a single file. By default, the .h files in here act as
their own header files, i.e. they declare the functions contained in the file but don't
actually result in any code getting compiled.

So in addition, you should select _exactly one_ C/C++ source file that actually instantiates
the code, preferably a file you're not editing frequently. This file should define a
specific macro (this is documented per-library) to actually enable the function definitions.
For example, to use stb_image, you should have exactly one C/C++ file that doesn't
include stb_image.h regularly, but instead does

```c
#define primary_NETWORK_IMPLEMENTATION
#include "can/lib/primary/c/network.h"
```

The right macro to define is pointed out right at the top of each of these libraries.

## What is generating the library from this repository?

Please refer to the [canlib](https://github.com/eagletrt/canlib) readme.

## Installing and updating canutils

You can download and execute the update scripts using:

```
wget https://raw.githubusercontent.com/eagletrt/can/master/canutils/canutils_x86_64.bash
bash canutils_x86_64.bash
```

```
wget https://raw.githubusercontent.com/eagletrt/can/master/canutils/canutils_arm.bash
bash canutils_arm.bash
```
