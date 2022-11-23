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
// ��ġ�� ���� �߰� ��, �ٸ� �� ���̿� ����

// ���� ���� �߰� ��, ū ������ �ڸ��� �ٲٰ�, �� ���� ������ �״�� ����

// size�� 5�����,
// 8���� ����								(0 ~ 0)
// 8�� 7 ��, 7�� 8�� ����					(0 ~ 1)
// 7, 8, 2 ��, 2, 7, 8�� ����				(0 ~ 2)
// 2, 7, 8, 3 ��, 2, 3, 7, 8�� ����		(0 ~ 3)
// 2, 3, 7, 8, 1 ��, 1, 2, 3, 7, 8�� ���� (0 ~ 4)

void InsertionSort(int input[], int size)
{
	for (int i = 1; i < size; i++)  // i�� �߰��� ���� ������ ���� index
	{
		int target = input[i];		// target = ������ (���� ������ ��)
		int j = i;					// j�� ���� ���� index

		while (--j >= 0 && target < input[j]) 
		{							// --j�� �����μ�, ���ʰ��̶� ��� ��
			input[j + 1] = input[j];
			input[j] = target;	
		}							// target�� �̹� �������� ���������Ƿ�
	}								// ���� Swap �Լ��� �Ƚᵵ �ȴ�.
}

// Ot = O (n ^ 2) // while�� Worst Case�� ���� ������ ���� ���� �������� (n - 1)
// Os = O (n)
// ���� ���� �˰����� ����.

int main()
{
	const int SIZE{ 5 };
	int array[SIZE]{ 8, 7, 2, 3, 1 };

	InsertionSort(array, SIZE);
	PrintArray(array, SIZE);
}