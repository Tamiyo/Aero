load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "AeroLib",
    srcs = glob(
        include = ["**/*.cc"],
        exclude = ["main.cc"],
    ),
    hdrs = glob(["**/*.h"]),
    copts = [
        "-Isrc",
        "-std=c++17",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@fmt//:fmtlib",
        "@magic_enum",
        "@spdlog//:spdlog",
    ],
    alwayslink = True,
)

cc_binary(
    name = "Aero",
    srcs = ["main.cc"],
    deps = [
        ":AeroLib",
    ],
)
