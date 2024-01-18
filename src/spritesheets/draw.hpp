#pragma once

#include <filesystem>
#include <optional>

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>


using namespace cv;
//https://docs.opencv.org/4.8.0/db/da5/tutorial_how_to_scan_images.html


namespace DrawUtil {
    const Mat DEAD_IMAGE(480, 480, CV_8UC3, Scalar(255, 255, 255));

    struct GeneratorPixel {
        uchar* pointer;
        int channels;
    };

    //this function will always modify the image
    //I decided that it's not useful to give a read only scan.
    void scanImage(Mat& mat, std::function<std::optional<uchar>(GeneratorPixel)> modify);
    Mat loadImage(const std::filesystem::path& imageFile);
}