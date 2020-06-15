package gocv

/*
#include <stdlib.h>
#include <tracking.h>
*/
import "C"
import (
	"unsafe"
)

// KalmanFilter is a wrapper around the cv::KalmanFilter algorithm.
type KalmanFilter struct {
	// C.KalmanFilter
	p unsafe.Pointer
}

// NewKalmanFilter returns a new KalmanFilter algorithm
//
// For further details, please see:
// https://docs.opencv.org/master/dd/d6a/classcv_1_1KalmanFilter.html#ac0799f0611baee9e7e558f016e4a7b40
//
func NewKalmanFilter() KalmanFilter {
	return KalmanFilter{p: unsafe.Pointer(C.KalmanFilter_Create())}
}

// NewKalmanFilterWithParams returns a new KalmanFilter algorithm
//
// For further details, please see:
// https://docs.opencv.org/master/dd/d6a/classcv_1_1KalmanFilter.html#abac82ecfa530611a163255bc7d91c088
//
func NewKalmanFilterWithParams(dynamParams, measureParams, controlParams, ktype int) KalmanFilter {
	return KalmanFilter{p: unsafe.Pointer(C.KalmanFilter_CreateWithParams(C.int(dynamParams), C.int(measureParams), C.int(controlParams), C.int(ktype)))}
}

// Close KalmanFilter.
func (k *KalmanFilter) Close() error {
	C.KalmanFilter_Close((C.KalmanFilter)(k.p))
	k.p = nil
	return nil
}

// Init re-initializes Kalman filter. The previous content is destroyed.
//
// For further details, please see:
// https://docs.opencv.org/master/dd/d6a/classcv_1_1KalmanFilter.html#a4f136c39c016d3530c7c5801dd1ddb3b
//
func (k *KalmanFilter) Init(dynamParams, measureParams, controlParams, ktype int) {
	C.KalmanFilter_Init((C.KalmanFilter)(k.p), C.int(dynamParams), C.int(measureParams), C.int(controlParams), C.int(ktype))
}

// Predict Computes a predicted state.
//
// For further details, please see:
// https://docs.opencv.org/master/dd/d6a/classcv_1_1KalmanFilter.html#aa710d2255566bec8d6ce608d103d4fa7
//
func (k *KalmanFilter) Predict(control Mat) Mat {
	return newMat(C.KalmanFilter_Predict((C.KalmanFilter)(k.p), control.p))
}

// Correct Updates the predicted state from the measurement.
//
// For further details, please see:
// https://docs.opencv.org/master/dd/d6a/classcv_1_1KalmanFilter.html#a60eb7feb569222ad0657ef1875884b5e
//
func (k *KalmanFilter) Correct(measurement Mat) Mat {
	return newMat(C.KalmanFilter_Correct((C.KalmanFilter)(k.p), measurement.p))
}

func (k *KalmanFilter) SetStatePre(statePre Mat) {
	C.KalmanFilter_SetStatePre((C.KalmanFilter)(k.p), statePre.p)
}
func (k *KalmanFilter) SetStatePost(statePost Mat) {
	C.KalmanFilter_SetStatePost((C.KalmanFilter)(k.p), statePost.p)
}
func (k *KalmanFilter) SetTransitionMatrix(transitionMatrix Mat) {
	C.KalmanFilter_SetTransitionMatrix((C.KalmanFilter)(k.p), transitionMatrix.p)
}
func (k *KalmanFilter) SetControlMatrix(controlMatrix Mat) {
	C.KalmanFilter_SetControlMatrix((C.KalmanFilter)(k.p), controlMatrix.p)
}
func (k *KalmanFilter) SetMeasurementMatrix(measurementMatrix Mat) {
	C.KalmanFilter_SetMeasurementMatrix((C.KalmanFilter)(k.p), measurementMatrix.p)
}
func (k *KalmanFilter) SetProcessNoiseCov(processNoiseCov Mat) {
	C.KalmanFilter_SetProcessNoiseCov((C.KalmanFilter)(k.p), processNoiseCov.p)
}
func (k *KalmanFilter) SetMeasurementNoiseCov(measurementNoiseCov Mat) {
	C.KalmanFilter_SetMeasurementNoiseCov((C.KalmanFilter)(k.p), measurementNoiseCov.p)
}
func (k *KalmanFilter) SetErrorCovPre(errorCovPre Mat) {
	C.KalmanFilter_SetErrorCovPre((C.KalmanFilter)(k.p), errorCovPre.p)
}
func (k *KalmanFilter) SetGain(gain Mat) {
	C.KalmanFilter_SetGain((C.KalmanFilter)(k.p), gain.p)
}
func (k *KalmanFilter) SetErrorCovPost(errorCovPost Mat) {
	C.KalmanFilter_SetErrorCovPost((C.KalmanFilter)(k.p), errorCovPost.p)
}
func (k *KalmanFilter) GetStatePre() Mat {
	return newMat(C.KalmanFilter_GetStatePre((C.KalmanFilter)(k.p)))
}
func (k *KalmanFilter) GetStatePost() Mat {
	return newMat(C.KalmanFilter_GetStatePost((C.KalmanFilter)(k.p)))
}
func (k *KalmanFilter) GetTransitionMatrix() Mat {
	return newMat(C.KalmanFilter_GetTransitionMatrix((C.KalmanFilter)(k.p)))
}
func (k *KalmanFilter) GetControlMatrix() Mat {
	return newMat(C.KalmanFilter_GetControlMatrix((C.KalmanFilter)(k.p)))
}
func (k *KalmanFilter) GetMeasurementMatrix() Mat {
	return newMat(C.KalmanFilter_GetMeasurementMatrix((C.KalmanFilter)(k.p)))
}
func (k *KalmanFilter) GetProcessNoiseCov() Mat {
	return newMat(C.KalmanFilter_GetProcessNoiseCov((C.KalmanFilter)(k.p)))
}
func (k *KalmanFilter) GetMeasurementNoiseCov() Mat {
	return newMat(C.KalmanFilter_GetMeasurementNoiseCov((C.KalmanFilter)(k.p)))
}
func (k *KalmanFilter) GetErrorCovPre() Mat {
	return newMat(C.KalmanFilter_GetErrorCovPre((C.KalmanFilter)(k.p)))
}
func (k *KalmanFilter) GetGain() Mat {
	return newMat(C.KalmanFilter_GetGain((C.KalmanFilter)(k.p)))
}
func (k *KalmanFilter) GetErrorCovPost() Mat {
	return newMat(C.KalmanFilter_GetErrorCovPost((C.KalmanFilter)(k.p)))
}
