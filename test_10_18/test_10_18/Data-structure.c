#include <stdio.h>

//int main()
//{
//	int i = 0;
//	int tmp = 0;
//	int arr1[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4 };
//	int arr2[10] = { 0 };
//	int* src1 = arr1;
//	int* dst = arr2;
//	tmp = arr1[0];
//	while ((src1 - arr1) < (sizeof(arr1)/4))
//	{
//		*dst = tmp;
//		dst++;
//		while ((src1 - arr1) < (sizeof(arr1) / 4) && tmp == *src1)
//		{
//			src1++;
//		}
//		tmp = *src1;
//	}
//	for (i = 0; i < (dst-arr2); i++)
//	{
//		printf("%d\n", arr2[i]);
//	}
//	return 0;
//}
//int main()
//{
//	int i = 5;
//	int m = 2;
//	int n = 2;
//	int arr1[] = { 1, 2, 3, 0, 0, 0};
//	int arr2[] = { 2, 5, 6 };
//	while (m >= 0 && n >= 0)
//	{
//		if (arr1[m] > arr2[n])
//		{
//			arr1[i] = arr1[m];
//			m --;
//			i --;
//		}
//		else
//		{
//			arr1[i] = arr2[n];
//			n--;
//			i--;
//		}
//	}
//	/*while (m >= 0)
//	{
//		arr1[i--] = arr1[m--];
//	}*/
//	while (n >= 0)
//	{
//		arr1[i--] = arr2[n--];
//	}
//
//	for (int j = 0; j <sizeof(arr1)/4; j++)
//	{
//		printf("%d ", arr1[j]);
//	}
//	
//	return 0;
//}
//int main()
//{
//
//}