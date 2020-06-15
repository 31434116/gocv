#ifndef _OPENCV3_FACEPROC_H_
#define _OPENCV3_FACEPROC_H_

#include "core.h"

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C"
{
#endif
    typedef struct FaceAttribute
    {
        float clarity;
        float lightness;
        float roll, yaw, pitch;
    } FaceAttribute;

    void FaceEvaluate(Mat img, Rect r, Points2f landmark, struct FaceAttribute *attrs);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_FACEPROC_H_