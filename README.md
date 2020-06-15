# Photo Sketching OpenCV using c++

## Algorithm in 6 steps
 * Load gray scale image
 * Median noise reduction
 * Create negative image (dst = 255 - src)
 * Edge detection for negative and gray image
 * Add images (dst = neg_img * 0.5 + gray_img * 0.5)
 * Invert image
 
g++ main.cpp -o main pkg-config --cflags --libs opencv

![jpg](/images/image.jpg)
![jpg](/doc/output.jpg)
