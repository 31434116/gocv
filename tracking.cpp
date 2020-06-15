#include "tracking.h"

KalmanFilter KalmanFilter_Create()
{
    return new cv::Ptr<cv::KalmanFilter>(new cv::KalmanFilter());
}

KalmanFilter KalmanFilter_CreateWithParams(int dynamParams, int measureParams, int controlParams, int type)
{
    return new cv::Ptr<cv::KalmanFilter>(new cv::KalmanFilter(dynamParams, measureParams, controlParams, type));
}

void KalmanFilter_Close(KalmanFilter k)
{
    delete k;
}

void KalmanFilter_Init(KalmanFilter k, int dynamParams, int measureParams, int controlParams, int type)
{
    (*k)->init(dynamParams, measureParams, controlParams, type);
}
Mat KalmanFilter_Predict(KalmanFilter k, Mat control)
{
    return new cv::Mat((*k)->predict(*control));
}
Mat KalmanFilter_Correct(KalmanFilter k, Mat measurement)
{
    return new cv::Mat((*k)->correct(*measurement));
}

void KalmanFilter_SetStatePre(KalmanFilter k, Mat statePre)
{
    (*k)->statePre = *statePre;
}
void KalmanFilter_SetStatePost(KalmanFilter k, Mat statePost)
{
    (*k)->statePost = *statePost;
}
void KalmanFilter_SetTransitionMatrix(KalmanFilter k, Mat transitionMatrix)
{
    (*k)->transitionMatrix = *transitionMatrix;
}
void KalmanFilter_SetControlMatrix(KalmanFilter k, Mat controlMatrix)
{
    (*k)->controlMatrix = *controlMatrix;
}
void KalmanFilter_SetMeasurementMatrix(KalmanFilter k, Mat measurementMatrix)
{
    (*k)->measurementMatrix = *measurementMatrix;
}
void KalmanFilter_SetProcessNoiseCov(KalmanFilter k, Mat processNoiseCov)
{
    (*k)->processNoiseCov = *processNoiseCov;
}
void KalmanFilter_SetMeasurementNoiseCov(KalmanFilter k, Mat measurementNoiseCov)
{
    (*k)->measurementNoiseCov = *measurementNoiseCov;
}
void KalmanFilter_SetErrorCovPre(KalmanFilter k, Mat errorCovPre)
{
    (*k)->errorCovPre = *errorCovPre;
}
void KalmanFilter_SetGain(KalmanFilter k, Mat gain)
{
    (*k)->gain = *gain;
}
void KalmanFilter_SetErrorCovPost(KalmanFilter k, Mat errorCovPost)
{
    (*k)->errorCovPost = *errorCovPost;
}

Mat KalmanFilter_GetStatePre(KalmanFilter k)
{
    return &(*k)->statePre;
}
Mat KalmanFilter_GetStatePost(KalmanFilter k)
{
    return &(*k)->statePost;
}
Mat KalmanFilter_GetTransitionMatrix(KalmanFilter k)
{
    return &(*k)->transitionMatrix;
}
Mat KalmanFilter_GetControlMatrix(KalmanFilter k)
{
    return &(*k)->controlMatrix;
}
Mat KalmanFilter_GetMeasurementMatrix(KalmanFilter k)
{
    return &(*k)->measurementMatrix;
}
Mat KalmanFilter_GetProcessNoiseCov(KalmanFilter k)
{
    return &(*k)->processNoiseCov;
}
Mat KalmanFilter_GetMeasurementNoiseCov(KalmanFilter k)
{
    return &(*k)->measurementNoiseCov;
}
Mat KalmanFilter_GetErrorCovPre(KalmanFilter k)
{
    return &(*k)->errorCovPre;
}
Mat KalmanFilter_GetGain(KalmanFilter k)
{
    return &(*k)->gain;
}
Mat KalmanFilter_GetErrorCovPost(KalmanFilter k)
{
    return &(*k)->errorCovPost;
}
