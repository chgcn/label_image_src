# Description:
#   TensorFlow C++ inference example for labeling images.

package(
    default_visibility = ["//tensorflow:internal"],
)

licenses(["notice"])  # Apache 2.0

exports_files(["LICENSE"])

cc_binary(
    name = "libcnn.so",
    srcs = [
        "cnnlib.cc",
    ],
    linkopts = select({
        "//tensorflow:android": [
            "-pie",
            "-landroid",
            "-ljnigraphics",
            "-llog",
            "-lm",
            "-z defs",
            "-s",
            "-Wl,--exclude-libs,ALL",
        ],
        "//conditions:default": ["-shared","-Wl,--version-script=tensorflow/tf_version_script.lds","-lm","-s","-Wl,--exclude-libs,ALL"],
    }),
linkshared=1,
copts = ["-O3"],
    deps = select({
        "//tensorflow:android": [
            # cc:cc_ops is used to include image ops (for label_image)
            # Jpg, gif, and png related code won't be included
            "//tensorflow/cc:cc_ops",
            "//tensorflow/core:android_tensorflow_lib",
            # cc:android_tensorflow_image_op is for including jpeg/gif/png
            # decoder to enable real-image evaluation on Android
            "//tensorflow/core/kernels:android_tensorflow_image_op",
        ],
        "//conditions:default": [
            "//tensorflow/cc:cc_ops",
            #"//tensorflow/core:core_cpu",
            #"//tensorflow/core:framework",
            #"//tensorflow/core:framework_internal",
            #"//tensorflow/core:lib",
            #"//tensorflow/core:protos_all_cc",
            "//tensorflow/core:all_kernels",
	    "//tensorflow/core:direct_session",


        ],
    }),
)
filegroup(
    name = "all_files",
    srcs = glob(
        ["**/*"],
        exclude = [
            "**/METADATA",
            "**/OWNERS",
            "bin/**",
            "gen/**",
        ],
    ),
    visibility = ["//tensorflow:__subpackages__"],
)


