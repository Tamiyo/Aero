# Aero

WIP Programming Language in C++

## Built with Bazel
Build with [Bazel](https://github.com/bazelbuild/bazel). Find out [more](https://www.bazel.build/).

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
