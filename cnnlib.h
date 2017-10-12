#ifndef _CNNLIB_H_
#define _CNNLIB_H_


#include <fstream>
#include <utility>
#include <vector>
#include "tensorflow/cc/ops/const_op.h"
#include "tensorflow/cc/ops/image_ops.h"
#include "tensorflow/cc/ops/standard_ops.h"
#include "tensorflow/core/framework/graph.pb.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/graph/default_device.h"
#include "tensorflow/core/graph/graph_def_builder.h"
#include "tensorflow/core/lib/core/errors.h"
#include "tensorflow/core/lib/core/stringpiece.h"
#include "tensorflow/core/lib/core/threadpool.h"
#include "tensorflow/core/lib/io/path.h"
#include "tensorflow/core/lib/strings/stringprintf.h"
#include "tensorflow/core/platform/env.h"
#include "tensorflow/core/platform/init_main.h"
#include "tensorflow/core/platform/logging.h"
#include "tensorflow/core/platform/types.h"
#include "tensorflow/core/public/session.h"
#include "tensorflow/core/util/command_line_flags.h"
using tensorflow::Flag;
using tensorflow::Tensor;
using tensorflow::Status;
using tensorflow::string;
using tensorflow::int32;
using namespace tensorflow;
void weclome(void);
void outString(const char *str);

Status ReadLabelsFile(const string& file_name, std::vector<string>* result,
                      size_t* found_label_count);

static Status ReadEntireFile(tensorflow::Env* env, const string& filename,
                             Tensor* output);

Status ReadTensorFromImageFile(const string& file_name, const int input_height,
                               const int input_width, const float input_mean,
                               const float input_std,
                               std::vector<Tensor>* out_tensors);
Status LoadGraph(const string& graph_file_name,
                 std::unique_ptr<tensorflow::Session>* session);
Status GetTopLabels(const std::vector<Tensor>& outputs, int how_many_labels,
                    Tensor* indices, Tensor* scores);

Status PrintTopLabels(const std::vector<Tensor>& outputs,
                      const string& labels_file_name);
Status CheckTopLabel(const std::vector<Tensor>& outputs, int expected,
                     bool* is_expected);
int cnnmain(int argc, char* argv[]);
#endif
