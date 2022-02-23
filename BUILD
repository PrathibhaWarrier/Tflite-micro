# Description:
#   TensorFlow Lite microcontroller example.
load("//tensorflow/lite/micro:build_def.bzl", "generate_cc_arrays")

package(
    default_visibility = ["//visibility:public"],
    # Disabling layering_check because of http://b/177257332
    features = ["-layering_check"],
    licenses = ["notice"],
)

cc_library(
    name = "simple_model_settings",
    srcs = [
        "simple_features/simple_model_settings.cc",
    ],
    hdrs = [
        "simple_features/simple_model_settings.h",
    ],
)

generate_cc_arrays(
    name = "generated_yes_1000ms_wav_cc",
    src = "testdata/yes_1000ms.wav",
    out = "testdata/yes_1000ms_audio_data.cc",
)

generate_cc_arrays(
    name = "generated_yes_1000ms_wav_hdr",
    src = "testdata/yes_1000ms.wav",
    out = "testdata/yes_1000ms_audio_data.h",
)

generate_cc_arrays(
    name = "generated_no_1000ms_wav_cc",
    src = "testdata/no_1000ms.wav",
    out = "testdata/no_1000ms_audio_data.cc",
)

generate_cc_arrays(
    name = "generated_no_1000ms_wav_hdr",
    src = "testdata/no_1000ms.wav",
    out = "testdata/no_1000ms_audio_data.h",
)

generate_cc_arrays(
    name = "generated_yes_30ms_wav_cc",
    src = "testdata/yes_30ms.wav",
    out = "testdata/yes_30ms_audio_data.cc",
)

generate_cc_arrays(
    name = "generated_yes_30ms_wav_hdr",
    src = "testdata/yes_30ms.wav",
    out = "testdata/yes_30ms_audio_data.h",
)

generate_cc_arrays(
    name = "generated_no_30ms_wav_cc",
    src = "testdata/no_30ms.wav",
    out = "testdata/no_30ms_audio_data.cc",
)

generate_cc_arrays(
    name = "generated_no_30ms_wav_hdr",
    src = "testdata/no_30ms.wav",
    out = "testdata/no_30ms_audio_data.h",
)

generate_cc_arrays(
    name = "generated_wav2letter_model_cc",
    src = "wav2letter.tflite",
    out = "wav2letter_model_data.cc",
)

generate_cc_arrays(
    name = "generated_wav2letter_model_hdr",
    src = "wav2letter.tflite",
    out = "wav2letter_model_data.h",
)

cc_library(
    name = "wav2letter_model_data",
    srcs = [
        ":generated_wav2letter_model_cc",
    ],
    hdrs = [
        ":generated_wav2letter_model_hdr",
    ],
)

cc_library(
    name = "simple_features_test_data",
    srcs = [
        "simple_features/no_simple_features_data.cc",
        "simple_features/yes_simple_features_data.cc",
    ],
    hdrs = [
        "simple_features/no_simple_features_data.h",
        "simple_features/yes_simple_features_data.h",
    ],
)

cc_test(
    name = "wav2letter_test",
    srcs = [
        "wav2letter_test.cc",
    ],
    deps = [
        ":wav2letter_model_data",
        "//tensorflow/lite/micro:micro_error_reporter",
        "//tensorflow/lite/micro:micro_framework",
        "//tensorflow/lite/micro:op_resolvers",
        "//tensorflow/lite/micro/examples/wav2letter/micro_features:micro_features_test_data",
        "//tensorflow/lite/micro/testing:micro_test",
        "//tensorflow/lite/schema:schema_fbs",
    ],
)

cc_library(
    name = "audio_sample_test_data",
    srcs = [
        ":generated_no_30ms_wav_cc",
        ":generated_yes_30ms_wav_cc",
    ],
    hdrs = [
        ":generated_no_30ms_wav_hdr",
        ":generated_yes_30ms_wav_hdr",
    ],
)

cc_library(
    name = "audio_large_sample_test_data",
    srcs = [
        ":generated_no_1000ms_wav_cc",
        ":generated_yes_1000ms_wav_cc",
    ],
    hdrs = [
        ":generated_no_1000ms_wav_hdr",
        ":generated_yes_1000ms_wav_hdr",
    ],
)

cc_library(
    name = "simple_features_generator_test_data",
    srcs = [
        "simple_features/no_power_spectrum_data.cc",
        "simple_features/yes_power_spectrum_data.cc",
    ],
    hdrs = [
        "simple_features/no_power_spectrum_data.h",
        "simple_features/yes_power_spectrum_data.h",
    ],
)

