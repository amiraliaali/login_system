cc_binary(
    name = "main",
    srcs = ["scripts/sources/main.cpp"],
    deps = [":system"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "user",
    srcs = ["scripts/sources/user.cpp"],
    hdrs = ["scripts/headers/user.hpp"],
    includes = ["scripts/headers/"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "system",
    srcs = ["scripts/sources/system.cpp"],
    hdrs = ["scripts/headers/system.hpp"],
    includes = ["scripts/headers/"],
    deps = [":user"],
    visibility = ["//visibility:public"],
)