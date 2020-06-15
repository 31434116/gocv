package gocv

/*
#include <stdlib.h>
#include "faceproc.h"
*/
import "C"
import (
	"image"
)

func FaceEvaluate(img Mat, rect image.Rectangle, landmarks []Point2f) []float64 {
	cRect := C.struct_Rect{
		x:      C.int(rect.Min.X),
		y:      C.int(rect.Min.Y),
		width:  C.int(rect.Size().X),
		height: C.int(rect.Size().Y),
	}
	cPoints := toCPoints2f(landmarks)
	cAttrs := C.struct_FaceAttribute{
		clarity:   0.,
		lightness: 0.,
		roll:      0.,
		yaw:       0.,
		pitch:     0.,
	}
	C.FaceEvaluate(img.p, cRect, cPoints, &cAttrs)
	return []float64{float64(cAttrs.clarity), float64(cAttrs.lightness), float64(cAttrs.roll), float64(cAttrs.yaw), float64(cAttrs.pitch)}
}
