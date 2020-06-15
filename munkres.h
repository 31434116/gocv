#if !defined(_OPENCV3_MUNKRES_H_)
#define _OPENCV3_MUNKRES_H_

#include "core.h"

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include "munkres.hpp"
extern "C"
{
#endif

#ifdef __cplusplus
    typedef cv::Munkres *Munkres;
#else
typedef void *Munkres;
#endif

    Munkres Munkres_New();
    void Munkres_Solve(Munkres m, Mat src, Mat dst);
    void Munkres_Close(Munkres m);

#ifdef __cplusplus
}
#endif

#endif /* !defined(_OPENCV3_MUNKRES_H_) */
