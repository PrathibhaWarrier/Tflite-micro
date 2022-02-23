
INCLUDES += \
 -I$(MAKEFILE_DIR)/downloads/kissfft

KISSFFT_LIB_SRCS :=

KISSFFT_LIB_HDRS := \
$(MAKEFILE_DIR)/downloads/kissfft/COPYING \
$(MAKEFILE_DIR)/downloads/kissfft/kiss_fft.c \
$(MAKEFILE_DIR)/downloads/kissfft/kiss_fft.h \
$(MAKEFILE_DIR)/downloads/kissfft/_kiss_fft_guts.h \
$(MAKEFILE_DIR)/downloads/kissfft/tools/kiss_fftr.c \
$(MAKEFILE_DIR)/downloads/kissfft/tools/kiss_fftr.h


MICRO_FEATURES_LIB_SRCS := \
tensorflow/lite/experimental/microfrontend/lib/fft.cc \
tensorflow/lite/experimental/microfrontend/lib/fft_util.cc \
tensorflow/lite/experimental/microfrontend/lib/filterbank.c \
tensorflow/lite/experimental/microfrontend/lib/filterbank_util.c \
tensorflow/lite/experimental/microfrontend/lib/frontend.c \
tensorflow/lite/experimental/microfrontend/lib/frontend_util.c \
tensorflow/lite/experimental/microfrontend/lib/kiss_fft_int16.cc \
tensorflow/lite/experimental/microfrontend/lib/log_lut.c \
tensorflow/lite/experimental/microfrontend/lib/log_scale.c \
tensorflow/lite/experimental/microfrontend/lib/log_scale_util.c \
tensorflow/lite/experimental/microfrontend/lib/noise_reduction.c \
tensorflow/lite/experimental/microfrontend/lib/noise_reduction_util.c \
tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control.c \
tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control_util.c \
tensorflow/lite/experimental/microfrontend/lib/window.c \
tensorflow/lite/experimental/microfrontend/lib/window_util.c \
$(KISSFFT_LIB_SRCS)

MICRO_FEATURES_LIB_HDRS := \
tensorflow/lite/experimental/microfrontend/lib/bits.h \
tensorflow/lite/experimental/microfrontend/lib/fft.h \
tensorflow/lite/experimental/microfrontend/lib/fft_util.h \
tensorflow/lite/experimental/microfrontend/lib/filterbank.h \
tensorflow/lite/experimental/microfrontend/lib/filterbank_util.h \
tensorflow/lite/experimental/microfrontend/lib/frontend.h \
tensorflow/lite/experimental/microfrontend/lib/frontend_util.h \
tensorflow/lite/experimental/microfrontend/lib/kiss_fft_common.h \
tensorflow/lite/experimental/microfrontend/lib/kiss_fft_int16.h \
tensorflow/lite/experimental/microfrontend/lib/log_lut.h \
tensorflow/lite/experimental/microfrontend/lib/log_scale.h \
tensorflow/lite/experimental/microfrontend/lib/log_scale_util.h \
tensorflow/lite/experimental/microfrontend/lib/noise_reduction.h \
tensorflow/lite/experimental/microfrontend/lib/noise_reduction_util.h \
tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control.h \
tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control_util.h \
tensorflow/lite/experimental/microfrontend/lib/window.h \
tensorflow/lite/experimental/microfrontend/lib/window_util.h \
$(KISSFFT_LIB_HDRS)

WAV2LETTER_SRCS := \
tensorflow/lite/micro/examples/wav2letter/in_tensor_appended.cc \
tensorflow/lite/micro/examples/wav2letter/main.cc \
tensorflow/lite/micro/examples/wav2letter/main_functions.cc \
tensorflow/lite/micro/examples/wav2letter/model.cc \
tensorflow/lite/micro/examples/wav2letter/wav2letter_test.cc

$(MICRO_FEATURES_GENERATOR_SRCS)

WAV2LETTER_HDRS := \
tensorflow/lite/micro/examples/wav2letter/in_tensor_appended.h \
tensorflow/lite/micro/examples/wav2letter/model.h \
tensorflow/lite/micro/examples/wav2letter/main_functions.h \
$(MICRO_FEATURES_GENERATOR_HDRS)

WAV2LETTER_MOCK_SRCS := \
tensorflow/lite/micro/examples/wav2letter/main.cc \
tensorflow/lite/micro/examples/wav2letter/main_functions.cc \
tensorflow/lite/micro/examples/wav2letter/in_tensor_appended.cc \
$(MICRO_FEATURES_GENERATOR_SRCS)

WAV2LETTER_MOCK_HDRS := \
tensorflow/lite/micro/examples/wav2letter/in_tensor_appended.h \
tensorflow/lite/micro/examples/wav2letter/main_functions.h \
$(MICRO_FEATURES_GENERATOR_HDRS)

WAV2LETTER_GENERATOR_INPUTS := \
tensorflow/lite/micro/examples/wav2letter/wav2letter.tflite \

WAV2LETTER_GENERATED_SRCS := \
$(GENERATED_SRCS_DIR)tensorflow/lite/micro/examples/wav2letter/wav2letter_model_data.cc \

WAV2LETTER_GENERATED_HDRS := \
$(GENERATED_SRCS_DIR)tensorflow/lite/micro/examples/wav2letter/wav2letter_model_data.h \

#Find any platform - specific rules for this example.
include $(wildcard tensorflow/lite/micro/examples/wav2letter/*/Makefile.inc)

# TODO(b/161489252): Disabling warnings for this example until we have a better
# way to build third_party code with a reduced list of CFLAGS.
CCFLAGS := $(filter-out $(CC_WARNINGS),$(CCFLAGS))

# Tests loading and running a speech model.
$(eval $(call microlite_test,wav2letter_test,\
$(WAV2LETTER_SRCS),$(WAV2LETTER_HDRS)))

list_wav2letter_example_sources:
	@echo $(WAV2LETTER_SRCS)

list_wav2letter_example_headers:
	@echo $(WAV2LETTER_HDRS)

list_wav2letter_mock_example_sources:
	@echo $(WAV2LETTER_MOCK_SRCS)

list_wav2letter_mock_example_headers:
	@echo $(WAV2LETTER_MOCK_HDRS)
