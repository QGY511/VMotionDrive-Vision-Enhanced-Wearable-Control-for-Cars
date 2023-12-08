/* Generated by Edge Impulse
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
// Generated on: 08.11.2023 10:42:22

#include <stdio.h>
#include <stdlib.h>
#include "edge-impulse-sdk/tensorflow/lite/c/builtin_op_data.h"
#include "edge-impulse-sdk/tensorflow/lite/c/common.h"
#include "edge-impulse-sdk/tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "edge-impulse-sdk/porting/ei_classifier_porting.h"

#if EI_CLASSIFIER_PRINT_STATE
#if defined(__cplusplus) && EI_C_LINKAGE == 1
extern "C" {
    extern void ei_printf(const char *format, ...);
}
#else
extern void ei_printf(const char *format, ...);
#endif
#endif

#if defined __GNUC__
#define ALIGN(X) __attribute__((aligned(X)))
#elif defined _MSC_VER
#define ALIGN(X) __declspec(align(X))
#elif defined __TASKING__
#define ALIGN(X) __align(X)
#elif defined __ICCARM__
#define ALIGN(x) __attribute__((aligned(x)))
#endif

#ifndef EI_MAX_SCRATCH_BUFFER_COUNT
#ifndef CONFIG_IDF_TARGET_ESP32S3
#define EI_MAX_SCRATCH_BUFFER_COUNT 4
#else
#define EI_MAX_SCRATCH_BUFFER_COUNT 4
#endif // CONFIG_IDF_TARGET_ESP32S3
#endif // EI_MAX_SCRATCH_BUFFER_COUNT

#ifndef EI_MAX_OVERFLOW_BUFFER_COUNT
#define EI_MAX_OVERFLOW_BUFFER_COUNT 10
#endif // EI_MAX_OVERFLOW_BUFFER_COUNT

using namespace tflite;
using namespace tflite::ops;
using namespace tflite::ops::micro;

namespace {

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX) || defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
constexpr int kTensorArenaSize = 1408;
#else
constexpr int kTensorArenaSize = 384;
#endif

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX)
#pragma Bss(".tensor_arena")
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#pragma Bss()
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16) __attribute__((section(".tensor_arena")));
#else
#define EI_CLASSIFIER_ALLOCATION_HEAP 1
uint8_t* tensor_arena = NULL;
#endif

static uint8_t* tensor_boundary;
static uint8_t* current_location;

template <int SZ, class T> struct TfArray {
  int sz; T elem[SZ];
};
enum used_operators_e {
  OP_FULLY_CONNECTED, OP_SOFTMAX,  OP_LAST
};
struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteAllocationType allocation_type;
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  size_t bytes;
  TfLiteQuantization quantization;
};
struct NodeInfo_t { // subset of TfLiteNode used for initialization from constant memory
  struct TfLiteIntArray* inputs;
  struct TfLiteIntArray* outputs;
  void* builtin_data;
  used_operators_e used_op_index;
};

typedef struct {
  TfLiteTensor tensor;
  int16_t index;
} TfLiteTensorWithIndex;

typedef struct {
  TfLiteEvalTensor tensor;
  int16_t index;
} TfLiteEvalTensorWithIndex;

TfLiteContext ctx{};
static const int MAX_TFL_TENSOR_COUNT = 4;
static TfLiteTensorWithIndex tflTensors[MAX_TFL_TENSOR_COUNT];
static const int MAX_TFL_EVAL_COUNT = 4;
static TfLiteEvalTensorWithIndex tflEvalTensors[MAX_TFL_EVAL_COUNT];
TfLiteRegistration registrations[OP_LAST];
TfLiteNode tflNodes[4];

const TfArray<2, int> tensor_dimension0 = { 2, { 1,39 } };
const TfArray<1, float> quant0_scale = { 1, { 0.13220690190792084, } };
const TfArray<1, int> quant0_zero = { 1, { -89 } };
const TfLiteAffineQuantization quant0 = { (TfLiteFloatArray*)&quant0_scale, (TfLiteIntArray*)&quant0_zero, 0 };
const ALIGN(16) int32_t tensor_data1[4] = { -143, 58, -18, 104, };
const TfArray<1, int> tensor_dimension1 = { 1, { 4 } };
const TfArray<1, float> quant1_scale = { 1, { 0.00051344919484108686, } };
const TfArray<1, int> quant1_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant1 = { (TfLiteFloatArray*)&quant1_scale, (TfLiteIntArray*)&quant1_zero, 0 };
const ALIGN(16) int8_t tensor_data2[4*10] = { 
  72, 55, 81, -32, -1, -117, -127, -23, 115, 49, 
  60, -19, -110, -121, -87, -44, -16, 30, -68, 32, 
  -96, 86, -118, -96, 64, -95, 91, 54, 53, -74, 
  -9, -16, 45, 65, 45, -27, 94, -30, -74, -116, 
};
const TfArray<2, int> tensor_dimension2 = { 2, { 4,10 } };
const TfArray<1, float> quant2_scale = { 1, { 0.0063427966088056564, } };
const TfArray<1, int> quant2_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant2 = { (TfLiteFloatArray*)&quant2_scale, (TfLiteIntArray*)&quant2_zero, 0 };
const ALIGN(16) int32_t tensor_data3[10] = { -50, -40, 324, 104, 235, 245, 161, -4, -169, -70, };
const TfArray<1, int> tensor_dimension3 = { 1, { 10 } };
const TfArray<1, float> quant3_scale = { 1, { 0.00043304020073264837, } };
const TfArray<1, int> quant3_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant3 = { (TfLiteFloatArray*)&quant3_scale, (TfLiteIntArray*)&quant3_zero, 0 };
const ALIGN(16) int8_t tensor_data4[10*20] = { 
  32, -65, -47, -2, 108, 22, 95, -62, -2, -54, -8, 21, 63, 93, 69, -97, 8, -4, -76, -13, 
  -43, -98, 51, 53, 47, -30, -46, -83, -76, 12, -42, -47, 49, 19, 58, 76, -38, 26, -35, -24, 
  -9, -60, 31, 58, 27, 2, -29, -3, -41, 14, 46, 55, -23, -60, -10, -69, 82, -82, -55, -57, 
  68, 16, 87, -19, -32, 76, -56, -56, -33, 97, 103, 50, -66, -78, -20, -69, -22, -61, 73, 32, 
  -22, 51, -78, -39, -45, 80, -24, -18, -75, 99, 97, 47, -20, 56, -8, -37, -29, 62, 92, 82, 
  -70, 76, -36, 90, -50, -93, 13, 127, -106, -20, 85, 69, -51, 39, -1, -55, 33, 67, -74, -22, 
  93, 47, -56, -34, 41, 48, 3, -37, -34, 29, 78, 27, -81, -17, -25, 20, 62, -34, 19, -11, 
  -30, 76, 34, 78, -33, 61, 82, -69, 102, -47, -56, 90, 58, -19, -72, 82, 93, 19, 32, 107, 
  50, 24, 46, 5, 109, 44, -83, -58, -5, 18, 62, 19, 15, -86, -27, 86, -121, 52, -33, -27, 
  12, -62, -3, -20, 96, 101, -8, 22, 76, -74, -65, 51, -37, -59, 72, -34, -9, 95, -17, 46, 
};
const TfArray<2, int> tensor_dimension4 = { 2, { 10,20 } };
const TfArray<1, float> quant4_scale = { 1, { 0.0046415608376264572, } };
const TfArray<1, int> quant4_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant4 = { (TfLiteFloatArray*)&quant4_scale, (TfLiteIntArray*)&quant4_zero, 0 };
const ALIGN(16) int32_t tensor_data5[20] = { -66, 60, -103, -75, -146, -4, 36, 18, -107, 296, 280, 237, -70, 7, -90, 70, 275, -57, 44, 66, };
const TfArray<1, int> tensor_dimension5 = { 1, { 20 } };
const TfArray<1, float> quant5_scale = { 1, { 0.00052126141963526607, } };
const TfArray<1, int> quant5_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant5 = { (TfLiteFloatArray*)&quant5_scale, (TfLiteIntArray*)&quant5_zero, 0 };
const ALIGN(16) int8_t tensor_data6[20*39] = { 
  -14, -27, -19, 66, 47, 47, 11, -53, 29, -72, -4, 31, -74, -63, -22, 62, 25, 87, -50, -47, 66, -25, 63, 16, -76, 51, -46, -34, -65, -65, 43, 11, 35, -71, -73, 39, -45, 66, 0, 
  -88, 39, 43, 9, -14, 0, 21, 11, 38, 89, -30, 47, 16, 5, 55, -62, 72, 66, 82, -43, -17, -19, 48, -32, 23, 27, -16, 68, 5, -60, -44, 76, 75, 82, 58, -22, -62, -7, 22, 
  42, -56, -39, -80, 10, -53, 41, 70, 64, -23, -73, 5, -60, 33, -29, 91, 1, 11, -11, 26, 81, -63, 57, -50, 20, -13, 80, 23, -71, -72, -13, 41, 30, -63, -18, -31, -73, -10, 39, 
  -57, 11, -53, 39, -13, 55, -9, 79, 36, -67, 64, 65, 48, 64, 19, -29, -68, -34, 23, 44, -53, 33, -41, -15, 67, 56, -57, 35, 55, 43, -29, 27, 59, -42, 42, 4, 74, -78, 15, 
  69, -32, 14, -69, -80, -53, 57, -21, -53, 21, -44, 11, -39, -21, -74, 42, 28, 49, -9, -19, -2, 95, 13, 15, -1, 23, 66, 25, -105, -83, 31, -65, 63, -62, -31, -45, -22, -66, 20, 
  -35, 25, 23, -19, -55, -73, 0, 76, -40, 1, -88, -36, -74, 38, 28, 28, -74, 35, -23, 14, -52, -43, 14, -22, 67, -16, 35, -37, -49, 73, -23, -10, 67, -39, 28, -70, 62, -37, 38, 
  60, -14, -48, -20, -24, -54, -12, 68, -14, 19, 3, 1, 0, 61, 2, -54, -16, -13, 90, 66, -38, 8, -36, 52, -24, -1, 74, -50, 64, 31, 53, -66, 4, -13, -68, 47, -71, 33, -63, 
  64, -58, 14, 76, 81, 32, 29, 35, -20, 76, -10, 80, -31, 38, -65, -127, -20, -45, -50, 75, 63, -65, -54, -7, -17, 78, -29, 22, -27, -3, 20, 78, 18, -72, -34, -75, -14, 20, 54, 
  50, 25, 39, -29, -64, 61, -18, -58, -14, -21, 1, 59, 57, -3, -7, -54, 29, -1, 82, 19, 73, 58, 87, 51, 79, 80, 55, -52, 78, -90, 7, -87, -15, -5, -72, -28, -65, 78, -48, 
  -65, 105, -40, 22, -60, 35, -50, 25, -14, -44, -30, -37, -68, -36, -1, 101, 13, 10, 70, -30, 4, 62, 5, 60, 53, 33, 30, 72, 15, 77, -24, 10, -30, 27, 89, 54, 72, 75, 9, 
  91, 72, 55, -36, -54, -21, 76, 46, 23, 49, -40, 27, 23, -67, 85, -2, 24, -39, 50, 41, -39, 67, -61, 74, 58, -26, -7, 29, 43, 96, -50, -27, -34, 14, 114, 103, 1, -43, -41, 
  16, 33, 83, 9, -49, -47, 108, -2, 81, -3, 80, 80, 66, 92, -1, 65, -2, -18, 98, 27, 11, 16, 107, 31, 42, 45, 82, 67, 77, 64, 12, 15, 30, -5, 50, 12, -30, 44, 48, 
  -22, -120, 1, -40, 39, -48, -49, -84, -68, 36, -15, -60, 33, 71, -52, 35, 15, 4, 76, -16, 41, 53, -34, 65, 67, 1, 12, -83, 59, -36, -55, 13, -78, 71, 46, 47, 71, -42, -60, 
  12, -71, -41, -11, 59, 59, -77, 73, -7, 21, 15, 17, 72, 12, 15, -71, -86, -23, -72, -38, -67, -61, -6, -30, -35, -82, -57, 76, -22, -5, 7, -85, -70, -77, -14, 16, 35, -12, 57, 
  83, -115, -22, 16, 3, -29, -29, 43, 38, 13, 63, -84, -67, 86, -87, -9, -83, -11, 48, -64, 75, 94, -18, 82, -50, -28, -11, -57, 30, -25, 106, -45, -42, 45, -16, -54, -63, 20, 63, 
  -5, 120, -60, -104, -102, 17, -10, -3, 40, 58, 41, 70, -6, 53, 38, 38, 31, 77, 45, 71, -60, 76, -60, 41, 25, 21, -17, -69, 1, -62, -32, -23, -10, 63, 14, 34, 24, -47, 44, 
  38, -9, -33, 45, 109, -4, -5, -43, 50, -50, -66, -35, 1, 61, -19, 2, -22, -5, 49, -21, -72, -66, 10, -56, 16, -42, -2, 73, 7, 92, 14, 25, 81, -36, -15, -36, 29, -70, -33, 
  -11, 4, 66, 35, 31, -14, -38, 57, 21, -17, -30, 86, -19, 83, -69, -37, -56, 51, 86, -27, 58, -10, -32, 103, -17, -36, -24, -16, 5, -63, -40, -65, 10, 30, 14, 84, 91, -21, 72, 
  -65, -38, 70, -68, 61, -5, -55, -5, -9, -30, -80, -38, -74, -54, -73, -43, 15, -36, -55, 16, -49, 56, -53, 56, -47, -80, 10, -49, -50, -42, 55, -28, -48, -77, 87, 65, 22, -52, -62, 
  -2, 79, 10, -31, -5, -48, 17, -13, 47, 50, -76, 49, 50, -4, 10, -38, 6, -66, -59, 3, -47, -89, 49, -77, -17, -9, -62, -39, 29, 73, -60, 10, 61, -61, -7, 12, -87, 0, -12, 
};
const TfArray<2, int> tensor_dimension6 = { 2, { 20,39 } };
const TfArray<1, float> quant6_scale = { 1, { 0.0039427699521183968, } };
const TfArray<1, int> quant6_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant6 = { (TfLiteFloatArray*)&quant6_scale, (TfLiteIntArray*)&quant6_zero, 0 };
const TfArray<2, int> tensor_dimension7 = { 2, { 1,20 } };
const TfArray<1, float> quant7_scale = { 1, { 0.093296244740486145, } };
const TfArray<1, int> quant7_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant7 = { (TfLiteFloatArray*)&quant7_scale, (TfLiteIntArray*)&quant7_zero, 0 };
const TfArray<2, int> tensor_dimension8 = { 2, { 1,10 } };
const TfArray<1, float> quant8_scale = { 1, { 0.080949969589710236, } };
const TfArray<1, int> quant8_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant8 = { (TfLiteFloatArray*)&quant8_scale, (TfLiteIntArray*)&quant8_zero, 0 };
const TfArray<2, int> tensor_dimension9 = { 2, { 1,4 } };
const TfArray<1, float> quant9_scale = { 1, { 0.1056942492723465, } };
const TfArray<1, int> quant9_zero = { 1, { 68 } };
const TfLiteAffineQuantization quant9 = { (TfLiteFloatArray*)&quant9_scale, (TfLiteIntArray*)&quant9_zero, 0 };
const TfArray<2, int> tensor_dimension10 = { 2, { 1,4 } };
const TfArray<1, float> quant10_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant10_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant10 = { (TfLiteFloatArray*)&quant10_scale, (TfLiteIntArray*)&quant10_zero, 0 };
const TfLiteFullyConnectedParams opdata0 = { kTfLiteActRelu, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs0 = { 3, { 0,6,5 } };
const TfArray<1, int> outputs0 = { 1, { 7 } };
const TfLiteFullyConnectedParams opdata1 = { kTfLiteActRelu, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs1 = { 3, { 7,4,3 } };
const TfArray<1, int> outputs1 = { 1, { 8 } };
const TfLiteFullyConnectedParams opdata2 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs2 = { 3, { 8,2,1 } };
const TfArray<1, int> outputs2 = { 1, { 9 } };
const TfLiteSoftmaxParams opdata3 = { 1 };
const TfArray<1, int> inputs3 = { 1, { 9 } };
const TfArray<1, int> outputs3 = { 1, { 10 } };
const TensorInfo_t tensorData[] = {
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension0, 39, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant0))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data1, (TfLiteIntArray*)&tensor_dimension1, 16, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant1))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data2, (TfLiteIntArray*)&tensor_dimension2, 40, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant2))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data3, (TfLiteIntArray*)&tensor_dimension3, 40, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant3))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data4, (TfLiteIntArray*)&tensor_dimension4, 200, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant4))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data5, (TfLiteIntArray*)&tensor_dimension5, 80, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant5))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data6, (TfLiteIntArray*)&tensor_dimension6, 780, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant6))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 48, (TfLiteIntArray*)&tensor_dimension7, 20, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant7))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension8, 10, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant8))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 16, (TfLiteIntArray*)&tensor_dimension9, 4, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant9))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension10, 4, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant10))}, },
};const NodeInfo_t nodeData[] = {
  { (TfLiteIntArray*)&inputs0, (TfLiteIntArray*)&outputs0, const_cast<void*>(static_cast<const void*>(&opdata0)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs1, (TfLiteIntArray*)&outputs1, const_cast<void*>(static_cast<const void*>(&opdata1)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs2, (TfLiteIntArray*)&outputs2, const_cast<void*>(static_cast<const void*>(&opdata2)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs3, (TfLiteIntArray*)&outputs3, const_cast<void*>(static_cast<const void*>(&opdata3)), OP_SOFTMAX, },
};

static void init_tflite_tensor(size_t i, TfLiteTensor *tensor) {
  tensor->type = tensorData[i].type;
  tensor->is_variable = 0;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
  tensor->allocation_type = tensorData[i].allocation_type;
#else
  tensor->allocation_type = (tensor_arena <= tensorData[i].data && tensorData[i].data < tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
#endif
  tensor->bytes = tensorData[i].bytes;
  tensor->dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
  if(tensor->allocation_type == kTfLiteArenaRw){
    uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

    tensor->data.data =  start;
  }
  else {
      tensor->data.data = tensorData[i].data;
  }
#else
  tensor->data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
  tensor->quantization = tensorData[i].quantization;
  if (tensor->quantization.type == kTfLiteAffineQuantization) {
    TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensorData[i].quantization.params));
    tensor->params.scale = quant->scale->data[0];
    tensor->params.zero_point = quant->zero_point->data[0];
  }

}

static void init_tflite_eval_tensor(int i, TfLiteEvalTensor *tensor) {

  tensor->type = tensorData[i].type;

  tensor->dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
  auto allocation_type = tensorData[i].allocation_type;
  if(allocation_type == kTfLiteArenaRw) {
    uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

    tensor->data.data =  start;
  }
  else {
    tensor->data.data = tensorData[i].data;
  }
#else
  tensor->data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
}

static void* overflow_buffers[EI_MAX_OVERFLOW_BUFFER_COUNT];
static size_t overflow_buffers_ix = 0;
static void * AllocatePersistentBufferImpl(struct TfLiteContext* ctx,
                                       size_t bytes) {
  void *ptr;
  uint32_t align_bytes = (bytes % 16) ? 16 - (bytes % 16) : 0;

  if (current_location - (bytes + align_bytes) < tensor_boundary) {
    if (overflow_buffers_ix > EI_MAX_OVERFLOW_BUFFER_COUNT - 1) {
      ei_printf("ERR: Failed to allocate persistent buffer of size %d, does not fit in tensor arena and reached EI_MAX_OVERFLOW_BUFFER_COUNT\n",
        (int)bytes);
      return NULL;
    }

    // OK, this will look super weird, but.... we have CMSIS-NN buffers which
    // we cannot calculate beforehand easily.
    ptr = ei_calloc(bytes, 1);
    if (ptr == NULL) {
      ei_printf("ERR: Failed to allocate persistent buffer of size %d\n", (int)bytes);
      return NULL;
    }
    overflow_buffers[overflow_buffers_ix++] = ptr;
    return ptr;
  }

  current_location -= bytes;

  // align to the left aligned boundary of 16 bytes
  current_location -= 15; // for alignment
  current_location += 16 - ((uintptr_t)(current_location) & 15);

  ptr = current_location;
  memset(ptr, 0, bytes);

  return ptr;
}
typedef struct {
  size_t bytes;
  void *ptr;
} scratch_buffer_t;
static scratch_buffer_t scratch_buffers[EI_MAX_SCRATCH_BUFFER_COUNT];
static size_t scratch_buffers_ix = 0;

static TfLiteStatus RequestScratchBufferInArenaImpl(struct TfLiteContext* ctx, size_t bytes,
                                                int* buffer_idx) {
  if (scratch_buffers_ix > EI_MAX_SCRATCH_BUFFER_COUNT - 1) {
    ei_printf("ERR: Failed to allocate scratch buffer of size %d, reached EI_MAX_SCRATCH_BUFFER_COUNT\n",
      (int)bytes);
    return kTfLiteError;
  }

  scratch_buffer_t b;
  b.bytes = bytes;

  b.ptr = AllocatePersistentBufferImpl(ctx, b.bytes);
  if (!b.ptr) {
    ei_printf("ERR: Failed to allocate scratch buffer of size %d\n",
      (int)bytes);
    return kTfLiteError;
  }

  scratch_buffers[scratch_buffers_ix] = b;
  *buffer_idx = scratch_buffers_ix;

  scratch_buffers_ix++;

  return kTfLiteOk;
}

static void* GetScratchBufferImpl(struct TfLiteContext* ctx, int buffer_idx) {
  if (buffer_idx > (int)scratch_buffers_ix) {
    return NULL;
  }
  return scratch_buffers[buffer_idx].ptr;
}

static const uint16_t TENSOR_IX_UNUSED = 0x7FFF;

static void ResetTensors() {
  for (size_t ix = 0; ix < MAX_TFL_TENSOR_COUNT; ix++) {
    tflTensors[ix].index = TENSOR_IX_UNUSED;
  }
  for (size_t ix = 0; ix < MAX_TFL_EVAL_COUNT; ix++) {
    tflEvalTensors[ix].index = TENSOR_IX_UNUSED;
  }
}

static TfLiteTensor* GetTensorImpl(const struct TfLiteContext* context,
                               int tensor_idx) {

  for (size_t ix = 0; ix < MAX_TFL_TENSOR_COUNT; ix++) {
    // already used? OK!
    if (tflTensors[ix].index == tensor_idx) {
      return &tflTensors[ix].tensor;
    }
    // passed all the ones we've used, so end of the list?
    if (tflTensors[ix].index == TENSOR_IX_UNUSED) {
      // init the tensor
      init_tflite_tensor(tensor_idx, &tflTensors[ix].tensor);
      tflTensors[ix].index = tensor_idx;
      return &tflTensors[ix].tensor;
    }
  }

  ei_printf("ERR: GetTensor called beyond MAX_TFL_TENSOR_COUNT (%d)\n", MAX_TFL_TENSOR_COUNT);
  return nullptr;
}

static TfLiteEvalTensor* GetEvalTensorImpl(const struct TfLiteContext* context,
                                       int tensor_idx) {

  for (size_t ix = 0; ix < MAX_TFL_EVAL_COUNT; ix++) {
    // already used? OK!
    if (tflEvalTensors[ix].index == tensor_idx) {
      return &tflEvalTensors[ix].tensor;
    }
    // passed all the ones we've used, so end of the list?
    if (tflEvalTensors[ix].index == TENSOR_IX_UNUSED) {
      // init the tensor
      init_tflite_eval_tensor(tensor_idx, &tflEvalTensors[ix].tensor);
      tflEvalTensors[ix].index = tensor_idx;
      return &tflEvalTensors[ix].tensor;
    }
  }

  ei_printf("ERR: GetTensor called beyond MAX_TFL_EVAL_COUNT (%d)\n", (int)MAX_TFL_EVAL_COUNT);
  return nullptr;
}

class EonMicroContext : public MicroContext {
 public:
  EonMicroContext(): MicroContext(nullptr, nullptr, nullptr) { }

  void* AllocatePersistentBuffer(size_t bytes) {
    return AllocatePersistentBufferImpl(nullptr, bytes);
  };
  TfLiteStatus RequestScratchBufferInArena(size_t bytes,
                                           int* buffer_index) {
  return RequestScratchBufferInArenaImpl(nullptr, bytes, buffer_index);
  }
  void* GetScratchBuffer(int buffer_index) {
    return GetScratchBufferImpl(nullptr, buffer_index);
  }

  TfLiteTensor* AllocateTempTfLiteTensor(int tensor_index) {
    return GetTensorImpl(nullptr, tensor_index);
  }
  void DeallocateTempTfLiteTensor(TfLiteTensor* tensor) {
    return;
  }
  bool IsAllTempTfLiteTensorDeallocated() {
    return true;
  }

  TfLiteEvalTensor* GetEvalTensor(int tensor_index) {
    return GetEvalTensorImpl(nullptr, tensor_index);
  }
};

} // namespace

TfLiteStatus tflite_learn_7_init( void*(*alloc_fnc)(size_t,size_t) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  tensor_arena = (uint8_t*) alloc_fnc(16, kTensorArenaSize);
  if (!tensor_arena) {
    ei_printf("ERR: failed to allocate tensor arena\n");
    return kTfLiteError;
  }
#else
  memset(tensor_arena, 0, kTensorArenaSize);
#endif
  tensor_boundary = tensor_arena;
  current_location = tensor_arena + kTensorArenaSize;

  EonMicroContext micro_context_;
  ctx.impl_ = static_cast<void*>(&micro_context_);
  ctx.AllocatePersistentBuffer = &AllocatePersistentBufferImpl;
  ctx.RequestScratchBufferInArena = &RequestScratchBufferInArenaImpl;
  ctx.GetScratchBuffer = &GetScratchBufferImpl;
  ctx.GetTensor = &GetTensorImpl;
  ctx.GetEvalTensor = &GetEvalTensorImpl;
  ctx.tensors_size = 11;
  for (size_t i = 0; i < 11; ++i) {
    TfLiteTensor tensor;
    init_tflite_tensor(i, &tensor);
    if (tensor.allocation_type == kTfLiteArenaRw) {
      auto data_end_ptr = (uint8_t*)tensor.data.data + tensorData[i].bytes;
      if (data_end_ptr > tensor_boundary) {
        tensor_boundary = data_end_ptr;
      }
    }
  }
  if (tensor_boundary > current_location /* end of arena size */) {
    ei_printf("ERR: tensor arena is too small, does not fit model - even without scratch buffers\n");
    return kTfLiteError;
  }
  registrations[OP_FULLY_CONNECTED] = Register_FULLY_CONNECTED();
  registrations[OP_SOFTMAX] = Register_SOFTMAX();

  for (size_t i = 0; i < 4; ++i) {
    tflNodes[i].inputs = nodeData[i].inputs;
    tflNodes[i].outputs = nodeData[i].outputs;
    tflNodes[i].builtin_data = nodeData[i].builtin_data;
tflNodes[i].custom_initial_data = nullptr;
      tflNodes[i].custom_initial_data_size = 0;
if (registrations[nodeData[i].used_op_index].init) {
      tflNodes[i].user_data = registrations[nodeData[i].used_op_index].init(&ctx, (const char*)tflNodes[i].builtin_data, 0);
    }
  }
  for (size_t i = 0; i < 4; ++i) {
    if (registrations[nodeData[i].used_op_index].prepare) {
      ResetTensors();

      TfLiteStatus status = registrations[nodeData[i].used_op_index].prepare(&ctx, &tflNodes[i]);
      if (status != kTfLiteOk) {
        return status;
      }
    }
  }
  return kTfLiteOk;
}

