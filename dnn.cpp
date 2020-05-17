#include "dnn.h"

Net Net_ReadNet(const char *model, const char *config)
{
    Net n = new cv::dnn::Net(cv::dnn::readNet(model, config));
    return n;
}

Net Net_ReadNetBytes(const char *framework, struct ByteArray model, struct ByteArray config)
{
    std::vector<uchar> modelv(model.data, model.data + model.length);
    std::vector<uchar> configv(config.data, config.data + config.length);
    Net n = new cv::dnn::Net(cv::dnn::readNet(framework, modelv, configv));
    return n;
}

Net Net_ReadNetFromCaffe(const char *prototxt, const char *caffeModel)
{
    Net n = new cv::dnn::Net(cv::dnn::readNetFromCaffe(prototxt, caffeModel));
    return n;
}

Net Net_ReadNetFromCaffeBytes(struct ByteArray prototxt, struct ByteArray caffeModel)
{
    Net n = new cv::dnn::Net(cv::dnn::readNetFromCaffe(prototxt.data, prototxt.length,
                                                       caffeModel.data, caffeModel.length));
    return n;
}

Net Net_ReadNetFromTensorflow(const char *model)
{
    Net n = new cv::dnn::Net(cv::dnn::readNetFromTensorflow(model));
    return n;
}

Net Net_ReadNetFromTensorflowBytes(struct ByteArray model)
{
    Net n = new cv::dnn::Net(cv::dnn::readNetFromTensorflow(model.data, model.length));
    return n;
}

Net Net_ReadNetFromDarknet(const char *config, const char *weights)
{
    Net n = new cv::dnn::Net(cv::dnn::readNetFromDarknet(config, weights));
    return n;
}

Net Net_ReadNetFromDarknetBytes(struct ByteArray config, struct ByteArray weights)
{
    Net n = new cv::dnn::Net(cv::dnn::readNetFromDarknet(config.data, config.length,
                                                         weights.data, weights.length));
    return n;
}

void Net_Close(Net net)
{
    delete net;
}

bool Net_Empty(Net net)
{
    return net->empty();
}

void Net_SetInput(Net net, Mat blob, const char *name)
{
    net->setInput(*blob, name);
}

Mat Net_Forward(Net net, const char *outputName)
{
    return new cv::Mat(net->forward(outputName));
}

void Net_ForwardLayers(Net net, struct Mats *outputBlobs, struct CStrings outBlobNames)
{
    std::vector<cv::Mat> blobs;

    std::vector<cv::String> names;
    for (int i = 0; i < outBlobNames.length; ++i)
    {
        names.push_back(cv::String(outBlobNames.strs[i]));
    }
    net->forward(blobs, names);

    // copy blobs into outputBlobs
    outputBlobs->mats = new Mat[blobs.size()];

    for (size_t i = 0; i < blobs.size(); ++i)
    {
        outputBlobs->mats[i] = new cv::Mat(blobs[i]);
    }

    outputBlobs->length = (int)blobs.size();
}

void Net_SetPreferableBackend(Net net, int backend)
{
    net->setPreferableBackend(backend);
}

void Net_SetPreferableTarget(Net net, int target)
{
    net->setPreferableTarget(target);
}

int64_t Net_GetPerfProfile(Net net)
{
    std::vector<double> layersTimes;
    return net->getPerfProfile(layersTimes);
}

void Net_GetUnconnectedOutLayers(Net net, IntVector *res)
{
    std::vector<int> cids(net->getUnconnectedOutLayers());
    int *ids = new int[cids.size()];

    for (size_t i = 0; i < cids.size(); ++i)
    {
        ids[i] = cids[i];
    }

    res->length = cids.size();
    res->val = ids;
    return;
}

void Net_GetLayerNames(Net net, CStrings *names)
{
    std::vector<cv::String> cstrs(net->getLayerNames());
    const char **strs = new const char *[cstrs.size()];

    for (size_t i = 0; i < cstrs.size(); ++i)
    {
        strs[i] = cstrs[i].c_str();
    }

    names->length = cstrs.size();
    names->strs = strs;
    return;
}

Mat Net_BlobFromImage(Mat image, double scalefactor, Size size, Scalar mean, bool swapRB,
                      bool crop)
{
    cv::Size sz(size.width, size.height);

    // set the output ddepth to the input image depth
    // int ddepth = image->depth(); // fatal if use
    cv::Scalar cm(mean.val1, mean.val2, mean.val3, mean.val4);
    return new cv::Mat(cv::dnn::blobFromImage(*image, scalefactor, sz, cm, swapRB, crop));
}

void Net_BlobFromImages(struct Mats images, Mat blob, double scalefactor, Size size,
                        Scalar mean, bool swapRB, bool crop, int ddepth)
{
    std::vector<cv::Mat> imgs;

    for (int i = 0; i < images.length; ++i)
    {
        imgs.push_back(*images.mats[i]);
    }

    cv::Size sz(size.width, size.height);
    cv::Scalar cm = cv::Scalar(mean.val1, mean.val2, mean.val3, mean.val4);

    // TODO: handle different version signatures of this function v2 vs v3.
    cv::dnn::blobFromImages(imgs, *blob, scalefactor, sz, cm, swapRB, crop, ddepth);
}

void Net_ImagesFromBlob(Mat blob_, struct Mats *images_)
{
    std::vector<cv::Mat> imgs;
    cv::dnn::imagesFromBlob(*blob_, imgs);
    images_->mats = new Mat[imgs.size()];

    for (size_t i = 0; i < imgs.size(); ++i)
    {
        images_->mats[i] = new cv::Mat(imgs[i]);
    }
    images_->length = (int)imgs.size();
}

Mat Net_GetBlobChannel(Mat blob, int imgidx, int chnidx)
{
    size_t w = blob->size[3];
    size_t h = blob->size[2];
    return new cv::Mat(h, w, CV_32F, blob->ptr<float>(imgidx, chnidx));
}

Scalar Net_GetBlobSize(Mat blob)
{
    Scalar scal = Scalar();
    scal.val1 = blob->size[0];
    scal.val2 = blob->size[1];
    scal.val3 = blob->size[2];
    scal.val4 = blob->size[3];
    return scal;
}

Layer Net_GetLayer(Net net, int layerid)
{
    return new cv::Ptr<cv::dnn::Layer>(net->getLayer(layerid));
}

void Layer_Close(Layer layer)
{
    delete layer;
}

int Layer_InputNameToIndex(Layer layer, const char *name)
{
    return (*layer)->inputNameToIndex(name);
}

int Layer_OutputNameToIndex(Layer layer, const char *name)
{
    return (*layer)->outputNameToIndex(name);
}

const char *Layer_GetName(Layer layer)
{
    return (*layer)->name.c_str();
}

const char *Layer_GetType(Layer layer)
{
    return (*layer)->type.c_str();
}

void Net_NMSBoxes(const Rects bboxes, const FloatVector scores,
                  const float score_threshold, const float nms_threshold,
                  IntVector *indices, const float eta, const int top_k)
{
    std::vector<cv::Rect> bs(bboxes.length);
    for (int i = 0; i < bboxes.length; i++)
    {
        Rect *r = bboxes.rects;
        bs[i] = cv::Rect(r[i].x, r[i].y, r[i].width, r[i].height);
    }
    std::vector<float> ss(scores.val, scores.val + scores.length);
    std::vector<int> is;
    cv::dnn::NMSBoxes(bs, ss, score_threshold, nms_threshold, is, eta, top_k);
    indices->val = is.data();
    indices->length = is.size();
}
