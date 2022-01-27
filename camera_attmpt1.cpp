/* This firrst attempt is to stream video from the camera */
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	// Open the default video camera
	cv::VideoCapture cap(0);

	// if not successful, then exit the program
	if(!cap.isOpened())
	{
		cout << "ERROR:: Cannot open video camera!" << endl;
		return EXIT_FAILURE;
	}

	double dWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH);
	double dHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT);

	cout << "Resolution of the video: " << dWidth << "x" << dHeight << endl;

	string window_name = "My Camera Feed";
	cv::namedWindow(window_name);

	while(true)
	{
		cv::Mat frame;
		bool bSuccess = cap.read(frame);

		if(!bSuccess)
		{
			cout << "Error::Video Camera is disconnected" << endl;
			break;
		}

		cv::imshow(window_name, frame);

		if(cv::waitKey(10) == 27)
		{
			cout << "Esc Key is pressed by user.\nStopping the video\n";
			break;
		}
	}

	return EXIT_SUCCESS;
}

