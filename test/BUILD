load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "AeroLexerTest",
    srcs = glob(["syntax/lexer/**/*.cc", "syntax/lexer/**/*.h"]),
    copts = ["-Isrc", "-std=c++17"],
    deps = [
        "//src:AeroLib",
        "@googletest//:gtest_main",
    ],
)