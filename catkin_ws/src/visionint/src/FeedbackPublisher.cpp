#include <sstream>

#include "ros/ros.h"

#include "src/FeedbackPublisher.h"
#include "visionint/RecoResults.h"


void FeedbackPublisher::publishFoundFace(int x, int y)
{
  //vision::RecoResults* res = new vision::RecoResults();
  //res->name = "face_saved";
  //res->x = x;
  //res->y = y;
  //publishFeedback(res);
}


void FeedbackPublisher::publishSavedPerson(int n)
{
  visionint::RecoResults* res = new visionint::RecoResults();
  std::stringstream name;
  name << "saved_person_" << n;
  res->name = name.str();
  publishFeedback(res);
}


void FeedbackPublisher::publishDetectedPerson(int idx, int x, int y)
{
  visionint::RecoResults* res = new visionint::RecoResults();
  std::stringstream name;
  name << "detected_person_" << idx;
  res->name = name.str();
  res->x = x;
  res->y = y;
  publishFeedback(res);
}


void FeedbackPublisher::publishDetectedBody(std::string name, int x, int y)
{
  visionint::RecoResults* res = new visionint::RecoResults();
  res->name = name.c_str();
  res->x = x;
  res->y = y;
  publishFeedback(res);
}

void FeedbackPublisher::publishDetectedObject(std::string label, int x, int y)
{
  std::stringstream name;
  name << "detected_object_" << label;
  visionint::RecoResults* res = new visionint::RecoResults();
  res->name = name.str();
  res->x = x;
  res->y = y;
  publishFeedback(res);
}
