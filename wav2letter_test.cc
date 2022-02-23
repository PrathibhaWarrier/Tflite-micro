/* Copyright 2020 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "in_tensor_appended.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "tensorflow/lite/micro/testing/micro_test.h"
#include "tensorflow/lite/schema/schema_generated.h"



TF_LITE_MICRO_TESTS_BEGIN

TF_LITE_MICRO_TEST(TestInvoke) {
  // Set up logging.
  tflite::MicroErrorReporter micro_error_reporter;

  // Map the model into a usable data structure. This doesn't involve any
  // copying or parsing, it's a very lightweight operation.
  const tflite::Model* model = ::tflite::GetModel(g_model);
  if (model->version() != TFLITE_SCHEMA_VERSION) {
    TF_LITE_REPORT_ERROR(&micro_error_reporter,
                         "Model provided is schema version %d not equal "
                         "to supported version %d.\n",
                         model->version(), TFLITE_SCHEMA_VERSION);
  }

  // Pull in only the operation implementations we need.
  // This relies on a complete list of all the ops needed by this graph.
  // An easier approach is to just use the AllOpsResolver, but this will
  // incur some penalty in code space for op implementations that are not
  // needed by this graph.
  //
  tflite::AllOpsResolver resolver;
 
  // Create an area of memory to use for input, output, and intermediate arrays.
#if defined(XTENSA)
  constexpr int tensor_arena_size = 1500 * 1024;
#else
  constexpr int tensor_arena_size = 6000 * 1024;
#endif
  uint8_t tensor_arena[tensor_arena_size];

  // Build an interpreter to run the model with.
  tflite::MicroInterpreter interpreter(model, resolver, tensor_arena,
                                       tensor_arena_size,
                                       &micro_error_reporter);
  interpreter.AllocateTensors();

  // Get information about the memory area to use for the model's input.
  TfLiteTensor* input = interpreter.input(0);

  // Make sure the input has the properties we expect.
  TF_LITE_MICRO_EXPECT_NE(nullptr, input);
  TF_LITE_MICRO_EXPECT_EQ(3, input->dims->size);
  TF_LITE_MICRO_EXPECT_EQ(1, input->dims->data[0]);
  TF_LITE_MICRO_EXPECT_EQ(296, input->dims->data[1]);
  TF_LITE_MICRO_EXPECT_EQ(39, input->dims->data[2]);
  TF_LITE_MICRO_EXPECT_EQ(kTfLiteInt8, input->type);



  // Copy a spectrogram created from a .wav audio file of someone saying "Yes",
  // into the memory area used for the input.

  const int* yes_features_data = g_in_tensor_appended;
  for (size_t i = 0; i < input->bytes/sizeof(int8_t); ++i) {
    input->data.int8[i] = yes_features_data[i];
  }

  // Run the model on this input and make sure it succeeds.
  TfLiteStatus invoke_status = interpreter.Invoke();
  if (invoke_status != kTfLiteOk) {
    TF_LITE_REPORT_ERROR(&micro_error_reporter, "Invoke failed\n");
  }
  TF_LITE_MICRO_EXPECT_EQ(kTfLiteOk, invoke_status);

  TfLiteTensor* output = interpreter.output(0); 
  TF_LITE_MICRO_EXPECT_EQ(4, output->dims->size);
  TF_LITE_MICRO_EXPECT_EQ(1, output->dims->data[0]);
  TF_LITE_MICRO_EXPECT_EQ(1, output->dims->data[1]);
  TF_LITE_MICRO_EXPECT_EQ(148, output->dims->data[2]);
  TF_LITE_MICRO_EXPECT_EQ(29, output->dims->data[3]);
  TF_LITE_MICRO_EXPECT_EQ(kTfLiteInt8, output->type);
  
  int output_array[]={};
  for(size_t i=0;i<output->bytes/sizeof(int8_t);i++)
  {
    output_array[i]=output->data.int8[i];
  
    printf("%d, ", output_array[i]);
   
  } 
  
  // FILE *fptr;
  //  // use appropriate location if you are using MacOS or Linux
  //  fptr = fopen("output.txt","a");

  //  if(fptr == NULL)
  //  {
  //     printf("Error!");   
  //     exit(1);             
  //  }
  // for (size_t count=0; count <sizeof(output_array)/sizeof(output_array[1]); count++)
  // {
  //  fprintf(fptr,"%d, ",output_array[count]);
  //  printf("%ld, ",count);

  // }fclose(fptr);
  // return;
  
   TF_LITE_REPORT_ERROR(&micro_error_reporter, "Ran successfully\n");
 }

TF_LITE_MICRO_TESTS_END
