//
//  EdgeDetectionSample.h
//  Teamboard
//
// Copyright 2013, Joe Lemay, All Rights Reserved.  Confidential        \n6/24/12.

//

#ifndef Teamboard_EdgeDetectionSample_h
#define Teamboard_EdgeDetectionSample_h


#include "SampleBase.h"

class EdgeDetectionSample : public SampleBase
{
public:
  EdgeDetectionSample();
  
  //! Gets a sample name
  virtual std::string getName() const;
  
  //virtual std::string getSampleIcon() const;
  
  //! Returns a detailed sample description
  virtual std::string getDescription() const;
    
  //! Processes a frame and returns output image 
  virtual bool processFrame(const cv::Mat& inputFrame, cv::Mat& outputFrame);
    
private:
  cv::Mat grayImage;
  cv::Mat edges;

  cv::Mat grad_x, grad_y;
  cv::Mat abs_grad_x, abs_grad_y;

  cv::Mat dst;
  cv::Mat dst_norm, dst_norm_scaled;

  bool m_showOnlyEdges;
  std::string m_algorithmName;
  
  // Canny detector options:
  int m_cannyLoThreshold;
  int m_cannyHiThreshold;
  int m_cannyAperture;
    
  // Harris detector options:
  int m_harrisBlockSize;
  int m_harrisapertureSize;
  double m_harrisK;
  int m_harrisThreshold;
};

#endif
