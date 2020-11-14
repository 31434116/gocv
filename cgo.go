// +build !customenv

package gocv

// Changes here should be mirrored in contrib/cgo.go and cuda/cgo.go.

/*
#cgo  pkg-config: opencv4
#cgo CXXFLAGS:  --std=c++11 -Wno-conversion-null
#cgo windows  CPPFLAGS:   -ID:/msys64/mingw64/include
#cgo windows  LDFLAGS:    -static-libstdc++ -static-libgcc -LD:/msys64/mingw64/lib -lopencv_gapi450 -lopencv_stitching450 -lopencv_alphamat450 -lopencv_aruco450 -lopencv_bgsegm450 -lopencv_ccalib450 -lopencv_dnn_objdetect450 -lopencv_dnn_superres450 -lopencv_dpm450 -lopencv_highgui450 -lopencv_face450 -lopencv_fuzzy450 -lopencv_hdf450 -lopencv_hfs450 -lopencv_img_hash450 -lopencv_intensity_transform450 -lopencv_line_descriptor450 -lopencv_ovis450 -lopencv_quality450 -lopencv_rapid450 -lopencv_reg450 -lopencv_rgbd450 -lopencv_saliency450 -lopencv_sfm450 -lopencv_stereo450 -lopencv_structured_light450 -lopencv_phase_unwrapping450 -lopencv_superres450 -lopencv_optflow450 -lopencv_surface_matching450 -lopencv_tracking450 -lopencv_datasets450 -lopencv_text450 -lopencv_dnn450 -lopencv_plot450 -lopencv_videostab450 -lopencv_videoio450 -lopencv_xfeatures2d450 -lopencv_shape450 -lopencv_ml450 -lopencv_ximgproc450 -lopencv_video450 -lopencv_xobjdetect450 -lopencv_objdetect450 -lopencv_calib3d450 -lopencv_imgcodecs450 -lopencv_features2d450 -lopencv_flann450 -lopencv_xphoto450 -lopencv_photo450 -lopencv_imgproc450 -lopencv_core450 -lyogo
*/
import "C"
