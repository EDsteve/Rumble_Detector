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
// Generated on: 14.02.2023 02:34:58

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
#endif

#ifndef EI_MAX_SCRATCH_BUFFER_COUNT
#define EI_MAX_SCRATCH_BUFFER_COUNT 4
#endif // EI_MAX_SCRATCH_BUFFER_COUNT

#ifndef EI_MAX_OVERFLOW_BUFFER_COUNT
#define EI_MAX_OVERFLOW_BUFFER_COUNT 10
#endif // EI_MAX_OVERFLOW_BUFFER_COUNT

using namespace tflite;
using namespace tflite::ops;
using namespace tflite::ops::micro;

namespace {

constexpr int kTensorArenaSize = 9040;

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
  OP_RESHAPE, OP_CONV_2D, OP_MAX_POOL_2D, OP_FULLY_CONNECTED, OP_SOFTMAX,  OP_LAST
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

TfLiteContext ctx{};
TfLiteTensor tflTensors[23];
TfLiteEvalTensor tflEvalTensors[23];
TfLiteRegistration registrations[OP_LAST];
TfLiteNode tflNodes[11];

const TfArray<2, int> tensor_dimension0 = { 2, { 1,3960 } };
const TfArray<1, float> quant0_scale = { 1, { 0.0035998774692416191, } };
const TfArray<1, int> quant0_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant0 = { (TfLiteFloatArray*)&quant0_scale, (TfLiteIntArray*)&quant0_zero, 0 };
const ALIGN(16) int32_t tensor_data1[4] = { 1, 1, 99, 40, };
const TfArray<1, int> tensor_dimension1 = { 1, { 4 } };
const ALIGN(16) int32_t tensor_data2[4] = { 1, 99, 1, 8, };
const TfArray<1, int> tensor_dimension2 = { 1, { 4 } };
const ALIGN(16) int32_t tensor_data3[4] = { 1, 1, 50, 8, };
const TfArray<1, int> tensor_dimension3 = { 1, { 4 } };
const ALIGN(16) int32_t tensor_data4[4] = { 1, 50, 1, 16, };
const TfArray<1, int> tensor_dimension4 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data5[2] = { -1, 400, };
const TfArray<1, int> tensor_dimension5 = { 1, { 2 } };
const ALIGN(16) int8_t tensor_data6[8*1*3*40] = { 
  /* [0][0][][] */ 14,35,2,-8,-4,74,52,59,124,-16,-4,-46,26,3,-11,-39,-26,-14,-62,-47,-22,75,-4,22,-17,-42,-109,-62,-80,-92,-78,-43,-63,-5,-10,-41,-97,-59,-118,-93, 76,13,29,-14,-2,74,90,41,116,11,44,-22,-28,-34,-1,18,-9,-23,-55,-75,6,46,12,9,-63,-102,-97,-93,-38,-51,-56,-7,3,0,-47,-67,-66,-21,-127,-89, 42,-7,3,9,18,87,86,72,84,-1,1,20,18,21,2,-1,-4,-39,-54,-25,20,64,-12,7,-57,-62,-82,-69,-63,-41,-77,-13,-8,-4,-19,-30,-27,-20,-78,-87, 
  /* [1][0][][] */ -25,38,33,-18,-8,37,15,2,-6,-32,-37,-44,-12,-49,-51,-89,-110,-16,-108,-116,-16,-70,-29,-13,-11,-4,-27,-32,-30,8,-27,-29,22,14,18,-2,-4,-6,-12,14, 11,82,79,33,23,62,62,45,31,22,11,12,42,-23,-3,-48,-48,15,-37,-45,22,-17,22,33,38,31,10,0,7,11,-17,-6,29,25,25,8,-19,1,-2,28, -64,34,37,3,-2,-5,-4,-13,-14,-32,-42,-52,-3,-43,-45,-72,-113,-21,-122,-127,-19,-77,-44,-15,-24,-7,-25,-53,-17,-6,-29,-22,28,28,28,3,1,0,-5,9, 
  /* [2][0][][] */ 3,-11,-8,-24,-65,56,21,59,13,-23,-12,45,70,90,76,-5,-18,-49,-39,-16,-78,-96,-79,-31,-82,-18,-22,-10,51,64,1,-9,19,-42,-44,18,6,-44,-22,-11, -32,-2,3,-51,-71,117,22,10,14,8,36,-15,83,115,94,-4,8,-54,-58,-33,-65,-101,-53,-53,-61,-13,-19,22,71,78,17,-7,11,-17,-36,-5,21,-33,-51,-13, -30,1,39,-62,-46,73,70,61,10,7,33,-21,47,127,93,16,-54,-35,-24,-50,-27,-99,-62,-57,-67,-11,5,21,57,55,16,-13,31,-10,-32,24,6,-58,-17,-32, 
  /* [3][0][][] */ -19,8,-21,5,4,-21,18,37,3,9,7,-23,6,14,39,-2,34,-49,-99,-127,-45,14,-65,-87,-50,-65,-35,-10,-37,14,-43,-63,-23,-32,-27,21,-39,19,4,13, -2,-5,-3,-67,-30,50,17,5,22,16,-28,-35,40,-6,-27,30,32,-37,-75,-113,-64,0,-50,-88,-78,-71,-38,20,17,17,-36,-64,-29,-18,-23,6,-61,-36,22,8, 13,-25,18,-64,-36,40,49,39,-6,16,30,6,45,27,12,-23,48,-30,-71,-91,-47,-22,-93,-88,-72,-74,-59,43,6,-14,-70,-87,-54,-14,-6,39,-66,-1,32,47, 
  /* [4][0][][] */ -25,55,40,-30,-24,1,26,25,17,9,11,-43,49,-36,-25,-75,-42,-54,-92,-105,23,-24,11,14,42,24,21,-27,-64,-33,-46,-40,30,16,-27,-4,42,34,-52,-49, 17,58,46,-37,-28,0,-2,2,21,6,10,-59,22,-65,0,-76,-54,-109,-106,-80,13,-49,-14,28,31,30,13,-11,-69,-56,-45,-12,24,23,15,17,37,7,-37,-46, 5,73,90,-8,-5,6,-10,-4,-12,1,5,-34,80,-79,15,-61,-87,-86,-127,-55,2,-25,-4,12,46,20,35,-9,-47,-55,-61,-14,43,16,11,36,38,20,-24,-23, 
  /* [5][0][][] */ 43,-24,-21,0,-4,46,8,6,-13,-7,14,20,39,1,-34,42,24,-35,-72,-65,-94,-89,-70,-89,-63,-17,6,-40,-29,40,7,-46,-49,-49,-70,-20,-41,-56,-33,10, 19,-42,-48,9,-16,81,32,36,-58,38,6,-1,14,2,-19,10,14,-77,-52,-103,-96,-127,-92,-99,-75,7,9,-27,-39,69,-2,-17,-41,-50,-56,-47,-78,-22,-8,16, 18,-21,-32,-56,-32,62,38,43,2,-5,16,54,45,44,-15,45,31,-70,-60,-79,-88,-101,-82,-101,-42,21,18,-31,7,57,-24,-71,-58,-61,-43,-72,-74,-37,-12,34, 
  /* [6][0][][] */ -3,-30,-38,-78,-65,40,17,4,-19,6,-21,-20,46,13,12,-12,-26,-118,-58,-127,-86,-100,-89,-61,-114,-118,-101,-62,28,13,-1,-27,-4,21,3,28,-12,-48,-44,33, 54,23,30,25,8,84,26,14,19,15,23,38,88,73,35,53,-51,-22,-49,-34,-29,-36,-21,-30,-68,-62,-59,-6,63,50,34,-4,4,-3,11,17,-14,-7,-31,20, 34,78,71,10,12,81,70,60,50,41,32,39,75,94,67,55,-28,-37,-12,-45,17,-21,-17,-6,-64,-55,9,21,79,54,28,2,22,28,37,26,4,-18,-6,23, 
  /* [7][0][][] */ 5,-23,-17,33,31,54,-8,4,-13,22,0,32,51,-3,-40,-36,-13,-12,-110,-120,-59,-106,2,3,13,39,18,-37,-9,79,-20,-51,6,-44,-83,-37,-12,-6,25,54, 17,-11,-14,22,-4,64,31,30,7,15,12,57,45,3,-39,-60,-6,-14,-106,-127,-69,-112,-1,-22,29,48,52,-24,-1,86,12,-35,-11,-47,-97,-49,-56,3,14,25, -6,-26,-25,-1,14,55,44,46,-22,8,-12,49,56,1,-55,-46,-13,-20,-121,-104,-57,-90,-19,-37,12,50,55,-5,-12,86,-18,-46,-12,-44,-69,-4,-57,-18,21,59, 
};
const TfArray<4, int> tensor_dimension6 = { 4, { 8,1,3,40 } };
const TfArray<8, float> quant6_scale = { 8, { 0.0064866538159549236, 0.016578581184148788, 0.0092895897105336189, 0.0078490274026989937, 0.01425462868064642, 0.0081797568127512932, 0.0095547037199139595, 0.011621525511145592, } };
const TfArray<8, int> quant6_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant6 = { (TfLiteFloatArray*)&quant6_scale, (TfLiteIntArray*)&quant6_zero, 0 };
const ALIGN(16) int32_t tensor_data7[8] = { 16318, -1181, 4885, 5715, 2376, -4695, 887, 4041, };
const TfArray<1, int> tensor_dimension7 = { 1, { 8 } };
const TfArray<8, float> quant7_scale = { 8, { 2.3351158233708702e-05, 5.9680860431399196e-05, 3.3441385312471539e-05, 2.8255537472432479e-05, 5.1314917072886601e-05, 2.9446122425724752e-05, 3.4395761758787557e-05, 4.1836068703560159e-05, } };
const TfArray<8, int> quant7_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant7 = { (TfLiteFloatArray*)&quant7_scale, (TfLiteIntArray*)&quant7_zero, 0 };
const ALIGN(16) int8_t tensor_data8[16*1*3*8] = { 
  /* [0][0][][] */ -105,-63,-111,54,-64,-18,-102,106, 123,-80,3,36,28,-127,15,27, 91,-102,-1,1,38,72,121,-42, 
  /* [1][0][][] */ -127,116,-57,-68,-41,-76,17,-36, -88,-4,-25,-39,-49,-25,33,-52, -47,32,-25,16,-94,-32,-63,4, 
  /* [2][0][][] */ -100,-85,-72,-91,-127,-18,-90,-105, -47,-79,-81,-52,-113,-30,-95,-62, -87,-103,-60,-53,-123,-14,-79,-84, 
  /* [3][0][][] */ -22,32,-41,22,-96,41,-20,127, -40,1,3,21,-96,59,-11,54, -12,38,51,-6,-99,36,-4,6, 
  /* [4][0][][] */ 46,-38,79,-21,127,-37,-18,66, -79,-19,21,28,-18,-38,-8,57, 54,-46,30,48,-76,108,-28,112, 
  /* [5][0][][] */ 0,-87,-127,-114,0,6,-119,-31, -9,-1,-6,-46,27,32,-96,-41, 18,-10,14,-36,115,18,28,1, 
  /* [6][0][][] */ -23,-42,59,61,-14,56,-7,127, -46,-11,14,-75,54,46,-9,1, -60,69,-43,-48,87,-31,-4,31, 
  /* [7][0][][] */ -86,-47,14,-92,-62,16,-17,-94, -30,-76,-127,-60,-19,25,-92,-114, -55,-79,-95,-87,-41,33,-127,-64, 
  /* [8][0][][] */ -102,-45,68,-40,-111,4,6,69, -109,29,-17,2,-62,0,-4,45, -100,-46,-1,-45,-127,-28,-25,75, 
  /* [9][0][][] */ -74,-23,-15,-35,42,14,-12,36, -101,80,62,-57,-15,-11,41,-25, -127,40,23,-43,-2,-25,-9,25, 
  /* [10][0][][] */ 51,-45,13,65,32,-9,-113,85, 30,-21,2,0,7,3,78,-39, -33,-6,-127,-10,-52,-12,-45,-32, 
  /* [11][0][][] */ -7,-16,-8,0,69,36,-24,51, -23,17,58,-23,-1,22,-10,127, -29,4,-5,4,101,15,7,45, 
  /* [12][0][][] */ -24,2,-117,-52,96,-2,-95,-127, -49,-29,70,-59,57,-58,-1,-13, -17,-48,18,-60,51,-17,-9,-7, 
  /* [13][0][][] */ -50,4,-89,9,-44,-30,-94,73, -20,-70,28,35,6,14,-121,68, -73,-40,-23,-22,-27,-51,127,-43, 
  /* [14][0][][] */ 81,-4,89,75,-127,45,29,-26, 13,25,-22,29,41,89,-22,-32, -101,81,2,-36,-44,22,-32,14, 
  /* [15][0][][] */ 127,-26,-60,41,-17,-124,-25,-28, 53,-51,-60,-56,112,17,8,-79, -41,-68,34,-107,-62,-3,-122,14, 
};
const TfArray<4, int> tensor_dimension8 = { 4, { 16,1,3,8 } };
const TfArray<16, float> quant8_scale = { 16, { 0.0047047771513462067, 0.0070995273999869823, 0.014360350556671619, 0.0096642989665269852, 0.0054793977178633213, 0.0062589389272034168, 0.0065929791890084743, 0.0038314068224281073, 0.0097114359959959984, 0.0067198742181062698, 0.00681706378236413, 0.0079917553812265396, 0.0078119928948581219, 0.00508528808131814, 0.0053332522511482239, 0.0036982339806854725, } };
const TfArray<16, int> quant8_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant8 = { (TfLiteFloatArray*)&quant8_scale, (TfLiteIntArray*)&quant8_zero, 0 };
const ALIGN(16) int32_t tensor_data9[16] = { -4962, -3011, 1977, -1122, -172, -1286, -2089, -3906, -413, -3223, -4242, -948, -2811, -2260, -4073, -5768, };
const TfArray<1, int> tensor_dimension9 = { 1, { 16 } };
const TfArray<16, float> quant9_scale = { 16, { 6.8816974817309529e-05, 0.00010384509369032457, 0.00021004946029279381, 0.00014136011304799467, 8.0147387052420527e-05, 9.1549773060251027e-05, 9.6435789600946009e-05, 5.6042154028546065e-05, 0.00014204959734342992, 9.8291893664281815e-05, 9.9713484814856201e-05, 0.00011689575330819935, 0.00011426636046962813, 7.4382725870236754e-05, 7.8009710705373436e-05, 5.4094227380119264e-05, } };
const TfArray<16, int> quant9_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant9 = { (TfLiteFloatArray*)&quant9_scale, (TfLiteIntArray*)&quant9_zero, 0 };
const ALIGN(16) int8_t tensor_data10[2*400] = { 
  59, -27, -127, 17, 42, 58, 46, -8, 8, -19, -69, 34, 24, 3, 21, -9, 8, 11, -66, 6, 21, 25, 21, 2, 6, 32, 85, -3, 20, 42, 31, 20, 6, 48, -80, -33, 12, 21, 9, -6, -6, 6, 3, 27, 73, 12, -36, 4, 12, -23, -43, -25, 20, 45, -2, -10, 0, -25, 12, 0, -6, 30, -18, 29, 12, 0, -63, 9, 25, 22, 23, -5, 11, -4, 11, 38, 59, -50, -35, -6, 0, -7, -84, -2, 30, -7, 22, -39, -14, -23, -26, 21, -18, -39, -22, 22, -10, 6, -24, 2, 31, 4, 22, -13, 21, 2, -37, -15, 0, 29, 1, 11, -25, 26, -90, 27, 26, -4, 3, 0, 13, -13, -25, 22, 47, -27, 5, -6, -3, -24, -43, -6, 30, 30, 17, -12, 32, -37, 45, 29, 1, -3, -7, 2, 7, 6, -54, 34, 9, 18, 3, -3, 12, -4, 15, 23, -8, 76, -17, -14, -36, 15, -51, 26, 4, -16, 12, 29, 27, -11, -10, 1, 27, -52, 7, -34, 42, 3, -43, -8, 10, 12, 22, -18, 9, -25, 8, 29, -33, 17, -7, 5, -26, -33, -56, 26, 35, -24, 14, 5, 7, -2, 46, 24, 7, -23, 8, -23, 12, -13, -36, 25, 2, 15, 30, 2, -9, -5, -15, 24, 6, 72, 16, 8, 32, 62, -62, 3, 49, 17, -5, -17, -7, 21, 43, 4, 41, 29, 13, 15, 15, 16, -101, -8, 0, -18, -6, -30, 24, 16, -21, -5, 38, 10, 9, 6, -16, 23, -47, 31, -12, 41, -24, -9, 29, -1, 25, -8, 31, -29, 1, -18, 71, -1, -62, 68, 1, 33, 21, 5, 47, 13, -15, 5, 16, 59, 7, -3, -4, 18, -27, 2, 4, -10, -7, -3, 17, 39, 28, -18, 9, 36, 42, 3, -30, 72, -38, -3, 4, -15, 23, 11, -25, 13, -22, -7, 5, -31, 14, 4, 33, 54, -44, 15, -9, 9, 15, 8, 23, 26, -15, 16, 36, 54, 15, -48, -77, 74, -122, 35, -5, 5, 40, -4, 30, 30, 53, 23, 21, -46, 20, -14, 25, 23, -91, 39, 1, -16, 3, -16, 48, 57, 29, 3, 59, 93, -27, -8, -8, -3, -76, 28, 12, -18, 33, -22, 56, 19, -16, 18, -3, 12, 22, 3, -10, 106, -34, 18, -7, -40, 21, -21, 106, 24, 17, 2, 91, 20, -22, 12, 
  -56, 4, 125, -18, -32, -60, -35, 15, -5, 23, 70, -30, -25, -2, -25, -4, 0, -19, 80, -5, -27, -21, -28, -5, -23, -39, -64, -5, -18, -36, -26, -5, -8, -46, 82, 23, -11, -35, 0, 2, -7, 4, 2, -11, -80, -24, 45, 2, -3, 24, 51, 36, -19, -45, -3, 22, 7, 9, 1, -1, 7, -48, 20, -22, -19, 7, 59, -32, -27, -33, -14, 13, -12, -15, -20, -37, -65, 55, 25, 1, -11, 11, 98, -8, -37, 0, -6, 33, 3, 7, 24, -37, 13, 44, 24, -21, 17, 8, 44, 0, -32, -5, -6, 12, -9, 1, 37, 17, -15, -34, 3, -11, 30, -34, 92, -29, -35, -14, -3, 7, -3, 14, 28, -11, -52, 20, 0, 4, 2, 23, 46, 19, -23, -37, -18, 19, -13, 37, -32, -22, -1, 16, 8, -2, -5, -18, 64, -17, 2, -22, -4, -4, 1, 9, -2, -19, 16, -81, 25, -4, 35, -6, 66, -18, 2, 13, -13, -16, -47, -4, 23, -8, -46, 60, 12, 23, -31, 8, 44, 18, -29, -18, -9, 19, -30, 42, -7, -21, 30, -13, -1, -5, 26, 34, 46, -38, -18, 17, -11, -10, 9, -6, -43, -16, -2, 24, -6, 33, 5, 4, 48, -28, -7, -26, -28, 1, -11, 11, 9, -31, 0, -75, -24, -8, -24, -63, 71, 8, -28, -2, 8, 8, 9, -6, -45, -11, -38, -48, 1, -3, -26, -13, 108, 22, -11, 19, -9, 29, -25, 0, 27, -7, -36, -8, -5, -12, 35, -20, 64, -24, 6, -19, 36, 3, -37, 3, -45, 2, -29, 20, 13, 19, -68, 1, 43, -71, -20, -35, -9, -4, -62, -16, 22, -12, -21, -67, -6, 0, 8, -19, 32, 0, -20, 2, -2, 8, -30, -35, -5, 22, -7, -52, -44, 15, 12, -66, 36, -11, -10, 10, -3, -18, 20, -23, 32, 5, 15, 33, -37, 0, -39, -32, 40, -21, 16, -8, -30, 4, -34, -33, 12, -26, -37, -38, -31, 45, 76, -85, 117, -21, -3, 4, -43, 15, -38, -44, -40, 1, -21, 28, -30, 11, -9, -4, 98, -52, -8, 16, -9, 16, -54, -56, -18, 7, -72, -87, 38, 7, 24, -19, 74, -35, -14, 15, -29, 22, -52, -30, 13, -15, 4, -28, -2, 3, 12, -105, 44, -16, 13, 57, -21, 18, -86, -29, -13, 11, -72, -15, 24, 4, 
};
const TfArray<2, int> tensor_dimension10 = { 2, { 2,400 } };
const TfArray<1, float> quant10_scale = { 1, { 0.010069272480905056, } };
const TfArray<1, int> quant10_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant10 = { (TfLiteFloatArray*)&quant10_scale, (TfLiteIntArray*)&quant10_zero, 0 };
const ALIGN(8) int32_t tensor_data11[2] = { 2975, -2975, };
const TfArray<1, int> tensor_dimension11 = { 1, { 2 } };
const TfArray<1, float> quant11_scale = { 1, { 0.00017366191605105996, } };
const TfArray<1, int> quant11_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant11 = { (TfLiteFloatArray*)&quant11_scale, (TfLiteIntArray*)&quant11_zero, 0 };
const TfArray<4, int> tensor_dimension12 = { 4, { 1,1,99,40 } };
const TfArray<1, float> quant12_scale = { 1, { 0.0035998774692416191, } };
const TfArray<1, int> quant12_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant12 = { (TfLiteFloatArray*)&quant12_scale, (TfLiteIntArray*)&quant12_zero, 0 };
const TfArray<4, int> tensor_dimension13 = { 4, { 1,1,99,8 } };
const TfArray<1, float> quant13_scale = { 1, { 0.014627043157815933, } };
const TfArray<1, int> quant13_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant13 = { (TfLiteFloatArray*)&quant13_scale, (TfLiteIntArray*)&quant13_zero, 0 };
const TfArray<4, int> tensor_dimension14 = { 4, { 1,99,1,8 } };
const TfArray<1, float> quant14_scale = { 1, { 0.014627043157815933, } };
const TfArray<1, int> quant14_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant14 = { (TfLiteFloatArray*)&quant14_scale, (TfLiteIntArray*)&quant14_zero, 0 };
const TfArray<4, int> tensor_dimension15 = { 4, { 1,50,1,8 } };
const TfArray<1, float> quant15_scale = { 1, { 0.014627043157815933, } };
const TfArray<1, int> quant15_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant15 = { (TfLiteFloatArray*)&quant15_scale, (TfLiteIntArray*)&quant15_zero, 0 };
const TfArray<4, int> tensor_dimension16 = { 4, { 1,1,50,8 } };
const TfArray<1, float> quant16_scale = { 1, { 0.014627043157815933, } };
const TfArray<1, int> quant16_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant16 = { (TfLiteFloatArray*)&quant16_scale, (TfLiteIntArray*)&quant16_zero, 0 };
const TfArray<4, int> tensor_dimension17 = { 4, { 1,1,50,16 } };
const TfArray<1, float> quant17_scale = { 1, { 0.01724671944975853, } };
const TfArray<1, int> quant17_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant17 = { (TfLiteFloatArray*)&quant17_scale, (TfLiteIntArray*)&quant17_zero, 0 };
const TfArray<4, int> tensor_dimension18 = { 4, { 1,50,1,16 } };
const TfArray<1, float> quant18_scale = { 1, { 0.01724671944975853, } };
const TfArray<1, int> quant18_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant18 = { (TfLiteFloatArray*)&quant18_scale, (TfLiteIntArray*)&quant18_zero, 0 };
const TfArray<4, int> tensor_dimension19 = { 4, { 1,25,1,16 } };
const TfArray<1, float> quant19_scale = { 1, { 0.01724671944975853, } };
const TfArray<1, int> quant19_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant19 = { (TfLiteFloatArray*)&quant19_scale, (TfLiteIntArray*)&quant19_zero, 0 };
const TfArray<2, int> tensor_dimension20 = { 2, { 1,400 } };
const TfArray<1, float> quant20_scale = { 1, { 0.01724671944975853, } };
const TfArray<1, int> quant20_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant20 = { (TfLiteFloatArray*)&quant20_scale, (TfLiteIntArray*)&quant20_zero, 0 };
const TfArray<2, int> tensor_dimension21 = { 2, { 1,2 } };
const TfArray<1, float> quant21_scale = { 1, { 0.26776841282844543, } };
const TfArray<1, int> quant21_zero = { 1, { 4 } };
const TfLiteAffineQuantization quant21 = { (TfLiteFloatArray*)&quant21_scale, (TfLiteIntArray*)&quant21_zero, 0 };
const TfArray<2, int> tensor_dimension22 = { 2, { 1,2 } };
const TfArray<1, float> quant22_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant22_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant22 = { (TfLiteFloatArray*)&quant22_scale, (TfLiteIntArray*)&quant22_zero, 0 };
const TfLiteReshapeParams opdata0 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs0 = { 2, { 0,1 } };
const TfArray<1, int> outputs0 = { 1, { 12 } };
const TfLiteConvParams opdata1 = { kTfLitePaddingSame, 1,1, kTfLiteActRelu, 1,1 };
const TfArray<3, int> inputs1 = { 3, { 12,6,7 } };
const TfArray<1, int> outputs1 = { 1, { 13 } };
const TfLiteReshapeParams opdata2 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs2 = { 2, { 13,2 } };
const TfArray<1, int> outputs2 = { 1, { 14 } };
const TfLitePoolParams opdata3 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs3 = { 1, { 14 } };
const TfArray<1, int> outputs3 = { 1, { 15 } };
const TfLiteReshapeParams opdata4 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs4 = { 2, { 15,3 } };
const TfArray<1, int> outputs4 = { 1, { 16 } };
const TfLiteConvParams opdata5 = { kTfLitePaddingSame, 1,1, kTfLiteActRelu, 1,1 };
const TfArray<3, int> inputs5 = { 3, { 16,8,9 } };
const TfArray<1, int> outputs5 = { 1, { 17 } };
const TfLiteReshapeParams opdata6 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs6 = { 2, { 17,4 } };
const TfArray<1, int> outputs6 = { 1, { 18 } };
const TfLitePoolParams opdata7 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs7 = { 1, { 18 } };
const TfArray<1, int> outputs7 = { 1, { 19 } };
const TfLiteReshapeParams opdata8 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs8 = { 2, { 19,5 } };
const TfArray<1, int> outputs8 = { 1, { 20 } };
const TfLiteFullyConnectedParams opdata9 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs9 = { 3, { 20,10,11 } };
const TfArray<1, int> outputs9 = { 1, { 21 } };
const TfLiteSoftmaxParams opdata10 = { 1 };
const TfArray<1, int> inputs10 = { 1, { 21 } };
const TfArray<1, int> outputs10 = { 1, { 22 } };
const TensorInfo_t tensorData[] = {
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 3968, (TfLiteIntArray*)&tensor_dimension0, 3960, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant0))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data1, (TfLiteIntArray*)&tensor_dimension1, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data2, (TfLiteIntArray*)&tensor_dimension2, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data3, (TfLiteIntArray*)&tensor_dimension3, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data4, (TfLiteIntArray*)&tensor_dimension4, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data5, (TfLiteIntArray*)&tensor_dimension5, 8, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data6, (TfLiteIntArray*)&tensor_dimension6, 960, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant6))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data7, (TfLiteIntArray*)&tensor_dimension7, 32, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant7))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data8, (TfLiteIntArray*)&tensor_dimension8, 384, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant8))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data9, (TfLiteIntArray*)&tensor_dimension9, 64, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant9))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data10, (TfLiteIntArray*)&tensor_dimension10, 800, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant10))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data11, (TfLiteIntArray*)&tensor_dimension11, 8, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant11))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension12, 3960, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant12))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 3968, (TfLiteIntArray*)&tensor_dimension13, 792, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant13))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension14, 792, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant14))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 800, (TfLiteIntArray*)&tensor_dimension15, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant15))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension16, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant16))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 800, (TfLiteIntArray*)&tensor_dimension17, 800, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant17))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension18, 800, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant18))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 800, (TfLiteIntArray*)&tensor_dimension19, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant19))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension20, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant20))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 400, (TfLiteIntArray*)&tensor_dimension21, 2, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant21))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension22, 2, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant22))}, },
};const NodeInfo_t nodeData[] = {
  { (TfLiteIntArray*)&inputs0, (TfLiteIntArray*)&outputs0, const_cast<void*>(static_cast<const void*>(&opdata0)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs1, (TfLiteIntArray*)&outputs1, const_cast<void*>(static_cast<const void*>(&opdata1)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs2, (TfLiteIntArray*)&outputs2, const_cast<void*>(static_cast<const void*>(&opdata2)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs3, (TfLiteIntArray*)&outputs3, const_cast<void*>(static_cast<const void*>(&opdata3)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs4, (TfLiteIntArray*)&outputs4, const_cast<void*>(static_cast<const void*>(&opdata4)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs5, (TfLiteIntArray*)&outputs5, const_cast<void*>(static_cast<const void*>(&opdata5)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs6, (TfLiteIntArray*)&outputs6, const_cast<void*>(static_cast<const void*>(&opdata6)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs7, (TfLiteIntArray*)&outputs7, const_cast<void*>(static_cast<const void*>(&opdata7)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs8, (TfLiteIntArray*)&outputs8, const_cast<void*>(static_cast<const void*>(&opdata8)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs9, (TfLiteIntArray*)&outputs9, const_cast<void*>(static_cast<const void*>(&opdata9)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs10, (TfLiteIntArray*)&outputs10, const_cast<void*>(static_cast<const void*>(&opdata10)), OP_SOFTMAX, },
};
static void* overflow_buffers[EI_MAX_OVERFLOW_BUFFER_COUNT];
static size_t overflow_buffers_ix = 0;
static void * AllocatePersistentBuffer(struct TfLiteContext* ctx,
                                       size_t bytes) {
  void *ptr;
  if (current_location - bytes < tensor_boundary) {
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

static TfLiteStatus RequestScratchBufferInArena(struct TfLiteContext* ctx, size_t bytes,
                                                int* buffer_idx) {
  if (scratch_buffers_ix > EI_MAX_SCRATCH_BUFFER_COUNT - 1) {
    ei_printf("ERR: Failed to allocate scratch buffer of size %d, reached EI_MAX_SCRATCH_BUFFER_COUNT\n",
      (int)bytes);
    return kTfLiteError;
  }

  scratch_buffer_t b;
  b.bytes = bytes;

  b.ptr = AllocatePersistentBuffer(ctx, b.bytes);
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

static void* GetScratchBuffer(struct TfLiteContext* ctx, int buffer_idx) {
  if (buffer_idx > (int)scratch_buffers_ix) {
    return NULL;
  }
  return scratch_buffers[buffer_idx].ptr;
}

static TfLiteTensor* GetTensor(const struct TfLiteContext* context,
                               int tensor_idx) {
  return &tflTensors[tensor_idx];
}

static TfLiteEvalTensor* GetEvalTensor(const struct TfLiteContext* context,
                                       int tensor_idx) {
  return &tflEvalTensors[tensor_idx];
}

} // namespace

TfLiteStatus trained_model_init( void*(*alloc_fnc)(size_t,size_t) ) {
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
  ctx.AllocatePersistentBuffer = &AllocatePersistentBuffer;
  ctx.RequestScratchBufferInArena = &RequestScratchBufferInArena;
  ctx.GetScratchBuffer = &GetScratchBuffer;
  ctx.GetTensor = &GetTensor;
  ctx.GetEvalTensor = &GetEvalTensor;
  ctx.tensors = tflTensors;
  ctx.tensors_size = 23;
  for (size_t i = 0; i < 23; ++i) {
    tflTensors[i].type = tensorData[i].type;
    tflEvalTensors[i].type = tensorData[i].type;
    tflTensors[i].is_variable = 0;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    tflTensors[i].allocation_type = tensorData[i].allocation_type;
#else
    tflTensors[i].allocation_type = (tensor_arena <= tensorData[i].data && tensorData[i].data < tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
#endif
    tflTensors[i].bytes = tensorData[i].bytes;
    tflTensors[i].dims = tensorData[i].dims;
    tflEvalTensors[i].dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    if(tflTensors[i].allocation_type == kTfLiteArenaRw){
      uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

     tflTensors[i].data.data =  start;
     tflEvalTensors[i].data.data =  start;
    }
    else {
       tflTensors[i].data.data = tensorData[i].data;
       tflEvalTensors[i].data.data = tensorData[i].data;
    }
#else
    tflTensors[i].data.data = tensorData[i].data;
    tflEvalTensors[i].data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
    tflTensors[i].quantization = tensorData[i].quantization;
    if (tflTensors[i].quantization.type == kTfLiteAffineQuantization) {
      TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensorData[i].quantization.params));
      tflTensors[i].params.scale = quant->scale->data[0];
      tflTensors[i].params.zero_point = quant->zero_point->data[0];
    }
    if (tflTensors[i].allocation_type == kTfLiteArenaRw) {
      auto data_end_ptr = (uint8_t*)tflTensors[i].data.data + tensorData[i].bytes;
      if (data_end_ptr > tensor_boundary) {
        tensor_boundary = data_end_ptr;
      }
    }
  }
  if (tensor_boundary > current_location /* end of arena size */) {
    ei_printf("ERR: tensor arena is too small, does not fit model - even without scratch buffers\n");
    return kTfLiteError;
  }
  registrations[OP_RESHAPE] = Register_RESHAPE();
  registrations[OP_CONV_2D] = Register_CONV_2D();
  registrations[OP_MAX_POOL_2D] = Register_MAX_POOL_2D();
  registrations[OP_FULLY_CONNECTED] = Register_FULLY_CONNECTED();
  registrations[OP_SOFTMAX] = Register_SOFTMAX();

  for (size_t i = 0; i < 11; ++i) {
    tflNodes[i].inputs = nodeData[i].inputs;
    tflNodes[i].outputs = nodeData[i].outputs;
    tflNodes[i].builtin_data = nodeData[i].builtin_data;
tflNodes[i].custom_initial_data = nullptr;
      tflNodes[i].custom_initial_data_size = 0;
if (registrations[nodeData[i].used_op_index].init) {
      tflNodes[i].user_data = registrations[nodeData[i].used_op_index].init(&ctx, (const char*)tflNodes[i].builtin_data, 0);
    }
  }
  for (size_t i = 0; i < 11; ++i) {
    if (registrations[nodeData[i].used_op_index].prepare) {
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
TfLiteTensor* trained_model_input(int index) {
  return &ctx.tensors[inTensorIndices[index]];
}

static const int outTensorIndices[] = {
  22, 
};
TfLiteTensor* trained_model_output(int index) {
  return &ctx.tensors[outTensorIndices[index]];
}

TfLiteStatus trained_model_invoke() {
  for (size_t i = 0; i < 11; ++i) {
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

TfLiteStatus trained_model_reset( void (*free_fnc)(void* ptr) ) {
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
