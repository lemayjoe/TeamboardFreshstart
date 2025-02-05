//
//  FeatureDetection.h
//  Teamboard
//
//  Created by Anton Belodedenko on 25/07/2012.

//

#ifndef Teamboard_FeatureDetection_h
#define Teamboard_FeatureDetection_h

#include "SampleBase.h"

class FeatureDetectionSample : public SampleBase
{
public:
    FeatureDetectionSample();
    
    //! Gets a sample name
    virtual std::string getName() const;
    
    virtual std::string getSampleIcon() const;
    
    //! Returns a detailed sample description
    virtual std::string getDescription() const;
        
    //! Processes a frame and returns output image 
    virtual bool processFrame(const cv::Mat& inputFrame, cv::Mat& outputFrame);
    
private:
    cv::Mat grayImage;
    
    std::vector<cv::KeyPoint> objectKeypoints;
    
    std::string m_detectorName;
    std::vector<std::string> m_alorithms;
    
    int m_maxFeatures;
    int m_fastThreshold;
};

#endif