cc_library(
    name = "simple_features_generator_reference",
    srcs = [
        "simple_features/simple_features_generator.cc",
    ],
    hdrs = [
        "simple_features/simple_features_generator.h",
    ],
    deps = [
        ":simple_model_settings",
        "//tensorflow/lite/c:common",
        "//tensorflow/lite/micro:micro_error_reporter",
    ],
)

cc_test(
    name = "simple_features_generator_reference_test",
    srcs = [
        "simple_features/simple_features_generator_test.cc",
    ],
    deps = [
        ":audio_sample_test_data",
        ":simple_features_generator_reference",
        ":simple_features_generator_test_data",
        ":simple_model_settings",
        "//tensorflow/lite/c:common",
        "//tensorflow/lite/micro:micro_error_reporter",
        "//tensorflow/lite/micro:micro_framework",
        "//tensorflow/lite/micro/testing:micro_test",
    ],
)

cc_library(
    name = "simple_features_generator_fixed",
    srcs = [
        "simple_features/fixed_point/simple_features_generator.cc",
    ],
    hdrs = [
        "simple_features/simple_features_generator.h",
    ],
    deps = [
        ":simple_model_settings",
        "//tensorflow/lite/c:common",
        "//tensorflow/lite/micro:micro_error_reporter",
    ],
)

cc_test(
    name = "simple_features_generator_fixed_test",
    srcs = [
        "simple_features/simple_features_generator_test.cc",
    ],
    deps = [
        ":audio_sample_test_data",
        ":simple_features_generator_fixed",
        ":simple_features_generator_test_data",
        ":simple_model_settings",
        "//tensorflow/lite/c:common",
        "//tensorflow/lite/micro:micro_error_reporter",
        "//tensorflow/lite/micro:micro_framework",
        "//tensorflow/lite/micro/testing:micro_test",
    ],
)

cc_library(
    name = "audio_provider",
    srcs = [
        "audio_provider.cc",
    ],
    hdrs = [
        "audio_provider.h",
    ],
    deps = [
        "//tensorflow/lite/c:common",
        "//tensorflow/lite/micro:micro_error_reporter",
        "//tensorflow/lite/micro/examples/wav2letter/micro_features:micro_model_settings",
    ],
)

cc_library(
    name = "audio_provider_mock",
    srcs = [
        "audio_provider_mock.cc",
    ],
    hdrs = [
        "audio_provider.h",
    ],
    deps = [
        ":audio_large_sample_test_data",
        "//tensorflow/lite/c:common",
        "//tensorflow/lite/micro:micro_error_reporter",
        "//tensorflow/lite/micro/examples/wav2letter/micro_features:micro_model_settings",
    ],
)

cc_test(
    name = "audio_provider_test",
    srcs = [
        "audio_provider_test.cc",
    ],
    deps = [
        ":audio_provider",
        "//tensorflow/lite/c:common",
        "//tensorflow/lite/micro:micro_error_reporter",
        "//tensorflow/lite/micro:micro_framework",
        "//tensorflow/lite/micro/examples/wav2letter/micro_features:micro_model_settings",
        "//tensorflow/lite/micro/testing:micro_test",
    ],
)

cc_test(
    name = "audio_provider_mock_test",
    srcs = [
        "audio_provider_mock_test.cc",
    ],
    deps = [
        ":audio_large_sample_test_data",
        ":audio_provider_mock",
        "//tensorflow/lite/c:common",
        "//tensorflow/lite/micro:micro_error_reporter",
        "//tensorflow/lite/micro:micro_framework",
        "//tensorflow/lite/micro/examples/wav2letter/micro_features:micro_model_settings",
        "//tensorflow/lite/micro/testing:micro_test",
    ],
)

cc_library(
    name = "feature_provider",
    srcs = [
        "feature_provider.cc",
    ],
    hdrs = [
        "feature_provider.h",
    ],
    deps = [
        ":audio_provider",
        "//tensorflow/lite/c:common",
        "//tensorflow/lite/micro:micro_error_reporter",
        "//tensorflow/lite/micro/examples/wav2letter/micro_features:micro_features_generator",
        "//tensorflow/lite/micro/examples/wav2letter/micro_features:micro_model_settings",
    ],
)

cc_test(
    name = "feature_provider_test",
    srcs = [
        "feature_provider_test.cc",
    ],
    deps = [
        ":audio_provider",
        ":feature_provider",
        "//tensorflow/lite/c:common",
        "//tensorflow/lite/micro:micro_error_reporter",
        "//tensorflow/lite/micro:micro_framework",
        "//tensorflow/lite/micro/examples/wav2letter/micro_features:micro_model_settings",
        "//tensorflow/lite/micro/testing:micro_test",
    ],
)

