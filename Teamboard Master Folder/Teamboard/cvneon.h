//
//  cvneon.h
//  Teamboard
//
// Copyright 2013, Joe Lemay, All Rights Reserved.  Confidential        \n8/12/12.
//
//

#ifndef Teamboard_cvneon_h
#define Teamboard_cvneon_h

namespace cv
{
  //! Return new matrix identical to the input but 16-bytes aligned
  cv::Mat align16(const cv::Mat& m);
  
  //! Return true if input matrix has 16 bytes aligned rows
  bool isAligned(const cv::Mat& m);
  
  //! 
  void neon_cvtColorBGRA2GRAY(const cv::Mat& input, cv::Mat& gray);
  
  //! 
  void neon_transform_bgra(const cv::Mat& input, cv::Mat& result, const cv::Mat_<float>& m_transposed);
}

#endif
