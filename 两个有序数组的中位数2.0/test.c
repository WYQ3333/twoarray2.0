#include<stdio.h>
#include<Windows.h>


double findMedianSortedArrays1(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int i = 0;
	int j = 0;
	int k = 0;
	if (nums1Size == 0)
	{
		return (nums2Size % 2 == 0) ? (nums2[nums2Size / 2 - 1] + nums2[nums2Size - 1]) / 2.0 : nums2[(nums2Size) / 2];
	}
	if (nums2Size == 0)
	{
		return (nums1Size % 2 == 0) ? (nums1[nums1Size / 2 - 1] + nums1[nums1Size - 1]) / 2.0 : nums1[(nums1Size) / 2];
	}
	for (i = 0; i<nums1Size;)
	{
		k = j + 1;
		if ((i<nums1Size) && (nums1[i] <= nums2[j]))
		{
			i++;
		}
		else
		{
			int tmp = nums1[i];
			if ((k<nums2Size) && (nums2[k]>nums1[i]))
			{
				nums1[i] = nums2[j];
				nums2[j] = tmp;
				j++;
			}
			else if ((j<nums2Size) && (nums2Size == 1))
			{
				nums1[i] = nums2[j];
				nums2[j] = tmp;
				j++;
			}
			else
			{
				j++;
			}
		}
	}
	int number = nums1Size + nums2Size;
	if ((number % 2 == 0))
	{
		int k1 = number / 2;
		if (k1 == nums1Size || (k1 - 1) == nums1Size)
		{
			return (nums1[nums1Size - 1] + nums2[0]) / 2.0;
		}
		else if (k1<nums1Size)
		{
			return (nums1[k1] + nums1[k1 - 1]) / 2.0;
		}
		else
		{
			return (nums2[k1] + nums2[k1 - 1]) / 2.0;
		}
	}
	else
	{
		int k2 = number / 2;
		if (k2 == nums1Size)
		{
			return nums2[0];
		}
		else
		{
			return nums1[k2];
		}
	}
}

int main()
{
	int nums1[] = { 3 };
	int nums2[] = { -2,-1 };
	int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
	int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
	double tmp = findMedianSortedArrays1(nums1, nums1Size, nums2, nums2Size);
	printf("中位数为：> %lf ", tmp);
	system("pause");
	return 0;
}