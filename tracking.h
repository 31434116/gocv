#ifndef _OPENCV3_TRACMING_H_
#define _OPENCV3_TRACKING_H_

#include <stdbool.h>

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/tracking.hpp>
extern "C"
{
#endif

#include "core.h"

#ifdef __cplusplus
    typedef cv::Ptr<cv::KalmanFilter> *KalmanFilter;
#else
typedef void *KalmanFilter;
#endif
    KalmanFilter KalmanFilter_Create();
    KalmanFilter KalmanFilter_CreateWithParams(int dynamParams, int measureParams, int controlParams, int type);
    void KalmanFilter_Close(KalmanFilter k);

    void KalmanFilter_Init(KalmanFilter k, int dynamParams, int measureParams, int controlParams, int type);
    Mat KalmanFilter_Predict(KalmanFilter k, Mat control);
    Mat KalmanFilter_Correct(KalmanFilter k, Mat measurement);

    void KalmanFilter_SetStatePre(KalmanFilter k, Mat statePre);
    void KalmanFilter_SetStatePost(KalmanFilter k, Mat statePost);
    void KalmanFilter_SetTransitionMatrix(KalmanFilter k, Mat transitionMatrix);
    void KalmanFilter_SetControlMatrix(KalmanFilter k, Mat controlMatrix);
    void KalmanFilter_SetMeasurementMatrix(KalmanFilter k, Mat measurementMatrix);
    void KalmanFilter_SetProcessNoiseCov(KalmanFilter k, Mat processNoiseCov);
    void KalmanFilter_SetMeasurementNoiseCov(KalmanFilter k, Mat measurementNoiseCov);
    void KalmanFilter_SetErrorCovPre(KalmanFilter k, Mat errorCovPre);
    void KalmanFilter_SetGain(KalmanFilter k, Mat gain);
    void KalmanFilter_SetErrorCovPost(KalmanFilter k, Mat errorCovPost);

    Mat KalmanFilter_GetStatePre(KalmanFilter k);
    Mat KalmanFilter_GetStatePost(KalmanFilter k);
    Mat KalmanFilter_GetTransitionMatrix(KalmanFilter k);
    Mat KalmanFilter_GetControlMatrix(KalmanFilter k);
    Mat KalmanFilter_GetMeasurementMatrix(KalmanFilter k);
    Mat KalmanFilter_GetProcessNoiseCov(KalmanFilter k);
    Mat KalmanFilter_GetMeasurementNoiseCov(KalmanFilter k);
    Mat KalmanFilter_GetErrorCovPre(KalmanFilter k);
    Mat KalmanFilter_GetGain(KalmanFilter k);
    Mat KalmanFilter_GetErrorCovPost(KalmanFilter k);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_TRACKING_H_