# Aero

Aero is a statically typed langauge that I am working on that compiles to LLVM-IR.

## Dependencies
Download these dependencies and put them under the `external/` folder.
- https://github.com/fmtlib/fmt
- https://github.com/gabime/spdlog
- https://github.com/google/googletest

## Build
Enter the following commands to build the project
```
mkdir build
cd build
cmake ..
make all
```

## Run the Project
To run the project run the following executable (from the `build` directory)
```
src/Aero_run
```

## Testing the Project
To test the project run the following executable (from the `build` directory)
```
tests/Aero_test
```