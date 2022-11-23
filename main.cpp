#include <iostream>

void PrintArray(int input[], int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << input[i] << " ";
	}
	std::cout << std::endl;
}

void Swap(int& value1, int& value2)
{
	int temp = value1;
	value1 = value2;
	value2 = temp;
}

// Insertion Sort
// 위치의 값을 발견 후, 다른 값 사이에 삽입

// 작은 값을 발견 후, 큰 값과는 자리를 바꾸고, 더 작은 값과는 그대로 유지

// size가 5개라면,
// 8에서 시작								(0 ~ 0)
// 8과 7 비교, 7과 8로 정렬					(0 ~ 1)
// 7, 8, 2 비교, 2, 7, 8로 정렬				(0 ~ 2)
// 2, 7, 8, 3 비교, 2, 3, 7, 8로 정렬		(0 ~ 3)
// 2, 3, 7, 8, 1 비교, 1, 2, 3, 7, 8로 정렬 (0 ~ 4)

void InsertionSort(int input[], int size)
{
	for (int i = 1; i < size; i++)  // i는 발견한 가장 오른쪽 값의 index
	{
		int target = input[i];		// target = 목적지 (가장 오른쪽 값)
		int j = i;					// j는 비교할 값의 index

		while (--j >= 0 && target < input[j]) 
		{							// --j를 함으로서, 왼쪽값이랑 계속 비교
			input[j + 1] = input[j];
			input[j] = target;	
		}							// target에 이미 원래값을 저장했으므로
	}								// 굳이 Swap 함수를 안써도 된다.
}

// Ot = O (n ^ 2) // while의 Worst Case는 가장 오른쪽 값이 가장 왼쪽으로 (n - 1)
// Os = O (n)
// 역시 이전 알고리즘들과 같다.

int main()
{
	const int SIZE{ 5 };
	int array[SIZE]{ 8, 7, 2, 3, 1 };

	InsertionSort(array, SIZE);
	PrintArray(array, SIZE);
}