// +build !customenv

package gocv

// Changes here should be mirrored in contrib/cgo.go and cuda/cgo.go.

/*
#cgo  pkg-config: opencv4
#cgo CXXFLAGS:  --std=c++11 -Wno-conversion-null
#cgo windows  CPPFLAGS:   -ID:/msys64/mingw64/include
#cgo windows  LDFLAGS:    -static-libstdc++ -static-libgcc -LD:/msys64/mingw64/lib -lopencv_gapi451 -lopencv_stitching451 -lopencv_alphamat451 -lopencv_aruco451 -lopencv_bgsegm451 -lopencv_ccalib451 -lopencv_dnn_objdetect451 -lopencv_dnn_superres451 -lopencv_dpm451 -lopencv_highgui451 -lopencv_face451 -lopencv_fuzzy451 -lopencv_hdf451 -lopencv_hfs451 -lopencv_img_hash451 -lopencv_intensity_transform451 -lopencv_line_descriptor451 -lopencv_ovis451 -lopencv_quality451 -lopencv_rapid451 -lopencv_reg451 -lopencv_rgbd451 -lopencv_saliency451 -lopencv_sfm451 -lopencv_stereo451 -lopencv_structured_light451 -lopencv_phase_unwrapping451 -lopencv_superres451 -lopencv_optflow451 -lopencv_surface_matching451 -lopencv_tracking451 -lopencv_datasets451 -lopencv_text451 -lopencv_dnn451 -lopencv_plot451 -lopencv_videostab451 -lopencv_videoio451 -lopencv_xfeatures2d451 -lopencv_shape451 -lopencv_ml451 -lopencv_ximgproc451 -lopencv_video451 -lopencv_xobjdetect451 -lopencv_objdetect451 -lopencv_calib3d451 -lopencv_imgcodecs451 -lopencv_features2d451 -lopencv_flann451 -lopencv_xphoto451 -lopencv_photo451 -lopencv_imgproc451 -lopencv_core451 -lyogo
*/
import "C"