static const int inTensorIndices[] = {
  0, 
};
TfLiteStatus tflite_learn_7_input(int index, TfLiteTensor *tensor) {
  init_tflite_tensor(inTensorIndices[index], tensor);
  return kTfLiteOk;
}

static const int outTensorIndices[] = {
  10, 
};
TfLiteStatus tflite_learn_7_output(int index, TfLiteTensor *tensor) {
  init_tflite_tensor(outTensorIndices[index], tensor);
  return kTfLiteOk;
}

TfLiteStatus tflite_learn_7_invoke() {
  for (size_t i = 0; i < 4; ++i) {
    ResetTensors();

    TfLiteStatus status = registrations[nodeData[i].used_op_index].invoke(&ctx, &tflNodes[i]);

#if EI_CLASSIFIER_PRINT_STATE
    ei_printf("layer %lu\n", i);
    ei_printf("    inputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].inputs->size; ix++) {
      auto d = tensorData[tflNodes[i].inputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");

    ei_printf("    outputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].outputs->size; ix++) {
      auto d = tensorData[tflNodes[i].outputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");
#endif // EI_CLASSIFIER_PRINT_STATE

    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}

TfLiteStatus tflite_learn_7_reset( void (*free_fnc)(void* ptr) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  free_fnc(tensor_arena);
#endif

  // scratch buffers are allocated within the arena, so just reset the counter so memory can be reused
  scratch_buffers_ix = 0;

  // overflow buffers are on the heap, so free them first
  for (size_t ix = 0; ix < overflow_buffers_ix; ix++) {
    ei_free(overflow_buffers[ix]);
  }
  overflow_buffers_ix = 0;
  return kTfLiteOk;
}