cc_library(
    name = "feature_provider_mock",
    srcs = [
        "feature_provider.cc",
    ],
    hdrs = [
        "feature_provider.h",
    ],
    deps = [
        ":audio_provider_mock",
        "//tensorflow/lite/c:common",
        "//tensorflow/lite/micro:micro_error_reporter",
        "//tensorflow/lite/micro/examples/wav2letter/micro_features:micro_features_generator",
        "//tensorflow/lite/micro/examples/wav2letter/micro_features:micro_model_settings",
    ],
)

cc_test(
    name = "feature_provider_mock_test",
    size = "small",
    srcs = [
        "feature_provider_mock_test.cc",
    ],
    tags = [
        "noasan",  # TODO(b/179930607): Fix with asan.
    ],
    deps = [
        ":feature_provider_mock",
        "//tensorflow/lite/c:common",
        "//tensorflow/lite/micro:micro_error_reporter",
        "//tensorflow/lite/micro:micro_framework",
        "//tensorflow/lite/micro/examples/wav2letter/micro_features:micro_features_test_data",
        "//tensorflow/lite/micro/examples/wav2letter/micro_features:micro_model_settings",
        "//tensorflow/lite/micro/testing:micro_test",
    ],
)

cc_library(
    name = "recognize_commands",
    srcs = [
        "recognize_commands.cc",
    ],
    hdrs = [
        "recognize_commands.h",
    ],
    deps = [
        "//tensorflow/lite/c:common",
        "//tensorflow/lite/micro:micro_error_reporter",
        "//tensorflow/lite/micro/examples/wav2letter/micro_features:micro_model_settings",
    ],
)

cc_test(
    name = "recognize_commands_test",
    srcs = [
        "recognize_commands_test.cc",
    ],
    tags = [
        "no_oss",  # TODO(122853023): Resolve issues and re-enable.
    ],
    deps = [
        ":recognize_commands",
        "//tensorflow/lite/c:common",
        "//tensorflow/lite/micro:micro_error_reporter",
        "//tensorflow/lite/micro:micro_framework",
        "//tensorflow/lite/micro:test_helpers",
        "//tensorflow/lite/micro/testing:micro_test",
    ],
)

cc_library(
    name = "command_responder",
    srcs = [
        "command_responder.cc",
    ],
    hdrs = [
        "command_responder.h",
    ],
    deps = [
        "//tensorflow/lite/c:common",
        "//tensorflow/lite/micro:micro_error_reporter",
    ],
)

cc_test(
    name = "command_responder_test",
    srcs = [
        "command_responder_test.cc",
    ],
    deps = [
        ":command_responder",
        "//tensorflow/lite/c:common",
        "//tensorflow/lite/micro:micro_error_reporter",
        "//tensorflow/lite/micro:micro_framework",
        "//tensorflow/lite/micro/testing:micro_test",
    ],
)

cc_binary(
    name = "wav2letter",
    srcs = [
        "main.cc",
        "main_functions.cc",
        "main_functions.h",
    ],
    deps = [
        ":audio_provider",
        ":command_responder",
        ":feature_provider",
        ":micro_speech_model_data",
        ":recognize_commands",
        "//tensorflow/lite/micro:micro_error_reporter",
        "//tensorflow/lite/micro:micro_framework",
        "//tensorflow/lite/micro:op_resolvers",
        "//tensorflow/lite/micro:system_setup",
        "//tensorflow/lite/micro/examples/wav2letter/micro_features:micro_model_settings",
        "//tensorflow/lite/schema:schema_fbs",
    ],
)

cc_binary(
    name = "wav2letter_mock",
    srcs = [
        "main.cc",
        "main_functions.cc",
        "main_functions.h",
    ],
    deps = [
        ":audio_provider_mock",
        ":command_responder",
        ":feature_provider",
        ":wav2letter_model_data",
        ":recognize_commands",
        "//tensorflow/lite/micro:micro_error_reporter",
        "//tensorflow/lite/micro:micro_framework",
        "//tensorflow/lite/micro:op_resolvers",
        "//tensorflow/lite/micro:system_setup",
        "//tensorflow/lite/micro/examples/wav2letter/micro_features:micro_model_settings",
        "//tensorflow/lite/schema:schema_fbs",
    ],
)

sh_test(
    name = "wav2letter_binary_mock_test",
    srcs = ["wav2letter_binary_mock_test.sh"],
    data = [":wav2letter_mock"],
)
