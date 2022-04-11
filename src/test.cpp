#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>
#include <string>
#include <iostream>
#include <unistd.h>

using namespace cv;

int main(int argc, char const **argv)
{
    char path[256];
    getcwd(path, 256);
    VideoCapture capture(std::string(path) + "/" + std::string(argv[1])); // open video source

    system(std::string("rm " + std::string(path) + "/../frames/*.png").c_str());
    
    if(!capture.isOpened()){
        std::cout << "error opening stream\n";
        return -1;
    }

    for(int i = 0; i < capture.get(CAP_PROP_FRAME_COUNT); i++){
        capture.set(CAP_PROP_POS_FRAMES, i);
        Mat frame;

        if(!capture.read(frame)){
            std::cout << "Failed to extract a frame.\n";
            return -1;
        }

        imwrite("../frames/" + std::to_string(i) + ".png", frame);
    }

    return 0;
}

