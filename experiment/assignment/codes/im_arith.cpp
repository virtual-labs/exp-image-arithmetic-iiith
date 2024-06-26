#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat imADD(const Mat &img1, const Mat &img2, int map_fn)
{
	int c = img1.cols;
	int r = img1.rows;

	Mat final_img(r, c, CV_8U);
	if (map_fn == 1)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				int grval = img1.at<uchar>(i, j) + img2.at<uchar>(i, j);
				if (grval > 255)
					grval = 255;
				final_img.at<uchar>(i, j) = grval;
			}
		}
	}
	else if (map_fn == 2)
	{
		int min_val = 100000;
		int max_val = -300;

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				int grval = img1.at<uchar>(i, j) + img2.at<uchar>(i, j);
				if (grval > max_val)
					max_val = grval;
				if (grval < min_val)
					min_val = grval;
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				int grval = img1.at<uchar>(i, j) + img2.at<uchar>(i, j);
				if (max_val == 0 && min_val == 0)
					grval = 0;
				else
					grval = ((grval - min_val) * 255) / (max_val - min_val);
				final_img.at<uchar>(i, j) = grval;
			}
		}
	}
	return final_img;
}

Mat imSUB(const Mat &img1, const Mat &img2, int map_fn)
{
	int c = img1.cols;
	int r = img1.rows;

	Mat final_img(r, c, CV_8U);
	if (map_fn == 1)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				int grval = img1.at<uchar>(i, j) - img2.at<uchar>(i, j);
				if (grval < 0)
					grval = 0;
				final_img.at<uchar>(i, j) = grval;
			}
		}
	}
	else if (map_fn == 2)
	{
		int min_val = 100000;
		int max_val = -300;

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				int grval = img1.at<uchar>(i, j) - img2.at<uchar>(i, j);
				if (grval > max_val)
					max_val = grval;
				if (grval < min_val)
					min_val = grval;
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				int grval = img1.at<uchar>(i, j) - img2.at<uchar>(i, j);
				if (max_val == 0 && min_val == 0)
					grval = 0;
				else
					grval = ((grval - min_val) * 255) / (max_val - min_val);
				final_img.at<uchar>(i, j) = grval;
			}
		}
	}
	return final_img;
}

Mat imDIFF(const Mat &img1, const Mat &img2, int map_fn)
{
	int c = img1.cols;
	int r = img1.rows;

	Mat final_img(r, c, CV_8U);
	if (map_fn == 1)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				int grval = abs(img1.at<uchar>(i, j) - img2.at<uchar>(i, j));
				final_img.at<uchar>(i, j) = grval;
			}
		}
	}
	else if (map_fn == 2)
	{
		int min_val = 100000;
		int max_val = -300;

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				int grval = abs(img1.at<uchar>(i, j) - img2.at<uchar>(i, j));
				if (grval > max_val)
					max_val = grval;
				if (grval < min_val)
					min_val = grval;
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				int grval = abs(img1.at<uchar>(i, j) - img2.at<uchar>(i, j));
				if (max_val == 0 && min_val == 0)
					grval = 0;
				else
					grval = ((grval - min_val) * 255) / (max_val - min_val);
				final_img.at<uchar>(i, j) = grval;
			}
		}
	}
	return final_img;
}

Mat imMULTIPLY(const Mat &img1, const Mat &img2, int map_fn)
{
	int c = img1.cols;
	int r = img1.rows;

	Mat final_img(r, c, CV_8U);
	if (map_fn == 1)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				int grval = img1.at<uchar>(i, j) * img2.at<uchar>(i, j);
				if (grval > 255)
					grval = 255;
				final_img.at<uchar>(i, j) = grval;
			}
		}
	}
	else if (map_fn == 2)
	{
		int min_val = 100000;
		int max_val = -300;

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				int grval = img1.at<uchar>(i, j) * img2.at<uchar>(i, j);
				if (grval > max_val)
					max_val = grval;
				if (grval < min_val)
					min_val = grval;
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				int grval = img1.at<uchar>(i, j) * img2.at<uchar>(i, j);
				if (max_val == 0 && min_val == 0)
					grval = 0;
				else
					grval = ((grval - min_val) * 255) / (max_val - min_val);
				final_img.at<uchar>(i, j) = grval;
			}
		}
	}
	return final_img;
}

Mat imDIVIDE(const Mat &img1, const Mat &img2, int map_fn)
{
	int c = img1.cols;
	int r = img1.rows;

	Mat final_img(r, c, CV_8U);
	if (map_fn == 1)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				double grval;
				if (img2.at<uchar>(i, j) != 0)
					grval = static_cast<double>(img1.at<uchar>(i, j)) / img2.at<uchar>(i, j);
				else
					grval = static_cast<double>(img1.at<uchar>(i, j)) / 0.5;
				if (grval > 255.0)
					grval = 255.0;
				final_img.at<uchar>(i, j) = static_cast<int>(grval);
			}
		}
	}
	else if (map_fn == 2)
	{
		double min_val = 1000000.0;
		double max_val = -300.0;

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				double grval;
				if (img2.at<uchar>(i, j) != 0)
					grval = static_cast<double>(img1.at<uchar>(i, j)) / img2.at<uchar>(i, j);
				else
					grval = static_cast<double>(img1.at<uchar>(i, j)) / 0.5;
				if (grval > max_val)
					max_val = grval;
				if (grval < min_val)
					min_val = grval;
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				double grval;
				if (img2.at<uchar>(i, j) != 0)
					grval = static_cast<double>(img1.at<uchar>(i, j)) / img2.at<uchar>(i, j);
				else
					grval = static_cast<double>(img1.at<uchar>(i, j)) / 0.5;
				if (max_val == 0 && min_val == 0)
					grval = 0;
				else
				{
					grval = ((grval - min_val) * 255.0) / (max_val - min_val);
				}
				final_img.at<uchar>(i, j) = static_cast<int>(grval);
			}
		}
	}
	return final_img;
}

int main(int argc, char *argv[])
{
	if (argc != 6)
	{
		cout << "Usage: <program_name> <image1_path> <image2_path> <output_image_path> <operation> <map_fn>" << endl;
		return -1;
	}

	Mat img1 = imread(argv[1], IMREAD_GRAYSCALE);
	if (img1.empty())
	{
		cout << "Error: Could not load image " << argv[1] << endl;
		return -1;
	}

	Mat img2 = imread(argv[2], IMREAD_GRAYSCALE);
	if (img2.empty())
	{
		cout << "Error: Could not load image " << argv[2] << endl;
		return -1;
	}

	int map_fn = atoi(argv[5]);
	int operation = atoi(argv[4]);

	Mat result_img;
	switch (operation)
	{
	case 1:
		result_img = imADD(img1, img2, map_fn);
		break;
	case 2:
		result_img = imSUB(img1, img2, map_fn);
		break;
	case 3:
		result_img = imDIFF(img1, img2, map_fn);
		break;
	case 4:
		result_img = imMULTIPLY(img1, img2, map_fn);
		break;
	case 5:
		result_img = imDIVIDE(img1, img2, map_fn);
		break;
	default:
		cout << "Invalid operation" << endl;
		return -1;
	}

	imwrite(argv[3], result_img);
	return 0;
}
