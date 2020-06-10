#include <opencv2/opencv.hpp>

using namespace cv;

Mat invert_image(Mat src);
Mat sketching(Mat src);
Mat _sobel(Mat src);


int main(int argc, const char* argv[]) {
    Mat src = imread(argv[1], IMREAD_COLOR);
    Mat gray, dst;

    if (src.empty()) {
        return 1;
    }

    cvtColor(src, gray, COLOR_BGR2GRAY);
    dst = sketching(gray);

    imshow("original", src);
    imshow("output", dst);
    imwrite("./doc/output.jpg", dst);

    waitKey(0);

    return 0;
}

Mat invert_image(Mat src){
    return 255 - src;
}

Mat sketching(Mat src) {
    Mat dst;

    medianBlur(src, src, 3);
    Mat neg_img = invert_image(src);

    Mat src_0 = _sobel(src);
    Mat src_1 = _sobel(neg_img);
    addWeighted(src_0, 0.5, src_1, 0.5, 0, dst);
    dst = invert_image(dst);

    return dst;
}

Mat _sobel(Mat src) {
    Mat sobel_x, sobel_y, dst;

    Sobel(src, sobel_x, CV_8UC1, 1, 0);
    Sobel(src, sobel_y, CV_8UC1, 0, 1);
    bitwise_or(sobel_x, sobel_y, dst);

    return dst;
}
