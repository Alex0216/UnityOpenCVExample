#pragma once

namespace NativeLibExample
{
    //Declare with C linkage to avoid name mangling
    extern "C"
    {
        void test(unsigned char* inputImage, float* output);
    }
}