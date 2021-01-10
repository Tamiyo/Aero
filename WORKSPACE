load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "magic_enum",
    strip_prefix = "magic_enum-806f2530efb7fea18116a0f8bb3e0b5079a6f27f",
    urls = ["https://github.com/Neargye/magic_enum/archive/806f2530efb7fea18116a0f8bb3e0b5079a6f27f.zip"],
)

http_archive(
    name = "googletest",
    sha256 = "7897bfaa5ad39a479177cfb5c3ce010184dbaee22a7c3727b212282871918751",
    strip_prefix = "googletest-a4ab0abb93620ce26efad9de9296b73b16e88588",
    urls = ["https://github.com/google/googletest/archive/a4ab0abb93620ce26efad9de9296b73b16e88588.tar.gz"],
)

FMT_BUILD = """
load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "fmtlib",
    hdrs = glob([
        "include/fmt/*.h",
    ]),
    defines = ["FMT_HEADER_ONLY"],
    includes = ["include"],
    visibility = ["//visibility:public"],
)
"""

http_archive(
    name = "fmt",
    build_file_content = FMT_BUILD,
    sha256 = "decfdf9ad274070fa85f26407b816f5a4d82205ae86bac1990be658d0795ea4d",
    strip_prefix = "fmt-7.0.3",
    urls = ["https://github.com/fmtlib/fmt/releases/download/7.0.3/fmt-7.0.3.zip"],
)

SPDLOG_BUILD = """
load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "spdlog",
    hdrs = glob([
        "include/**/*.h",
    ]),
    defines = ["SPDLOG_FMT_EXTERNAL"],
    includes = ["include"],
    visibility = ["//visibility:public"],
    deps = ["@fmt//:fmtlib"],
)
"""

http_archive(
    name = "spdlog",
    build_file_content = SPDLOG_BUILD,
    sha256 = "f0114a4d3c88be9e696762f37a7c379619443ce9d668546c61b21d41affe5b62",
    strip_prefix = "spdlog-1.7.0",
    urls = ["https://github.com/gabime/spdlog/archive/v1.7.0.tar.gz"],
)