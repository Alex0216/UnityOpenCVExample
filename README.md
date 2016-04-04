# UnityOpenCVExample

This is an example librairy to demonstrate how to use OpenCV in a NativePlugin with Unity

## Prerequisite
You will need Visual Studio 2013 or 2015 and [NVIDIA CodeWorks for Android](https://developer.nvidia.com/codeworks-android)

For CodeWorks, you will want to install the following components: 
* The right Android SDK (if you don't already have one)
* Android NDK (if you don't already have it)
* Java SDK (if you don't already have one)
* Apache Ant
* Gradle
* USB Driver (not sure about this one)
* Nsight Tegra, Visual Studio Edition
* OpenCV

Make sure everything is installed in the NVPACK folder. There should be a environnement variable (%NVPACK_ROOT%) pointing there after the installation.

## Visual Studio

In Visual Studio we will need to create a new Dynamic Library for Android project.
![Dynamic Library for Android](https://github.com/Alex0216/UnityOpenCVExample/blob/master/picture/1.PNG)

Next, we will need to include and link to the right library. In this example I will using OpenCV.
We will use the OpenCV version that came with NVIDIA CodeWorks. This is just a standard include and linking in Visual Studio, there is nothing special here. There is plenty of information about this around the web if you are not familiar with this, so I won't go into details here about this.

![C/C++ - General/Additional Include Directories](https://github.com/Alex0216/UnityOpenCVExample/blob/master/picture/2.PNG)
![](https://github.com/Alex0216/UnityOpenCVExample/blob/master/picture/3.PNG)
![](https://github.com/Alex0216/UnityOpenCVExample/blob/master/picture/4.PNG)

## Unity

To use your library with Unity, you will need to copy the library (in our case NativeLibExample.so) and ALL its dependencies in your Plugins/Android folder. The dependencies you will want to copy are located under the NVPACK/OpenCV-2.4.8.2-Tegra-sdk/sdk/native folder.

IN THE C# script in Unity

You will need to import your function like this:

    [DllImport("NameOfYourLib")]
    private static extern return_type name_of_your_function(type param, ...);

For our example, this will look like this:

    [DllImport("NativeLibExample")]
    private static extern void test(IntPtr inputImage, IntPtr output);`

Notice that `char*` becomes `IntPtr` in C#. If we had a `char** param`, it would
become `ref IntPt param`

###Send a buffer to unmanaged code

Lets say we have a buffer containing our image like this:
`byte[] imageBuffer;`

We will need to allocate an unmanaged buffer and copy our buffer

    IntPtr unmanagedBuffer = Marshal.AllocHGlobal(imageBuffer.Length);
    Marshal.Copy(imageBufffer, 0, unmanagedBuffer, imageBuffer.Length);

For our example, we will also need a float buffer of size 2

    IntPtr floatBuffer = Marshal.AllocHGlobal(sizeof(float)*2);

We can then call our function:
    test(unmanagedBuffer, floatBuffer);

Don't forget to cleanup your buffer!

    Marshal.FreeHGlobal(unmanagedBuffer);
    Marshal.FreeHGlobal(floatBuffer);
