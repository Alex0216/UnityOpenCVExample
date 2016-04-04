#include "NativeLibExample.h"

#include <opencv2\core\core.hpp>

//The Tango API provide a 1280x720 YUV image
#define HEIGHT 720
#define WIDTH 1280

// inputImage is a buffer containing the image we want to work on
// output is a buffer of the right size that was allocated by the caller of the function
void NativeLibExample::test(unsigned char* inputImage, float* output)
{

    //We can create a cv::Mat from the input image
    cv::Mat source = cv::Mat(HEIGHT, WIDTH, CV_8U, inputImage);

    //do stuff with your image


    //If we want to send something back to the managed code...
    //Lets assume that 'output' is an array of size 2 that will 
    //contain a normalized 'xy' coordinate
    output[0] = 0.5f; 
    output[1] = 0.5f;
}

