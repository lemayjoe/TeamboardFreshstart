//
//  Whiteboard.cpp
//  Teamboard
//
// Copyright 2013, Joe Lemay, All Rights Reserved.  Confidential        \n7/19/12.

//

#include <iostream>
#include "Whiteboard.h"

Whiteboard::Whiteboard()
{
  }

std::string Whiteboard::getName() const
{
  return "Whiteboard filter";
}

std::string Whiteboard::getDescription() const
{
  return "Whiteboard capture";
}

bool Whiteboard::processFrame(const cv::Mat& inputFrame, cv::Mat& outputFrame)
{
    outputFrame = inputFrame;
  return true;
}