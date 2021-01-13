# Aero

WIP Programming Language in C++ <br>
This is primarly a project I work on in my free time to get experience with Modern C++ and Compilers. <br>
Any content is subject to change at any time. <br>
Docs will be added once signifigant progress has been made.

## Built with Bazel
Built with [Bazel](https://github.com/bazelbuild/bazel). Find out [more](https://www.bazel.build/).

## Pipeline
### Build All
```
bazel build //...
```

### Build Source
```
bazel build //src:Aero
```

### Build & Run Source
```
bazel run //src:Aero
```

### Build & Run Tests
```
bazel test //...
```

## Stylistic Choices
Strictly following the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) for consistency reasons.
