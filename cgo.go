// +build !customenv

package gocv

// Changes here should be mirrored in contrib/cgo.go and cuda/cgo.go.

/*
#cgo  pkg-config: opencv4
#cgo CXXFLAGS:  --std=c++11 -Wno-conversion-null
#cgo windows  CPPFLAGS:   -ID:/msys64/mingw64/include
#cgo windows  LDFLAGS:    -static-libstdc++ -static-libgcc -LD:/msys64/mingw64/lib -lopencv_gapi452 -lopencv_stitching452 -lopencv_alphamat452 -lopencv_aruco452 -lopencv_bgsegm452 -lopencv_ccalib452 -lopencv_dnn_objdetect452 -lopencv_dnn_superres452 -lopencv_dpm452 -lopencv_highgui452 -lopencv_face452 -lopencv_fuzzy452 -lopencv_hdf452 -lopencv_hfs452 -lopencv_img_hash452 -lopencv_intensity_transform452 -lopencv_line_descriptor452 -lopencv_ovis452 -lopencv_quality452 -lopencv_rapid452 -lopencv_reg452 -lopencv_rgbd452 -lopencv_saliency452 -lopencv_sfm452 -lopencv_stereo452 -lopencv_structured_light452 -lopencv_phase_unwrapping452 -lopencv_superres452 -lopencv_optflow452 -lopencv_surface_matching452 -lopencv_tracking452 -lopencv_datasets452 -lopencv_text452 -lopencv_dnn452 -lopencv_plot452 -lopencv_videostab452 -lopencv_videoio452 -lopencv_xfeatures2d452 -lopencv_shape452 -lopencv_ml452 -lopencv_ximgproc452 -lopencv_video452 -lopencv_xobjdetect452 -lopencv_objdetect452 -lopencv_calib3d452 -lopencv_imgcodecs452 -lopencv_features2d452 -lopencv_flann452 -lopencv_xphoto452 -lopencv_photo452 -lopencv_imgproc452 -lopencv_core452 -lyogo
*/
import "C"
